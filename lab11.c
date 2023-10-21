#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE (255)
#define ALPHABET_SIZE (26)

struct TrieNode
{

    struct TrieNode *children[ALPHABET_SIZE]; // pointer Array
    bool isEndOfWord;                         // denotes end of the word
};

struct TrieNode *getNode()
{
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));

    if (pNode)
    {
        pNode->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}
int my_strlen(char *string)
{
    int k=0;
    while(string[k]!=0){
        k++;
    }
    return k;
}
void insert(struct TrieNode *root, char *key)
{
    struct TrieNode *a=root;
    int j=0,ind;
while(key[j]!=0){
        ind = key[j]-'a';
        if(a->children[ind]==NULL)
        a->children[ind] = getNode();
        a = a->children[ind];
        j++;
    }
    a->isEndOfWord = true;
}


// Recursive Function to Print in Lexicographic order using DFS
void dfs_word(struct TrieNode *root, char *word, int *plent)
{
    int i,j;
    for(i=0;i<ALPHABET_SIZE;i++){
        if(root->children[i]!=NULL){
            word[(*plent)++] = i;
            if(root->children[i]->isEndOfWord==true){
                for(j=0;j<(*plent);j++)
                 printf("%c",(word[j]+'a'));
                printf("\n");
            }
            dfs_word(root->children[i],word,plent);
        }
    }
    (*plent)--;
    return;
}


// Function to Display
void display(struct TrieNode *root)
{

    char word[MAXSIZE] = "";
    int length = 0;
    dfs_word(root, word, &length);
}


int main()
{
    int number_of_ele, i;

    // Number of input elements
    scanf("%d", &number_of_ele);

    // initialising root node
    struct TrieNode *root = getNode();
    char input[MAXSIZE][MAXSIZE];

    
    for (i = 0; i < number_of_ele; i++)
    {
        scanf("%s\n", input[i]);
    }

    // Inserting Into the Trie
    for (int i = 0; i < number_of_ele; i++)
    {

        insert(root, input[i]);
    }

    display(root);
    return 0;
}