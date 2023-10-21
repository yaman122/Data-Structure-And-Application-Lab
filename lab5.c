#include <stdio.h>
#include <stdlib.h>

int check = 0;
int found = 0;
// struct for node
struct node
{
    char* value; // all void types replaced by char*
    struct node *p_left;
    struct node *p_right;
};

int my_strlen(const char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

void my_strcpy(char *str1, char *str2) // str2 is source, str1 is dest
{
    int i = 0;
    while (str2[i] != '\0')
    {
        str1[i] = str2[i];
        i++;
    }
    str1[i]='\0';
}

int my_strcmp(const char *a, const char *b)
{
    int i = 0;
    if (my_strlen(a) > my_strlen(b))
    {
        int i = 0;
        while (b[i] != '\0')
        {
            if (a[i] > b[i])
            {
                return 1;
            }
            else if (a[i] < b[i])
            {
                return -1;
            }
            i++;
        }
        return 1;
    }
    else if (my_strlen(a) < my_strlen(b))
    {
        int i = 0;
        while (a[i] != '\0')
        {
            if (a[i] > b[i])
            {
                return 1;
            }
            else if (a[i] < b[i])
            {
                return -1;
            }
            i++;
        }
        return -1;
    }
    else
    {
        int i = 0;
        while (b[i] != '\0')
        {
            if (a[i] > b[i])
            {
                return 1;
            }
            else if (a[i] < b[i])
            {
                return -1;
            }
            i++;
        }
        return 0;
    }
}
// inserts elements into the tree
void insert(char *key, struct node **leaf)
{
    struct node *root = *leaf;
    struct node *newnode, *cur, *pre;
    newnode = malloc(sizeof(struct node));
    newnode->value = malloc(my_strlen(key)+1);
    my_strcpy(newnode->value, key);
    newnode->p_left = newnode->p_right = NULL;

    if (root == NULL)
    {
        *leaf=newnode;
    }
    else
    {
        pre = NULL;
        cur = root;
        while (cur != NULL)
        {
            pre = cur;
            if (my_strcmp(key, cur->value) > 0)
            {
                cur = cur->p_right;
            }
            else if (my_strcmp(key, cur->value) < 0)
            {
                cur = cur->p_left;
            }
            else
            {
            	check=-1;
            	return;
            }
        }
        if (my_strcmp(key, pre->value) > 0)
        {
            pre->p_right = newnode;
        }
        else // duplicates in p_left
        {
            pre->p_left = newnode;
        }
        return;
    }
}

// recursive function to print out the tree inorder
void asc_order(struct node *root)
{
    if (root != NULL)
    {
        // step 1: p_left subtree
        asc_order(root->p_left);
        // step2: Root
        printf("%s\n", root->value);
        // step3: p_right subtree
        asc_order(root->p_right);
    }
}

// searches elements in the tree
void search(char* key, struct node *leaf) // no need for *
{
    if (leaf == NULL)
    {
        return;
    }
    else if (my_strcmp(leaf->value, key) == 0)
    {
        found = 1;
    }
    else if (my_strcmp(key, leaf->value) > 0)
        search(key, leaf->p_right);
    else
        search(key, leaf->p_left);
}

int main()
{
    struct node *p_root = NULL;
    char *value;
    size_t malloc_size = 100;
    int size;
    int temp = 100;
    scanf("%d", &size);
    int i;
    // reading the input and inserting in the tree
    char *srn[size];
    for (i = 0; i < size; i++)
    {
        srn[i] = malloc(malloc_size * sizeof(char)); /* allocates 100 bytes */
        scanf("%99s", srn[i]);
        insert(srn[i], &p_root);
    }
    char searchname[temp];
    scanf("%s", searchname);

    // checking inorder print
    asc_order(p_root);

    // checking for 1 or more duplicate insertions
    printf("%d\n", check);

    // searching a string in the tree
    search(searchname, p_root);
    printf("%d\n", found);
    return 0;
}