#ifndef AST_H
#define AST_H
typedef struct ASTNode
{
char op;
struct ASTNode *left;
struct ASTNode *right;
int val;
}ASTNode;
ASTNode *makenode(char op,ASTNode *left,ASTNode *right);
ASTNode *makeleaf(int val);
void print(ASTNode *node);
#endif
