#include <stdio.h>
int main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			putchar(c);

			while ((c = getchar()) != EOF && c == ' ')
				;
		}
		if (c == EOF)
			break;
		putchar(c);
	}
	/*to avoid this situation, that is _______EOF . where _ stands for space*/
	
	return 0;
}