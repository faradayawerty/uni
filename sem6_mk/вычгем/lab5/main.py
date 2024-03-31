
from time import sleep
from tkinter import *
from random import randint

CANVAS_WIDTH = 800
CANVAS_HEIGHT = 600
POINT_RADIUS = 4

root = Tk()
canvas = Canvas(bg="white", width=800, height=600)
points = [complex(randint(CANVAS_WIDTH / 4, 3 * CANVAS_WIDTH / 4), randint(CANVAS_HEIGHT / 4,  3 * CANVAS_HEIGHT / 4)) for i in range(5)]
convex_cover = []

def create_point(event):
	points.append(complex(event.x, event.y))
	calculate()

def delete_point(event):
	if len(points) < 4:
		return
	points.pop()
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

def dot(A, B):
	return (A.conjugate() * B).real

def graham_scan(event):
	P = points.copy()
	for i in range(len(P)):
		for j in range(len(P)):
			if P[i].imag > P[j].imag:
				P[i], P[j] = P[j], P[i]
	for i in range(len(P)):
		for j in range(len(P)):
			if cross(P[i] - P[0], P[j] - P[0]) < 0:
				P[i], P[j] = P[j], P[i]
	R = []
	N = len(P)
	for i in range(N):
		while len(R) >= 2 and cross(R[-1] - R[-2], P[i] - R[-1]) >= 0:
			R.pop()
		R.append(P[i])
	calculate(R, 'red')

def jarvis_march(event):
	P = points.copy()
	for i in range(len(P)):
		for j in range(len(P)):
			if P[i].imag > P[j].imag:
				P[i], P[j] = P[j], P[i]
	R = [P[0]]
	P.remove(P[0])
	while len(P) > 0:
		max_p = P[0]
		for i in range(len(P)):
			if cross(max_p - R[-1], P[i] - R[-1]) > 0:
				max_p = P[i]
		if cross(max_p - R[-1], R[0] - R[-1]) > 0:
			break
		R.append(max_p)
		P.remove(max_p)

	calculate(R, 'orange')

def draw_polygon(P, color):
	if P is None or len(P) < 1:
		return
	previous = P[0]
	for k, v in enumerate(P[1:] + [P[0]]):
		canvas.create_line(v.real + POINT_RADIUS, v.imag + POINT_RADIUS, previous.real + POINT_RADIUS, previous.imag + POINT_RADIUS, fill=color, width=4, tag=f'L{k}')
		previous = v

def calculate(convex_cover=None, color=None):
	canvas.delete('all')
	info = 'инструкция:\n\t'
	info += 'нажмите пкм чтобы создать точку\n\t'
	info += 'нажмите скм чтобы удалить последнюю созданную точку\n\t'
	info += 'вы можете перемещать точки используя лкм\n\t'
	info += 'нажмите g чтобы сосчитать выпуклую оболочку методом грехема\n\t'
	info += 'нажмите j чтобы сосчитать выпуклую оболочку методом джарвиса\n\t'
	canvas.create_text(256, 64, fill='darkblue', text=info, tag='info')
	for k, v in enumerate(points):
		canvas.create_oval(v.real, v.imag, v.real + 2 * POINT_RADIUS, v.imag + 2 * POINT_RADIUS, fill="blue", tag=f'P{k}')
	if convex_cover is not None:
		draw_polygon(convex_cover, color=color)

def main():
	root.title("Лабораторная #5: выпуклая оболочка")
	root.geometry("1366x768")
	root.bind('g', graham_scan)
	root.bind('j', jarvis_march)
	calculate()
	canvas.bind('<B1-Motion>', move_point)
	canvas.bind('<Button-2>', delete_point)
	canvas.bind('<Button-3>', create_point)
	canvas.pack(anchor=CENTER, expand=1)
	root.mainloop()

if __name__ == '__main__':
	main()

