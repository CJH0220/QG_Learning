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

Status initLStack(LinkStack *s)//初始化栈
{
	s=(LinkStack*)malloc(sizeof(struct LinkStack));
	s->top=(StackNode *)malloc(sizeof(struct StackNode));
	s->top->next=NULL;
	s->count=0;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)//判断栈是否为空
{
	if(s->top!= NULL)
		return ERROR;
	if(s->top== NULL)
		return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)//入栈
{
	StackNode *tmp =(StackNode *)malloc(sizeof(StackNode));
	tmp->data =data;
	tmp->next=s->top;
	s->top=tmp;
	s->count++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)//出栈
{
	if(isEmptyLStack(s))
	{
		printf("请先初始化或者入栈元素！\n");
		return ERROR;
	}
	int tmp1;
	StackNode *stmp = s->top;
	tmp1 = s->top->data;
	s->top = stmp->next;
	s->count --;
	printf("出栈元素为：%d",tmp1);
	return SUCCESS; 
}

Status getTopLStack(LinkStack *s,ElemType *e)//得到栈顶元素
{
	int tmp2;
	tmp2 = s->top->data;
	printf("栈顶元素为：%d\n",tmp2);
	return SUCCESS; 
}


Status clearLStack(LinkStack *s)//清空栈
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

Status destroyLStack(LinkStack *s)//销毁栈
{
	
	if (NULL == s)
	{
		printf("已经被销毁了！\n");
		return ERROR;
	}
	s = NULL;
	return SUCCESS; 
}

Status LStackLength(LinkStack *s,int *length)//检测栈长度
{
	int len;
	 struct LinkStack *s2=s;
	len=s2->count;
	printf("检测栈的长度成功！长度为：%d \n",len);
	return SUCCESS; 	
}

void menu()/*选择菜单界面*/
{
    system("color 0e");//换背景和字体颜色
	printf("\t\t\t  ******************************************************\n\n");
	printf("\t\t\t  *********************链栈功能菜单*********************\n");
	printf("\t\t\t     ----------------------   ----------------------  \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 1.初始化链栈         2.入栈               *   \n");
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
		initLStack(s1);
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
		pushLStack(s1,num);
		printf("入栈成功！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("3",dengluma))
	{
		popLStack(s1,e1);
		printf("出栈完成！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("4",dengluma))
	{
		if(isEmptyLStack(s1))
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
		getTopLStack(s1,e1);
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("6",dengluma))
	{
		clearLStack(s1);
		printf("清空栈成功\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("7",dengluma))
	{
		LStackLength(s1,Len);
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("8",dengluma))
	{
		destroyLStack(s1); 
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
	s1=&LinkStack1;
	menu();
	sign();
}


