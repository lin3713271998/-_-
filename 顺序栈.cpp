#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
typedef struct {
	int	a[100];
	int	top;
}stack;
stack slt;
/*����*/
int Tips()
{
	int p;
	printf( "<----------��ѡ����---------->\n" );
	printf( "<----------1.��ջ-------->\n" );
	printf( "<----------2.��ջ-------->\n" );
	printf( "<----------3.��ӡ-------->\n" );
	printf( "<----------4.ȡջ��-------->\n" );
	scanf( "%d", &p );
	return(p);
}


/* ��ʼ�� */
void init( stack *L )
{
	L->top	= 0;
}


/* ��ջ */
void pop( stack *L )
{
	if ( L->top == 0 )
	{
		printf( "�յ�" );
	}else  {
		L->top--;
	}
}


/* ������� */
void display( stack *L )
{
	for ( int i = 0; i < L->top; i++ )
	{
		printf( "%d ", L->a[i] );
	}
	printf( "\n" );
}


/* ȡջ�� */
void read( stack *L )
{
	if ( L->top == 0 )
	{
		printf( "�յ�" );
	}else  {
		printf( "%d\n", L->a[L->top - 1] );
	}
}


/*������*/
int main()
{
	int	num;
	int	i;
	init( &slt );
	while ( true )
	{
		system( "cls" );
		i = Tips();
		switch ( i )
		{
		case 1:
		{ system( "cls" );

		  printf( "*********����5����ջ����*********\n\n\n" );
		  for ( i = 1; i <= 5; i++ )
		  {
			  printf( "�����%d����ջ����\n", i );
			  scanf( "%d", &num );
			  /* slt = (stack*)malloc(sizeof(stack)); */
			  slt.top++;   /* ��ջ���Լ� */
			  slt.a[slt.top] = num;
		  }
		  getch();
		  break; }
		case 2:
		{
			system( "cls" );
			pop( &slt );
			getch();
			break;
		}
		case 3:
		{ system( "cls" );
		  display( &slt );
		  getch();
		  break; }
		case 4:
		{ system( "cls" );
		  read( &slt );
		  getch();
		  break; }
		}
	}
}
