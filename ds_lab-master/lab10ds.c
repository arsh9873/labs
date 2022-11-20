#include <stdio.h>
#include <stdlib.h>
struct pque
{
  char n[4];
  int pr;
 struct pque  *next;
};
struct pque *front=NULL;
int count=0;
void disp()
{  printf("\n***********************************");
    if(front==NULL)
    {
    printf("\nempty queue");
    return;
    }
    struct pque *temp;
    temp=front;
    printf("\n");
    while(temp!=NULL)
        {
        printf("%s \t%d|",temp->n,temp->pr);
        temp=temp->next;
        }
}
void enque()
    {
    printf("\n***********************************");
    struct pque *ptr;   
    count++;
    ptr=(struct pque*)malloc(sizeof(struct pque));    
    printf("\nenter string and priority::");
    scanf("%s%d",ptr->n,&(ptr->pr));
    if(front==NULL || ptr->pr<front->pr)
        {
        ptr->next=front;
        front=ptr;
        } 
    else  
    {  struct pque *temp;
        temp = front;  
        while( temp->next != NULL && temp->next->pr <= ptr->pr )  
            temp=temp->next;  
        ptr->next = temp->next;  
        temp->next = ptr;  
    }  
  
    }

void deuque()
{printf("\n***********************************");
if(front==NULL)
    {
    printf("\nunderflow");
    return;
    }
printf("\ndequed element was %s",front->n);    
count--;
front=front->next;
}

void front_pos()
{
struct pque *temp;
temp=front;
printf("\n***********************************");
printf("\nfront is pointing at %s",temp->n);
while(temp->next!=NULL)
     {temp=temp->next;   
     }
printf("\nrear is pointing at %s",temp->n);
}

void isempty()
{printf("\n***********************************");
if(front==NULL)
    {
    printf("\ntrue");
    }    
else
    {
    printf("\nfalse");
    }    
}

void total()
{printf("\n***********************************");
printf("\nnumber of elements are %d",count);
}

int main()
{int opt;
do{
printf("\n***********************************");
printf("\n1. Enqueue \n2. Dequeue \n3. Front and Rear Element \n4. Isempty \n5. Total no of element");
printf("\n6. Display \n7. Exit::");
scanf("%d",&opt);
    switch(opt)
        {
            case 1:enque();
                    break;
            case 2:deuque();
                    break;
            case 3:front_pos();
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