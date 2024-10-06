#include <cstdio>

int main()
{
	unsigned int x, s = 0;
	bool is_added = false;

	while(x != 0) {
		scanf("%d", &x);
		if(is_added)
			s += x;
		is_added = !is_added;
	}
	printf("%d\n", s);

	return 0;
}

