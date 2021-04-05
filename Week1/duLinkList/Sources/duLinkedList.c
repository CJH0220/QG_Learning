#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duLinkedList.h"

struct DuLinkedList *L1,*L2;
struct DuLNode list1,list2;
char dengluma[20]="0";

void visit(ElemType e)/*拜访函数（打印）*/
{
	printf("%d\n",e);
}

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
 
Status InitList_DuL(DuLinkedList *L) 
{
	L=(DuLNode*)malloc(sizeof(DuLNode));
	if(L!=NULL)
	{
	((DuLinkedList)L)->data = 0;
	((DuLinkedList)L)->prior = NULL;
	((DuLinkedList)L)->next = NULL;
	}
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) 
{	
	DuLinkedList p;
	while(((DuLinkedList)L)->next)
	{
		p=((DuLinkedList)L)->next;
		((DuLinkedList)L)->next = p->next;
		free(p);
	}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) 
{
	if(p==NULL||q==NULL)
	{
		print("This is wrong!!\n");
		return ERROR;
	}
		while(p->prior!=NULL)
	{ 
		p=p->prior;
	}
	q->next=p;
	p->prior=q;
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) 
{
	if(p==NULL||q==NULL)
	{
		print("This is wrong!!\n");
		return ERROR;
	}
		while(p->next!=NULL)
	{ 
		p=p->next;
	}
	p->next=q;
	q->prior=p;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
	DuLNode *p1,*p2;
	p1 =(DuLNode *)malloc(sizeof(DuLNode));
	p2 =(DuLNode*)malloc(sizeof(DuLNode));
	if(p==NULL)
	{
		print("This is wrong!!\n");
		return ERROR;
	}
	p1 = p->next;
	*e = p1->data;
	p2 = p1->next;
	p->next =p2 ;
	p2->prior =p;
	free(p1);
	free(p2);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) 
{
	DuLNode *p=L;
	p =((DuLinkedList)p)->next; 
	while (p->next = NULL)
	{
		visit(p->data); /*访问*/
		p = p ->next; /*遍历*/
	}
}
DuLNode* CreateList_Tail(DuLNode* L)/*尾插法插入结点*/ 
{
	ElemType x;
	DuLNode *s,*f=L;
	while(f->next!=NULL)
	{
		f=f->next;
	}
	DuLNode *r=f;
	printf("双链表输入数值，输入-1时结束单链表的输入\n");
	scanf("%d",&x);
	while(x!=-1)
	{                             
		s=(DuLNode*)malloc(sizeof(DuLNode));     //创建新的结点 
		s->data=x;                           
		r->next=s;                      
		r=r->next;
		r->prior=s; 
		scanf("%d",&x);
	}
	r->next=NULL;
	
	printf("\n输入结束！！\n");
	getchar();
	return L;
}

int main()
{
	printf("输入第一个双链表");
	return 0;
} 
