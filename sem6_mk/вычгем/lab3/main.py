
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
	if len(points) < 4:
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

def cross(A, B, C):
	AB, BC  = B - A, C - B
	return (AB.conjugate() * BC).imag

def calculate():

	for k, v in enumerate(points):
		canvas.delete(f'P{k}')
		canvas.create_oval(v.real, v.imag, v.real + 2 * POINT_RADIUS, v.imag + 2 * POINT_RADIUS, fill="blue", tag=f'P{k}')

	previous = points[0]
	for k, v in enumerate(points[1:] + [points[0]]):
		canvas.delete(f'L{k}')
		canvas.create_line(v.real + POINT_RADIUS, v.imag + POINT_RADIUS, previous.real + POINT_RADIUS, previous.imag + POINT_RADIUS, fill="red", width=4, tag=f'L{k}')
		previous = v

	N = len(points)
	all_positive, all_negative = True, True
	for i in range(N + 3):
		cross_product = cross(points[i % N], points[(i + 1) % N], points[(i + 2) % N])
		print(cross_product)
		all_positive = all_positive and (cross_product >= 0)
		all_negative = all_negative and (cross_product <= 0)

	canvas.delete('text')
	if all_positive or all_negative:
		canvas.create_text(128, 128, fill='darkblue', text='выпуклый', tag='text')
		print('выпуклый')
	else:
		canvas.create_text(128, 128, fill='darkblue', text='не выпуклый', tag='text')
		print('не выпуклый')
	print()

def draw_info():
	canvas.delete('info')
	canvas.create_text(256, 64, fill='darkblue', text='инструкция:\n\tнажмите пкм чтобы создать точку\n\tнажмите скм чтобы удалить последнюю созданную точку\n\tвы можете перемещать точки используя лкм', tag='info')
		
	
def main():
	root.title("Лабораторная #3: выпуклый многоугольник")
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

