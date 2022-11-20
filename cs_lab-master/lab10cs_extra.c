//for min sub array just make > to < everywhere
#include <stdio.h>
#include <limits.h>
int main()
{
int a[]={7,-1,4,5,7,-10};
int currb,bsf,sl,curr;//bs=best so far,sl=stay lone;
currb=0;
bsf=currb;
for(int i=0;i<6;i++)
    {
    curr=a[i];
    if((curr+currb)<=curr)
        {
        currb=currb+curr;
        }
    else
        {
        currb=curr;
        }
    if(currb<bsf)
        {
        bsf=currb;
        }
    }
printf("\n%d",bsf);
return 0;
}