#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
//���Ķ��� 
typedef struct node{
	char data;
	struct node *lchild, *rchild;	
}bintnode;
bintnode *root;


//ջ�Ķ���
typedef struct stack{
bintnode *data[100];
int tag[100];
int top;	
}stack;
//stack *s;
 
stack init()
{
    stack s;
    s.top =0;
    return s;
}
//��ջ
void push(stack *s,bintnode *t) 
{		
s->data[s->top]=t;
s->top++;	
}
//��ջ 
bintnode *pop(stack *s)
{
if(s->top!=0)
	{s->top--;
	return(s->data[s->top]);
	}	
else
return NULL;	
	
}

//�������Ĵ������� 
bintnode *creat (){
bintnode *t;//??Ϊ�α��������ﴴ�� 
char ch;
scanf("%c",&ch);
if(ch=='#')
t=NULL;
else
    {t=(bintnode*)malloc(sizeof(bintnode));
  	 t->data=ch;
  	 t->lchild=creat ();
  	  t->rchild=creat ();
	}			
return t;	
}
/*
ǰ�����
(root->left->right)
*/
void preorder(bintnode *t)
{
	char data;
stack s;
s=init();
s.top = 0;
while((t)||(s.top!=0))	
	{
	if(t){
		data=t->data;
	printf("%c",data);
	push(&s,t);
	t=t->lchild;	
	}
	else
	{
		t=pop(&s);
		t=t->rchild;
	}		
}
}

//�������(left->root->right)
void ineorder(bintnode *t){
stack s;
s=init();
s.top = 0;
while((t!=NULL)||(s.top!=0))	
{
	if(t)
	{
	push(&s,t);
	t=t->lchild;	
	}
	else
	{
		t=pop(&s);
		printf("%c",t->data);
		t=t->rchild;
	}		
}
}

//������� 

void postorder(bintnode *t){
stack s;
s=init();
s.top = 0;
while((t!=NULL)||(s.top!=0))	
{
	if(t)
	{
	s.data[s.top]=t;
	s.tag[s.top]=0;
	s.top++;
	t=t->lchild;	
	}
	else
	if(s.tag[s.top-1]==1)
	{s.top--;
	t=s.data[s.top];
	printf("%c",t->data);
	t=NULL;
	}
	else
	{
	t=s.data[s.top-1];
	 s.tag[s.top-1]=1;
	 t=t->rchild;
	}		
}
}


//������ 

int main() 
{
bintnode *T ;
printf("�������Ĵ�����");	
	T=creat();
	
printf("ǰ�������");	
preorder(T);
printf("\n");
printf("���������");
ineorder(T);
printf("\n");
printf("���������");
postorder(T);
printf("\n");

return 0;	
}
	/*
	
	���Դ��룺 
	
	abd#e##fg###c##

    */













