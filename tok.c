#include<stdio.h>
#define MAXSIZE 10
#include<string.h>
#include<malloc.h>

int main()
{
 int i,l,k,count=0,p=1;
 char exp[MAXSIZE];
 char *ch;
  printf("Enter the expression...\n");
 scanf("%[^\n]",&exp);
// printf("string=%s",exp);
 l=strlen(exp);
 ch=(char*)malloc(l*sizeof(char));
 
//printf("length=%d",l);
 for(i=0;i<l;i++)
   {
      if(exp[i]=='-'&& exp[i+1]=='-')
        {
         printf("-- is unary minus operator\n");
         i=i+1;
        }      
      else if(exp[i]=='+'&& exp[i+1]=='+')
         {
          printf("++ is unary plus operator\n");
          i=i+1;
        }
      else if(exp[i]=='=')
         printf("= is assignment operator\n");
      else if(exp[i]=='+')
         printf("+ is plus operator\n");
      else if(exp[i]=='-')
         printf("- is minus operator\n");
      else if(exp[i]=='*')
         printf("* is multiplication operator\n");
      else if(exp[i]=='/')
         printf("/ is division operator\n");
      else if(exp[i]=='%')
         printf("% is modulo operator\n");
      else if(exp[i]=='^')
         printf("^ is power of operator\n");
      else if(exp[i]=='!')
         printf("! is logical not operator\n");
      else if(exp[i]=='&')
         printf("&& is logical AND operator\n");
      else if(exp[i]=='|')
         printf("|| is logical OR operator\n");
      else if(exp[i]==' ')
            k=0;
else if(exp[i]>='a' && exp[i]<='z' ||exp[i]<='A' && exp[i]<='Z')     
{
	int t=0;
	//printf("hi");
	ch[t]=exp[i];
 	t++;
 
while(exp[i+1]>='a' && exp[i+1]<='z' || exp[i]>='A' && exp[i]<='Z' || exp[i+1]>='0' && exp[i+1]<='9')
{
  ch[t]=exp[i+1];
	i++;
	t++;
		 }
	     ch[t]='\0';
		 if(strcmp(ch,"exp")==0)
		 printf("%s is an expresion",ch); 
		 else   
		 printf("%s is an operand %d\n",ch,p++);

}
}
return 0;
}
