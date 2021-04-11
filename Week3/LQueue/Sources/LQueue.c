#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LQueue.h"


void InitLQueue(LQueue *Q)//初始化队列
{
	Node *P=(Node *)malloc(sizeof(Node));
	Q->front=P;
	Q->front->data=(void *)malloc(typeSize);
	Q->front->next=NULL;
	Q->rear=Q->front;
	Q->rear->data=(void *)malloc(typeSize);	
	Q->length=0;
}

void DestoryLQueue(LQueue *Q)//销毁队列
{
	Q->length=0;
	free(Q->front);
	if(Q->front!=Q->rear)
		free(Q->rear);
	printf("退出成功！\n");
	exit(1);
}

Status IsEmptyLQueue(const LQueue *Q)//检查队列是否为空
{
	if(Q->length==0)
		return FALSE;
	return TRUE;
}

Status GetHeadLQueue(LQueue *Q, void *e)//查看队头元素
{
	if (!IsEmptyLQueue(Q)) 
		return FALSE;
	memcpy(e,Q->front->data,typeSize);
        return TRUE;
}
int LengthLQueue(LQueue *Q) //确定队列长度
{
	return Q->length;	
}
Status EnLQueue(LQueue *Q, void *data)//入队操作
{
	if(Q->length==0)
	{
		memcpy(Q->front->data,data,typeSize);
		memcpy(Q->rear->data,data,typeSize);
		Q->length++;
		return TRUE;
	}
	
	
	Node *p=(Node *)malloc(sizeof(Node));
	Node *p1;	
	p1=Q->rear;
	
	p->data=(void *)malloc(typeSize);
	p->next=NULL;
	memcpy(p->data,data,typeSize);
	Q->front->next=p;
	Q->front=p;
	
	if(Q->length==1)
	{
		p1->next=p;	
		p1=p1->next;	
		memcpy(p1->data,data,typeSize);
		p1->next=0;
	}
	if(Q->length!=1)
	{
	while(p1->next!=NULL)
	{
		p1=p1->next;
	}
		p1->next=p;
		p1=p1->next;
		memcpy(p1->data,data,typeSize);
		p1->next=0;		
	}
	Q->length++;
	return TRUE; 
}

Status DeLQueue(LQueue *Q)//出队操作
{
	if(!IsEmptyLQueue(Q)) 
	{
		printf("队列是空的！\n");
		return FALSE;
	}
	Q->rear=Q->rear->next;
	Q->length--;
	return TRUE;
}

void ClearLQueue(LQueue *Q)//清空队列
{
	Q->front=Q->rear;
	free(Q->rear);
	Q->length=0; 
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))//遍历函数操作
{
	if(IsEmptyLQueue(Q)==0) 
	{
		printf("队列是空的！\n");
		return FALSE;
	}
	Node *p3;
	p3=Q->rear;
		foo(Q->rear->data);
		p3=p3->next;
	while(p3!=NULL)
	{	 
		foo(p3->data);
		p3=p3->next;
	}
	return TRUE;
}	

void LPrint(void *q)//操作函数
{
	if  (type == 'd')
             printf("--> %.2f", *(double*)q);
     else if (type == 'c')
             printf("--> %c", *(char*)q);
     else if (type == 'i')
             printf("--> %d ", *(int*)q);
     else if (type == 's')
             printf("--> %s ", (char *)q);
}

char * s_gets(char *st,int n);
void setType();
int getInt();
void menu();
void select(LQueue * Q);
void setVoid(LQueue * Q);

//打印菜单
void menu()
{
	puts("************************************************\n");
    puts("\t\t1.删除队列并退出系统");
    puts("\t\t2.判断队列是否为空");
    puts("\t\t3.判断队列是否已满");
    puts("\t\t4.输出头结点数据");
    puts("\t\t5.输出队列现存长度");
    puts("\t\t6.入队操作");
    puts("\t\t7.出队操作");
    puts("\t\t8.清空队列");
    puts("\t\t9.遍历队列并输入元素");
    puts("\t\t10.清空记录");
    puts("************************************************\n");
}

