#include <stdio.h>
#include <stdlib.h>

int m_w, m_h;
int **m_a, **m_b;

void calc_b(int i, int j);
int get_b(int i, int j);
void m_print(int **arr);
void m_create(int **arr);
void m_randomize(int **arr);

int u_min(int a, int b);
int u_min3(int a, int b, int c);

int main()
{

	printf("количество столбцов: "); scanf("%d", &m_w);
	printf("количество строк: "); scanf("%d", &m_h);

	m_create(m_a);
	m_create(m_b);

	m_print(m_a);

	//m_randomize(m_a);
	//m_print(m_a);

	//calc_b(m_h - 1, m_w - 1);
	//m_print(m_b);

	return 0;
}

void calc_b(int i, int j)
{
	if(i == 0 || j == 0)
		m_b[i][j] = m_a[i][j];
	else if(m_a[i][j] == 0)
		m_b[i][j] = 0;
	else if(m_a[i][j] == 1)
		m_b[i][j] = u_min3(get_b(i-1, j), get_b(i, j-1), get_b(i-1, j-1)) + 1;
}

int get_b(int i, int j)
{
	calc_b(i, j);
	return m_b[i][j];
}

void m_randomize(int **arr)
{
	for(int i = 0; i < m_h; i++)
		for(int j = 0; j < m_w; j++)
			arr[i][j] = rand() % 2;
}

void m_create(int **arr)
{
	arr = (int **)calloc(sizeof(int*), m_h);
	for(int i = 0; i < m_h; i++)
		arr[i] = (int *)calloc(sizeof(int), m_w);
}

void m_print(int **arr)
{
	for(int i = 0; i < m_h; i++) {
		for(int j = 0; j < m_w; j++)
			printf("\t%d", arr[i][j]);
		putchar('\n');
	}
}

int u_min(int a, int b)
{
	return a > b ? b : a;
}

int u_min3(int a, int b, int c)
{
	return u_min(u_min(a, b), c);
}

