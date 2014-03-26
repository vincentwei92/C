#include <stdio.h>
int main()
{
	int c, lastc;
	while ((c = getchar()) != EOF) {
		if (c != ' ' || lastc != ' ') {
			putchar(c);
		}
		lastc = c;
	}
	return 0;
}