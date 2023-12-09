#include <cstdio>

#define INITIAL_WIDTH 324
#define INITIAL_HEIGHT 141

int main()
{
	int w = INITIAL_WIDTH, h = INITIAL_HEIGHT, c = 0, sidelength = 0;

	do {
		if (w > h) {
			c += w / h;
			w %= h;
			sidelength = h;
		} else if (w < h) {
			c += h / w;
			h %= w;
			sidelength = w;
		} else {
			c += 1;
			sidelength = w;
		}
		printf("cutting squares with side %d\n", sidelength);

	} while(w > 0 && h > 0 && w != h);

	printf("\n%d squares\n", c);

	return 0;
}

