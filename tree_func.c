#include <stdio.h>
#include <stdlib.h>

typedef int Data;

// typedef struct Node Node;
typedef struct Node {
    Data data;      // данные в узле
    struct Node* left;    // указатель на левого ребенка
    struct Node* right;   // указатель на правого ребенка
} Node;

typedef struct Node_list {
    Data data;      // данные в узле
    struct Node_list * prev;    // указатель на предыдущий узел
    struct Node_list * next;    // указатель на следующий узел
} Node_list;


//void tree_print(Node * tree);


//void tree_left(Node* tree, size_t* num_left);

Node* print_last_left_fork(Node* tree); 
void sub_tree_print(Node* tree);
void tree_print(Node* tree);
void tree_print_recurant(Node* tree, Node_list* list_tree);


void list_init(Node_list * list);
Node_list * list_push_front(Node_list * list, Data d);
Node_list * list_push_back(Node_list * list, Data d);
void list_print (Node_list * list);
void list_clear(Node_list * list);



int main()
{
    printf("HUI\n");
    Node ptree  = {0, NULL, NULL};
    Node* tree = &ptree; // сначала дерево пустое 
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
    (&three)->right = &eight;
    (&three)->left  = &two;
    (&two)->left    = &one;
    (&eight)->left  = &five;
    (&five)->right  = &seven;
    (&seven)->left  = &six;
    (&five)->left   = &four;

    tree_print(tree);

    

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
/*
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

*/

/*void tree_print(Node* tree)
{
    Node* tree_search = tree;
    while(tree_search->left != NULL)
    {
        tree_print(tree_search->left);
    }
    printf("%d ", tree_search->data);



    if(tree_search->left != NULL)
    {
        ptintf("%d ", (tree_search->left)->data);
    }
    printf("%d ", tree_search->data);
    if(tree_search->right != NULL)
    {
        ptintf("%d ", (tree_search->right)->data);
    }
}*/

void tree_print(Node* tree)
{
    Node_list list_tree_prototype;
    Node_list* list_tree = &list_tree_prototype;
    list_init(list_tree);
    list_push_front(list_tree, tree->data);
    tree_print_recurant(tree, list_tree);
    list_print(list_tree);
    list_clear(list_tree);
}

void tree_print_recurant(Node* tree, Node_list* list_tree)
{
    if(tree->left != NULL)
    {
        list_push_front(list_tree, (tree->left)->data);
        tree_print_recurant(tree->left, list_tree);
    }
    if(tree->right != NULL)
    {
        list_push_back(list_tree, (tree->right)->data);
        tree_print_recurant(tree->right, list_tree);
    }
}


void list_init(Node_list * list)
{
    list->next = list;
    list->prev = list;
}

Node_list * list_push_back(Node_list * list, Data d)
{
    Node_list* new_node = malloc(sizeof(Node_list));
    Node_list* blist = list->prev;
    new_node->prev = blist;
    new_node->next = list;
    new_node->data = d;
    blist->next = new_node;
    list->prev = new_node;
    return new_node;
}

Node_list * list_push_front(Node_list * list, Data d)
{
    Node_list* new_node = malloc(sizeof(Node_list));
    Node_list* nlist = list->next;
    new_node->prev = list;
    new_node->next = nlist;
    new_node->data = d;
    nlist->prev = new_node;
    list->next = new_node;
    return new_node;
}

void list_clear(Node_list * list)
{
    Node_list* spec_list = list->next;
    Node_list* while_list = list->next;
    while (while_list != list)
    {
        while_list = while_list->next;
        free(spec_list);
        spec_list = while_list;
    }
}

void list_print (Node_list* list)
{
   if (list != NULL)
    {
        Node_list* nlist = list->next;
        while (nlist != list)
        {
            printf("%d ", nlist->data);
            nlist = nlist->next;
        }
    }
    printf("\n");
}






























