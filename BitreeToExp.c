//
// Created by smth on 2020/12/7.
//
#include <stdio.h>
#include "stdlib.h"
typedef struct node{
   char data[10];
   struct node *left,*right;
}BTree;

void bitreeToExp(BTree *root,int deep){
    if(root==NULL){
        return;
    } else if(root->left==NULL&&root->right==NULL)
        printf("%s",root->data);
    else{
        if(deep>1)
            printf("(");
        bitreeToExp(root->left,deep+1);
        printf("%s",root->data);
        bitreeToExp(root->right,deep+1);
        if(deep>1){
            printf(")");
        }
    }
}

void bitreeToE(BTree *root){
    bitreeToExp(root,1);
}

