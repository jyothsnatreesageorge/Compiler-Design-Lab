//line,word,char count
$ cat exp1.l
%{
#include<stdio.h>
int line=0,word=0,chars=0;
%}
%option noyywrap
%%
[a-zA-Z]+ {word++;chars+=yyleng;}
\n {line++;chars++;}
. {chars++;}
%%
int main()
{
yyin=fopen("input.txt","r");
if(yyin==NULL)
{
printf("Error in opening the file!\n");
return 0;
}
yylex();
printf("Words:%d\nChars:%d\nLines:%d\n",word,chars,line);
fclose(yyin);
return 0;
}
