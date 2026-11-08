//first-follow
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char lhs[20],rhs[20][20];
char first[26][128]={'\0'};
char follow[26][128]={'\0'};
int i,j,k,n,nullable;
int add(char set[],char ch)
{
   if(!set[(unsigned char)ch])
   {
      set[(unsigned char)ch]=1;
      return 1;
   }
   return 0;
}
int hasE(char set[])
{
   return set['#'];
}
void findfirst()
{
   int change;
   do
   {
      change=0;
      for(i=0;i<n;i++)
      {
         int A=lhs[i]-'A';
         nullable=1;
         for(j=0;rhs[i][j]!='\0';j++)
         {
            char ch=rhs[i][j];
            if(!isupper((unsigned char)ch))
            {
               change|=add(first[A],ch);
               nullable=0;
               break;
            }
            int B=ch-'A';
            for(k=0;k<128;k++)
            {
               if(k!='#'&&first[B][k])
               {
                  change|=add(first[A],(char)k);
               }
            }
            if(!hasE(first[B]))
            {
               nullable=0;
               break;
            }
         }
         if(nullable)
         {
            change|=add(first[A],'#');
         }
      }
   }while(change);
}
void findfollow()
{
   int change;
   add(follow[lhs[0]-'A'],'$');
   do
   {
      change=0;
      for(i=0;i<n;i++)
      {
         int A=lhs[i]-'A';
         for(j=0;rhs[i][j]!='\0';j++)
         {
            char ch=rhs[i][j];
            if(isupper((unsigned char)ch))
            {
               int B=ch-'A';
               nullable=1;
               for(k=j+1;rhs[i][k]!='\0';k++)
               {
                  char next=rhs[i][k];
                  if(next=='#')
                  {
                     continue;
                  }
                  if(!isupper((unsigned char)next))
                  {
                     change|=add(follow[B],next);
                     nullable=0;
                     break;
                  }
                  int C=next-'A';
                  for(int x=0;x<128;x++)
                  {
                     if(x!='#'&&first[C][x])
                     {
                        change|=add(follow[B],(char)x);
                     }
                  }
                  if(!hasE(first[C]))
                  {
                     nullable=0;
                     break;
                  }
               }
               if(nullable)
               {
                  for(int x=0;x<128;x++)
                  {
                     if(follow[A][x])
                     {
                        change|=add(follow[B],(char)x);
                     }
                  }
               }
            }
         }
      }
   }while(change);
}
void display()
{
   printf("First sets\n");
   for(i=0;i<26;i++)
   {
      int exist=0;
      for(j=0;j<n;j++)
      {
         if(lhs[j]=='A'+i)
         {
            exist=1;
            break;
         }
      }
      if(exist)
      {
         printf("First(%c)={",'A'+i);
         for(k=0;k<128;k++)
         {
            if(first[i][k])
            {
               printf("%c ",k);
            }
         }
         printf("}\n");
      }
   }
   printf("Follow Sets\n");
   for(i=0;i<n;i++)
   {
      int exist=0;
      for(j=0;j<128;j++)
      {
         if(lhs[j]=='A'+i)
         {
            exist=1;
            break;
         }
      }
      if(exist)
      {
         printf("Follow(%c)={",'A'+i);
         for(k=0;k<128;k++)
         {
            if(follow[i][k])
            {
               printf("%c ",k);
            }
         }
         printf("}\n");
      }
   }
}
int main()
{
   printf("Enter the no of expr:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      scanf(" %c=%s",&lhs[i],rhs[i]);
   }
   findfirst();
   findfollow();
   display();
}
