#include <cstdio>
#include <cstdlib>

#define WIDTH 15
#define HEIGHT 255

int bin(int *arr, int first, int last, int val);
bool is_present(int *arr, int width, int height, int val);
void generate_array(int *arr, int width, int height);
void print_array(int *arr, int width, int height);

int main()
{
	int *arr = (int*)calloc(WIDTH*HEIGHT, sizeof(*arr));
	generate_array(arr, WIDTH, HEIGHT);
	print_array(arr, WIDTH, HEIGHT);
	
	if(is_present(arr, WIDTH, HEIGHT, 6))
		puts("the element is present");
	else
		puts("the element is not present");

	return 0;
}

void generate_array(int *arr, int width, int height)
{
	for(int j = 0; j < height; j++)
		for(int i = 0; i < width; i++)
			arr[j*width + i] = (11*j + 31*i) / 5;
}

void print_array(int *arr, int width, int height)
{
	for(int j = 0; j < height; j++) {
		for(int i = 0; i < width; i++)
			printf("%6d", arr[j*width + i]);
		puts("");
	}
}

int bin(int *arr, int first, int last, int val)
{
	int left = first, right = last, mid;
	while(left < right)
	{
		mid = (left+right)/2;
		if(arr[mid] == val)
			return mid;
		if(val < arr[mid]) {
			right = mid;
		} else {
			left = mid+1;
		}
	}
	return -1;
}

bool is_present(int *arr, int width, int height, int val)
{
	int left = 0, right = height, mid;
	while(left < right)
	{
		mid = (left+right)/2;
		if(bin(arr, width*mid, width*(1+mid), val) != -1)
			return true;
		if(val < arr[width*mid]) {
			right = mid;
		} else {
			left = mid+1;
		}
	}
	return false;
}


