#include <stdio.h>

int main()
{
 int m[10][5],n,hs[10],mavgs,hsm[10],flag=-1;
float avg[10],mavg;        
printf("\nenter the number of students");
scanf("%d",&n);
 printf("\nenter the details of the student in the following order:");
 printf("\n1-roll num\t2-age\t-3-subject1\t-4-subject2\t-5-subject3");
for(int i=0;i<n;i++)
{
        for(int j=0;j<5;j++)
                {
                scanf("%d",&m[i][j]);        
                }
}

for(int i=0;i<n;i++)//average calculation
{
        for(int j=2;j<5;j++)//subject marks start from index j=2
                {
                avg[i]=avg[i]+m[i][j];        
                }
                avg[i] = avg[i]/3;
                
}
hs[0]=0;
hs[1]=0;
hs[2]=0;//initializing highest mark array to 0 for each subject
for(int i=0;i<n;i++)
{
        if(m[i][2]>hs[0])//comparison of highest marks for each subject with main array
                {
                hs[0]=m[i][2];//highest marks get assigned to hs array
                hsm[0]=i;//index number of highest mark scores gets assigned to hsm array
                }
        if(m[i][3]>hs[1])
                {
                hs[1]=m[i][3];        
                hsm[1]=i;
                }
        if(m[i][4]>hs[2])
                {
                hs[2]=m[i][4];        
                hsm[2]=i;
                }
}

printf("\nthe details are as follows:");
printf("\nrno\tage\tsub1\tsub2\tsub3");
for(int i=0;i<n;i++)
{       printf("\n");
        for(int j=0;j<5;j++)
                {
                printf("%d\t",m[i][j]);        
                }
}
printf("\n");

mavg=0;
for(int i=0;i<n;i++)//highest percentage comparison using the avg array
{
printf("\nthe percentage scored by roll number %d is %f",m[i][0],avg[i]);
 if(avg[i]>mavg)
        {
        mavg=avg[i];        
        mavgs=i;
        }
else if(avg[i]==mavg)
        {
        flag=i;//flag gets the value of i when it detects any 2 percentages as same        
        continue;
        }
}

if(flag!=(-1) && (mavg==avg[flag]))//checks if any 2 percentages were same AND if they were equal to the max percentage
        {
                if(m[flag][1]<m[(flag-1)][1])
                        {
        printf("\nthe highest percentage is %f which has been scored by roll number %d",mavg,m[flag][0]);
                        }
                else if(m[flag][1]>m[(flag-1)][1])
                {
        printf("\nthe highest percentage is %f which has been scored by roll number %d",mavg,m[flag-1][0]);
                        }
                else//both candidates have same age
                {
        printf("\nthere are 2 students with highest percent %f whose rolls are %d and %d",mavg,m[flag][0],m[flag-1][0]);
                        }
        }
else{        
printf("\nthe highest percentage is %f which has been scored by roll number %d",mavg,m[mavgs][0]);
}

for(int i=0;i<3;i++)//displays the highest marks for each subject using the hsm array and his roll number using hsm array
{
printf("\nthe highest marks in subject%d are:%d and are scored by roll number %d",(i+1),hs[i],m[(hsm[i])][0]);        
}

return 0;
}
