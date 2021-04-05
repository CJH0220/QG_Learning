#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

char dengluma[20];
struct  LinkStack *s1;
struct StackNode StackNode1;
struct  LinkStack LinkStack1;
ElemType num=0;
ElemType *e1;
int *Len; 

Status initLStack(LinkStack *s)//��ʼ��ջ
{
	s=(LinkStack*)malloc(sizeof(struct LinkStack));
	s->top=(StackNode *)malloc(sizeof(struct StackNode));
	s->top->next=NULL;
	s->count=0;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ��
{
	if(s->top!= NULL)
		return ERROR;
	if(s->top== NULL)
		return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)//��ջ
{
	StackNode *tmp =(StackNode *)malloc(sizeof(StackNode));
	tmp->data =data;
	tmp->next=s->top;
	s->top=tmp;
	s->count++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)//��ջ
{
	if(isEmptyLStack(s))
	{
		printf("���ȳ�ʼ��������ջԪ�أ�\n");
		return ERROR;
	}
	int tmp1;
	StackNode *stmp = s->top;
	tmp1 = s->top->data;
	s->top = stmp->next;
	s->count --;
	printf("��ջԪ��Ϊ��%d",tmp1);
	return SUCCESS; 
}

Status getTopLStack(LinkStack *s,ElemType *e)//�õ�ջ��Ԫ��
{
	int tmp2;
	tmp2 = s->top->data;
	printf("ջ��Ԫ��Ϊ��%d\n",tmp2);
	return SUCCESS; 
}


Status clearLStack(LinkStack *s)//���ջ
{
	struct StackNode* pNew =NULL;
	while (s->count!=0)
	{
		pNew =s->top;
		s->top =s->top->next;
		s->count -- ;
		free(pNew);
	} 
	return SUCCESS;
}

Status destroyLStack(LinkStack *s)//����ջ
{
	
	if (NULL == s)
	{
		printf("�Ѿ��������ˣ�\n");
		return ERROR;
	}
	s = NULL;
	return SUCCESS; 
}

Status LStackLength(LinkStack *s,int *length)//���ջ����
{
	int len;
	 struct LinkStack *s2=s;
	len=s2->count;
	printf("���ջ�ĳ��ȳɹ�������Ϊ��%d \n",len);
	return SUCCESS; 	
}

void menu()/*ѡ��˵�����*/
{
    system("color 0e");//��������������ɫ
	printf("\t\t\t  ******************************************************\n\n");
	printf("\t\t\t  *********************��ջ���ܲ˵�*********************\n");
	printf("\t\t\t     ----------------------   ----------------------  \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 1.��ʼ����ջ         2.��ջ               *   \n");
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
		initLStack(s1);
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
		pushLStack(s1,num);
		printf("��ջ�ɹ���\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("3",dengluma))
	{
		popLStack(s1,e1);
		printf("��ջ��ɣ�\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("4",dengluma))
	{
		if(isEmptyLStack(s1))
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
		getTopLStack(s1,e1);
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("6",dengluma))
	{
		clearLStack(s1);
		printf("���ջ�ɹ�\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("7",dengluma))
	{
		LStackLength(s1,Len);
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("8",dengluma))
	{
		destroyLStack(s1); 
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
	s1=&LinkStack1;
	menu();
	sign();
}


