#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 20


typedef struct {
    int stack1[SIZE];    // stack used for enqueue
    int stack2[SIZE];    
    int top1;               
    int top2;               
} MyQueue;




void enqueue(MyQueue *q, int x) {
    q->stack1[++q->top1]=x;
}



int dequeue(MyQueue *q) {
    int a;
    if(q->top1==-1)
     return -1;
    else
    {
    while(q->top1!=0)
    {
        q->stack2[++q->top2]=q->stack1[q->top1--];
    }
    a=q->stack1[q->top1--];
    while(q->top2!=-1)
    {
        q->stack1[++q->top1]=q->stack2[q->top2--];
    }
    return a;
    }
}



int peek(MyQueue *q) {
    if(q->top1==-1)
        return -1;
    return q->stack1[0];
}



bool empty(MyQueue *q) {
    return q->top1==-1;
    
}


int validate(MyQueue *q, int pops){
    if(q->top2 != -1 || q->top1 < pops){
        return -1;
    }

    int x = pops, a = -1;
    while(x > 0 && q->top1 != -1){
        q->stack2[++q->top2] = q->stack1[q->top1--];
        x--;
    }

    if(q->top1 != -1){
        a = q->stack1[q->top1];
    }

    x = pops;
    while(x > 0 && q->top2 != -1){
        q->stack1[++q->top1] = q->stack2[q->top2--];
        x--;
    }

    return a;
}


int main(){
    MyQueue q;
    q.top1 = -1;
    q.top2 = -1;

    int no_of_operations;
    scanf("%d", &no_of_operations);

    int a, correct_a, no_of_pops;
    char operation;

    for(int i = 0; i < no_of_operations; i++){
        scanf(" %c", &operation);
        switch (operation)
        {   
            case 'E':
                scanf("%d", &a);
                enqueue(&q, a);
                printf("1 ");
                break;
            
            case 'D':
                a = dequeue(&q);
                printf("%d ", a);
                break;
            
            case 'P':
                a = peek(&q);
                printf("%d ", a);
                break;

            case 'V':
                scanf("%d", &no_of_pops);
                printf("%d ", validate(&q, no_of_pops));
                break;
        }
    }
}