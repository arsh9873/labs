#include<stdio.h>
#include<stdlib.h>
//made by ARSH ALI KHAN
int count=-1;
void disp(int *p)
{
if(count==-1)
    {
    printf("\nempty stack");
    return;
    }
printf("\nthe elements are:");
for(int i=0;i<=count;i++)
    {
    printf("\t%d",p[i]);
    }
}

void push(int *p,int n)
{
if(count==(n-1))
    {
    printf("\noverflow");
    return;
    }
count=count+1;
printf("\nenter element");
scanf("%d",&p[count]);
}

void pop(int *p)
{
if(count==-1)
    {
    printf("\nunderflow");
    return;
    }
count = count - 1;
}

void peek(int *p)
{
printf("\nthe last element is:%d",p[count]);

}

void isempty()
{
if(count==-1)
    {printf("\nthe stack is empty");

        }
}

void isfull(int n)
{
if(count==(n-1))
    {printf("\nthe stack is full");

        }
}

void total()
{
printf("\nthe total number of elements entered is %d",count+1);
}

int main()
{
int opt,n,*ptr;
printf("\nenter the number of elements");
scanf("%d",&n);
ptr=(int *)malloc(n*sizeof(int));
do{
printf("\n1-push\n2-pop\n3-peek\n4-isempty\n5-isfull\n6-total num\n7-display\n8-exit");
scanf("%d",&opt);
switch(opt)
    {
    case 1:push(ptr,n);
            disp(ptr);
            break;
    case 2:pop(ptr);
            disp(ptr);
            break;
    case 3:peek(ptr);
            break;
    case 4:isempty();
            break;
    case 5:isfull(n);
            break;
    case 6:total();
            break;
    case 7:disp(ptr);
            break;
    case 8:exit(0);
    default:break;
    }
}while(1);
return 0;
}
