#include <stdio.h>
#include <stdlib.h>
int count=-1;

struct stud_data{
 char name[30];
 int rollno,sub1,sub2,sub3,per;
 };
 struct stud_data stud1[10],stud2[10];
void display()
 {   FILE *fptr;
     int i;
     if(count==-1)
     {
         printf("empty file \n");
         fclose(fptr);
     }
     else{
    fptr=fopen("file.txt","rb");
    fread(stud2,sizeof(stud2),1,fptr);
    printf("\nName \tRoll No\t Subject1\tSubject2 \tSubject3 \tPercentage \n");
    for(i=0;i<=count;i++)
    {
        printf("%s\t",stud2[i].name);
        printf("%d\t\t",stud2[i].rollno);
        printf("%d\t\t",stud2[i].sub1);
        printf("%d\t\t",stud2[i].sub2);
        printf("%d\t\t",stud2[i].sub3);
        printf("%d\t\n",stud2[i].per);
    }
    printf("\n");
    fclose(fptr);
     }
 }

 void update()
 {
     FILE *fptr,*fptr1;
     int no,flag=0,ch;
     int i;
     printf("Enter roll number of the student\n");
     scanf("%d",&no);
     fptr=fopen("file.txt","rb");
     fread(stud1,sizeof(stud1),1,fptr);
     for(i=0;i<=count;i++)
     {
         if(stud1[i].rollno==no)
         {
             flag=1;
             printf("choose the subject to change marks \n");
             scanf("%d",&ch);
             printf("Enter the subjects new marks \n");
             if(ch==1)
             {
                scanf("%d",&stud1[i].sub1);
             }
             if(ch==2)
             {
                scanf("%d",&stud1[i].sub2);
             }
             if(ch==3)
             {
                scanf("%d",&stud1[i].sub3);
             }
         }

     }
     if(flag==0)
     {
         printf("\nnot found");
         fclose(fptr);
     }
     else
     {
         fptr1=fopen("temp.txt","wb");
         fwrite(stud1,sizeof(stud1),1,fptr1);
         fclose(fptr);
         fclose(fptr1);
         remove("file.txt");
         rename("temp.txt","file.txt");
         display();
     }

 }

 void del()
 {
     FILE *fptr,*fptr1;
     int no,flag=0,i,x;
     printf("Enter the roll number of the student \n");
     scanf("%d",&no);
     fptr=fopen("file.txt","rb");
     fread(stud1,sizeof(stud1),1,fptr);
     for(i=0;i<=count;i++)
     { 
         if(stud1[i].rollno==no)
         {   flag=1;
             for(x=i;x<count-1;x++)
             {
               stud1[x]=stud1[x+1];
             }
         }
     }
     if(flag==0)
     {
         printf("\nnot found");
         fclose(fptr);
     }
     else
     {   count--;
         fptr1=fopen("temp.txt","wb");
         fwrite(stud1,sizeof(stud1),1,fptr1);
         fclose(fptr);
         fclose(fptr1);
         remove("file.txt");
         rename("temp.txt","file.txt");
         display();
     }

 }

 void insert()
 {
     FILE *fptr;
    fptr=fopen("file.txt","wb");
        count++;
        printf("Enter name and roll:");
        scanf("%s%d",&stud1[count].name,&stud1[count].rollno);
        printf("Enter subject 1 2 3 marks :\n");
        scanf("%d%d%d",&stud1[count].sub1,&stud1[count].sub2,&stud1[count].sub3);
        printf("Enter total percentage\n");
        scanf("%d",&stud1[count].per);
    fwrite(stud1,sizeof(stud1),1,fptr);
    fclose(fptr);
 }

 

int main()
{
    int opt;
    printf("\n********************");
    do
    {
    printf("\n1.Insert Row \n2.Display Row \n3.Update Row \n4.Delete \n5.Exit \n");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1: insert();
                printf("\n********************");
                break;
        case 2: display();
                printf("\n********************");
                break;
        case 3: update();
                printf("\n********************");
                break;
        case 4: del();
                printf("\n********************");
                break;
        case 5: exit(0);
        default:break;
    }
    }while(1);
    return 0;

}
