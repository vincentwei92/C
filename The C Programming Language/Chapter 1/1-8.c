#include <stdio.h>
int main()
{
	int c, nw, nt, nl;
	nw = nt = nl = 0;

	while ((c =getchar()) != EOF) {
		if (c == ' ') 
			nw++;
		else if (c == '\t') 
			nt++;
		else if (c == '\n') 
			nl++;
	}

	printf("nw is %d, nt is %d, nl is %d", nw, nt, nl);

	return 0;
}