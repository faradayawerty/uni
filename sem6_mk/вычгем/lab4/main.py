
from tkinter import *
from random import randint

CANVAS_WIDTH = 800
CANVAS_HEIGHT = 600
POINT_RADIUS = 4

root = Tk()
canvas = Canvas(bg="white", width=800, height=600)
points = [complex(randint(CANVAS_WIDTH / 4, 3 * CANVAS_WIDTH / 4), randint(CANVAS_HEIGHT / 4,  3 * CANVAS_HEIGHT / 4)) for i in range(5)]

def create_point(event):
	points.append(complex(event.x, event.y))
	calculate()

def delete_point(event):
	if len(points) < 5:
		return
	points.pop()
	canvas.delete('all')
	draw_info()
	calculate()

def move_point(event):
	z = complex(event.x, event.y)

	# найти ближайшую к курсору точку
	closest = f'P{0}'
	for k, v in enumerate(points):
		if abs(z - v) < abs(z - points[int(closest[1])]):
			closest = f'P{k}'

	x, y, _, _ = canvas.coords(closest)
	points[int(closest[1])] = complex(event.x, event.y)
	canvas.move(closest, event.x - x, event.y - y)
	calculate()

def cross(A, B):
	return (A.conjugate() * B).imag

def sign(x):
	if x > 0:
		return 1
	elif x < 0:
		return -1
	return 0

def calculate():

	color = 'yellow'
	radius_scale = 2
	for k, v in enumerate(points):
		canvas.delete(f'P{k}')
		canvas.create_oval(v.real, v.imag, v.real + 2 * POINT_RADIUS * radius_scale, v.imag + 2 * POINT_RADIUS * radius_scale, fill=color, tag=f'P{k}')
		color = 'blue'
		radius_scale = 1

	previous = points[1]
	for k, v in enumerate(points[2:] + [points[1]]):
		canvas.delete(f'L{k}')
		canvas.create_line(v.real + POINT_RADIUS, v.imag + POINT_RADIUS, previous.real + POINT_RADIUS, previous.imag + POINT_RADIUS, fill="red", width=4, tag=f'L{k}')
		previous = v

	N = len(points[1:])

	O = complex(0, 0)
	for point in points[1:]:
		O += point
	O = O / N

	# https://en.wikipedia.org/wiki/Shoelace_formula
	area = 0
	for i in range(N + 1):
		P1, P2 = points[1:][i % N], points[1:][(i + 1) % N]
		area += 0.5 * cross(P1, P2)

	Q = points[0] - O
	centered_points = [P - O for P in points[1:]]

	if sign(area) > 0:
		centered_points.reverse()

	inside_polygon = False
	for i in range(N + 1):
		P1, P2 = centered_points[i % N], centered_points[(i + 1) % N]
		inside_triangle = (cross(P2 - P1, Q) > 0) and (cross(P1, Q) * cross(P2, Q) < 0) and (cross(P2 - P1, Q - P1) < 0)
		inside_polygon = inside_polygon or inside_triangle

	canvas.delete('text')
	if inside_polygon:
		canvas.create_text(128, 128, fill='darkblue', text='внутри', tag='text')
	else:
		canvas.create_text(128, 128, fill='darkblue', text='снаружи', tag='text')


def draw_info():
	canvas.delete('info')
	canvas.create_text(256, 64, fill='darkblue', text='инструкция:\n\tнажмите пкм чтобы создать точку\n\tнажмите скм чтобы удалить последнюю созданную точку\n\tвы можете перемещать точки используя лкм', tag='info')
	
def main():
	root.title("Лабораторная #4: точка в многоугольнике")
	root.geometry("1366x768")
	draw_info()
	calculate()
	canvas.bind('<B1-Motion>', move_point)
	canvas.bind('<Button-2>', delete_point)
	canvas.bind('<Button-3>', create_point)
	canvas.pack(anchor=CENTER, expand=1)
	root.mainloop()

if __name__ == '__main__':
	main()

