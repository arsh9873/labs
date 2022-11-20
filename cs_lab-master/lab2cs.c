#include <stdio.h>

int main()
{
    int a[10],opt,count,m,lim,pos,ch=1,n;
    printf("\nenter the size of the array");
    scanf("%d",&n);
    count=n;
    printf("\nenter the array elements");
    for(int i=0;i<n;i++)
    {
    scanf("%d",&a[i]);    
    }
    printf("\n the array entered is as follows:");
    for(int i=0;i<n;i++)
    {
    printf("%d \t",a[i]);
    }
    do{
    printf("\nenter your choice");
    printf("\n1-insert element at begining.\n2-insert element at end.\n3insert element at position.");
    printf("\n4-delete element at begining.\n5-delete element at end.\n6-delete element at position");
    printf("\n7-exit");
    scanf("%d",&opt);
    switch (opt)
    {
    case 1:
        if(count<10)
        {printf("\nenter the element you want to enter");
        scanf("%d",&m);
        for(int i=(n-1);i>=0;i--)
            {
            a[i+1]=a[i];    
            }
            a[0]=m;
        for(int i=0;i<(n+1);i++)
        {
         printf("%d \t",a[i]);
            }      
        n++;
        count=n;
        } 
        else{
            printf("\noverflow");
        }     
        break;
    case 2:if(count<10)
            {printf("\nenter the element you want to insert at end");
            scanf("%d",&m);
            a[n]=m;
            for(int i=0;i<(n+1);i++)
        {
         printf("%d \t",a[i]);
            } 
        n++;
        count=n;
        }
        else
        {
            printf("\noverflow");
        }           
        break;
    case 3:if(count<10){
            printf("\nenter the element and the position");
            scanf("%d%d",&m,&pos);
            for(int i=n;i>pos;i--)
            {a[i]=a[i-1];
            }
            a[pos]=m;
            for(int i=0;i<(n+1);i++)
        {
         printf("%d \t",a[i]);
            }
        n++; 
        count=n;
        } 
        else
        {
            printf("\noverflow");
        }          
        break;
    case 4:if(count>0){ 
            for(int i=0;i<(n-1);i++)
            {
                a[i]=a[i+1];
            }
            for(int i=0;i<(n-1);i++)
        {
         printf("%d \t",a[i]);
            } 
        n--; 
        count=n;
        }
        else{
            printf("\nunderflow");
        }          
        break;    
    case 5:if(count>0)
            {
            n--;
           for(int i=0;i<n;i++)
            {
            printf("%d \t",a[i]);
            }
            count=n;
            }  
        else
        {
            printf("\nunderflow");
        } 
        break;
    case 6:if(count>0)
            {
            printf("\nenter the position of element to delete");
            scanf("%d",&pos);
            for(int i=pos;i<n;i++)
                {
                a[i]=a[i+1];
                }    
            for(int i=0;i<(n-1);i++)
            {
            printf("%d \t",a[i]);
            }
        n--;
        count=n;
        }
        else
        {
            printf("\nunderflow");
        }            
        break;
    case 7:ch=0;
        break;
    default:printf("\nplease enter a valid choice");
        break;
    }
    }while(ch!=0);
return 0;
}