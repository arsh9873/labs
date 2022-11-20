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
            printf("%d\t",temp->data);
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
    else
        {
        int pos;
        printf("\nenter position to delete from:");
        scanf("%d",&pos);
            if(pos>count)
                {
                printf("\npos not found");
                }
            else if(pos==count)
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
            else if(pos==1)
                {
                front=front->next;
                }
            else
                {
                int curr=1;
                struct arr *temp;
                temp=front;
                while(curr<pos-1)
                    {
                    temp=temp->next;
                    curr++;
                    }
                temp->next=temp->next->next;
                }   
        }
        disp();                
    }
void total()
    {
    printf("\ntotal num of elements are:%d",count);
    }
void sum_total()
    {
    int sum=0;
    struct arr *temp;
    temp=front;
    while(temp!=NULL)
        {sum=sum+temp->data;
        temp=temp->next;
        }
    printf("\nsum of all elements is %d",sum);
    }
void search()
    {
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
void maxnum()
    {
    int max=0,pos=0;
    struct arr *temp;
    temp=front;
    while(temp!=NULL)
        {
        pos++;
        if(temp->data>max)
            {
            max=temp->data;
            }
        temp=temp->next;
        }
    printf("\nthe largest value is %d",max);
    }
int main()
{
int opt;
do
{
printf("\n1. Insert at beg\n2. Insert at end\n3. Insert at given position");
printf("\n4. Deletion from beg\n5. Deletion from end\n6. Deletion from given position");
printf("\n7. Total no. of Elements\n8. Sum of Elements of Linked list\n9. Search of Item");
printf("\n10. Maximum No. in Linked List\n11. Display\n12. Exit::");
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
        case 6:deque(6);
                break;
        case 7:total();
                break;
        case 8:sum_total();
                break;
        case 9:search();
                break;
        case 10:maxnum();
                break;
        case 11:disp();
                break;
        case 12:exit(0);
        default:break;
        }
} while (1);

return 0;
}