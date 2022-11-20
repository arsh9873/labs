#include <stdio.h>
#include <stdlib.h>
struct arr{
    int data;
    struct arr *next;
};
struct arr *front,*rear,*ptr;
int count=0;
void disp()
    {
        struct arr *temp;
        temp=front;
        printf("\n");
        while(temp!=NULL)
            {
            printf("%d\t|",temp->data);
            temp=temp->next;
            }
    }
void enque(int opt)
    {
    count++;
    ptr=(struct arr*)malloc(sizeof(struct arr));
    printf("\nenter value:");
    scanf("%d",&(ptr->data));
    if(opt==1)
        {      
            if(front==NULL)
                {
                front=ptr;
                rear=ptr;
                }
            else
                {
                ptr->next=front;
                front=ptr;    
                }
        }
    else if(opt==2)
        {      
            if(front==NULL)
                {
                front=ptr;
                rear=ptr;
                }
            else
                {
                rear->next=ptr;
                rear=ptr;    
                }
        }
    else
        {
         if(front==NULL)
                {
                front=ptr;
                rear=ptr;
                }
        else
                {
                int pos;
                struct arr *temp;
                printf("\nenter the position:");
                scanf("%d",&pos);
                if(pos>count)
                    {
                    printf("\nposition doesnt exist");
                    }
                else if(pos==count)
                    {
                    rear->next=ptr;
                    rear=ptr;   
                    }
                else
                    {
                    int curr=1;
                    temp=front;
                    while(curr<(pos-1))
                        {
                        temp=temp->next;
                        curr++;    
                        }
                    ptr->next=temp->next;
                    temp->next=ptr;
                    }
                }       
        }
        disp();        
    }
void deque(int opt)
    {
    if(front==NULL)
        {
        printf("\nempty");
        return;
        }
    count--;
    if(opt==4)
        {
        front=front->next;
        }
    else if(opt==5)
        {
        struct arr *temp;
        temp= front;
        while(temp->next->next!=NULL)
            {
            temp=temp->next;
            }
        temp->next=NULL;
        rear=temp;
        }
        disp();                
    }
void total()
    {
    printf("\ntotal num of elements are:%d",count);
    }

void search()
    {
    if(front==NULL)
        {
        printf("\nempty");
        return;
        }
    int pos=0,find,flag=0;
    printf("\nenter data to be searched");
    scanf("%d",&find);
    struct arr *temp;
    temp=front;
    while(temp!=NULL)
        {
            pos++;
            if(find==temp->data)
            {
            flag=1;
            break;
            }
            temp=temp->next;
        }
    if(flag==1)
        {
        printf("\nitem found at pos %d",pos);
        }
    else
        {
        printf("\nitem not found");
        }
    }

int main()
{
int opt;
do
{
printf("\n1. Insert at beg\n2. Insert at end\n3. Insert at given position");
printf("\n4. Deletion from beg\n5. Deletion from end");
printf("\n6. Total no. of Elements\n7. Search of Item");
printf("\n8. Display\n9. Exit::");
scanf("%d",&opt);
    switch (opt)
        {
        case 1:enque(1);
                break;
        case 2:enque(2);
                break;
        case 3:enque(3);
                break;
        case 4:deque(4);
                break;        
        case 5:deque(5);
                break;
        case 6:total();
                break;
        case 7:search();
                break;
        case 8:disp();
                break;
        case 9:exit(0);
        default:break;
        }
} while (1);

return 0;
}