#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct Node Node;
struct Node {
    Data data;      // данные в узле
    Node * left;    // указатель на левого ребенка
    Node * right;   // указатель на правого ребенка
};


//void tree_print(Node * tree);


//void tree_left(Node* tree, size_t* num_left);

Node* print_last_left_fork(Node* tree); 
void sub_tree_print(Node* tree);


int main()
{
    Node* tree = NULL; // сначала дерево пустое 
    Node one   = {1, NULL, NULL}; 
    Node two   = {2, NULL, NULL};
    Node three = {3, NULL, NULL};
    Node four  = {4, NULL, NULL};
    Node five  = {5, NULL, NULL};
    Node six   = {6, NULL, NULL};
    Node seven = {7, NULL, NULL};
    Node eight = {8, NULL, NULL};
    Node nine  = {9, NULL, NULL};

    tree            = &nine;
    tree->left      = &three;
    (&three)->right = &seven;
    (&three)->left  = &two;
    (&two)->left    = &one;
    (&seven)->right = &eight;
    (&seven)->left  = &five;
    (&five)->right  = &six;
    (&five)->left   = &four;

    sub_tree_print(tree);

}

/*
void tree_print(Node * tree) 
{
    size_t num_left  = 0;
    size_t num_right = 0;
     
    Node* sub_tree_head = tree_left(tree, &num_left);            //search Node with minimum number and return the head of subtree(latest branching)

    int numbers[10];
    while 

    tree_print = tree;
    while (tree_print->right == NULL)
    {
        for (size_t i = 0; i < num_left; i++)
        {
            tree_print = tree_print->left;
        }
        printf("%d ", tree_print->data);
    }


}

Node* tree_left(Node* tree, size_t* num_left)                   //search Node with minimum number and return the head of subtree(latest branching)
{
    Node* tree_search   = tree;
    Node* sub_tree_head = tree;

    while (tree_search->left != NULL)
    {
        if (tree_search->right != NULL)
        {
            sub_tree_head = tree_search;
        }
        tree_search = tree_search->left;
        num_left++;
    }

    return sub_tree_head;
}

Node* tree_right(Node* tree, size_t* num_right)
{
    Node* tree_search = tree;

    while (tree_search->left == NULL)
    {
        tree_search = tree_search->right;
        num_right++;
    }

    return tree_search;
}

void sub_tree_print(Node* sub_tree_head)
{
    Node* sub_sub_tree_head = tree_left(tree, &num_left);
    sub_tree_print(sub_sub_tree_head);

    Node* sub_tree_counter = sub_tree_head;
    size_t counter = 0;
    while (sub_tree_counter->left != )
    {
        sub_tree_counter = sub_tree_counter->left;
        counter++;
    }
    sub_sub_tree
}*/

Node* print_last_left_fork(Node* tree)                   //search last left fork, print this and return the head of subtree(latest branching)
{
    Node* tree_search   = tree;
    Node* sub_tree_head = tree;

    size_t counter = 0;



    while(tree_search->left != NULL)
    {
        tree_search = tree_search->left;
        counter++;
        if (tree_search->right != NULL)
        {
            sub_tree_head = tree_search;
            counter = 0;
        }
    }

    Data* numbers = calloc(counter, sizeof(Data));

    tree_search = sub_tree_head;
    for(size_t i = 0; tree_search->left != NULL; i++)
    {
        tree_search = tree_search->left;
        *(numbers + i) = tree_search->data;
    }

    for (int i = counter - 1; i >= 0; i--)
    {
        printf("%d ", *(numbers + i));
    }



    free(numbers);

    return sub_tree_head;
}

void sub_tree_print(Node* tree)                         //print only one subtree with min value
{
    Node* tree_search = tree;
    while(tree_search->left != NULL || tree_search->right != NULL)
    {
        tree_search = print_last_left_fork(tree_search);

        printf("%d ", tree_search->data);

        tree_search = tree_search->right;
        while(tree_search->left == NULL && tree_search->right != NULL)
        {
            printf("%d ", tree_search->data);
            tree_search = tree_search->right;
        }
    }
        printf("%d ", tree_search->data);
}



































