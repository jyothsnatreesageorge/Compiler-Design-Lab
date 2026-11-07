//AST
%{
#include<stdio.h>
#include<stdlib.h>
#include "exp8.h"
int yylex();
int yyerror(char *s);
ASTNode *root=NULL;
%}
%code requires{
#include "exp8.h"
}
%union{
int INT;
ASTNode *ptr;
}
%token <INT> NUMBER
%type <ptr> E
%left '+' '-'
%left '*' '/'
%%
S:E '\n' {root=$1;return 0;};
E:E '+' E {$$=makenode('+',$1,$3);}
|E '-' E {$$=makenode('-',$1,$3);}
|E '*' E {$$=makenode('*',$1,$3);}
|E '/' E {$$=makenode('/',$1,$3);}
|'(' E ')' {$$=$2;}
|NUMBER {$$=makeleaf($1);};
%%
int main()
{
printf("Enter the expression:");
yyparse();
printf("generated AST:");
print(root);
return 0;
}
int yyerror(char *s)
{
printf("%s",s);
return 0;
}
