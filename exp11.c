//recursive descent parser
$ cat exp11.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int i=0,error=0;
char input[100];
void E();
void Eprime();
void T();
void Tprime();
void F();
void E()
{
   T();
   Eprime();
}
void Eprime()
{
   if(input[i]=='+'||input[i]=='-')
   {
      i++;
      T();
      Eprime();
   }
}
void T()
{
   F();
   Tprime();
}
void Tprime()
{
   if(input[i]=='*'||input[i]=='/')
   {
      i++;
      F();
      Tprime();
   }
}
void F()
{
   if(isalnum(input[i]))
   {
      i++;
   }
   else if(input[i]=='(')
   {
      i++;
      E();
      if(input[i]==')')
      {
         i++;
      }
      else
      {
         error=1;
      }
   }
   else
   {
      error=1;
   }
}
int main()
{
   printf("Enter the expr:");
   scanf("%s",&input);
   E();
   if(strlen(input)==i&&error==0)
   {
      printf("Valid expr!\n");
   }
   else
   {
      printf("Invalid expr!\n");
   }
   return 0;
}
