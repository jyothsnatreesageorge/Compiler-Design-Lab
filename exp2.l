//substring conversion
%{
#include<stdio.h>
#include<string.h>
%}
%option noyywrap
%%
"abc" {strcpy(yytext,"ABC");ECHO;}
%%
int main()
{
printf("Enter the string:");
yylex();
return 0;
}
