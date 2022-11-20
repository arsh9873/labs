#include <stdio.h>
int main()
{
    int dec,rem,q;
    int i,j,t;
    char hex[20];
    printf("Enter any decimal number: ");
	scanf("%d",&dec);
    q=dec;
    i=0;
    while(q!=0)
        {
            t= q%16;
            if(t<10)
            {
            t=t+48;
            }
            else
            {
            t=t+55;
            }
        hex[i++]=t;
        q=q/16;
        }
    for(int j=i;j>0;j--)
        {
            printf("%c",hex[j]);
        }
     return 0;
}