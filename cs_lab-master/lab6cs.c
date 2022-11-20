#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int len(char *ch)
{
int count=0;
while(*ch!='\0')
    {
    count++;
    ch++;
        }
return count;    
}

void cmp(char *ch1,char *ch2)
{
int len1,len2;
len1=len(ch1);
len2=len(ch2);
if(len1!=len2)
    {
    printf("\n-----------------------------------------------------");    
    printf("\ntheir lenghts arent equal");    
    }
else
    {int size,flag=0;
    size = len1;
    for(int i=0;i<size;i++)
        {
            if(*ch1!=*ch2)
            {
            printf("\n-----------------------------------------------------");
            printf("\nthe strings are same lenght but different");    
            flag=1;
            break;
            }
            ch1++;
            ch2++;
        }
    if(flag==0)
        {
        printf("\n-----------------------------------------------------");    
        printf("\nthe strings are equal");    
        }    
    }   
}

void pall(char *ch)
{
int size,flag=0;
size=len(ch);
int higher=size-1;
int lower=0;
while(higher>lower)
    {
    if(ch[lower]!=ch[higher])
        {
        printf("\n-----------------------------------------------------");    
        printf("\nstring is not a pallindrome");
        flag=1;
        break;    
        }    
    lower++;
    higher--;    
    }
if(flag==0)
    {   printf("\n-----------------------------------------------------");
        printf("\nstring is a pallindrome");
    }
}

void cat(char *ch1,char *ch2)
{
int size1,size2,sizet,i=0,j=0;
size1=len(ch1);
size2=len(ch2);
sizet=size1+size2;
char catstr[40];
while(ch1[i]!='\0')
    {
    catstr[j]=ch1[i];
    i++;
    j++;    
    }
i=0;
while(ch2[i]!='\0')
    {
    catstr[j]=ch2[i];
    i++;
    j++;    
    }
catstr[j]='\0';
printf("\n-----------------------------------------------------");
printf("\nthe concatenared string is %s",catstr);
}

void rev(char *ch)
{
char revch[20];
int size,i=0;
size=len(ch);
while(i<size)
    {
    revch[i]=ch[(size-1)-i];
    i++;
    }
revch[i]='\0';
printf("\n-----------------------------------------------------");
printf("\nthe reversed string is %s",revch);
}

void cpy(char *ch)
{
char cpystr[20];
int size,i=0;
size=len(ch);
while(i<size)
    {
    cpystr[i]=ch[i];
    i++;    
    }
cpystr[i]='\0';
printf("\n-----------------------------------------------------");
printf("\nthe copied string is %s",cpystr);
}

void substring(char *ch1,char *ch2)
{
int size1,size2,sizet,i=0,sub,mflag=0,pos;
size1=len(ch1);
size2=len(ch2);
while(i<size1)
    {
    if(ch2[0]==ch1[i])
        {   mflag=1;
            for(int j=i,cnt=0;cnt<size2;j++,cnt++)
                {
                pos=i;
                sub=0;
                if(ch2[cnt]!=ch1[j])
                    {
                    sub=1;
                    break;
                    }
                }
            if(sub==0)
                {
                printf("\n-----------------------------------------------------");    
                printf("\nsubstring confirmed at position %d",(pos+1));
                break;    
                }        
        }
    i++;
    }
if(sub==1||mflag==0)
{
printf("\n-----------------------------------------------------");
printf("\nnot a substring");    
}    
}

int main()
{
char str[20],str2[20];
int opt;
do{
printf("\n*************************************************");
printf("\nenter your choice");
printf("\n1-lenght finder\n2-string reverse\n3-string copy");
printf("\n4-string compare\n5-string concatenation\n6-pallindrome");
printf("\n7-substring checker\n8-exit:");
scanf("%d",&opt);
switch(opt)
{
    case 1:printf("\nenter the string:");
            scanf("%s",str);
            printf("\nthe lenght of the string is =%d",len(str));
            break;
    case 2:printf("\nenter the string:");
            scanf("%s",str);
            rev(str);
            break;
    case 3:printf("\nenter the string:");
            scanf("%s",str);
            cpy(str);
            break;
    case 4:printf("\nenter the 1st string:");
            scanf("%s",str);
            printf("\nenter the 2nd string:");
            scanf("%s",str2);
            cmp(str,str2);
            break;
    case 5:printf("\nenter the 1st string:");
            scanf("%s",str);
            printf("\nenter the 2nd string:");
            scanf("%s",str2);
            cat(str,str2);
            break;
    case 6:printf("\nenter the string:");
            scanf("%s",str);
            pall(str);
            break;
    case 7:printf("\nenter the string:");
            scanf("%s",str);
            printf("\nenter the 2nd string:");
            scanf("%s",str2);
            substring(str,str2);
            break;
    case 8:exit(0);
            break;
    default:printf("\nenter a valid option please:");    
}
}while(1);
return 0;
}