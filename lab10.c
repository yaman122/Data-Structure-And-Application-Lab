#include <stdio.h>
#include<stdlib.h>
#define SIZE 13

void insertIntoHash(int key, int *hashtable)
{
    int p=11;
    int s1=0;
    int co=0;
    for(int s = 0;s<SIZE;s++){
        if(hashtable[s] != 0)
            co++;
    }
    if(co == SIZE){
        printf("-1\n");
        return;
    }
        if (s1==SIZE)
            printf("%d",-1);

        
        int in =key%SIZE;

        
        if (hashtable[in] != 0)
        {
        
            int in2 = (p-(key%p));
            int i = 1;
            while (1==1)
            {
                
                int newIn = (in + i * in2) % SIZE;

                
                if (hashtable[newIn] == 0)
                {
                    hashtable[newIn] = key;
                    break;
                }
                i++;
            }
        }

        
        else
            hashtable[in] = key;
        s1++;
}


void printHashTable(int *hashtable)
{
   for(int i=0;i<SIZE;i++){
       printf("%d ",hashtable[i]);
   }
}

int main()
{
    int i;
    int h[SIZE]={0};

    int n;
    scanf("%d", &n);

    int stk[n];
    for(int k=0;k<n;k++){
        scanf("%d", &stk[k]);
    }

    for(int i=0;i<n;i++){
        insertIntoHash(stk[i], h);
    }

    printHashTable(h);

    return 0;
}