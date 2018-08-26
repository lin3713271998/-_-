#include"stdio.h"

#include"stdlib.h"

#include"string.h"

#include"conio.h"

#define PAGE 3

#define MAX 1000

#define N 5

int k = 0;

/*�ṹ��*/

typedef struct

{
	int num;/*ѧ��*/

	char name[20];/*����*/

	char sex[5];/*�Ա�*/

	int age;/*����*/

	char studentclass[20];/*�༶*/

	int dorm;/*�����*/

}STUDENTS;



int read_file(STUDENTS stu[])

{
	FILE *fp;

	int i = 0;

	if ((fp = fopen("stu.txt", "rt")) == NULL)

	{
		printf("\n\n*****����ļ������ڣ��봴");

		return 0;

	}

	while (feof(fp) != 1)

	{

		fread(&stu[i], sizeof(STUDENTS), 1, fp);

		if (stu[i].num == 0)

			break;

		else

			i++;

	}

	fclose(fp);

	return i;

}

void save_file(STUDENTS stu[], int sum)

{
	FILE*fp;

	int i;

	if ((fp = fopen("stu.txt", "wb")) == NULL)

	{
		printf("д�ļ�����!\n");

		return;

	}

	for (i = 0; i<sum; i++)

		if (fwrite(&stu[i], sizeof(STUDENTS), 1, fp) != 1)

			printf("д�ļ�����!\n");

	fclose(fp);

}





/*����*/

int input(STUDENTS stu[])

{
	int i, x;

	for (i = 0; i<1000; i++)

	{

		system("cls");

		printf("\n\n                 ¼��ѧ����Ϣ  (���%d��)\n", MAX);

		printf("-----------------------------\n");



		printf("\n                     ��%d��ѧ��", k + 1);

		printf("\n ������ѧ����ѧ��:");

		scanf("%d", &stu[k].num);

		printf("\n ������ѧ��������:");

		scanf("%s", stu[k].name);

		printf("\n ������ѧ�����Ա�:");

		scanf("%s", stu[k].sex);

		printf("\n ������ѧ��������:");

		scanf("%d", &stu[k].age);

		printf("\n ������ѧ���İ༶:");

		scanf("%s", stu[k].studentclass);

		printf("\n ������ѧ���������:");

		scanf("%d", &stu[k++].dorm);

		printf("\n �밴1�����ز˵���0����������");

		scanf("%d", &x);

		if (x)

			break;

	}



	return k;

}





/*ɾ��*/

void deletel(STUDENTS stu[])

{
	system("cls");

	char Stuname2[20];

	int i, j;

	printf("������ѧ��������");

	scanf("%s", Stuname2);

	printf("\n");

	for (i = 0; i<k; i++)

		if (strcmp(stu[i].name, Stuname2) == 0)

			for (j = 0; j<20; j++)

				stu[i].name[j] = stu[i + 1].name[j];
	k--;




	printf("ɾ���ɹ�\n");

	printf("��������ӻس��������˵�!");

	scanf("%d", &i);

	getchar();

}


/*��ѯ*/

void inquire(STUDENTS stu[])

{
	int i;

	int num;

	system("cls");

	printf("     \n\n��������Ҫ���ҵ�ѧ����ѧ��");

	scanf("%d", &num);

	for (i = 0; i<k; i++)

		if (num == stu[i].num)

			printf("\n\n\nѧ�ţ�%d,������%s,�Ա�%s,���䣺%d,�༶��%s,�����: %d\n", stu[i].num, stu[i].name,

				stu[i].sex, stu[i].age, stu[i].studentclass, stu[i].dorm);

	printf("��������ӻس��������˵�!");

	scanf("%d", &i);

	getchar();

}





/*�޸�*/

void change(STUDENTS stu[])

