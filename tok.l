%{
#include<stdio.h>
%}

%%
[a-zA-z][a-zA-z0-9_]*  {printf("\n%s is an operand\n",yytext);}
[ \t]   ;
[+] {printf("\n%s is a plus operator\n",yytext);}
[-] {printf("\n%s is a minus operator\n",yytext);}
[/] {printf("\n%s is a division operator\n",yytext);}
[*] {printf("\n%s is a multiplication operator\n",yytext);}
[%] {printf("\n%s is a modulo operator\n",yytext);}
[=] {printf("\n%s is an assignment operator\n",yytext);}
"--" {printf("\n%s is a unary minus operator\n",yytext);}
"++" {printf("\n%s is a unary plus operator\n",yytext);} 
'^' {printf("\n%s is a powerof operator\n",yytext);}

.|\n {ECHO;}
%%
int yywrap()
{return 1;
}
int main()
{
yylex();
return 0;
}
