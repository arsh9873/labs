#include <stdio.h>
#include <stdlib.h>



void add(int m1[10][10],int m2[10][10],int ans[10][10],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
    for(j=0;j<col;j++)
    {ans[i][j] =  (m1[i][j] + m2[i][j]);
    }
    }
sum(ans[10][10],row,col);
}

void sub(int m1[10][10],int m2[10][10],int ans[10][10],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
    for(j=0;j<col;j++)
    {
    ans[i][j] =  (m1[i][j] - m2[i][j]);
    }
    }
sum(ans[10][10],row,col);
}

void mult(int m1[10][10],int m2[10][10],int ans[10][10],int row,int col)
{
    int i,j,k;
    for(i=0;i<row;i++)
    {
    for(j=0;j<col;j++)
    {
    ans[i][j]=0;
    for(k=0;k<col;k++)
    {ans[i][j] += m1[i][k]*m2[k][j] ;
    }
    }
    }
sum(ans[10][10],row,col);
}

void sum(int ans[10][10],int row,int col)
{
   for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            ans[i][j]=0;
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
         printf("%d",ans[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    int m1[10][10],m2[10][10],ans[10][10];
    int row,col,ch;
    printf("\nenter values for rows and collums");
    scanf("%d%d",&row,&col);
    printf("enter values for matrix m1");
    for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
            scanf("%d",&m1[i][j]);
            }
        }
    printf("enter values for matrix m2");
    for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                scanf("%d",&m2[i][j]);
            }
        }

    printf("\n choose 1 option.\n 1-add.\n 2-subtract.\n 3-multiply");
    scanf("%d",&ch);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            ans[i][j]=0;
        }
    }
    switch (ch)
    {
        case 1:add(m1,m2,ans,row,col);
                printf("test");
                break;
        case 2:sub(m1,m2,ans,row,col);
                break;
        case 3:mult(m1,m2,ans,row,col);
                break;
        default:printf("\n enter a correct choice ");
                break;
    }
    return 0;
}

