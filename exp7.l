//calculator
%{
#include "exp7.tab.h"
%}
%option noyywrap
%%
[0-9]+ {yylval=atoi(yytext);return NUMBER;}
[+\-*/()] {return yytext[0];}
[ \t] ;
\n {return '\n';}
. {return yytext[0];}
%%
