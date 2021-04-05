#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqStack.h"


//���������˳��ջ
Status initStack(SqStack *s,int sizes);//��ʼ��ջ
Status isEmptyStack(SqStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopStack(SqStack *s,ElemType *e); //�õ�ջ��Ԫ��
Status clearStack(SqStack *s);//���ջ
Status destroyStack(SqStack *s);//����ջ
Status stackLength(SqStack *s,int *length);//���ջ����
Status pushStack(SqStack *s,ElemType data);//��ջ
Status popStack(SqStack *s,ElemType *data);//��ջ


Status initStack(SqStack *s,int sizes)//��ʼ��ջ
{
	int a[sizes];
	s->size = sizes;
	s->elem=a;
	s->top = -1;
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)//�ж�ջ�Ƿ�Ϊ��
{
	if(s->top==-1)
		return ERROR;
	if(s->top!=-1)
		return SUCCESS;
}

Status stackLength(SqStack *s,int *length)//���ջ����
{
	*length =s->top;
	return SUCCESS;
}

Status destroyStack(SqStack *s)//����ջ
{
	s->top=-1;	
	return SUCCESS;
}

Status getTopStack(SqStack *s,ElemType *e) //�õ�ջ��Ԫ��
{
	*e=s->elem[s->top];
	return SUCCESS;
	
}

Status pushStack(SqStack *s,ElemType data)//��ջ
{
	s->top ++;
    s->elem[s->top]=data; 
    return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data)//��ջ
{
	if(isEmptyStack(s)) 
		s->top --;	
	else
		{
			printf("ջ��!\n");
			return ERROR;
		}
	return SUCCESS;
}



