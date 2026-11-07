//AST
%{
#include "exp8.tab.h"
#include<stdio.h>
#include<stdlib.h>
%}
%option noyywrap
%%
[0-9]+ {yylval.INT=atoi(yytext);return NUMBER;}
[ \t] ;
\n {return '\n';}
. {return yytext[0];}
%%
