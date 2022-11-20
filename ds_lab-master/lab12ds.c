//written by ARSH KHAN -20BCS081
#include <stdio.h>
#include <stdlib.h>
struct node
{
int data; 
struct node * prev; 
struct node * next; 
};
struct node *top;
int count=0;
void disp()
        {
        printf("\n******************");
        if(top==NULL)
                {
                printf("\nempty");
                return;
                }
        struct node *temp;
        temp=top;
        printf("\n");
        while(temp!=NULL)
                {
                printf("\t%d|",temp->data);
                temp=temp->next;
                }
        }
void insert_beg()
        {
        int item;
        struct node *ptr;
        ptr=(struct node*)malloc(sizeof(struct node));
        printf("\nenter value:");
        scanf("%d",&item);
        ptr->data=item;
        if(top==NULL)
                {
                top=ptr;
                ptr->next=NULL;
                ptr->prev=NULL;
                }
        else
                {
                ptr->next=top;
                top->prev=ptr;
                ptr->prev=NULL;
                top=ptr;
                }
        printf("\ninserted");
        count++;
        }
void insert_end()
        {
        int item;
        struct node *ptr,*temp;
        ptr=(struct node*)malloc(sizeof(struct node));
        printf("\nenter value:");
        scanf("%d",&item);
        ptr->data=item;
        if(top==NULL)
                {
                top=ptr;
                ptr->next=NULL;
                ptr->prev=NULL;
                }
        else
                {
                temp=top;
                while(temp->next!=NULL)
                        {
                        temp=temp->next;
                        }
                temp->next=ptr;
                ptr->prev=temp;
                ptr->next=NULL;
                }
        printf("\ninserted");
        count++;
        }
void insert_pos()
        {
        int pos;
        printf("\nenter the position:");
        scanf("%d",&pos);
        if(pos==1)
                {
                insert_beg();
                }
        else if(pos==count+1)
                {
                insert_end();
                }
        else if(pos<1 || pos>count+1)
                {
                printf("\nposition doesnt exist");
                }
        else
                {
                int item;
                struct node *ptr,*temp,*ptemp;
                ptr=(struct node*)malloc(sizeof(struct node));
                printf("\nenter value:");
                scanf("%d",&item);
                ptr->data=item;
                temp=top;
                for(int i=1;i<pos;i++)
                        {
                        ptemp=temp;
                        temp=temp->next;
                        }
                ptr->next=temp;
                temp->prev=ptr;
                ptemp->next=ptr;
                ptr->prev=ptemp;
                printf("\ninserted");
                count++;
                }
        }
void delete_beg()
        {
        if(top==NULL)
                {
                printf("\nunderflow");
                return;
                }
        else if(top->next==NULL)
                {
                top=NULL;
                }
        else
                {
                top=top->next;
                top->prev=NULL;
                }
        printf("\ndeleted");
        count--;
        }
void delete_end()
        {
        if(top==NULL)
                {
                printf("\nunderflow");
                return;
                }
        else if(top->next==NULL)
                {
                top=NULL;
                }
        else
                {
                struct node *temp;
                temp=top;
                while(temp->next->next!=NULL)
                        {
                        temp=temp->next;
                        }
                temp->next->prev=NULL;
                temp->next=NULL;
                }
        printf("\ndeleted");
        count--;
        }
void print_rev()
        {
        if(top==NULL)
                {
                printf("\nempty");
                return;
                }
        else if(top->next==NULL)
                {
                printf("\n%d",top->data);
                }
        else
                {
                struct node *temp;
                temp=top;
                printf("\n");
                while(temp->next!=NULL)
                        {
                        temp=temp->next;        
                        }
                while(temp!=NULL)
                        {
                        printf("\t%d",temp->data);
                        temp=temp->prev;
                        }
                }
        }
void search()
        {
        if(top==NULL)
            {
            printf("\nempty");
            return;
            }
        int item,pos=0,flag=0;
        printf("\nenter value to be searched:");
        scanf("\n%d",&item);
        struct node *temp;
        temp=top;
        while(temp!=NULL)
                {
                pos++;
                if(temp->data==item)
                        {
                        flag=1;
                        break;
                        }
                temp=temp->next;
                }
        if(flag==0)
                {
                printf("\nitem not found");
                }
        else
                {
                printf("\nitem found at pos %d",pos);
                }
        }
int main()
{
int opt;
do{
printf("\n________________________________________________________________");
printf("\n1.Insert at beg\t\t2.Insert at end\t\t3.Insert at given position");
printf("\n4.Deletion from beg\t5.Deletion from end\t6.Print reverse order");
printf("\n7.Search\t\t8.Display\t\t9.Exit:");
scanf("%d",&opt);
switch(opt)
    {
    case 1: printf("\n**************************");
            insert_beg();
            disp();
            break;
    case 2:printf("\n**************************");
            insert_end();
            disp();
            break;
    case 3:printf("\n**************************");
            insert_pos();
            disp();
            break;
    case 4:printf("\n**************************");
            delete_beg();
            disp();
            break;
    case 5:printf("\n**************************");
            delete_end();
            disp();
            break;
    case 6:printf("\n**************************");
            print_rev();
            break;
    case 7:printf("\n**************************");
            search();
            break;
    case 8:printf("\n**************************");
            disp();
            break;
    case 9:exit(0);
            break;
    default:break;
    }}while(1);       
    return 0;
}
