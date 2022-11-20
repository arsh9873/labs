#include <stdio.h>
#include <stdlib.h>
int count=0,f=-1,r=-1;
void enque(int *q,int size)
        {       printf("\n----------------------------");
                if((r+1)%size==f)
                {
                printf("\noverflow");
                return;
                }
                count++;
                int x;
                printf("\nenter element:");
                scanf("%d",&x);
                if(f==-1 && r==-1)
                        {
                        f++;
                        r++;
                        q[r]=x;
                        }
                else
                        {
                        r=(r+1)%size;
                        q[r]=x;
                        }
        
        }
void deque(int *q,int size)
{
printf("\n----------------------------");
    if((f==-1) && (r==-1)) 
        {
        printf("\nunderflow");
        }
    else if(f==r)
        {
        count--;
        printf("\nThe dequeued element is %d",q[f]);
        q[f]=0;
        f=-1;
        r=-1;
        }
    else
        {
        count--;
        printf("\nThe dequeued element is %d",q[f]);
        q[f]=0;
        f=(f+1)%size;
        }
}

void front_rear(int *q)
        {
        printf("\n----------------------------");
        if(f==-1 && r==-1)
                {
                        printf("\nqueue is empty");
                }
        else
                {
                        printf("\nfront element is %d and front is %d",q[f],f);
                        printf("\nrear element is %d and rear is %d",q[r],r);
                }
        }
void isempty()
        {printf("\n----------------------------");
                if(f==-1 && r==-1)
                        {
                        printf("\nqueue is empty");
                        }
                else
                        {
                        printf("\nqueue is not empty");
                        }
        }
        
void isfull(int size)
        {printf("\n----------------------------");
              if((r+1)%size==f)
                {
                printf("\nqueue is full");
                }  
                else
                {
                printf("\nqueue isnt full");
                }
        }

void total_num()
{printf("\n----------------------------");
printf("\nnumber of elements in the queue are %d",count);
}

void disp(int *q,int size)
        {printf("\n----------------------------");
        if(f==-1 && r==-1)
                {
                printf("\nqueue is empty");
                }
        else
                {
                printf("\n");
                if(f<=r)
                        {
                        for(int i=f;i<=r;i++)
                                {
                                printf("\t%d",q[i]);
                                }
                        }
                else
                {
                        int i=f;
                        while(i<=(size-1))
                                {
                                printf("\t%d",q[i]);
                                i++;
                                }
                        i=0;        
                        while(i<=r)
                                {
                                printf("\t%d",q[i]);
                                i++;
                                }
                }
                }
        }

int main()
{
int opt,*q,n;
printf("\nenter the size of queue");
scanf("%d",&n);
q=(int*)malloc(n*sizeof(int));
do{
printf("\n----------------------------");
printf("\nenter your choice \n1. Enqueue \n2. Dequeue \n3. Front and Rear Element \n4. Isempty");
printf("\n5. Isfull \n6. Total no of element \n7. Display \n8. Exit:");
scanf("%d",&opt);
switch(opt)
        {
                case 1:enque(q,n);
                        break;
                case 2:deque(q,n);
                        break;
                case 3:front_rear(q);
                        break;
                case 4:isempty(q);
                        break;
                case 5:isfull(n);
                        break;
                case 6:total_num(q);
                        break;
                case 7:disp(q,n);
                        break;
                case 8:exit(0);
                default:break;
        }}while(1);
    return 0;
}
