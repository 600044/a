#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct tab
{
	char name[20];
	char type[20];
	int scope;
	long size;
	struct tab* next;
}table;
table* create()
{
	return NULL;
}
table* new_row(char* n,char* ty,int s)
{
	table *t=(table*)malloc(sizeof(table));
	t->scope=s;
	//printf("hi\n");
	strcpy(t->name,n);
	strcpy(t->type,ty);
	t->size=sizeof(ty);
	t->next=NULL;
	return t;
}
table* insert(table* t,char* n,char* ty,int s)
{
	table *temp=new_row(n,ty,s);
	if(!t)
		return temp;
	table *t1=t;
	while(t1->next)
		t1=t1->next;
	t1->next=temp;
	return t;
}
int func(char* c)
{
	if(strcmp("short",c)==0)
		return 2;
	if(strcmp("int",c)==0)
		return 4;
	if(strcmp("long",c)==0)
		return 8;
	if(strcmp("float",c)==0)
		return 4;
	if(strcmp("double",c)==0)
		return 8;
	if(strcmp("char",c)==0)
		return 1;
}
void display(table* t)
{
	table* t1=t;
	while(t1)
	{
		printf("identifier:\t%s\n",t1->name);
		printf("type:\t%s\n",t1->type);
		if(t1->scope==1)
			printf("scope:\tlocal\n");
		else
			printf("scope:\tglobal\n");
		printf("size:\t%d\n\n",func(t1->type));
		t1=t1->next;
	}
	printf("\n");
}
int check(char* c)
{
	if(strcmp("short",c)==0 || strcmp("int",c)==0 || strcmp("long",c)==0 || strcmp("float",c)==0 || strcmp("double",c)==0 || strcmp("char",c)==0)
		return 1;
	else 
		return -1;
}
int main()
{
	FILE *f;
	int i,ans,t=0,l=0,flag=0;
	char fname[20],ch,s[20]={'\0'},c1[10];
	printf("Enter the file name\n");
	scanf("%s",fname);
	f=fopen(fname,"r");
	ch=fgetc(f);
	table *st=create();
	long size;
	while(ch!=EOF)
	{
		if(ch>='0' && ch<='9')
		{
			s[i]=ch;
			i+=1;
		}
		else if(ch<'a' || ch>'z')
		{
			//printf("%s\n",s);
			if(strcmp("main",s)==0)
			{
				l=1;
				i=0;	
				t=0;
				memset(s,0,sizeof(s));
			}
			else if(t==1)
			{
				if(flag==0)
					st=insert(st,s,c1,l);
				i=0;	
				if(ch==';')
					t=0;
				flag=1;
				if(ch==',')
					flag=0;
				memset(s,0,sizeof(s));
			}
			
			else
			{
				ans=check(s);
				i=0;	
				if(ans!=-1)
				{
					flag=0;
					strcpy(c1,s);
					t=1;
				}
				memset(s,0,sizeof(s));
			}
		}
		else
		{
			s[i]=ch;
			i+=1;
		}
		ch=fgetc(f);
	}
	fclose(f);
	printf("\n\n");
	display(st);
	return 0;
}
