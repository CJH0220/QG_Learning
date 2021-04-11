#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AQueue.h"


void InitAQueue(AQueue *Q)//初始化队列
{
	int i;
	for(i = 0; i < MAXQUEUE; i++)
        Q->data[i] = (void *)malloc(typeSize);
	Q->front=0;
	Q->rear=0;
	Q->length=0;
}

void DestoryAQueue(AQueue *Q)//销毁队列
{
	int i = 0;
 	while (Q->length--)
         free(Q->data[i++]);
    printf("退出成功！\n");
	exit(1);
}

Status IsFullAQueue(const AQueue *Q)//检查队列是否已满
{
	if (Q->length == MAXQUEUE)
         return TRUE;
     return FALSE;

}

Status IsEmptyAQueue(const AQueue *Q)//检查队列是否为空
{
	if(Q->length == 0)
		return FALSE;
	return TRUE;
}

Status GetHeadAQueue(AQueue *Q, void *e)//查看队头元素
{
	if (IsEmptyAQueue(Q)) 
		return FALSE;
     memcpy(e,Q->data[0],typeSize);
        return TRUE;
}

int LengthAQueue(AQueue *Q)//确定队列长度	
{
	return Q->length;
}

Status EnAQueue(AQueue *Q, void *data)//入队操作
{
	 if (IsFullAQueue(Q)==1)
 	{
 		printf("插插插！队列满了你还插\n");
 		return FALSE;
 	}
	memcpy(Q->data[Q->rear],data,typeSize);
	Q->rear = (Q->rear +1) % MAXQUEUE; 
	Q->length++;
	return TRUE;
}

Status DeAQueue(AQueue *Q)//出队操作
{
	if(IsEmptyAQueue(Q)==0)
	{
		printf("队列是空的！\n");
		return FALSE;
	}
	Q->front = (Q->front +1 )%MAXQUEUE;
	Q->length--;
	return TRUE;
}

void ClearAQueue(AQueue *Q)//清空队列
{
	Q->front = 0;
	Q->rear = 0;
	Q->length = 0;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))//遍历函数操作
{
	
	int i,j;
	if (IsEmptyAQueue(Q)==0)
     {
         puts("队列为空！");
         return FALSE;
     }
	for (i = Q->front,j = Q->length;j > 0;j--)
	{
		foo(Q->data[i]) ;
		i = (i+1)%MAXQUEUE; 	 
	} 
		return TRUE;
}

void APrint(void *q)//操作函数（打印） 
 {
      if  (type == 'd')
             printf("--> %.2lf", *(double*)q);
     else if (type == 'c')
             printf("--> %c", *(char*)q);
     else if (type == 'i')
             printf("--> %d ", *(int*)q);
     else if (type == 's')
             printf("--> %s ", (char *)q);
     else if (type == '*')
             printf("--> %p ", *(char *)q);
 }
 
char * s_gets(char *st,int n);
void setType();
int getInt();
void menu();
void select(AQueue * Q);
void setVoid(AQueue * Q);

//选择操作
void select(AQueue * Q)
{
    int i =0;
    void *t;

    puts("请选择你的操作");
    switch(getInt())
    {
        case 1:DestoryAQueue(Q);
        case 2:if (IsEmptyAQueue(Q)) puts("队列为空");
                else puts("队列不为空");
                break;
        case 3:if (IsFullAQueue(Q)) puts("队列已满");
                else puts("队列未满");
                break;
        case 4:if (GetHeadAQueue(Q,t))
                {
                    printf("操作成功,头结点数据为");
                    APrint(t);
                    printf("\n");
                }
                else puts("操作失败,队列为空");
                break;
        case 5:i = LengthAQueue(Q);printf("队列长度为%d\n",i);
                break;
        case 6:if (IsFullAQueue(Q)) puts("操作失败,队列已满");
                else {
                    setVoid(Q);
                    puts("操作成功");
                }
                break;
        case 7:if (DeAQueue(Q)) puts("操作成功");
                else puts("操作失败，队列为空");
                break;
        case 8:ClearAQueue(Q);puts("已清空");break;
        case 9:if (TraverseAQueue(Q,APrint)) puts("操作成功");
                else puts("操作失败");
                break;
        case 10:system("cls");menu();break;
        default :puts("输入错误");
    }
    select(Q);

}

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
    else if (t[0] == 'e' && t[1] == '\0')
    {
        type = '*';
        typeSize = sizeof(char *);
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
void setVoid(AQueue * Q)
{
    char c[100];

    if (type == 'i')
    {
        int a = 0;
    
        puts("请输入数据");
        a = getInt();
        EnAQueue(Q,&a);
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
        EnAQueue(Q,&c[0]);
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
        EnAQueue(Q,&d);
    }
    else if (type == 's')
    {
        puts("请输入数据");
        s_gets(c,100);
        EnAQueue(Q,&c);
    }
    else if (type == '*')
    {
        EnAQueue(Q,&c[Q->length]);

    }

}


int main()
{
    AQueue * Q;
    Q = (AQueue *)malloc(sizeof(AQueue));
    puts("欢迎使用泛型队列(循环)ADT测试系统");
    puts("队列要存取哪种数据类型:\n a.int型\t b.char型 \n c.double型\t d.string型 \n e.指针类(系统将简单创建测试用例)");
    setType();
    puts("选择测试操作。");
    InitAQueue(Q);
    menu();
    select(Q);
    return 1;
}


