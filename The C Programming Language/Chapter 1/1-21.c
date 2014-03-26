#include <stdio.h>
#define TABINC 8

int main()
{
	int c, pos, nb = 0, nt = 0; 
	pos = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++nb;
			++pos;
			if (pos % TABINC == 0) {
				nb = 0;
				++nt;
			}
		} else {
			while (nt > 0) {
				putchar('\t');
				--nt;
			}
			if (c == '\t') {
				nb = 0; 							/* here, nb always equals 0, no matter nb > 0 or  = 0, so I'd like to assign it to 0. */
				pos = pos - pos % TABINC + TABINC;
			} else {
				while (nb > 0) {
					putchar(' ');
					--nb;
				}
				if (c == '\n') {
					pos = 0;
				} else {
					++pos;
				}				
			}
			putchar(c);
		} 
	}
	return 0;
}