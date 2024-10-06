import math
from tkinter import*

SCALE = 10
POINT_RADIUS = 4

root = Tk()
canvas = Canvas(root)

def main():
	canvas.pack()

	inputs = []
	try:
		file_inputs = open('inputs.txt', 'r')
		for line in file_inputs.readlines():
			inputs += [[int(num) for num in line.split(' ')]]
		file_inputs.close()
	except:
		print("ошибка чтения файла")
		return

	P = inputs
	draw_points(P)
	draw_polygon(jarvismarch(P))

	root.mainloop()

def cover(P):
	return P

def draw_points(P):
	for p in P:
		canvas.create_oval(p[0] * SCALE - POINT_RADIUS,
			p[1] * SCALE - POINT_RADIUS,
			p[0] * SCALE + POINT_RADIUS,
			p[1] * SCALE + POINT_RADIUS, fill="blue", outline="#DDD", width=2)

def draw_polygon(P):
	P_raw = []
	for p in P:
		P_raw += [p[0] * SCALE, p[1] * SCALE]
	P_raw += [P[0][0] * SCALE, P[0][1] * SCALE]
	canvas.create_polygon(P_raw, outline='gray', fill='',  width=2)	

def rotate(A,B,C):
  return (B[0]-A[0])*(C[1]-B[1])-(B[1]-A[1])*(C[0]-B[0])

def jarvismarch(A):
  n = len(A)
  P = list(range(n))
  # start point
  for i in range(1,n):
    if A[P[i]][0]<A[P[0]][0]: 
      P[i], P[0] = P[0], P[i]  
  H = [P[0]]
  del P[0]
  P.append(H[0])
  while True:
    right = 0
    for i in range(1,len(P)):
      if rotate(A[H[-1]],A[P[right]],A[P[i]])<0:
        right = i
    if P[right]==H[0]: 
      break
    else:
      H.append(P[right])
      del P[right]
  return [A[i] for i in H]

if __name__ == '__main__':
	main()
