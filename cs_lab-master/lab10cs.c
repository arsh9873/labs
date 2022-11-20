#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
int main()
{   
    int n;
    printf("\nsize of array:");
    scanf("%d",&n);
    int *arr,*arrs;
    arr=(int *)malloc(n*sizeof(int));
    arrs=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        {
        scanf("%d",&arr[i]);    
        arrs[i]=arr[i];
        }
    int min_sf=INT_MAX,min_h=0,min_sf1;
    for(int i=0;i<n;i++)
        {
        min_sf1=min_sf;    
        min_h=min_h+arr[i];
            if(min_h<min_sf)
                {
                min_sf=min_h;    
                }
            if(min_h>0)
                {
                min_h=0;
                }
        }       
    printf("\nthe minimum sum is %d",min_sf);
    printf("\nand the subarray is:");
    int temp_sum=INT_MAX,t=0,count=0,pos;
    for(int i=0;i<n;i++)
        {  
            for(int j=i;j<n;j++)
                {
                t=t+arrs[j];
            if(t==min_sf)
                {
                count=1;
                pos=j;
                break;   
                } 
                }
            if(count==1){
                printf("\n");
            for(int k=i;k<=pos;k++)
                {
                printf("\t%d",arrs[k]);
                }
                }
            t=0;     
            count=0;
            pos=0;         
        }
    return 0;
}