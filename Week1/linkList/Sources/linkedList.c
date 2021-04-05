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

void YNemptylist(LinkedList *L)/*�ж��б�ͷ�Ƿ�Ϊ��*/ 
{
	if(((LinkedList)L)->next==NULL)
	{
		printf("��ǰ����Ϊ��,���ȳ�ʼ��������㣡");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
		exit(1); 
	}
}

void menu()/*ѡ��˵�����*/
{
    system("color 0e");//��������������ɫ
	printf("\t\t\t  ******************************************************\n\n");
	printf("\t\t\t  *********************�����ܲ˵�*********************\n");
	printf("\t\t\t     ----------------------   ----------------------  \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 1.��ʼ������         2.�����㣨β�壩   *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 3.�����������     4.��ת����           *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 5.������ż˳���     6.�ҳ��м�ڵ� ��    *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 7.ɾ����㲢ȡֵ��   8.����������ɻ�     *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 9.�ж������Ƿ�ɻ�   10.���������������  *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t     ----------------------   ----------------------  \n");
}

void sign()/*ѡ����*/ 
{
	printf("�����������ţ�"); 
	scanf("%s",dengluma);getchar();
	if(!strcmp("1",dengluma))
	{
		InitList(L1);
		printf("��ʼ���ɹ���\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("2",dengluma))
	{
		CreateList_Tail(L1);
		printf("������ɹ���\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("3",dengluma))
	{
		YNemptylist(L1); 
		TraverseList(L1, k);
		printf("�����ɣ�\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("4",dengluma))
	{
		YNemptylist(L1); 
		ReverseList(L1); 
		printf("��ת�ɹ���\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("5",dengluma))
	{
		YNemptylist(L1); 
		L1=ReverseEvenList(L1); 
		printf("��ż�Ի��ɹ���\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("6",dengluma))
	{
		YNemptylist(L1); 
		L2=FindMidNode(L1);
		printf("�ҵ��м�ڵ�����\n��������Ϊ��%d",((LinkedList)L2)->data);
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("7",dengluma))
	{
		YNemptylist(L1); 
		DeleteList(L1, e); /*ɾ����һ�����*/ 
		printf("ɾ�����ɹ���\n�䷵��ֵΪ��%d",*e);
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("8",dengluma))
	{
		YNemptylist(L1);
		L1=chenghuan(L1);
		printf("�ɻ����������ɹ���\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("9",dengluma))
	{
		YNemptylist(L1);
		IsLoopList(L1);
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("10",dengluma))
	{
		DestroyList(L1);
		printf("��������ɹ���\n");
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

void visit(ElemType e)/*�ݷú�������ӡ��*/
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
	while( NULL != tmp->next )//��������β�� 
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
Status InitList(LinkedList *L) /*��ʼ������*/ 
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
void DestroyList(LinkedList *L) /*��������*/ 
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
Status InsertList(LNode *p, LNode *q)  /*��������*/ 
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
Status DeleteList(LNode *p, ElemType *e) /*ɾ�����*/ 
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
void TraverseList(LinkedList L, void (*visit)(ElemType e))   /*��������*/ 
{
	LNode *p=L;
	p =((LinkedList)p)->next; 
	while (((LinkedList)p)!=NULL)
	{
		visit(((LinkedList)p)->data); /*����*/
		p =((LinkedList)p)->next; /*����*/
	} 
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e)   /*��ѯ��ֵ*/ 
{
	struct LNode *p=L;
	while(p!=NULL)
	{
		if(p->data==e)
		{	
			printf("�����ֵӴ���ߺ���\n");
			return SUCCESS;
			
		}
		p=p->next;
	}
	printf("û�����ֵ������ϧ��ϧ\n");
	return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list ��ת���� 
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
 *	@description : judge whether the linked list is looped �ж��Ƿ�ɻ� 
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) /*�ж��Ƿ�ɻ�*/
{
	if(L == NULL ||L->next == NULL)
	{
		printf("�����\n\n");
		return ERROR;
	}
	LNode *pf=L; /*��ָ��*/
	LNode *ps=L;/*��ָ��*/

	while(pf!=NULL&&ps->next!=NULL)
	{
		pf = pf->next->next;
		ps = ps->next;
		if(pf == ps)
		{
			printf("�Ǹ�������!\n");
			return SUCCESS;
		}
	} 
	printf("���Ǹ�������!\n");
	return ERROR;
}


/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L) ��ż�Ի� 
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L)
{
	LNode *p=L;
	LNode *p1=L,*p2=L;/*p1Ϊ����ָ�룬p2Ϊż��ָ��*/ 
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
LNode* FindMidNode(LinkedList *L) /*���м���*/ 
{
	LNode *p1=L,*p2=L;/*p1һ����һ����p2һ��������*/
	while(p2!=NULL||p2->next!=NULL)
	{
		p2=p2->next;
		p2=p2->next;
		p1=p1->next;
	}
	return p1;
}


LNode* CreateList_Tail(LNode* L)/*β�巨������*/ 
{
	ElemType x;
	LNode *s,*f=L;
	while(f->next!=NULL)
	{
		f=f->next;
	}
	LNode *r=f;
	printf("������������ֵ������-1ʱ���������������\n");
	scanf("%d",&x);
	while(x!=-1)
	{                             
		s=(LNode*)malloc(sizeof(LNode));     //�����µĽ�� 
		s->data=x;                           
		r->next=s;                      
		r=r->next;
		scanf("%d",&x);
	}
	r->next=NULL;
	printf("\n�����������\n");
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




