//const propagation
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct quad
{
   char op[10];
   char op1[10];
   char op2[10];
   char res[10];
};
struct quad q[100];
int n;
int isint(char *s)
{
   int i=0;
   if(s[0]=='+'||s[0]=='-')
   {
      i++;
   }
   if(s[i]=='\0')
   {
      return 0;
   }
   for(;s[i]!='\0';i++)
   {
      if(!isdigit(s[i]))
      {
         return 0;
      }
   }
   return 1;
}
int calculate(char *op,int a,int b)
{
   if(strcmp(op,"+")==0)
   {
      return a+b;
   }
   if(strcmp(op,"-")==0)
   {
      return a-b;
   }
   if(strcmp(op,"*")==0)
   {
      return a*b;
   }
   if(strcmp(op,"/")==0)
   {
      if(b!=0)
      {
         return a/b;
      }
   }
   return 0;
}
int getconst(char *var,int *val)
{
   for(int i=0;i<n;i++)
   {
      if((strcmp(q[i].op,"=")==0)&&(strcmp(q[i].res,var)==0)&&(isint(q[i].op1)))
      {
         *val=atoi(q[i].op1);
         return 1;
      }
   }
   return 0;
}
void fold()
{
   for(int i=0;i<n;i++)
   {
      
if((strcmp(q[i].op,"+")==0)||(strcmp(q[i].op,"-")==0)||(strcmp(q[i].op,"*")==0)||(strcmp(q[i].op,"/")==0)&&(
isint(q[i].op1))&&(isint(q[i].op2)))
      {
         int a=atoi(q[i].op1);
         int b=atoi(q[i].op2);
         if(strcmp(q[i].op,"/")&&b==0)
         {
            continue;
         }
         int res=calculate(q[i].op,a,b);
         strcpy(q[i].op,"=");
         sprintf(q[i].op1,"%d",res);
         strcpy(q[i].op2,"-");
      }
   }
}
void propagate()
{
   int value;
   for(int i=0;i<n;i++)
   {
      if(!isint(q[i].op1))
      {
         if(getconst(q[i].op1,&value))
         {
            sprintf(q[i].op1,"%d",value);
         }
      }
   }
   for(int i=0;i<n;i++)
   {
      if(!isint(q[i].op2))
      {
         if(getconst(q[i].op2,&value))
         {
            sprintf(q[i].op2,"%d",value);
         }
      }
   }
   fold();
}
void display()
{
   printf("OP\tOP1\tOP2\tRES\n");
   for(int i=0;i<n;i++)
   {
      printf("%s\t%s\t%s\t%s\n",q[i].op,q[i].op1,q[i].op2,q[i].res);
   }
}
int main()
{
   printf("Enter the number of instr:");
   scanf("%d",&n);
   printf("Enter the instr:");
   for(int i=0;i<n;i++)
   {
      scanf("%s %s %s %s",q[i].op,q[i].op1,q[i].op2,q[i].res);
   }
   printf("TAC entered\n");
   display();
   fold();
   propagate();
   printf("TAC optimized\n");
   display();
   return 0;
}
