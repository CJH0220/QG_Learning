#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"


char dengluma[20];
struct LinkedList *L1,*L2;
struct LNode list1;
ElemType (*k) (ElemType);
ElemType num=0;
ElemType *e; 

void YNemptylist(LinkedList *L)/*判断列表头是否为空*/ 
{
	if(((LinkedList)L)->next==NULL)
	{
		printf("当前链表为空,请先初始化或插入结点！");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
		exit(1); 
	}
}

void menu()/*选择菜单界面*/
{
    system("color 0e");//换背景和字体颜色
	printf("\t\t\t  ******************************************************\n\n");
	printf("\t\t\t  *********************链表功能菜单*********************\n");
	printf("\t\t\t     ----------------------   ----------------------  \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 1.初始化链表         2.插入结点（尾插）   *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 3.遍历链表并输出     4.反转链表           *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 5.调换奇偶顺序×     6.找出中间节点 ×    *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 7.删除结点并取值×   8.将现有链表成环     *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 9.判断链表是否成环   10.销毁链表结束程序  *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t     ----------------------   ----------------------  \n");
}

void sign()/*选择栏*/ 
{
	printf("请输入操作序号："); 
	scanf("%s",dengluma);getchar();
	if(!strcmp("1",dengluma))
	{
		InitList(L1);
		printf("初始化成功！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("2",dengluma))
	{
		CreateList_Tail(L1);
		printf("插入结点成功！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("3",dengluma))
	{
		YNemptylist(L1); 
		TraverseList(L1, k);
		printf("输出完成！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("4",dengluma))
	{
		YNemptylist(L1); 
		ReverseList(L1); 
		printf("反转成功！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("5",dengluma))
	{
		YNemptylist(L1); 
		L1=ReverseEvenList(L1); 
		printf("奇偶对换成功！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("6",dengluma))
	{
		YNemptylist(L1); 
		L2=FindMidNode(L1);
		printf("找到中间节点啦！\n它的数据为：%d",((LinkedList)L2)->data);
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("7",dengluma))
	{
		YNemptylist(L1); 
		DeleteList(L1, e); /*删除第一个结点*/ 
		printf("删除结点成功！\n其返回值为：%d",*e);
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("8",dengluma))
	{
		YNemptylist(L1);
		L1=chenghuan(L1);
		printf("成环啦！！！成功！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("9",dengluma))
	{
		YNemptylist(L1);
		IsLoopList(L1);
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("10",dengluma))
	{
		DestroyList(L1);
		printf("销毁链表成功！\n");
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

void visit(ElemType e)/*拜访函数（打印）*/
{
	printf("%d\n",e);
}

LNode* chenghuan(LinkedList *L)
{
	LNode *p = L;
	while(((LinkedList)L)->next!=NULL)
	{
		L=((LinkedList)L)->next;
	}
	((LinkedList)L)->next=p;
	L=((LinkedList)L)->next;
	return L;
}

int add_node_tail(LNode* head, LNode* new_node)
{
	if(NULL == head || NULL == new_node)
		return -1;
	LNode* tmp = head;
	while( NULL != tmp->next )//遍历链表到尾部 
	{
		tmp = tmp->next;
	}
	tmp->next = new_node;
	new_node->next = NULL; 
	return 0;
}

/**
 *  @name        : Status InitList(LinkedList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) /*初始化链表*/ 
{	
	L=(LNode*)malloc(sizeof(LNode));
	((LinkedList)L)->data = 0; 
	((LinkedList)L)->next = NULL;
	return SUCCESS;
}
 
/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) /*销毁链表*/ 
{	
	
	LinkedList p;
	while(((LinkedList)L)->next)
	{
		p=((LinkedList)L)->next;
		((LinkedList)L)->next = p->next;
		free(p);
	}

}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q)  /*连接链表*/ 
{
	if(p==NULL||q==NULL)
	{
		printf("This is wrong!!\n");
		return ERROR;
	}
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next =q->next;
	return SUCCESS;
	
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) /*删除结点*/ 
{
	LNode *p1=p;
	p1=p1->next;
	if(p==NULL)
	{
		printf("This is wrong!!\n");
		return ERROR;
	}
	p=p->next;
	*e =p1->data;
	p->next=p1->next;
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e))   /*遍历链表*/ 
{
	LNode *p=L;
	p =((LinkedList)p)->next; 
	while (((LinkedList)p)!=NULL)
	{
		visit(((LinkedList)p)->data); /*访问*/
		p =((LinkedList)p)->next; /*遍历*/
	} 
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e)   /*查询数值*/ 
{
	struct LNode *p=L;
	while(p!=NULL)
	{
		if(p->data==e)
		{	
			printf("有这个值哟！芜湖！\n");
			return SUCCESS;
			
		}
		p=p->next;
	}
	printf("没有这个值啊，可惜可惜\n");
	return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list 反转链表 
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) 
{
	if(L==NULL||((LinkedList)L)->next==NULL)
		return ERROR;
	LNode *p1=((LinkedList)L)->next;
	LNode *p2=p1->next;
	LNode *p3; 
	p1->next=NULL;
	if(p2 == NULL || p1 == NULL)
        return ERROR;
    while(p2!=NULL)
	{
		p3=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p3;
    }
    ((LinkedList)L)->next=p1;
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped 判断是否成环 
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) /*判断是否成环*/
{
	if(L == NULL ||L->next == NULL)
	{
		printf("表错误\n\n");
		return ERROR;
	}
	LNode *pf=L; /*快指针*/
	LNode *ps=L;/*慢指针*/

	while(pf!=NULL&&ps->next!=NULL)
	{
		pf = pf->next->next;
		ps = ps->next;
		if(pf == ps)
		{
			printf("是个环链表!\n");
			return SUCCESS;
		}
	} 
	printf("不是个环链表!\n");
	return ERROR;
}


/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L) 奇偶对换 
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L)
{
	LNode *p=L;
	LNode *p1=L,*p2=L;/*p1为奇数指针，p2为偶数指针*/ 
	p2=p2->next;
	ElemType count_01=0;
	while(p2->next!=NULL&&p2!=NULL)
	{
		count_01=p1->data;
		p1->data=p2->data;
		p2->data=count_01;
		
		p->data=p1->data;
		p=p->next;
		p->data=p2->data;
		p=p->next;
		
		p1=p1->next->next;
		p2=p2->next->next; 
	}
	return p;
}



/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) /*找中间结点*/ 
{
	LNode *p1=L,*p2=L;/*p1一次走一步，p2一次走两步*/
	while(p2!=NULL||p2->next!=NULL)
	{
		p2=p2->next;
		p2=p2->next;
		p1=p1->next;
	}
	return p1;
}


LNode* CreateList_Tail(LNode* L)/*尾插法插入结点*/ 
{
	ElemType x;
	LNode *s,*f=L;
	while(f->next!=NULL)
	{
		f=f->next;
	}
	LNode *r=f;
	printf("单链表输入数值，输入-1时结束单链表的输入\n");
	scanf("%d",&x);
	while(x!=-1)
	{                             
		s=(LNode*)malloc(sizeof(LNode));     //创建新的结点 
		s->data=x;                           
		r->next=s;                      
		r=r->next;
		scanf("%d",&x);
	}
	r->next=NULL;
	printf("\n输入结束！！\n");
	getchar();
	return L;
}

int main()
{
	k=visit;
	L1=&list1;
	menu();
	sign();	
	return 1;	
}




