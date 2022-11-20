#include <stdio.h>
#include <stdlib.h>
struct abc{
        int info;
        struct abc *next;
}*front,*rear,*ptr;
int count=0;
void disp()
        {
        if(rear==NULL)
                {
                printf("\n*************************");
                printf("\nqueue is emtpy");
                }
        else
        {
        printf("\n*************************");    
        struct abc *temp;
        temp=front;
        printf("\n");
        while(temp!=NULL)
                {
                printf("\t%d",temp->info);
                temp=temp->next;
                }
        }
        }
void enque()
        {
        int x;
        printf("\n*************************");
        printf("\nenter value:");
        scanf("%d",&x);
        ptr=(struct abc*)malloc(sizeof(struct abc));
        if(front == NULL || rear == NULL)
                {
                front=ptr;
                rear=ptr;
                }
        else
                {
                rear->next=ptr;
                rear=ptr;
                }
        ptr->info=x;
        ptr->next=NULL;
        count++;
        disp();
        }
void deque()
        {
        if(rear == NULL)      
                {
                printf("\n*************************");
                printf("\nunderflow");
                }
        else
                {
                printf("\n*************************");
                printf("\ndeleted element:%d",front->info);
                front=front->next;
                count--;
                disp();
                }
                
        }
void front_rear()
        {
        if(rear==NULL)
                {
                printf("\n*************************");
                printf("\nqueue is emtpy");
                }
        else
                {
                printf("\n*************************");
                printf("\nfront element:%d",front->info);
                printf("\nrear element:%d",rear->info);
                }
        }
void isempty()
        {
        if(rear==NULL)
                {
                printf("\n*************************");
                printf("\nqueue is empty");
                }
        else
                {
                printf("\n*************************");
                printf("\nqueue is not empty");
                }
        }
void total_num()
        {
        printf("\n*************************");
        printf("\ntotal number of elements in the queue are %d",count);
        }
int main()
{
   int opt;
   do{
    printf("\n*************************");
   printf("\n1-enque\n2-deque\n3-front and rear\n4-isempty\n5-total num");
   printf("\n6-display\n7-exit:");
   scanf("%d",&opt);
   switch(opt)
        {
        case 1:enque();
                break;
        case 2:deque();
                break;
        case 3:front_rear();
                break;
        case 4:isempty();
                break;
        case 5:total_num();
                break;
        case 6:disp();
                break;
        case 7:exit(0);
        default:break;
        }}while(1);
    return 0;
}
