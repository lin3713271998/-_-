#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#define len sizeof(stu)

typedef struct student{
    int num;//ѧ��
	char name[20];//����
	int studentclass;//�༶
	int dorm;//�����
    struct student *next;
}stu;
stu *head;
int n;
int Tips()
{
    int p;
    printf("<-----����ѧ������ϵͳ����ʵ��------>\n");
    printf("<----------1.���------------------->\n");
    printf("<----------2.ɾ��------------------->\n");
    printf("<----------3.����------------------->\n");
    printf("<----------4.��ת���--------------->\n");
    printf("<----------5.ɾ��XY֮��------------->\n");
    printf("<----------6.��ӡ���--------------->\n");
    printf("<----------7.�����----------------->\n");
    printf("<----------8.���뵽����------------->\n");
    printf("<----------0.�˳�------------------->\n");
   
    scanf("%d",&p);
    return p;

}


/*���*/
stu * creat()
{
    stu *p1,*p2,*head;int i,k=1,sum;
    n=0;
    printf("����ѧ����Ϣ�ĸ���\n");
    scanf("%d",&sum);

    for(i=0;i<sum;i++)
    {
        p1=(stu *)malloc(len);
        printf("\n�����%d��ѧ������Ϣ\n",k++);
        printf("\n ������ѧ����ѧ�ţ�");
        scanf("%d",&p1->num);
		printf("\n ������ѧ��������:");
		scanf("%s", &p1->name);
		printf("\n ������ѧ���İ༶:");
		scanf("%d", &p1->studentclass);
		printf("\n ������ѧ���������:");
		scanf("%d", &p1->dorm); 
        n=n+1;
        if(n==1)
            head=p1;
        else
        p2->next=p1;
        p2=p1;
    }
    p2->next=0;
    return head;
}

/*ɾ��*/
stu * del(stu * head,long num)
{
    stu *p1,*p2;
    if(head==0)
        printf("���!\n");
    else
    {
        p1=head;
        while(p1->num!=num && p1->next!=0)
        {
            p2=p1;p1=p1->next;
        }
        if(p1->num==num)
        {
            if(p1==head)
            {
            head=p1->next;
            }
            else
            {
                p2->next=p1->next;

            }
            printf("ɾ��ѧ��:%ld�ɹ�\n",num);
            n=n-1;
       }
       else
            printf("û��%ld���ѧ��!\n",num);
    }
      return head;
}


/*����*/
stu *find(stu * head,int x)
{
    int num=x;
     stu * p;
    
    p=head;
    if(head!=0)
    {
     while(p!=0)
       {if(p->num==num) 
       { printf("ѧ��:%-10ld ������%s �༶��%d ���᣺%d\n",p->num,p->name,p->studentclass,p->dorm);
       getch();
	   }
        p=p->next;
        
		}
    
}
}

/*���*/
void print(stu * head)
{
    stu * p;
    printf("��ʱ��%d��ѧ����Ϣ��:\n",n);
    p=head;
    if(head!=0)
    {
     while(p!=0)
       {
        printf("ѧ��:%-10ld ������%s �༶��%d ���᣺%d\n",p->num,p->name,p->studentclass,p->dorm);
        p=p->next;
       }
    }
}

/*�����*/
void num(stu * head)
{
    stu * p;
    int num;
    p=head;
    if(head!=0)
    {
     while(p!=0)
       {num=num+1;
        p=p->next;
       }
        printf("�����Ϊ%d",num);
    }
}

/*ɾ��xy֮��*/
void delin(stu * head)
{
    stu * p,*q;
    int x,y;
    p=head;
    q=head;
    if(head!=0)
    {
     printf("������x y\n ");
     scanf("%d %d",&x,&y);
    	for(p=head;p!=0;q=q->next)
   		 {
		    	if(p->num>=x&&p->num<=y)
		    	{
		    
		       del(head,p->num);
				}
           p=p->next;
		 }
    }
    printf("ɾ�����Ϊ��\n");
print(head);
}

//����
void insert(stu *head)
{
    stu *p,*pnew;
    int m;
	pnew=(stu*)malloc(sizeof(stu));
    printf("�༶:\n");
	scanf("%d",&pnew->studentclass);
	printf("ѧ��:\n");
	scanf("%d",&pnew->num);
	printf("����:\n");
	scanf("%s",&pnew->name);
	printf("�����:\n");
	scanf("%d",&pnew->dorm);
	printf("\n");
    printf("��������Ҫ�嵽��λ�ã�\n");
	scanf("%d",&m);
	p=head;
	for(int j=1;j<m&&p!=NULL;j++)
	{
	    p=p->next;
	}
	pnew->next=p->next;
	p->next=pnew;
}
 
//typedef struct student{
//    int num;//ѧ��
//	char name[20];//����
//	int studentclass;//�༶
//	int dorm;//�����
//    struct student *next;
//}stu;
/*ת��*/ 
void rever(stu *head)
{
  stu *p,*q,*s;
  q=head;
  p=q->next;
  s=p->next;
  
while (s->next!=NULL)
{
p->next=q;
q=p;
p=s;
s=p->next;
}
s->next=p;
p->next=q;
head->next=NULL;
head=s;
print(head);
}

/*������*/
int main()
{
    stu * head=0,*stud;
    int m,x;
    long del_num;
    int i=1;
	int g;
    while(i>0)
    {
        system("cls");
        i=Tips();
        switch(i)
        {
            case 1:
           {   system("cls");
               printf("��ʼ����ѧ����Ϣ:\n");
               head=creat();
               system("cls");
               print(head);
               printf("������0����\n");
               scanf("%d",&m);
               while(m!=0)
               {
                   printf("������0����\n");
                   scanf("%d",&m);
               }
               break;

           }
            case 2:
           { 
                system("cls");
                printf("����Ҫɾ����ѧ��:");
                scanf("%ld",&del_num);
                head=del(head,del_num);
                print(head);
                printf("������0����\n");
                scanf("%d",&m);
                while(m!=0)
                {
                   printf("������0����\n");
                   scanf("%d",&m);
                }
                break;
           }
            case 3:
            {
                system("cls");
                getch();
                printf("\n ����������ѧ����ѧ��:");
		    	scanf("%d",&x); 
		    	find(head,x) ;
                break;
            }
            
            case 4:{//��ת��� 
            	system("cls");
            	rever(head);
            	getch();
				break; 
		           }
		    case 5:{ 
            	system("cls");
            	delin(head);
            	getch();
            	break;
		           }
		           
		    case 6:
            {   
                system("cls");
                print(head);
                printf("������0����\n");
                scanf("%d",&m);
                while(m!=0)
                {
                    printf("������0����\n");
                    scanf("%d",&m);
                }
                break;
            }
             case 7:{
            	system("cls");
            	 num(head);
            	 getch();
            	 break; 
		           }
		    case 8:{
            	system("cls");
            	 insert(head);
            	 getch();
            	 break; 
		           }
		    
		          
       }
    }
}
