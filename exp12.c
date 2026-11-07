//shift reduce
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char input[100],stack[100];
char prod[6][50]={"E=E+E","E=E-E","E=E*E","E=E/E","E=(E)","E=i"};
int top=-1,ip=0;
char *pp=&prod[0][0];
void shift(char c);
void reduce(int pno,char *pos);
void shift(char c)
{
   stack[++top]=c;
   printf("%s\t%s\tShifted:%c\n",stack,input+ip,c);
}
void reduce(int pno,char *pos)
{
   int len=strlen(pos);
   top-=len;
   bzero((stack+top+1),len);
   stack[++top]=prod[pno][0];
   printf("%s\t%s\tReduced by:%s\n",stack,input+ip,prod[pno]);
}
int main()
{
   printf("Enter the input:");
   scanf("%s",input);
   printf("Stack\tInput\tAction\n");
   while(input[ip]!='\0')
   {
      shift(input[ip++]);
      for(int j=0;j<6;j++)
      {
         for(int i=0;i<6;i++)
         {
            char *pos=strstr(stack,(pp+i*50+2));
            if(pos!=NULL)
            {
               reduce(i,pos);
            }
         }
      }
   }
   if(stack[top]=='E'&&top==0)
   {
      printf("Input Accepted\n");
   }
   else
   {
      printf("Input rejected\n");
   }
}
