//valid expression
%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror(char* s);
%}
%token NUMBER
%left '+' '-'
%left '*' '/'
%%
S:E '\n' {printf("Valid Expression\n");return 0;};
E:E '+' E
|E '-' E
|E '*' E
|E '/' E
|'(' E ')'
|NUMBER;
%%
int main()
{
printf("Enter an arithmetic expression:");
yyparse();
return 0;
}
int yyerror(char* s)
{
printf("invalid expression!\n");
return 0;
}
