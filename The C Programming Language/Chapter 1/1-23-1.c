#include <stdio.h>
#define OPEN	0
#define CLOSE	1	

int main()
{
	
	int c, s_quotes = CLOSE, d_quotes = CLOSE, coment = CLOSE;
    c = getchar();
	while (c != EOF) {
        if (c == '\'' && coment == CLOSE) {
        	putchar(c);
        	if (d_quotes == CLOSE)
          		s_quotes = !s_quotes;
        } else if (c == '\"' && coment == CLOSE) {
        	putchar(c);
        	if (s_quotes == CLOSE) {
        		d_quotes = !d_quotes;
        	}
        } else if (c == '/') {
            if (coment == OPEN)
                ;
        	else if (s_quotes == CLOSE && d_quotes == CLOSE) {
                if ((c = getchar()) != EOF && c == '*') {
        			coment = OPEN;
        		} else{
        			putchar('/');
        			continue;
        		}
        	} else {
        		putchar(c);
        	} 
        } else if (c == '*') {
        	if (coment == OPEN && s_quotes == CLOSE && d_quotes == CLOSE) {
        		if ((c = getchar()) != EOF && c == '/') {
        			coment = CLOSE;
        		} else {
                    /* mark here */
                    continue;
        		}
        	} else {
        		putchar(c);
        	}
        } else if (c == '\\' && coment == CLOSE) {
            putchar(c);
            if ((c = getchar()) != EOF && (c == '\\' || c == '\'' || c == '\"')) 
                ;
            else 
                continue;
        } else if (coment == CLOSE) {
        	putchar(c);
        }

        c = getchar();
    }
	return 0;
}
