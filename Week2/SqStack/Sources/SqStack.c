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

//基于数组的顺序栈


Status clearStack(SqStack *s)//清空栈
{
	s->top=-1;
}

Status initStack(SqStack *s,int sizes)//初始化栈
{
	s->top = -1;
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)//判断栈是否为空
{
	if(s->top!=-1)
		return ERROR;
	if(s->top==-1)
		return SUCCESS;
}

Status stackLength(SqStack *s,int *length)//检测栈长度
{
	int len;
	len =s->top;
	if(s->top == -1 )
	{
		printf("空栈\n"); 
		return ERROR;
	}
	printf("栈的长度:%d\n",len+1);
	return SUCCESS;
}

Status destroyStack(SqStack *s)//销毁栈
{
	s->top=-1;	
	return SUCCESS;
}

Status getTopStack(SqStack *s,ElemType *e) //得到栈顶元素
{
	int e2;
	if(s->top == 0)
	{
		printf("空栈\n");
		return ERROR;
	}
	e2 = s->arry[s->top];
	printf("栈顶元素为%d\n",e2); 
	return SUCCESS;
	
}

Status pushStack(SqStack *s,ElemType data)//入栈
{
	if(s->top ==MAXSIZE-1)
	{
		printf("栈满");
		return ERROR;
	}
	s->top++;
	s->arry[s->top]=data;	 	//e成为新栈顶 
    return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data)//出栈
{
	if(s->top == -1 )
	{
		printf("空栈\n"); 
		return ERROR;
	}
	int data1;
	data1 = s->arry[s->top];
	printf("出栈的元素为%d\n",data1);			 
	s->top--;
	return SUCCESS;
}

void menu()/*选择菜单界面*/
{
    system("color 0e");//换背景和字体颜色
	printf("\t\t\t  ******************************************************\n\n");
	printf("\t\t\t  *******************顺序栈功能菜单*********************\n");
	printf("\t\t\t     ----------------------   ----------------------  \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 1.初始化栈           2.入栈               *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 3.出栈               4.判断栈是否为空     *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 5.得到栈顶元素       6.清空栈             *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 7.检测栈的长度       8.销毁栈             *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 9.遍历栈并输出×     10.结束程序          *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t     ----------------------   ----------------------  \n");
}

void sign()/*选择栏*/ 
{
	printf("请输入操作序号："); 
	scanf("%s",dengluma);getchar();
	if(!strcmp("1",dengluma))
	{
		initStack(s1,100);
		printf("初始化链栈成功！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("2",dengluma))
	{
		printf("请输入你所需要入栈的元素值:");
		scanf("%d",&num);	
		getchar();
		pushStack(s1,num);
		printf("入栈成功！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("3",dengluma))
	{
		popStack(s1,e1);
		printf("出栈完成！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("4",dengluma))
	{
		if(isEmptyStack(s1))
			printf("\n是空的栈！\n");
		else
			printf("\n有点东西的！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("5",dengluma))
	{
		getTopStack(s1,e1);
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("6",dengluma))
	{
		clearStack(s1);
		printf("清空栈成功\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("7",dengluma))
	{
		stackLength(s1,Len);
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("8",dengluma))
	{
		destroyStack(s1); 
		printf("销毁栈成功\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("9",dengluma))
	{
		printf("都说有 ×号了，你还点\n");
		printf("敲击任意键返回:");//遍历栈并输出 
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("10",dengluma))
	{
		printf("感谢使用!\n"); 
		printf("敲击任意键返回:");
		getchar();
		exit(1);
	}
	if(!(dengluma=="1"||dengluma=="2"||dengluma=="3"||dengluma=="4"
	||dengluma=="5"||dengluma=="6"||dengluma=="7"||dengluma=="8"
	||dengluma=="9"||dengluma=="10"))
		{
			printf("输入序号有误,请重新输入\n");
			printf("敲击任意键返回:");
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

