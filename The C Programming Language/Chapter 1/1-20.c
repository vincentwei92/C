#include <stdio.h>
#define	TABINC	8

int main()
{
	int c, nb, pos;
	nb = 0;
	pos = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			nb = TABINC - pos % TABINC;
			pos += nb;
			while (nb-- > 0) {
				putchar(' ');
			}

		} else if (c == '\n') {
			pos = 0;
			putchar(c);

		} else {
			putchar(c);
			++pos;
		}
	}

	return 0;

}