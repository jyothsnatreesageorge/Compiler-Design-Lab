//AST
#include<stdio.h>
#include<stdlib.h>
#include "exp8.tab.h"
ASTNode *makenode(char op, ASTNode *left,ASTNode *right)
{
   ASTNode *node=(ASTNode*)malloc(sizeof(ASTNode));
   node->op=op;
   node->left=left;
   node->right=right;
   node->val=0;
   return node;
}
ASTNode *makeleaf(int val)
{
   ASTNode *node=(ASTNode*)malloc(sizeof(ASTNode));
   node->op=0;
   node->left=NULL;
   node->right=NULL;
   node->val=val;
   return node;
}
void print(ASTNode *node)
{
   if(node==NULL)
   {
      return;
   }
   print(node->left);
   print(node->right);
   if(node->op)
   {
    printf("%c",node->op);
   }
   else
   {
   printf("%d",node->val);
   }
}
