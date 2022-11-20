#include<stdlib.h>
#include<stdio.h>
#define size 3
int arr[size],front=-1,rear=-1,count=-1;
void enque()
        {
         if(rear==(size-1))
                {
                printf("\nqueue is full");
                return;
                }
        count++;
        if(front==-1 && rear==-1)
                {
                rear++;
                front++;
                }
        else
                {
                rear++;
                }
                int x;
                printf("\nenter element:");
                scanf("%d",&x);
                arr[rear]=x;
        }
void deque()
        {
        if(rear==-1)
                {
                printf("\nqueue is empty");
                return;
                }
        printf("\nelement dequed was:%d",arr[rear]);
        count--;
        if(rear==0 && front==0)
                {
                rear=-1;
                front=-1;
                }
        else
        {
        rear=rear-1;
        }
        }
void display()
        {
        if(rear==-1)
                {
                printf("\nqueue is empty");
                return;        
                }
        else
        {
                for(int i=front;i<=rear;i++)
                        {
                        printf("\t%d",arr[i]);
                        }
        }
        }
void front_rear()
        {
        if(rear==-1)
                {
                printf("\nqueue is empty");
                return;
                }
        printf("\nthe front element is %d",arr[front]);
        printf("\nthe rear element is %d",arr[rear]);
        }
void isempty()
        {
        if(front==-1)
                {
                printf("\nqueue is empty");
                }
        }

void isfull()
        {
        if(rear==(size-1))
                {
                printf("\nqueue is full");
                }
        }      

void total_number()
{
if(count ==-1)
        {
        printf("\nqueue is empty");
        return;
        }
printf("\ntotal number of elements are %d",count+1);
}

#include <stdio.h>
int main()
{
int opt;
while(1)
{
printf("\n1-enque\n2-deque\n3-display\n4-front and rear\n5-isempty\n6-isfull");
printf("\n7-total number");
scanf("%d",&opt);
switch (opt){
        case 1:enque();
                display();
                break;
        case 2:deque();
                display();
                break;
        case 3:display();
                break;
        case 4:front_rear();
                break;
        case 5:isempty();
                break;
        case 6:isfull();
                break;
        case 7:total_number();
                break;
        default:exit(0);
}

}
    return 0;
}
