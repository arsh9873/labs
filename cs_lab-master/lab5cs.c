#include <stdlib.h>
#include <stdio.h>
int main()
{
int n,m;
printf("\nInput the number of rows : ");
scanf("%d",&m);
printf("\nInput the number of columns : ");
scanf("%d",&n);
int arr[m][n];
int i,j;
printf("\nInput the matrix \n");
for(i = 0; i < m; i++)
{
for(j = 0; j < n; j++)
{
scanf("%d",&arr[i][j]);
}
}
printf("\nThe Matrix is \n");
for(i = 0; i < m; i++)
{
for(j = 0; j < n; j++)
{
printf("%d ",arr[i][j]);
}
printf("\n");
}
printf("\nSpiral Matrix : ");
int srow = 0, scol = 0;
while(srow < m && scol < n)
{
for(i = scol; i < n; i++)
{
printf("%d ",arr[srow][i]);
}
srow++;
for(i = srow; i < m; i++)
{
printf("%d ",arr[i][n-1]);
}
n--;
if(srow < m)
{
for(i = n - 1; i >= 0; --i)
{
printf("%d ",arr[m-1][i]);
}
m--;
}
if(scol < n)
{
for(i = m - 1; i >= srow; i--)
{
printf("%d ",arr[i][scol]);
}
scol++;
}
}
return 0;
}

