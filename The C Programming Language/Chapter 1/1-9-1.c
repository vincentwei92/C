#include <stdio.h>
#define IN  1 // in space
#define OUT 0

int main()
{
	int c, state;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (state == OUT) {
				putchar(c);
			}
			state = IN;
		} else {
			putchar(c);
			state = OUT;
		}
	}
	return 0;
}