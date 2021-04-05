#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqStack.h"


//基于数组的顺序栈
Status initStack(SqStack *s,int sizes);//初始化栈
Status isEmptyStack(SqStack *s);//判断栈是否为空
Status getTopStack(SqStack *s,ElemType *e); //得到栈顶元素
Status clearStack(SqStack *s);//清空栈
Status destroyStack(SqStack *s);//销毁栈
Status stackLength(SqStack *s,int *length);//检测栈长度
Status pushStack(SqStack *s,ElemType data);//入栈
Status popStack(SqStack *s,ElemType *data);//出栈


Status initStack(SqStack *s,int sizes)//初始化栈
{
	int a[sizes];
	s->size = sizes;
	s->elem=a;
	s->top = -1;
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)//判断栈是否为空
{
	if(s->top==-1)
		return ERROR;
	if(s->top!=-1)
		return SUCCESS;
}

Status stackLength(SqStack *s,int *length)//检测栈长度
{
	*length =s->top;
	return SUCCESS;
}

Status destroyStack(SqStack *s)//销毁栈
{
	s->top=-1;	
	return SUCCESS;
}

Status getTopStack(SqStack *s,ElemType *e) //得到栈顶元素
{
	*e=s->elem[s->top];
	return SUCCESS;
	
}

Status pushStack(SqStack *s,ElemType data)//入栈
{
	s->top ++;
    s->elem[s->top]=data; 
    return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data)//出栈
{
	if(isEmptyStack(s)) 
		s->top --;	
	else
		{
			printf("栈空!\n");
			return ERROR;
		}
	return SUCCESS;
}



