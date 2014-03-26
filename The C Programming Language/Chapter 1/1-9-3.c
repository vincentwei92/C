#include <stdio.h>
int main()
{
	int c, lastc;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (lastc != ' ')
				putchar(c);
		} else {
			putchar(c);
		}
		lastc = c;
	} 

	return 0;
}