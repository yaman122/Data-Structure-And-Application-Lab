#include<stdio.h>
#include<stdlib.h>

void main()
{
int a[50]={1,2,3,4,5} ;
int n ; int k;

printf("enter the element to be searched: ");
scanf("%d",&n);

int i;
for (i = 0; i<sizeof(a); i++){
if (a[i] == n)
{
printf("a[ %d ]=%d",i,n);
}
}
}