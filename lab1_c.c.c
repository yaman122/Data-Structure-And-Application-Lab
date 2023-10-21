#include <stdio.h>
#include<stdlib.h>
void main()
{ 
    char word[100];

    FILE *fp;
    fp = fopen("string.txt", "w");

    if (fp == NULL) {
    printf("error");
    exit(1);
}
printf("Enter: ");
fgets(word, sizeof(word), stdin);
fprintf(fp, "%s", word);
fclose(fp);




FILE *fl;

fl = fopen("string.txt","r");

if(fl == NULL)
{
printf("error");   
exit(1); }

fscanf(fl,"%s", &word);

printf("%s", word);
fclose(fl);

}

