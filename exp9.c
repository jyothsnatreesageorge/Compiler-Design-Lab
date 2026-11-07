//lexical analyzer in c
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int isKeyword(char str[])
{
   char kw[10][10]={"int","char","float","if","else","break","continue","return"};
   for(int i=0;i<10;i++)
   {
      if(strcmp(str,kw[i])==0)
      {
         return 1;
      }
   }
   return 0;
}
int main()
{
   FILE *fp;
   char ch,next,buffer[100];
   int i;
   fp=fopen("input2.txt","r");
   if(fp==NULL)
   {
      printf("Error in opening the file!\n");
      return -1;
   }
   while((ch=fgetc(fp))!=EOF)
   {
      if(isspace(ch))
      {
         continue;
      }
      if(ch=='/')
      {
         next=fgetc(fp);
         if(next=='/')
         {
            while((ch=fgetc(fp))!=EOF&&ch!='\n')
            {
               continue;
            }
         }
         if(next=='*')
         {
            char prev='\0';
            while((ch=fgetc(fp))!=EOF)
            {
               if(prev=='*'&&ch=='/')
               {
                  break;
               }
               prev=ch;
            }
            continue;
         }
         else
         {
            ungetc(next,fp);
         }
      }
      if(ch=='"')
      {
         i=0;
         buffer[i++]=ch;
         while((ch=fgetc(fp))!=EOF&&ch!='"')
         {
            buffer[i++]=ch;
         }
         buffer[i++]='"';
         buffer[i]='\0';
         printf("String-%s\n",buffer);
      }
      else if(isalpha(ch)||ch=='_')
      {
         i=0;
         buffer[i++]=ch;
         while((ch=fgetc(fp))!=EOF&&(isalnum(ch)||ch=='_'))
         {
            buffer[i++]=ch;
         }
         buffer[i]='\0';
         if(ch!=EOF)
         {
            ungetc(ch,fp);
         }
         if(isKeyword(buffer))
         {
            printf("Keyword-%s\n",buffer);
         }
         else
         {
            printf("Identifier-%s\n",buffer);
         }
      }
      else if(isdigit(ch))
      {
         i=0;
         buffer[i++]=ch;
         while((ch=fgetc(fp))!=EOF&&isdigit(ch))
         {
            buffer[i++]=ch;
         }
         buffer[i]='\0';
         if(ch!=EOF)
         {
            ungetc(ch,fp);
         }
         printf("Integer-%s\n",buffer);
      }
      else if(ch=='='||ch=='<'||ch=='>'||ch=='&'||ch=='|'||ch=='!')
      {
         next=fgetc(fp);
         if(ch=='='&&next=='=')
         {
            printf("Relational Op-==\n");
         }
         else if((ch=='<'||ch=='>'||ch=='!')&&next=='=')
         {
            printf("Relational Op-%c%c\n",ch,next);
         }
         else if(ch=='&'&&next=='&')
         {
            printf("Logical Op-&&\n");
         }
         else if(ch=='|'&&next=='|')
         {
            printf("Logical Op-||\n");
         }
         else
         {
            if(next!=EOF)
            {
               ungetc(next,fp);
            }
            if(ch=='<'||ch=='>')
            {
               printf("Relational Op-%c\n",ch);
            }
            else if(ch=='=')
            {
               printf("Assignement Op-=\n");
            }
            else if(ch=='!')
            {
               printf("Logical Op-!\n");
            }
            else
            {
               printf("Bitwise Op-%c\n",ch);
            }
         }
      }
      else if(ch=='^')
      {
         printf("Bitwise Op-^\n");
      }
      else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%')
      {
         next=fgetc(fp);
         if(next=='=')
         {
            printf("Assignement Op-%c%c\n",ch,next);
         }
         else if(next!=EOF)
         {
            ungetc(next,fp);
            printf("Arithmetic Op-%c\n",ch);
         }
      }
      else if(ch==';'||ch==','||ch=='{'||ch=='}'||ch=='('||ch==')'||ch=='#'||ch=='.'||ch=='['||ch==']')
      {
         printf("Punctuator-%c\n",ch);
      }
      else
      {
         printf("Unknown char!\n");
      }
   }
   fclose(fp);
   return 0;
}
