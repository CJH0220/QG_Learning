#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqStack.h"
#define MAXSIZE 100 

char dengluma[20];
struct  SqStack *s1;
struct SqStack  SqStack1; 
ElemType num=0;
ElemType *e1;
int *Len; 

//���������˳��ջ


Status clearStack(SqStack *s)//���ջ
{
	s->top=-1;
}

Status initStack(SqStack *s,int sizes)//��ʼ��ջ
{
	s->top = -1;
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)//�ж�ջ�Ƿ�Ϊ��
{
	if(s->top!=-1)
		return ERROR;
	if(s->top==-1)
		return SUCCESS;
}

Status stackLength(SqStack *s,int *length)//���ջ����
{
	int len;
	len =s->top;
	if(s->top == -1 )
	{
		printf("��ջ\n"); 
		return ERROR;
	}
	printf("ջ�ĳ���:%d\n",len+1);
	return SUCCESS;
}

Status destroyStack(SqStack *s)//����ջ
{
	s->top=-1;	
	return SUCCESS;
}

Status getTopStack(SqStack *s,ElemType *e) //�õ�ջ��Ԫ��
{
	int e2;
	if(s->top == 0)
	{
		printf("��ջ\n");
		return ERROR;
	}
	e2 = s->arry[s->top];
	printf("ջ��Ԫ��Ϊ%d\n",e2); 
	return SUCCESS;
	
}

Status pushStack(SqStack *s,ElemType data)//��ջ
{
	if(s->top ==MAXSIZE-1)
	{
		printf("ջ��");
		return ERROR;
	}
	s->top++;
	s->arry[s->top]=data;	 	//e��Ϊ��ջ�� 
    return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data)//��ջ
{
	if(s->top == -1 )
	{
		printf("��ջ\n"); 
		return ERROR;
	}
	int data1;
	data1 = s->arry[s->top];
	printf("��ջ��Ԫ��Ϊ%d\n",data1);			 
	s->top--;
	return SUCCESS;
}

void menu()/*ѡ��˵�����*/
{
    system("color 0e");//��������������ɫ
	printf("\t\t\t  ******************************************************\n\n");
	printf("\t\t\t  *******************˳��ջ���ܲ˵�*********************\n");
	printf("\t\t\t     ----------------------   ----------------------  \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 1.��ʼ��ջ           2.��ջ               *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 3.��ջ               4.�ж�ջ�Ƿ�Ϊ��     *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 5.�õ�ջ��Ԫ��       6.���ջ             *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 7.���ջ�ĳ���       8.����ջ             *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 9.����ջ�������     10.��������          *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t     ----------------------   ----------------------  \n");
}

void sign()/*ѡ����*/ 
{
	printf("�����������ţ�"); 
	scanf("%s",dengluma);getchar();
	if(!strcmp("1",dengluma))
	{
		initStack(s1,100);
		printf("��ʼ����ջ�ɹ���\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("2",dengluma))
	{
		printf("������������Ҫ��ջ��Ԫ��ֵ:");
		scanf("%d",&num);	
		getchar();
		pushStack(s1,num);
		printf("��ջ�ɹ���\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("3",dengluma))
	{
		popStack(s1,e1);
		printf("��ջ��ɣ�\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("4",dengluma))
	{
		if(isEmptyStack(s1))
			printf("\n�ǿյ�ջ��\n");
		else
			printf("\n�е㶫���ģ�\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("5",dengluma))
	{
		getTopStack(s1,e1);
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("6",dengluma))
	{
		clearStack(s1);
		printf("���ջ�ɹ�\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("7",dengluma))
	{
		stackLength(s1,Len);
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("8",dengluma))
	{
		destroyStack(s1); 
		printf("����ջ�ɹ�\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("9",dengluma))
	{
		printf("��˵�� �����ˣ��㻹��\n");
		printf("�û����������:");//����ջ����� 
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("10",dengluma))
	{
		printf("��лʹ��!\n"); 
		printf("�û����������:");
		getchar();
		exit(1);
	}
	if(!(dengluma=="1"||dengluma=="2"||dengluma=="3"||dengluma=="4"
	||dengluma=="5"||dengluma=="6"||dengluma=="7"||dengluma=="8"
	||dengluma=="9"||dengluma=="10"))
		{
			printf("�����������,����������\n");
			printf("�û����������:");
			getchar();
			system("cls");
			menu();
			sign();
			exit(1);
		}
}

int main()
{
	s1=&SqStack1;
	menu();
	sign();
	return 0;
} 

