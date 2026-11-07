//vowels consonant count
%{
#include<stdio.h>
#include<string.h>
int v=0,c=0;
%}
%option noyywrap
%%
[aeiouAEIOU] {v++;}
[a-z|A-Z] {c++;}
.
%%
int main()
{
printf("Enter the string:");
yylex();
printf("vowels:%d\nconsonants:%d\n",v,c);
return 0;
}
