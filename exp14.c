//intermediate code gen
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char op[20]={'\0'};
char opnd[20][20]={'\0'};
int top1=-1,top2=-1;
char input[20];
int priority(char c)
{
   if(c=='+'||c=='-')
   {
      return 1;
   }
   else if(c=='*'||c=='/')
   {
      return 2;
   }
   else if(c=='=')
   {
      return 0;
   }
   else
   {
      return -1;
   }
}
void icg()
{
   char temp[20]={'\0'};
   int i=0,t=1;
   while(input[i]!='\0')
   {
      int j=0;
      for(;isalnum(input[i]);)
      {
         temp[j++]=input[i++];
      }
      if(j!=0)
      {
         strcpy(opnd[++top1],temp);
      }
      if(input[i]==' ')
      {
         i++;
         continue;
      }
      if(((top1>0&&priority(op[top2]))<priority(input[i]))||top2<0)
      {
         op[++top2]=input[i++];
      }
      else if(top2>=0)
      {
         char pop[2]={'\0'};
         pop[0]=op[top2--];
         printf("t%d=%s %s %s\n",t,opnd[top1-1],pop,opnd[top1]);
         sprintf(opnd[--top1],"t%d",t++);
      }
   }
   while(top2>=0)
   {
      char pop[2]={'\0'};
      pop[0]=op[top2--];
      if(strcmp(pop,"=")!=0)
      {
         printf("t%d=%s %s %s\n",t,opnd[top1-1],pop,opnd[top1]);
         sprintf(opnd[--top1],"t%d",t++);
      }
      else
      {
         printf("%s=t%d\n",opnd[top1-1],t-1);
      }
   }
}
int main()
{
   printf("Enter an expr:");
   scanf("%s",input);
   icg();
   return 0;
}
