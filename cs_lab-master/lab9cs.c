#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int len(char *s)
{
int count=0;
char *ptr;
ptr=s;
while((*ptr)!='\0')
    {
    count++;
    ptr++;
    }
return count-1;
}
void find_replace(char *ch1,char *ch2,char *chr)
{
int size1,size2,i=0,sub,mflag=0,pos;
char replaced[80];
size1=len(ch1);
size2=len(ch2);
while(i<size1)//substring finder
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
                printf("\nsubstring confirmed at index %d",(pos));
                break;    
                }        
        }
    i++;
    }
if(sub==1||mflag==0)
{
printf("\n-----------------------------------------------------");
printf("\nnot a substring");    
return;
}    
int lenr;
lenr=len(chr);
    if(lenr==size2)//if replacing word same size as orignal
{
for(int i=pos,j=0;j<lenr;i++,j++)
    {    
    ch1[i]=chr[j];
    }
printf("\nmodified string is:%s",ch1);
}
    else
{
int lendiff;
lendiff=lenr-size2;
for(int j=0,i=0,k=0;j<(size1+lendiff);j++)
    {
    if(j<pos)
    {
    replaced[j]=ch1[j];
    i++;
    }
    else if(j>=pos && k<lenr)
    {
         if(j==pos)
            {
            i=i+size2;
            }
    replaced[j]=chr[k];
    k++;
    }
    else
    {
    replaced[j]=ch1[i];
    i++;
    }
    }
    replaced[size1+lendiff]='\0';
printf("\nmodified string is:%s",replaced);
}
}
int main()
{
char str1[80],strf[30],strr[30];
printf("\nenter your orignal string:");
fgets(str1,80,stdin);
printf("\nenter the word to be found:");
fgets(strf,30,stdin);
printf("\nenter the word the replaced word:");
fgets(strr,30,stdin);
find_replace(str1,strf,strr);
return 0;
}