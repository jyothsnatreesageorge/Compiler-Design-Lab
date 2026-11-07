//lexical analyzer in c
%{
#include<stdio.h>
#include<string.h>
%}
%option noyywrap
%%
"#".* {printf("%s-PREPROCESSOR\n",yytext);}
"int"|"char"|"float"|"if"|"else"|"else if"|"break"|"continue"|"return" {printf("%s-KEYWORDS\n",yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {printf("%s-IDENTIFIERS\n",yytext);}
[0-9]+ {printf("%s-INTEGERS\n",yytext);}
"+"|"-"|"*"|"%"|"/" {printf("%s-ARITHMETIC OP\n",yytext);}
"="|"+="|"-="|"*="|"/="|"%=" {printf("%s-ASSIGNMENT OP\n",yytext);}
">"|"<"|">="|"<="|"=="|"!=" {printf("%s-RELATIONAL OP\n",yytext);}
"&&"|"||"|"!" {printf("%s-LOGICAL OP\n",yytext);}
"~"|"&"|"^"|"|" {printf("%s-BITWISE OP\n",yytext);}
[.':;()\[\]{}] {printf("%s-PUNCTUATORS\n",yytext);}
"//".* {printf("%s-SINGLE LINE COMMENT\n",yytext);}
"/*"(.|\n)*"*/" {printf("%s-MULTI LINE COMMENT\n",yytext);}
\".*\" {printf("%s-STRING LITERAL\n",yytext);}
.
%%
int main()
{
yyin=fopen("input2.txt","r");
if(yyin==NULL)
{
printf("Error in opening the file\n");
return 0;
}
yylex();
fclose(yyin);
return 0;
}
