#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

struct node* head;

void display(node* head);
void display_reverse(node* head);
void insert_at_start(int val);
void insert_at_end(int val);
void delete_at_start();
void delete_at_end();

int main(){
    node* a = (node *)malloc(sizeof(node));
    node* b = (node *)malloc(sizeof(node));
    node* c = (node *)malloc(sizeof(node));
    node* d = (node *)malloc(sizeof(node));
    head = a;
    a->data = 10;
    a->next = b;
    a->prev = NULL;


    b->data = 20;
    b->next = c;
    b->prev = a;

    c->data = 30;
    c->next = d;
    c->prev = b;

    d->data = 40;
    d->next = NULL;
    d->prev = c;
    
    display(head);
    insert_at_start(45);
    insert_at_end(4);
    display(head);
    display_reverse(head);
    delete_at_start();
    display(head);
    delete_at_end();
    display(head);
    display_reverse(head);
    return 0;
}

void display(node* head){
    node* temp = head;
    printf("START");
    while(temp != NULL){
        printf("-%d-", temp->data);
        temp = temp->next;
    }
    printf("END\n");
}
void display_reverse(node* head){
    node* temp = head;
    printf("END");
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        printf("-%d-", temp->data);
        temp = temp->prev;
    }
    printf("START");
}

void insert_at_start(int val){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = head;
    head->prev = newnode;
    newnode->prev = NULL;
    head = newnode;
}

void insert_at_end(int val){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = NULL;
}

void delete_at_start(){
    node* temp = (node*)malloc(sizeof(node));
    temp = head;
    head = temp->next;
    head->prev = NULL;
    temp->next = NULL;
    free(temp);
}

void delete_at_end(){
    node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next->prev = NULL;
    temp->next = NULL;
    free(temp->next);
}