{
	int num, i, choice;

	system("cls");

	printf("\n\n\n      ��������Ҫ�޸ĵ�ѧ����ѧ��");

	scanf("%d", &num);

	for (i = 0; i<k; i++)

	{
		if (num == stu[i].num)

			printf("\nѧ�ţ�%d,������%s,�Ա�%s,���䣺%d,�༶��%s,�����: %d\n", stu[i].num, stu[i].name,

				stu[i].sex, stu[i].age, stu[i].studentclass, stu[i].dorm);



		printf("\n\n\n     ********����������Ҫ�޸ĵ�����********\n\n");

		printf("                1. ѧ��\n\n");

		printf("                2. ����\n\n");

		printf("                3. �Ա�\n\n");

		printf("                4. ����\n\n");

		printf("                5. �༶\n\n");

		printf("                6. �����\n\n");

		printf("                 ��ѡ��1-6��:");

		scanf("%d", &choice);

		switch (choice)

		{
		case 1: {

			printf("\n   ��������ĵ���ѧ��");

			scanf("%d", &stu[i].num);

			break;

		}

		case 2: {

			printf("\n   ��������ĵ�������");

			scanf("%s", stu[i].name);

			break;

		}

		case 3: {

			printf("\n   ��������ĵ����Ա�");

			scanf("%s", stu[i].sex);

			break;

		}

		case 4: {

			printf("\n   ��������ĵ�������");

			scanf("%d", &stu[i].age);

			break;

		}

		case 5: {

			printf("\n   ��������ĵ��°༶");

			scanf("%s", stu[i].studentclass);

			break;

		}

		case 6: {

			printf("\n   ��������ĵ�������");

			scanf("%d", &stu[i].dorm);

			break;

		}

		}



		printf("ѧ�ţ�%d,������%s,�Ա�%s,���䣺%d,�༶��%s,�����: %d\n", stu[i].num, stu[i].name,

			stu[i].sex, stu[i].age, stu[i].studentclass, stu[i].dorm);

		printf("��������ӻس��������˵�!");

		scanf("%d", &i);

		break;

	}

}

/*��ʼҳ��*/ 
void pagedis()

{

	printf(" \n\n\n                   **********************************\n");

	printf("                   *                                *\n");

	printf("                   *                                *\n");

	printf("                   *                                *\n");

	printf("                   *  ��ӭ����ѧ��������Ϣ����ϵͳ  *\n");

	printf("                   *                                *\n");

	printf("                   *                                *\n");

	printf("                   *                                *\n");

	printf("                   **********************************\n");



}

void check()

{

	char userName[5];
	char userPWD[5];

	int i, sum;



	for (i = 1; i < 4; i++)

	{

		printf("   �û����������Ϊ123\n\n");

		printf("\n       �����������û���:");

		gets(userName);



		printf("\n       ��������������:");

		gets(userPWD);



		if ((strcmp(userName, "123") == 0) && (strcmp(userPWD, "123") == 0))

		{

			printf("�û�����������ȷ����ʾ���˵�");

			return;

		}

		else

		{

			if (i < 3)

			{

				printf("�û��������������ʾ�û���������");

				printf("�û����������������������!");

			}

			else

			{

				printf("����3������û��������룬�˳�ϵͳ��");

				printf("��������3�ν��û������������ϵͳ���˳�!");

				exit(1);

			}

		}

	}

}

void menu()

{

	STUDENTS stu[20];

	int choice, k, sum;

	sum = read_file(stu);

	if (sum == 0)

	{
		printf("����¼����������Ϣ�����س������*****\n");

		getch();

		sum = input(stu);

	}



	do

	{
		system("cls");

		printf("\n\n\n               ********ѧ����Ϣ����ϵͳ********\n\n");

		printf("                      1. ����ѧ����Ϣ\n\n");

		printf("                      2. ��ѯѧ����Ϣ\n\n");

		printf("                      3. �޸�ѧ����Ϣ\n\n");

		printf("                      4. ɾ��ѧ����Ϣ\n\n");

		printf("                      0. �˳�ϵͳ\n\n");

		printf("                       ��ѡ��0-6��:");

		scanf("%d", &choice);

		switch (choice)

		{

		case 1: k = input(stu); break;/*����ѧ����Ϣ*/

		case 2: inquire(stu); break;/*��ѯѧ����Ϣ*/

		case 3: change(stu); break;/*�޸�ѧ����Ϣ*/

		case 4: deletel(stu); break;/*ɾ��ѧ����Ϣ*/

		case 0: break;

		}

	} while (choice != 0);

	save_file(stu, sum);

}

int main()

{





	int i, sum;

	pagedis();

	check();

	menu();
}


