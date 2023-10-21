#include<stdio.h>
#include <stdlib.h>

int main()
{
  
   FILE *fp;

   fp = fopen("text.txt","w");

   if(fp == NULL)
   {
      printf("error");   
      exit(1);              }

printf("Enter the number: ");
int num;
scanf("%d",&num);

fprintf(fp,"%d",num);
fclose(fp);
 



FILE *fl;

fl = fopen("text.txt","r");

if(fl == NULL)
{
printf("error");   
exit(1); }

fscanf(fl,"%d", &num);

printf("%d", num);
fclose(fl); 


return 0;}

