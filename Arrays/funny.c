#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int i,j,t;
    char str[10000],rev[10000];
    scanf("%d",&t);
    while(t > 0)
    {
            scanf("%s",str);
            int length = strlen(str);
            for(i = length - 1,j = 0;i >=0 ; i--)
            {
                rev[j++] = str[i];
            }
            for(i = 1; i < length ; i++)
            {
                    if(abs((int)str[i] - (int)str[i - 1]) != abs((int)rev[i] - (int)rev[i - 1]))
                    {
                        //printf("\nFunny");
                        break;
                    }
            }
            if(i == length)
            {
                   printf("\nFunny");
            }
	    else
		printf("\nNot Funny");
            
            t--;
    }
    return 0;
}
