//epsilon closure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int epsilon[20][20]={'\0'};
int epsilonclosure[20][20]={'\0'};
int closurecount[20]={0};
int n;
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
   return 0;
}
