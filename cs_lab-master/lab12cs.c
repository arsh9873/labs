#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
float extractor(char *str)
    {
    float num=0,tnum=0,dnum=0,num2=0,fsum;
    int i=0,pos,flag=0,len=0;
    while(str[i]!='\0')
        {
            if(str[i]=='.')
                {
                flag=1;
                pos=i;
                break;
                }
            i++;
            len++;
        }
    if(flag==0)
        {
            for(int j=0;j<len;j++)
                {
                tnum=str[j]-'0';
                num=num + tnum*(pow(10,(len-1)-j));
                }
        }
    else
        {
        for(int j=0;j<len;j++)
                {
                tnum=str[j]-'0';
                num=num + tnum*(pow(10,(len-1)-j));
                }
        int k=0;
        for(int j=pos+1;str[j]!='\0';j++)
            {
            k++;
            dnum=str[j]-'0';
            num2=num2+ dnum*(pow(10,-k));
            }
        }
fsum=num+num2;
return fsum;
    }
    
    
void complex_prog(int opt,char *arr)
{
char c1[20],c2[20];
int i=0,j=0;
char a1s[5],b1s[5],a2s[5],b2s[5];
while(arr[i]!=',')
    {
    c1[i]=arr[i];
    i++;
    }
c1[i]='\0';
i++;
while(arr[i]!='\0')
    {
    c2[j]=arr[i];
    i++;
    j++;
    }
c2[j]='\0';    
printf("\nthe comp nums are %s and %s",c1,c2);
i=0;
j=0;
while(c1[i]!='+')
    {
    a1s[i]=c1[i];
    i++;
    }
a1s[i]='\0';
i=0;
while(c2[i]!='+')
    {
    a2s[i]=c2[i];
    i++;
    }    
a2s[i]='\0';
int i1,i2;
for(i1=0;c1[i1]!='+';i1++);
for(i2=0;c2[i2]!='+';i2++);
i1++;
i2++;
i=0;
while(c1[i1]!='j')
    {
    b1s[i]=c1[i1];
    i++;
    i1++;
    }
b1s[i]='\0';
i=0;
while(c2[i2]!='j')
    {
    b2s[i]=c2[i2];
    i++;
    i2++;
    } 
b2s[i]='\0';
i=0;
float a1,a2,b1,b2;
a1=extractor(a1s);
a2=extractor(a2s);
b1=extractor(b1s);
b2=extractor(b2s);
printf("\nthe nums are %f + %f and %f + %f",a1,b1,a2,b2);
switch(opt)
    {
    case 1:printf("\nthe sum is (%f) + (%f)i",a1+a2,b1+b2);
            break;
    case 2:printf("\nthe difference is (%f) + (%f)i",a1-a2,b1-b2);
            break;
    case 3:printf("\nthe sum is (%f) + (%f)i",(a1*a2)-(b1*b2),(a1*b2 + b1*a2));
            break;
    case 4:printf("\nthe quotiont is\n:");
            printf("\n\t(%f)+(%f)i",(a1*a2 + b1*b2),(b1*a2 - a1*b2));
            printf("\n\t_______________________");
            printf("\n\t\t(%f)",a2*a2 + b2*b2);
            break;
    default:break;
    }

}

int main()
{
char arr[40];
int opt;
printf("\nenter the numbers(using a+ij format and seperated by ,)");
fgets(arr,40,stdin);
printf("\n1-add\n2-subtract\n3-multiply\n4=divide:");
scanf("\n%d",&opt);
complex_prog(opt,arr);
return 0;
}