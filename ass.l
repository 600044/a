%{

%}

%%

[a-z]+[=][a-z]+(.)* {ECHO;printf(" is a assignment statement\n");}

(.)* {ECHO;printf(" is not a assignment statement\n");}

%%
int yywrap()
{
return 1;
}

void main()
{
char exp[100];
printf("Enter the statement\n");
yylex();
}
