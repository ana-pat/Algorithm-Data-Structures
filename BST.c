/*
Question:Given a positive integer n where n = 2^k −1, k ∈ Z+. Considering n an user input, create the
binary search tree (BST) from these n integers, such that,
• The height of BST is minimum;
• The height of BST is maximum.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct binary_tree_node_t *Tree;

struct binary_tree_node_t {
    int key;
    Tree parent;
    Tree left;
    Tree right;
};

void insertionSort(int *a,int s){
    int i, j, key;
    for(i = 1; i < s; i++){
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}


Tree newTree(int key, Tree parent, Tree left, Tree right) {
    Tree tree = (Tree) calloc (1, sizeof(struct binary_tree_node_t));
    tree->key = key;
    tree->parent = parent;
    tree->left = left;
    tree->right = right;
    return tree;
}

Tree insertIntoBSTHelper(Tree tree, int key, Tree parent) {
    if (!tree) {
        return newTree(key, parent, NULL, NULL);
    }
    if (tree->key > key) {
        tree->left = insertIntoBSTHelper(tree->left, key, tree);
    } else {
        tree->right = insertIntoBSTHelper(tree->right, key, tree);
    }
    return tree;
}

Tree minTree(int *a, int start, int end)
{

    if (start > end)
    return NULL;


    int mid = (start + end)/2;
    Tree root = newTree(a[mid], NULL, NULL, NULL);

    root->left = minTree(a, start,
                                    mid - 1);

    root->right = minTree(a, mid + 1, end);

    return root;
}

Tree insertIntoBST(Tree tree, int key) {
    return insertIntoBSTHelper(tree, key, NULL);
}

void postOrder(Tree tree) {
    if (tree == NULL) {
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    printf("%d ", tree->key);

}

void inOrder(Tree tree) {
    if (tree == NULL) {
        return;
    }
    inOrder(tree->left);
    printf("%d ", tree->key);
    inOrder(tree->right);
}

int main(){
Tree min = NULL;
Tree max = NULL;
int n, i;
printf("Enter n : ");
scanf("%d", &n);
int a[n];

printf("Enter the node values: ");
for(i = 0; i < n;i++){
	scanf("%d", &a[i]);
}
insertionSort(a, n);

//Working for finding BST with max. height
for(i = 0; i < n; i++){
	max = insertIntoBST(max, a[i]);
}

printf("Tree with maximum height is: \n");
inOrder(max);
printf("\n");
postOrder(max);

//Working for finding BST with min. height
min = minTree(a, 0, n-1);

printf("\nTree with minimum height is: \n");
inOrder(min);
printf("\n");
postOrder(min);

return 0;
}
