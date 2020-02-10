%{
char* scope();
int flag=0;
int gflag=0;
%}
%%
(main)|(return) {
}
['][a-z][']|[=][a-z] {
}
[{] {
gflag=1;
}
[;,#<>,()\n] {
}
[}] {
gflag=0;
}
[0-9=] {
}
(int) {
flag=1;
}
(float) {
flag=2;
}
(char) {
flag=3;
}
(double) {
flag=4;
}
[a-z+] {
switch(flag) {
case 1:printf("\n%s\t\t%s\t%d\t%s\n",yytext,"int",sizeof(int),scope());break;
case 2:printf("\n%s\t\t%s\t%d\t%s\n",yytext,"float",sizeof(float),scope());break;
case 3:printf("\n%s\t\t%s\t%d\t%s\n",yytext,"char",sizeof(char),scope());break;
case 4:printf("\n%s\t\t%s\t%d\t%s\n",yytext,"double",sizeof(double),scope());break;
}
}
%%
int yywrap() {
return 1;
}
char* scope() {
if(flag==1)
return "local";
else
return "global";
}
int main()
{
FILE *fp;
fp=fopen("input.c","r");
yyin=fp;
printf("\n identifier \t type \t size \t scope\n");
printf("-----------------------------------\n");
yylex();
return 0;
}

