//calculator
%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror(char* s);
%}
%token NUMBER
%left '+' '-'
%left '*' '/'
%right UMINUS
%%
S:E '\n' {printf("Result:%d\n",$1);};
E:E '+' E {$$=$1+$3;}
| E '-' E {$$=$1-$3;}
| E '*' E {$$=$1*$3;}
| E '/' E {$$=$1/$3;}
| '(' E ')' {$$=$1;}
| '-' E %prec UMINUS {$$=-$2;}
| NUMBER {$$=$1;};
%%
int main()
{
printf("Enter the expression:");
yyparse();
return 0;
}
int yyerror(char* s)
{
printf("Expression cannot be evaluated!\n");
return 0;
}
