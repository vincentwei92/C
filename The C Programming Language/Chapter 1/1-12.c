#include <stdio.h>
#define OUT 0
#define IN  1

int main()
{
	int c, state = IN;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			state = OUT;
		} else {
			if (state == OUT) {
				putchar('\n');
				state = IN;
			} 
			putchar(c);
		}
	}

	return 0;
}