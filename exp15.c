//target code
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct quad
{
   char op;
   char op1[10];
   char op2[10];
   char res[10];
};
struct quad q[100];
char instr[100];
int n;
void read()
{
   printf("Enter the no of instr:");
   scanf("%d",&n);
   printf("Enter the instr:\n");
   for(int i=0;i<n;i++)
   {
      scanf("%s = %s %c %s",q[i].res,q[i].op1,&q[i].op,q[i].op2);
   }
}
char *get_instr(char op)
{
   char mnemonic[6][6]={"MUL","ADD","","SUB","","DIV"};
   strcpy(instr,mnemonic[op-'*']);
   return instr;
}
void target()
{
   for(int i=0;i<n;i++)
   {
      printf("MOV AX,%s\n%s AX,%s\nMOV %s,AX\n",q[i].op1,get_instr(q[i].op),q[i].op2,q[i].res);
   }
}
int main()
{
   read();
   printf("Target Code\n");
   target();
   return 0;
}
