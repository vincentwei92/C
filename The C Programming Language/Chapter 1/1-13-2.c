#include <stdio.h>
#define MAXHIST 15
#define MAXWORD 11
#define IN  1
#define OUT 0

/* print vertical histogram */

int main()
{
	int i, j, c, maxvalue, nc, len, state, wl[MAXWORD], ovflow;

	state = OUT;
	ovflow = 0;
	nc = 0;
	for (i = 0; i < MAXWORD; i++) {
		wl[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if(c == ' ' || c == '\t' || c == '\n') {
			if (state == IN) {
				if (nc < MAXWORD) 
					++wl[nc];
				else
					++ovflow;

				state = OUT;
			}
		} else if (state == OUT) {
			nc = 1;
			state = IN;
		} else {
			++nc;
		}
	}

	maxvalue = 0;
	for (i = 1; i < MAXWORD; i++) {
		if (wl[i] > maxvalue) {
			maxvalue = wl[i];
		}
	}

	for (i = MAXHIST; i > 0; i--) {
		putchar('|');
		for (j = 1; j < MAXWORD; j++) 
			if (wl[j] * MAXHIST / maxvalue >= i)
				printf(" * ");
			else
				printf("   ");

		putchar('\n');
	}

	putchar('+');
	for (i = 1; i < MAXWORD; i++) {
		printf("---");
	}
	putchar('\n');

	for (i = 1; i < MAXWORD; i++) {
		printf("%3d", i);
	}
	putchar('\n');
	if (ovflow > 0) 
		printf("There are %d words >= %d", ovflow, MAXWORD);

	return 0;
}