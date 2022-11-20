#include<stdlib.h>
#include <stdio.h>
struct employee{
        int id;
        char name[20];
        int salary;
};
void add(struct employee *ptr,int i)
{printf("\n----------------------------");
printf("\nenter the id name and pay for empployee:");
scanf("%d %s %d", &(ptr+i)->id,(ptr+i)->name,&(ptr+i)->salary);
}

void display_all(struct employee *ptr,int i)
{printf("\n----------------------------");
printf("\ndetails are as followed");
printf("\n\tid\tname\tpay:");        
for(int j=0;j<i;j++)    
{
printf("\n\t%d\t%s\t%d",(ptr+j)->id,(ptr+j)->name,(ptr+j)->salary);        
}
}

void idsearch(struct employee *ptr,int i)
{
int x,found=0,foundid;
printf("\n----------------------------");
printf("\nenter the id to be searched:");
scanf("%d",&x);
for(int j=0;j<i;j++)
{
if(((ptr+j)->id)==x)
        {
        foundid=j;
        found=1;
        break;
        }
}
if(found==0)
{printf("\n----------------------------");
printf("\nid not found");        
}
else
{printf("\n----------------------------");
printf("\nthe employee details are as followed:");
printf("\n\tid\tname\tpay");     
printf("\n\t%d\t%s\t%d",(ptr+foundid)->id,(ptr+foundid)->name,(ptr+foundid)->salary);    
}
}

void namesearch(struct employee *ptr,int i)
{
char x[20];
int found=0,foundid,comp;
printf("\n----------------------------");
printf("\nenter the name to be searched:");
scanf("%s",x);
for(int j=0;j<i;j++)
{
comp=strcmp(((ptr+j)->name),x);        
if(comp==0)
        {
        foundid=j;
        found=1;
        
        break;
        }
}
if(found==0)
{printf("\n----------------------------");
printf("\nid not found");        
}
else
{printf("\n----------------------------");
printf("\nthe employee details are as followed:");
printf("\n\tid\tname\tpay");     
printf("\n\t%d\t%s\t%d",(ptr+foundid)->id,(ptr+foundid)->name,(ptr+foundid)->salary);    
}
}

void highestpay(struct employee *ptr,int i)
{
int highest,highestid;
highest=(ptr+0)->salary;
for(int j=0;j<i;j++)
{
        if(highest<((ptr+j)->salary))
                {
                highest=(ptr+j)->salary;        
                highestid=j;
                }
}
printf("\n----------------------------");
printf("\nthe highest pay is of employee with id:%d name:%s  and is equal to %d",(ptr+highestid)->id,(ptr+highestid)->name,(ptr+highestid)->salary);
}



int main()
{     
int num,i=0,opt;
printf("\n----------------------------");
    printf("\nenter the total number of employees");
    scanf("%d",&num);
struct employee *ptr;
ptr=(struct employee *)malloc(num*sizeof(struct employee));
do{
printf("\n----------------------------");
printf("\n1-add employee\n-2display all\n-3search by empid\n-4search by name");
printf("\n5-highest salary\n6-total number of employees\n7-exit:");
scanf("%d",&opt);
switch(opt)
        {
        case 1:if(i<num){
                
                add(ptr,i);
                i++;
                break;
                }
                else{
                printf("\n----------------------------");
                printf("\ncannot add more employees memory limit reached");        
                break;
                }
        case 2:if(i==0)
                {printf("\n----------------------------");
                printf("\nno employees entered yet");        
                break;
                }
                else{
                display_all(ptr,i);
                break;
                }
        case 3:if(i==0)
                {printf("\n----------------------------");
                printf("\nno employees entered yet");        
                break;
                }
                else{
                idsearch(ptr,i);
                break;
                }
        case 4:if(i==0)
                {printf("\n----------------------------");
                printf("\nno employees entered yet");        
                break;
                }
                else{
                namesearch(ptr,i);
                break;
                }
        case 5:if(i==0)
                {printf("\n----------------------------");
                printf("\nno employees entered yet");        
                break;
                }
                else{
                highestpay(ptr,i);
                break;
                }
        case 6:printf("\n----------------------------");
                printf("\nnumber of employees is %d",(i));
                break;
        case 7:exit(0);
                break;
        default:printf("\n----------------------------");
                printf("\nenter correct choice");
                break;
        }
}while(1);
return 0;
}
