//Valid identifier
%{
#include "exp6.tab.h"
%}
%option noyywrap
%%
[0-9] {return NUMBER;}
[_A-Za-z] {return LETTER;}
[ \t] ;
\n {return '\n';}
. {return yytext[0];}
%%