//选择操作
void select(LQueue * Q)
{
    int i =0;
    void *t;

    puts("请选择你的操作");
    switch(getInt())
    {
        case 1:DestoryLQueue(Q);
        		break;
        case 2:if (!IsEmptyLQueue(Q)) puts("队列为空");
                else puts("队列不为空");
                break;
        case 3:printf("该功能失效！\n");
                break;
        case 4:if (GetHeadLQueue(Q,t))
                {
                    printf("操作成功,头结点数据为");
                    LPrint(t);
                    printf("\n");
                }
                else puts("操作失败,队列为空");
                break;
        case 5:i = LengthLQueue(Q);printf("队列长度为%d\n",i);
                break;
        case 6:
                    setVoid(Q);
                    puts("操作成功");
                break;
        case 7:if (DeLQueue(Q)) puts("操作成功");
                else puts("操作失败，队列为空");
                break;
        case 8:ClearLQueue(Q);puts("已清空");break;
        case 9:if (TraverseLQueue(Q,LPrint)) puts("操作成功");
                else puts("操作失败");
                break;
        case 10:system("cls");menu();break;
        default :puts("输入错误");
    }
    select(Q);
}

//确定泛型
void setType()
{
    char t[3];
    s_gets(t,3);
    if (t[0] == 'a' && t[1] == '\0')
    {
        type = 'i';
        typeSize = sizeof(int);
    }
    else if (t[0] == 'b' && t[1] == '\0')
    {
        type = 'c';
        typeSize = sizeof(char);
    }
    else if (t[0] == 'c' && t[1] == '\0')
    {
        type = 'd';
        typeSize = sizeof(double);
    }
    else if (t[0] == 'd' && t[1] == '\0')
    {
        type = 's';
        typeSize = sizeof(char)*100;
    }
    else {
        puts("输入错误！请重新输入");
        setType();
    }

}

//获得int
int getInt()
{
    char in[11];
    int t;
    s_gets(in,11);
    t = atoi(in);
    if (t == 0) {
            if (in[1] != 0 || in[2] != '\0')
            {
                printf("输入错误，请重新输入！\n");
                t = getInt();
            }
    }
    return t;
}

//读取键盘输入
char * s_gets(char *st,int n)
{
    char * ret_val;
    char * find;

    fflush(stdin);
    ret_val = fgets(st,n,stdin);
    if (ret_val)
    {
        find = strchr(st,'\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                    continue;
    }
    return ret_val;
}

//入队数据操作
void setVoid(LQueue * Q)
{
    char c[100];

    if (type == 'i')
    {
        int a = 0;
        puts("请输入数据");
        a = getInt();
        EnLQueue(Q,&a);
    }
    else if (type == 'c')
    {
        puts("请输入数据");
        s_gets(c,3);
        if (c[2] != '\0')
        {
            puts("类型错误，请重新输入");
            s_gets(c,3);
        }
        EnLQueue(Q,&c[0]);
    }
    else if (type == 'd')
    {
        double d;
        puts("请输入数据");
        s_gets(c,100);

skip :  d = atof(c);
        if (d == 0 ) {
            int i = 0;
            while (c[i++] != '\0')
            {
                if (c[i] != '0' && c[i] != '.')
                {
                    puts("输入错误，请重新输入\n");
                    s_gets(c,100);
                    goto skip;
                }
            }
        }
        EnLQueue(Q,&d);
    }
    else if (type == 's')
    {
        puts("请输入数据");
        s_gets(c,100);
        EnLQueue(Q,&c);
    }
}

 int main()
{
    LQueue * Q;
    Q = (LQueue *)malloc(sizeof(LQueue));
    puts("欢迎使用泛型队列(链表)ADT测试系统");
    puts("队列要存取哪种数据类型:\n a.int型\t b.char型 \n c.double型\t d.string型 \n");
    setType();
    puts("选择测试操作。");
    InitLQueue(Q);
    menu();
    select(Q);
    return 1;
}



