//e nfa to nfa
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int epsilon[20][20]={'\0'};
int epsilonclosure[20][20]={'\0'};
int transition[20][20][20]={'\0'};
int closurecount[20]={0};
char symbols[20]={'\0'};
int n,m;
void add(int state,int s)
{
   if(!epsilonclosure[state][s])
   {
      epsilonclosure[state][s]=1;
      closurecount[state]++;
      for(int t=0;t<n;t++)
      {
         if(epsilon[s][t])
         {
            add(state,t);
         }
      }
   }
}
void compute()
{
   for(int i=0;i<n;i++)
   {
      memset(epsilonclosure[i],0,sizeof(epsilonclosure[i]));
      closurecount[i]=0;
      add(i,i);
   }
}
int main()
{
   printf("Enter no of states:");
   scanf("%d",&n);
   printf("Enter the number of symbols:");
   scanf("%d",&m);
   printf("Enter the symbols\n");
   for(int i=0;i<m;i++)
   {
      scanf(" %c",&symbols[i]);
   }
   printf("Enter normal transitions:\n");
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
      {
         printf("From state %d with symbol %c\n",i,symbols[j]);
         printf("Enter no of next states:");
         int num;
         scanf("%d",&num);
         printf("Enter next states:\n");
         if(num>0)
         {
            for(int k=0;k<num;k++)
            {
               int s;
               scanf("%d",&s);
               transition[i][j][s]=1;
            }
         }
      }
   }
   int from,to;
   printf("Enter epsilon transition:-1 -1 to stop\n");
   while(1)
   {
      scanf("%d %d",&from,&to);
      if(from==-1&&to==-1)
      {
         break;
      }
      epsilon[from][to]=1;
   }
   compute();
   for(int i=0;i<n;i++)
   {
      printf("Epsilon closure of q%d:{",i);
      for(int j=0;j<n;j++)
      {
         if(epsilonclosure[i][j])
         {
            printf("%d ",j);
         }
      }
      printf("}\n");
   }
   printf("NFA without epsilon:\n");
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
      {
         int result[20]={0};
         for(int k=0;k<n;k++)
         {
            if(epsilonclosure[i][k])
            {
               for(int l=0;l<n;l++)
               {
                  if(transition[k][j][l])
                  {
                     for(int p=0;p<n;p++)
                     {
                        if(epsilonclosure[l][p])
                        {
                           result[p]=1;
                        }
                     }
                  }
               }
            }
         }
         printf("State %d----%c---->{",i,symbols[j]);
         for(int x=0;x<n;x++)
         {
            if(result[x]==1)
            {
               printf("%d ",x);
            }
         }
         printf("}\n");
      }
   }
   return 0;
}
