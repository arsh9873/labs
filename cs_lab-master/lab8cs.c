#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int monthdays[12]
    = { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };

int leapyearcount(int y,int m)
    {   
        if(m<=2)
            {
            y--;
            }
        return y/4 - y/100 + y/400;
    }

void date_calc(char *date)
{
int i=0,j=0,intdate1[15],intdate2[15];
char date1[15],date2[15];
while(i<strlen(date))
        {
        if(i<10) // dd/mm/yyyy,dd/mm/yyyy
                {
                date1[i]=date[i];                        
                }
        else if(i>10)
                {
                date2[j]=date[i];    
                j++;
                }
        else if(i==10)
                {
                date1[i]='\0';
                }
        i++;
        }
    date2[j]='\0';
printf("\n dates individually are:%s %s",date1,date2);
int k=0,z=0;
while(date1[k]!='\0') //typecasting
{   
    if(date1[k]!='/')
        {
        intdate1[z]= date1[k] - '0';
        z++;
        }   
        k++; 
}
k=0;
z=0;
while(date2[k]!='\0')
{   
    if(date2[k]!='/')
        {
        intdate2[z]=date2[k] - '0';
        z++;
        }   
        k++; 
}

int year1=0,year2=0,month1=0,month2=0,day1=0,day2=0,multi=1000;
for(int i=4;i<8;i++)
    {
    year1=year1+(intdate1[i]*multi);
    year2=year2+(intdate2[i]*multi);
    multi = multi/10;
    }
multi=10;
for(int i=2;i<4;i++)
    {
    month1=month1+(intdate1[i]*multi);
    month2=month2+(intdate2[i]*multi);
    multi=multi/10;
    }
multi=10;
for(int i=0;i<3;i++)
    {
    day1=day1+(intdate1[i]*multi);
    day2=day2+(intdate2[i]*multi);
    multi=multi/10;
    }    

int n1,n2;
n1=year1*365+day1;
for(int i=0;i<month1;i++)
    {
        n1=n1+ monthdays[i];
    }
n1 = n1 + leapyearcount(year1,month1);
n2=year2*365 + day1;
for(int i=0;i<month2;i++)
    {
    n2=n2+monthdays[i];
    }
n2 = n2 + leapyearcount(year2,month2); 
printf("\n finals days are %d",abs(n2-n1));
}
int main()
{
char date[25];
printf("\nenter 2 dates in the format dd/mm/yyyy,dd/mm/yyyy:");
fgets(date,25,stdin);
date_calc(date);
return 0;
}
