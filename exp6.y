//Valid identifier
%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror(char* s);
%}
%token NUMBER LETTER;
%%
S:ID '\n' {printf("Valid Identifier\n");return 0;};
ID:LETTER
|ID LETTER
|ID NUMBER;
%%
int main()
{
printf("Enter an identifier:");
yyparse();
return 0;
}
int yyerror(char* s)
{
printf("Invalid identifier");
return 0;
}
