#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
typedef struct{
	int a[100];
    int size;
	}slist;
	
/*����*/ 
int Tips()
{
    int p;
    printf("<----------��ѡ����---------->\n");
    printf("<----------1.�ÿ�-------->\n");
    printf("<----------2.��ӡ-------->\n");
    printf("<----------3.����-------->\n");
    printf("<----------4.����-------->\n");
    printf("<----------5.ɾ��-------->\n");
    scanf("%d",&p);
    return p;

}
/*�ÿ�*/ 
void append(slist *slt)
{
slt->size=0;	
}
/*��ӡ*/
void display(slist slt)
{
	int i;
	for(i=1;i<=slt.size;i++)
	{
	printf("%5d",slt.a[i]);
	}
}

/*����*/
void find(slist *slt,int y) 
{
	int x=y;
	int i=0;
	while(i<slt->size&&slt->a[i]!=x) i++;
	if(i<slt->size)
	printf("��%d��Ϊ������",i+1);
	else
	printf("δ�ҵ���\n");
}

/*����*/
void insert(slist *slt,int y) 
{
    int i;
    int x;
    printf("������ֵ\n");
    scanf("%d",&x);
	for(i=slt->size;i>y;i--)
	slt->a[i]=slt->a[i-1];
	slt->a[y]=x;
	slt->size++;
}

/*ɾ��*/
void del(slist *slt,int x) 
{
	int b=x;
    int i;
	for(i=b;i<slt->size-1;i++)
	slt->a[i]=slt->a[i+1];
	slt->size--;
}


/*������*/
int main()
{
    int i=1;
	int x,y,z;
    int n = 5;
    slist l= {{1,2,3,4,5}, 5};
    while(i>0)
    {
        system("cls");
        i=Tips();
        switch(i)
        {
            case 1:
           {   system("cls");
               append(&l);
               getch();
               break;

           }
        
            case 2:
            {system("cls");
                for(i=0;i<l.size;i++)
    				{
					printf("%5d",l.a[i]);
					}
					  getch();
                break; 
            }
            case 3:
            {  system("cls");
				printf("���������ֵ\n");
            	scanf("%d",&z); 
               find(&l,z);
                 getch();
                break;
            }
            case 4:{ 
            	system("cls");
            	printf("���������λ��\n");
            	scanf("%d",&y);
            	insert(&l,y);
            	  getch();
            	break;
		           }
		    case 5:{
            	system("cls");
            	printf("������ɾ��λ��\n");
            	scanf("%d",&x);
            	del(&l,x);
            	  getch();
            	  break;
		           }
		     
       }
    }
}
