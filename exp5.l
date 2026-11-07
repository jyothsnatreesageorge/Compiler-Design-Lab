//valid expression
%{
#include "exp5.tab.h"
%}
%option noyywrap
%%
[0-9]+ {return NUMBER;}
[+\-*/()] {return yytext[0];}
[ \t] ;
\n {return '\n';}
. {return yytext[0];}
%%
