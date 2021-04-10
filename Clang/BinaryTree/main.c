#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int num;
    struct tree *left,*right;
} BinaryTree;
BinaryTree *CreateBinaryTreeNode();//BinaryTree *);
void ForeachNode(BinaryTree *);
int main(){
//    BinaryTree *root = CreateBinaryTreeNode(root);
    BinaryTree * (* createROOT)();
    createROOT = CreateBinaryTreeNode;
    BinaryTree *root = createROOT();
    ForeachNode(root);
    return 0;
}

BinaryTree *CreateBinaryTreeNode(){//BinaryTree *node){
    int num;
    BinaryTree *node = (BinaryTree *)malloc(sizeof(BinaryTree));
    if ( scanf("%d",&num) ){
        node->num = num;
        node->left = CreateBinaryTreeNode(node->left);
        node->right = CreateBinaryTreeNode(node->right);
        return node;
    } else {
        node->num = 0;
        node->left = node->right = NULL;
        fflush(stdin);
        return NULL;
    }
}

void ForeachNode(BinaryTree *node){
    if (node == NULL){
        printf("0\t");
        return;
    }
    printf("%d\n",node->num);
    ForeachNode(node->left);
    ForeachNode(node->right);
}