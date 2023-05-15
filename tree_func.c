#include <stdio.h>
#include <stdlib.h>

typedef int Data;

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



void tree_print(Node* tree);
void tree_count_recurant(Node* tree, size_t* counter);
void tree_make_list_recurant(Node* tree, Node_list* list_tree, Node_list** list_new_node);

Node* tree_add(Node* tree, Data d);

void tree_destroy(struct Node * tree);

int tree_height(Node* tree);

int tree_is_balanced(Node* tree);

void tree_print_nodes_on_height(Node* tree, int height);
void tree_make_list_nodes_on_height_recurant(Node* tree, Node_list** list_new_node, int height, int required_height);


void list_init(Node_list * list);
void list_print (Node_list * list);
void list_insert_front(Node_list * list, Node_list * t);
void list_insert_back(Node_list * list, Node_list * t);



// int main()
// {
//     Node ptree  = {0, NULL, NULL};
//     Node* tree = &ptree; // сначала дерево пустое 
//     Node one   = {1, NULL, NULL}; 
//     Node two   = {2, NULL, NULL};
//     Node three = {3, NULL, NULL};
//     Node four  = {4, NULL, NULL};
//     Node five  = {5, NULL, NULL};
//     Node six   = {6, NULL, NULL};
//     Node seven = {7, NULL, NULL};
//     Node eight = {8, NULL, NULL};
//     Node nine  = {9, NULL, NULL};

//     tree            = &seven;
//     (&seven)->right = &eight;
//     (&eight)->right = &nine;
//     (&seven)->left  = &two;
//     (&two)->left    = &one;
//     (&two)->right   = &six;
//     (&six)->left    = &four;
//     (&four)->left   = &three;
//     (&four)->right  = &five;

//     tree_print(tree);

    

// }

// int main()
// {
//     Node * tree = NULL;         // указатель на корень
//     tree = tree_add(tree, 7);   // указатель на корень изменился
//     tree = tree_add(tree, 9);
//     tree = tree_add(tree, 0);
//     tree = tree_add(tree, 2);
//     tree = tree_add(tree, 5);
//     tree_print(tree);                // 7
//     tree_destroy(tree);
//     return 0;
// }

int main()
{
    Node* tree = NULL;
    
    int number = 0;
    scanf("%d", &number);
    while (number != 0)
    {
        tree = tree_add(tree, number);
        scanf("%d", &number);
        tree_print(tree);
    }
    if (tree != NULL)
    {
        tree_print(tree);
        tree_destroy(tree);
    }
}







void tree_print_nodes_on_height(Node* tree, int required_height)
{
    size_t counter = 1;                                                            //because tree_count_recurant didn't count head of tree
    tree_count_recurant(tree, &counter);
   
    Node_list* list_tree = (Node_list*) calloc((counter + 1), sizeof(Node_list));
    list_init(list_tree);

    Node_list* list_new_node = list_tree + 1;
    list_new_node->data = tree->data;
    if (required_height == 0)
    {
        list_insert_front(list_tree, list_new_node);
        list_new_node = list_new_node + 1;
    }
    int height = 0;
    tree_make_list_nodes_on_height_recurant(tree, &list_new_node, height, required_height);

    list_print(list_tree);
    free(list_tree);
}

void tree_make_list_nodes_on_height_recurant(Node* tree, Node_list** list_new_node, int height, int required_height)
{
    if(tree->left != NULL)
    {
        int left_height = height + 1;
        (*list_new_node)->data = (tree->left)->data;
        if (left_height == required_height)
        {
            list_insert_front((*list_new_node) - 1, *list_new_node);
            *list_new_node = (*list_new_node) + 1;
        }
        tree_make_list_nodes_on_height_recurant(tree->left, list_new_node, left_height, required_height);
    }
    if(tree->right != NULL)
    {
        int right_height = height + 1;
        (*list_new_node)->data = (tree->right)->data;
        if (right_height == required_height)
        {
            list_insert_front((*list_new_node) - 1, *list_new_node);
            *list_new_node = (*list_new_node) + 1;
        }
        tree_make_list_nodes_on_height_recurant(tree->right, list_new_node, right_height, required_height);
    }
}


