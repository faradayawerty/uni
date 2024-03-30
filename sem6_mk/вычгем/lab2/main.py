
from tkinter import *
from random import randint

CANVAS_WIDTH = 800
CANVAS_HEIGHT = 600
POINT_RADIUS = 4

root = Tk()
canvas = Canvas(bg="white", width=800, height=600)

points = {
	'A': complex(randint(0, CANVAS_WIDTH), randint(0, CANVAS_HEIGHT)),
	'B': complex(randint(0, CANVAS_WIDTH), randint(0, CANVAS_HEIGHT)),
	'C': complex(randint(0, CANVAS_WIDTH), randint(0, CANVAS_HEIGHT)),
	'D': complex(randint(0, CANVAS_WIDTH), randint(0, CANVAS_HEIGHT))
}

def reset_points(event):
	for k, v in points.items():
		points[k] = complex(randint(0, CANVAS_WIDTH), randint(0, CANVAS_HEIGHT))
	calculate()

def move_point(event):
	z = complex(event.x, event.y)

	# найти ближайшую к курсору точку
	closest = 'A'
	for k, v in points.items():
		if abs(z - v) < abs(z - points[closest]):
			closest = k

	x, y, _, _ = canvas.coords(closest)
	points[closest] = complex(event.x, event.y)
	canvas.move(closest, event.x - x, event.y - y)
	calculate()
	

def calculate():

	for k, v in points.items():
		canvas.delete(k)
		canvas.create_oval(v.real, v.imag, v.real + 2 * POINT_RADIUS, v.imag + 2 * POINT_RADIUS, fill="blue", tag=k)

	A, B, C, D = points.values()

	canvas.delete('AB')
	canvas.create_line(A.real + POINT_RADIUS, A.imag + POINT_RADIUS, B.real + POINT_RADIUS, B.imag + POINT_RADIUS, fill="red", width=4, tag='AB')

	canvas.delete('CD')
	canvas.create_line(C.real + POINT_RADIUS, C.imag + POINT_RADIUS, D.real + POINT_RADIUS, D.imag + POINT_RADIUS, fill="red", width=4, tag='CD')

	# найти |CA×BA|, |DA×BA|, |AC×DC|, |BC×DC|
	CA_cross_BA = ((C - A).conjugate() * (B - A)).imag
	DA_cross_BA = ((D - A).conjugate() * (B - A)).imag
	AC_cross_DC = ((A - C).conjugate() * (D - C)).imag
	BC_cross_DC = ((B - C).conjugate() * (D - C)).imag

	print(A, B, C, D)
	print(CA_cross_BA, DA_cross_BA)
	print(AC_cross_DC, BC_cross_DC)

	canvas.delete('text')
	if CA_cross_BA * DA_cross_BA < 0 and AC_cross_DC * BC_cross_DC < 0:
		canvas.create_text(128, 128, fill="darkblue", text=f"пересекаются", tag='text')
		print('пересекаются')
	else:
		canvas.create_text(128, 128, fill="darkblue", text=f"не пересекаются", tag='text')
		print('не пересекаются')

	print()

def main():
	canvas.create_text(256, 32, fill="darkblue", text=f"инструкция:\n\tвы можете перемещать точки, спользуя лкм\n\tзадать случаное положение точек - пкм")
	root.title("Лабораторная #2: пересечение отрезков")
	root.geometry("1366x768")
	calculate()
	canvas.bind("<B1-Motion>", move_point)
	canvas.bind("<Button-3>", reset_points)
	canvas.pack(anchor=CENTER, expand=1)
	root.mainloop()

if __name__ == '__main__':
	main()

