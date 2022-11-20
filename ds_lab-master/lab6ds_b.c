#include<stdio.h>
#include<stdlib.h>
struct abc{
    int a;
    struct abc *next;
};
struct abc *top,*ptr;
int count=-1;

void disp()
{
struct abc *temp;
if(top==NULL)
    {
        printf("\nstack is empty");
    }
else
    {
        temp=top;
        while(temp!=NULL)
            {
            printf("\t%d",temp->a);
            temp=temp->next;
            }
    }
}

void push()
{
count++;
int x;
ptr=(struct abc*)malloc(sizeof(struct abc));
if(ptr==NULL)
{ printf("\nMemory is not allocated");
return ;
}
printf("\nenter your element");
scanf("%d",&x);
ptr->a=x;
ptr->next=NULL;
if(top==NULL)
    {
    top=ptr;
    }
else
    {
    ptr->next=top;
    top=ptr;
    printf("\ninserted.");
    }    
}

void pop()
{
if(top==NULL)
    {
        printf("\nunderflow");
    }
else
    {
    count--;
    printf("\ndeleted element was %d",top->a);
    top=top->next;
    }
}

void peek()
{
if(top==NULL)
    {
        printf("\nstack is empty");
    }
else
    {
        printf("\ntop has the element %d",top->a);

        }   
}

void isempty()
{
if(top==NULL)
    {printf("\nthe stack is empty");
        }
else
printf("\nthe stack is not empty");
}

void total()
{
printf("\nthe number of elements in the stack is %d",count+1);
}

int main()
{
int opt;
do{
printf("\n1-push\n2-pop\n3-peek\n4-isempty\n5-total num\n6-display\n7-exit");
scanf("%d",&opt);
switch(opt)
    {
    case 1:push();
            break;
    case 2:pop();
            break;
    case 3:peek();
            break;
    case 4:isempty();
            break;
    case 5:total();
            break;
    case 6:disp();
            break;
    case 7:exit(0);
    default:break;
    }
}while(1);
return 0;
}