int tree_is_balanced(Node* tree)
{
    int left_height = 1;
    int right_height = 1;

    if (tree->left != NULL)
    {
        left_height = tree_height(tree->left); 
        left_height++;
    }
     if (tree->right != NULL)
    {
        right_height = tree_height(tree->right); 
        right_height++;
    }

    if (((left_height - right_height) > 1) || ((right_height - left_height) > 1))
    {
        return 0;
    }


    int is_balanced_left  = 1;
    int is_balanced_right = 1;

    if (tree->left != NULL)
    {
        is_balanced_left = tree_is_balanced(tree->left);
    }
    if (tree->right != NULL)
    {
        is_balanced_right = tree_is_balanced(tree->right);
    }

    if (is_balanced_left > is_balanced_right)
    {
        return is_balanced_left;
    }
    else
    {
        return is_balanced_right;
    }
}


int tree_height(Node* tree)
{
    int height = 1;
    int left_height = 1;
    int right_height = 1;

    if (tree->left != NULL)
    {
        left_height = tree_height(tree->left); 
        left_height++;
    }
     if (tree->right != NULL)
    {
        right_height = tree_height(tree->right); 
        right_height++;
    }

    if (tree == NULL)
    {
        height = 0;
    }
    else if (left_height > right_height)
    {
        height = left_height;
    }
    else if (right_height >= left_height)
    {
        height = right_height;
    }

    return height;
}


void tree_destroy(struct Node * tree)
{
    if(tree->left != NULL)
    {
        tree_destroy(tree->left);
    }
    if(tree->right != NULL)
    {
        tree_destroy(tree->right);
    }
    free(tree);
}


Node* tree_add(Node* tree, Data d) 
{
    if (tree == NULL)
    {
        tree = (Node*) calloc(1, sizeof(Node));
        tree->data = d;
    }
    else
    {
        if (d < tree->data)
        {
            if (tree->left != NULL)
            {
                tree_add(tree->left, d);
            }
            else
            {
                Node* new_node = (Node*) calloc(1, sizeof(Node));
                new_node->data = d;
                tree->left = new_node;
            }
        }
        if (d > tree->data)
        {
            if (tree->right != NULL)
            {
                tree_add(tree->right, d);
            }
            else
            {
                Node* new_node = (Node*) calloc(1, sizeof(Node));
                new_node->data = d;
                tree->right = new_node;
            }
        }
    }
    return tree;
}


void tree_print(Node* tree)
{

    size_t counter = 1;                                                            //because tree_count_recurant didn't count head of tree
    tree_count_recurant(tree, &counter);
   
    Node_list* list_tree = (Node_list*) calloc((counter + 1), sizeof(Node_list));
    list_init(list_tree);

    Node_list* list_new_node = list_tree + 1;
    list_new_node->data = tree->data;
    list_insert_front(list_tree, list_new_node);
    list_new_node = list_new_node + 1;

    tree_make_list_recurant(tree, (list_new_node - 1), &list_new_node);

    list_print(list_tree);
    free(list_tree);
}

void tree_count_recurant(Node* tree, size_t* counter)
{
    if(tree->left != NULL)
    {
        (*counter)++;
        tree_count_recurant(tree->left, counter);
    }
    if(tree->right != NULL)
    {
        (*counter)++;
        tree_count_recurant(tree->right, counter);
    }
}

void tree_make_list_recurant(Node* tree, Node_list* list_tree, Node_list** list_new_node)
{
    if(tree->left != NULL)
    {
        (*list_new_node)->data = (tree->left)->data;
        list_insert_front(list_tree, *list_new_node);
        *list_new_node = (*list_new_node) + 1;
        tree_make_list_recurant(tree->left, (*list_new_node) - 1, list_new_node);
    }
    if(tree->right != NULL)
    {
        (*list_new_node)->data = (tree->right)->data;
        list_insert_back(list_tree, *list_new_node);
        *list_new_node = (*list_new_node) + 1;
        tree_make_list_recurant(tree->right, (*list_new_node) - 1, list_new_node);
    }
}





void list_init(Node_list * list)
{
    list->next = list;
    list->prev = list;
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

void list_insert_front(Node_list * list, Node_list * t)
{
    Node_list* nlist = list->next;
    list->next = t;
    nlist->prev = t;
    t->next = nlist;
    t->prev = list;
}

void list_insert_back(Node_list * list, Node_list * t)
{
    Node_list* blist = list->prev;
    list->prev = t;
    blist->next = t;
    t->next = list;
    t->prev = blist;
}






























