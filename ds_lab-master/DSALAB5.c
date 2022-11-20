#include<stdlib.h>
#include <stdio.h>
#include <string.h>
struct employee{
int empid;
char name[20];
int salary;
struct employee *next;
};
struct employee *top,*ptr,*temp;
void add()
{
ptr=(struct employee*)malloc(sizeof(struct employee));
printf("\n----------------------------");
printf("\nenter the id name and pay for employee:");
scanf("%d %s %d", &(ptr)->empid,(ptr)->name,&(ptr)->salary);
ptr->next=NULL;
if(top==NULL)
        {
        top=ptr;        
        }
else
        {
        ptr->next=top;
        top=ptr;
        }
}

void display_all()
{
if(top==NULL)
        {
        printf("\nno employees added");        
        }
else{
        printf("\n----------------------------");
        printf("\ndetails are as followed");
        printf("\n\tid\tname\tpay:");
        ptr=top;
        while(ptr!=NULL)
        {
        printf("\n\t%d\t%s\t%d",(ptr)->empid,(ptr)->name,(ptr)->salary);
        ptr=ptr->next;
        }
        }
}


void idsearch()
{
if(top==NULL)
        {
        printf("\nno employees added");        
        }
else
        {
int x,found=0,foundid;
printf("\n----------------------------");
printf("\nenter the id to be searched:");
scanf("%d",&x);
ptr=top;
while(ptr!=NULL)
        {
if((ptr->empid)==x)
{
found=1;
break;
}
ptr=ptr->next;
        }
if(found==0)
{printf("\n----------------------------");
printf("\nid not found");
}
else
{printf("\n----------------------------");
printf("\nthe employee details are as followed:");
printf("\n\tid\tname\tpay");
printf("\n\t%d\t%s\t%d",(ptr)->empid,(ptr)->name,(ptr)->salary);
}
        }
}

void namesearch()
{
if(top==NULL)
        {
        printf("\nno employees added");        
        }
else   
        {
char x[20];
int found=0,foundid;
printf("\n----------------------------");
printf("\nenter the name to be searched:");
scanf("%s",x);
ptr=top;
while(ptr!=NULL)
        {
if(strcmp((ptr->name),x)==0)
{
found=1;
break;
}
ptr=ptr->next;
        }
if(found==0)
{printf("\n----------------------------");
printf("\nname not found");
}
else
{printf("\n----------------------------");
printf("\nthe employee details are as followed:");
printf("\n\tid\tname\tpay");
printf("\n\t%d\t%s\t%d",(ptr)->empid,(ptr)->name,(ptr)->salary);
}
        }
}


void highestpay()
{
if(top==NULL)
        {
        printf("\nno employees added");        
        }
else
        {
int highest,highestid;
ptr=top;
highest=(ptr)->salary;
while(ptr!=NULL)
        {
if(highest<((ptr)->salary))
{
highest=(ptr)->salary;
temp=ptr;
}
ptr=ptr->next;
        }
printf("\nthe highest salary is %d and belongs to id %d and name %s",temp->salary,temp->empid,temp->name);        

        }        
        }

void numemp()
{
int count =0;
ptr=top;
while(ptr!=NULL)
        {
        count++;
        ptr=ptr->next;
        }
printf("\nthe total number of employees are %d",count);        
}


int main()
{
int num,i=0,opt;
do{
printf("\n----------------------------");
printf("\n1-add employee\n-2display all\n-3search by empid\n-4search by name");
printf("\n5-highest salary\n6-total number of employees\n7-exit:");
scanf("%d",&opt);
switch(opt)
{
        case 1:add();
                break;
        case 2:display_all();
                break;
        case 3:idsearch();
                break;
        case 4:namesearch();
                break;
        case 5:highestpay();
                break;
        case 6:numemp();
                break;
        case 7:exit(0);
        default:printf("\n----------------------------");
        printf("\nenter correct choice");
        break;
}
}while(1);
return 0;
}