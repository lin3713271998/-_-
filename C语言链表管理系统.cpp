#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#define format "%d\n%s\n%f\n%f\n%f\n"
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
    printf("<----------��ѡ����---------->\n");
    printf("<----------1.����-------->\n");
    printf("<----------2.ɾ��-------->\n");
    printf("<----------3.����-------->\n");
    printf("<----------4.����-------->\n");
    printf("<----------5.����-------->\n");
    printf("<----------6.��ʾ-------->\n");
    printf("<----------0.�˳�------------------->\n");
    scanf("%d",&p);
    return p;

}


/*����*/
stu * creat()
{
    stu *p1,*p2,*head;int i,k=1,sum;
    n=0;
    printf("����ѧ����Ϣ�ĸ���\n");
    scanf("%d",&sum);

    //head=0;
    for(i=0;i<sum;i++)
    {
        p1=(stu *)malloc(len);
        printf("�����%d��ѧ������Ϣ\n",k++);
        printf("\n ������ѧ����ѧ�ţ�");
        scanf("%ld",&p1->num);
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






/*�����Ϊ����*/
stu *insert(stu * head, stu * stud)
{
    stu *p1,*p2,*p0;
    p0=stud;p1=head;
    if(head==0)
    {
        head=p0;stud->next=0;
    }
    else
    {
        while(p1->num<p0->num && p1->next!=0)
        {
            p2=p1;p1=p1->next;
        }
        if(p1->num>=p0->num)
        {
            if(p1==head)
            {
                head=p0;
                p0->next=p1;
             }
            else
            {
                p2->next=p0;
                p0->next=p1;
            }

        }
        else
        {
            p1->next=p0,p0->next=0;
        }

    }
    n=n+1;
    return head;
}



int save(stu *p)
{
	FILE *fp;
	stu *head;
	head = p;//pΪ�Ѿ������õ�����
	if ((fp = fopen("data.txt", "ab+")) == NULL)
	{
		printf("�޷���!\n");
		return -1;
	}
	while (p != NULL)
	{

		fwrite(p, sizeof(stu), 1, fp);
		p = p->next;
	}
	fclose(fp);
	return 1;
}//���������ļ�


stu* read()
{
	FILE *fp;
	if ((fp = fopen("data.txt", "rb")) == NULL)
	{
		printf("�޷���ȡ\n");
		return NULL;
	}
	int sign;
	stu *s,*p,*head;
	
	head= (stu*)malloc(sizeof(stu));
	if (head == NULL)
	{
		printf("��ȡʧ�ܣ��ڴ�ռ����벻�㣡\n");
		return NULL;
	}
	fseek(fp, 0, SEEK_END);
	if (ftell(fp) == 0)
	{
		return NULL;
	}
	p = head;
	p->next = NULL;
	while (!feof(fp))
	{
		s = (stu*)malloc(sizeof(stu));
		fread(s, sizeof(stu), 1, fp);
		p->next = s;
		p = s;
		p->next = NULL;
	}
	fclose(fp);
	return head;
}//��ȡ�ļ�������






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




/*������*/
int main()
{
    stu * head=0,*stud;
    int m;
    long del_num;
    int i=1;

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
                stud=(stu *)malloc(len);
                printf("\n ������ѧ��������:");
		    	scanf("%s", &stud->name);
		    	printf("\n ������ѧ���İ༶:");
		    	scanf("%s", &stud->studentclass);
	     		printf("\n ������ѧ���������:");
	     		scanf("%d", &stud->dorm);
                head=insert(head,stud);
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
            case 4:{//���� 
            	system("cls");
            	save(head);
		           }
		    case 5:{//���� 
            	system("cls");
            	read( ); 
		           }
       }
    }
}
