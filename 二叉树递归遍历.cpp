#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <windows.h>

//���Ķ��� 
typedef struct node{
	char data;
	struct node *lchild, *rchild;	
}bintnode;
bintnode *root;



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
{char data;
	
if(t!=NULL)
{data=t->data;
printf("%c",data);
preorder(t->lchild);
	
preorder(t->rchild);	
}	
	
}

//�������(left->root->right)
void ineorder(bintnode *t){
char data;	
if(t!=NULL)
{data=t->data;

preorder(t->lchild);
printf("%c",data);	
preorder(t->rchild);	

}
}
//������� 

void postorder(bintnode *t){

char data;	
if(t!=NULL)
{data=t->data;

preorder(t->lchild);
	
preorder(t->rchild);
printf("%c",data);
}
}

//������ 

int main() 
{
	system("color 4");
	system("color 1D");
bintnode *t=0;
printf("�������Ĵ�����");	
	t=creat();
printf("\n");	
printf("ǰ�������");	
preorder(t);
printf("\n");
printf("���������");
ineorder(t);
printf("\n");
printf("���������");
postorder(t);

return 0;	
}
	//abd#e##fg###c##















