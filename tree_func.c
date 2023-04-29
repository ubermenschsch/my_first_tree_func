#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct Node Node;
struct Node {
    Data data;      // данные в узле
    Node * left;    // указатель на левого ребенка
    Node * right;   // указатель на правого ребенка
};


void tree_print(Node * tree);


void tree_left(Node* tree, size_t* num_left);


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
}


void tree_print(Node * tree) 
{
    size_t num_left  = 0;
    size_t num_right = 0;
     
    Node* sub_tree_head = tree_left(tree, &num_left);             //search tree with minimum number and return the head of subtree(latest branching)

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

Node* tree_left(Node* tree, size_t* num_left)
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
