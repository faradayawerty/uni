
# https://docs.google.com/presentation/d/12VpkUbnivlViQQeAK17OX4BeToQXPVEvBjP2IJ7_d4Q/edit?usp=drivesdk

from random import randint, randrange
from operator import itemgetter, attrgetter
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

infinity = float('inf')

def bruteForceClosestPair(point):
    numPoints = len(point)
    if numPoints < 2:
        return infinity, (None, None)
    return min( ((abs(point[i] - point[j]), (point[i], point[j]))
                 for i in range(numPoints-1)
                 for j in range(i+1,numPoints)),
                key=itemgetter(0))

def closestPair(point):
    xP = sorted(point, key= attrgetter('real'))
    yP = sorted(point, key= attrgetter('imag'))
    return _closestPair(xP, yP)

def _closestPair(xP, yP):
    numPoints = len(xP)
    if numPoints <= 3:
        return bruteForceClosestPair(xP)
    Pl = xP[:numPoints//2]
    Pr = xP[numPoints//2:]
    Yl, Yr = [], []
    xDivider = Pl[-1].real
    for p in yP:
        if p.real <= xDivider:
            Yl.append(p)
        else:
            Yr.append(p)
    dl, pairl = _closestPair(Pl, Yl)
    dr, pairr = _closestPair(Pr, Yr)
    dm, pairm = (dl, pairl) if dl < dr else (dr, pairr)
    # Points within dm of xDivider sorted by Y coord
    closeY = [p for p in yP  if abs(p.real - xDivider) < dm]
    numCloseY = len(closeY)
    if numCloseY > 1:
        # There is a proof that you only need compare a max of 7 next points
        closestY = min( ((abs(closeY[i] - closeY[j]), (closeY[i], closeY[j]))
                         for i in range(numCloseY-1)
                         for j in range(i+1,min(i+8, numCloseY))),
                        key=itemgetter(0))
        return (dm, pairm) if dm <= closestY[0] else closestY
    else:
        return dm, pairm


def create_point(event):
	points.append(complex(event.x, event.y))
	calculate()

def delete_point(event):
	if len(points) < 3:
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

def calculate(color=None):
	canvas.delete('all')
	info = 'инструкция:\n\t'
	info += 'нажмите пкм чтобы создать точку\n\t'
	info += 'нажмите скм чтобы удалить последнюю созданную точку\n\t'
	info += 'вы можете перемещать точки используя лкм\n\t'
	canvas.create_text(256, 64, fill='darkblue', text=info, tag='info')
	for k, v in enumerate(points):
		canvas.create_oval(v.real - POINT_RADIUS, v.imag - POINT_RADIUS, v.real + POINT_RADIUS, v.imag + POINT_RADIUS, fill="blue", tag=f'P{k}')
	length = closestPair(points)[0]
	P1, P2 = closestPair(points)[1]
	canvas.create_line(P1.real, P1.imag, P2.real, P2.imag, fill='red', width=2)
	canvas.create_oval(P1.real - 2 * POINT_RADIUS, P1.imag - 2 * POINT_RADIUS, P1.real + 2 * POINT_RADIUS, P1.imag + 2 * POINT_RADIUS, fill="yellow", tag=f'P{k}')
	canvas.create_oval(P2.real - 2 * POINT_RADIUS, P2.imag - 2 * POINT_RADIUS, P2.real + 2 * POINT_RADIUS, P2.imag + 2 * POINT_RADIUS, fill="yellow", tag=f'P{k}')
	canvas.create_text((0.5 * P1 + 0.5 * P2).real, (0.5 * P1 + 0.5 * P2).imag, fill='darkblue', text="{:4.0f}".format(length), tag='info')

def main():
	root.title("Лабораторная #7: пара ближайших точек")
	root.geometry("1366x768")
	calculate()
	canvas.bind('<B1-Motion>', move_point)
	canvas.bind('<Button-2>', delete_point)
	canvas.bind('<Button-3>', create_point)
	canvas.pack(anchor=CENTER, expand=1)
	root.mainloop()

if __name__ == '__main__':
	main()
