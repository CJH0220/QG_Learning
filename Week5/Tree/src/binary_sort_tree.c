#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_sort_tree.h"

BinarySortTreePtr s1;//��ָ�� 
BinarySortTree sa;//�� 
NodePtr h1;//Ҷָ�� 
StackNode LB1; //����
StackNode *L1;
LinkStack *Z;//��ջ 
ElemType x1,x2,x3,x4;//��ֵ
ElemType *data;
//LQueue Q1;//���� 
//LQueue *Q;
ElemType YN,XS;//�ж� 
int ii=1;
char dengluma[20];//��½�� 

/*
void InitLQueue(LQueue *Q) //��ʼ������
{
	StackNode *P =(StackNode *)malloc(sizeof(StackNode));
	Q->front=P;
	Q->front->next=NULL;
	Q->rear=Q->front;
	Q->length=0;
}

void DestoryLQueue(LQueue *Q)//���ٶ���
{
	Q->length=0;
	free(Q->front);
	if(Q->front!=Q->rear)
		free(Q->rear);
}

Status IsEmptyLQueue(const LQueue *Q)//�������Ƿ�Ϊ��
{
	if(Q->length==0)
		return ERROR;
	return SUCCESS;
}

ElemType GetHeadLQueue(LQueue *Q)//�õ���ͷԪ�� 
{
	if(!IsEmptyLQueue(Q)) 
	{
		return 0;
	}
	return Q->rear->data;
}

Status EnLQueue(LQueue *Q, ElemType data)//��Ӳ���
{
	if(Q->length==0)
	{
		Q->front->data=data;
		Q->rear->data=data;
		Q->length++;
		return SUCCESS;
	}
	StackNode *p=(StackNode *)malloc(sizeof(StackNode));
	StackNode *p1;	
	p1=Q->rear;
	p->next=NULL;
	p->data=data;
	Q->front->next=p;
	Q->front=Q->front->next;
	if(Q->length==1)
	{
		p1->next=p;	
		p1=p1->next;	
		p1->data=data;
		p1->next=NULL;
	}
	if(Q->length!=1)
	{
	while(p1->next!=NULL)
	{
		p1=p1->next;
	}
		p1->next=p;
		p1=p1->next;
		p1->data=data;
		p1->next=NULL;		
	}
	Q->length++;
	return SUCCESS; 
}

Status DeLQueue(LQueue *Q)//���Ӳ���
{
	if(!IsEmptyLQueue(Q)) 
	{
		return ERROR;
	}
	printf("%d ",Q->rear->data);
	Q->rear=Q->rear->next;
	Q->length--;
	return SUCCESS;
}
*/
//ջ 
Status initLStack(LinkStack *s)//��ʼ��ջ
{
	s=(LinkStack *)malloc(sizeof(struct LinkStack));
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



Status pushLStack(LinkStack *s,Node *root)//��ջ
{
	StackNode *tmp =(StackNode *)malloc(sizeof(StackNode));
	tmp->Root =root;
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
	ElemType tmp1;
	StackNode *stmp = s->top;
	tmp1 = s->top->Root->value;
	s->top = stmp->next;
	s->count --;
	printf("%d ",tmp1);
	return SUCCESS; 
}





Status BST_init(BinarySortTreePtr s)//��ʼ����
{
	
	int n;//�����������
	int i=0;//ѭ������ 
	int x;//��ʱ������ֵ 
	printf("����������Ҫ�������ֵ������n����ʱֻ֧��������\n n��");
	scanf("%d",&n);
	printf("������������������Ľ�����ֵ���ûس����������������룩��\n");
	for(i=0;i<n;i++)
	{
		printf("��%d����㣺",i+1);
		scanf("%d",&x);
		s->root =  CreateTree(s->root,x);
	}
	return SUCCESS;
} 

NodePtr CreateTree(NodePtr root,ElemType x)//ѭ������ 
{
	if(!root)  //���root���Ϊ�գ�����Ҷ�ӽ��
	{
		root = (NodePtr)malloc(sizeof(Node));
		root->value = x;
		root->left=root->right=NULL;
	}else
	{
		if(root->value==x)
			{
				printf("��ֵ�Ѵ��ڻ�����ظ�����ֵ!\n");
				return root;
			}
		if(root->value>x) 
			root->left = CreateTree(root->left,x);  //�ݹ������
		else if(root->value<x)
			root->right = CreateTree(root->right,x);//�ݹ������
	}
	return root;
}

Status BST_insert(BinarySortTreePtr s, ElemType data)//����ֵ
{
	s->root =  CreateTree(s->root,data);
	return SUCCESS;
} 

Status BST_delete(BinarySortTreePtr s, ElemType x)//ɾ��ֵ 
{
	Delete(s->root,x);
	return SUCCESS;
} 



NodePtr Delete(NodePtr BST,ElemType x)//ɾ�� 
{
	NodePtr p;
	if (BST == NULL) //�����Ϊ��ֱ�ӷ���
		return NULL;
	else if (x < BST->value) //С�����������ݹ�ɾ��
		BST->left = Delete(BST->left, x);
	else if (x > BST->value) //�������������ݹ�ɾ��
		BST->right = Delete(BST->right, x);
	else //�������ҵ���Ҫɾ���Ľ��
	{
		//�����ɾ���Ľ���������������ӽ��
		if (BST->left && BST->right)
		{
			//�ҵ�����������СԪ��
			p = FindMin(BST->right);
			//�����ɾ���Ľ��
			BST->value= p->value;
			//�ڱ�ɾ��������������ɾ���ղ��ҵ�������������СԪ��
			BST->right = Delete(BST->right, p->value);
		}
		//�����ɾ�����ֻ��һ�����ӽ���û�к��ӽ��
		else
		{
			p = BST;
			if (BST->left == NULL) //���Һ��ӽ���û�к��ӽ��
				BST = BST->right;
			else if (BST->right == NULL) //�����ӽ���û�к��ӽ��
				BST = BST->left;
			free(p); //�ͷŽ��
		}
	}
	return BST;
}

NodePtr FindMin(NodePtr BST)//����С 
{
	if(BST == NULL) //��Ϊ��ֱ�ӷŻ�
		return NULL;
	else if(BST->left == NULL) //�ҵ�����Ҷ�ӽ�㲢����
		return BST;
	else
		return FindMin(BST->left); //�����֧�����ݹ����
}

Status XXBLtofind(NodePtr nd,ElemType data)//�ݹ�ǰ�����ȥѰ����ֵ 
{
	if(nd==NULL)
		return ERROR;
	if(nd->value==data)
	{
		YN=1;
		h1=nd;
		return SUCCESS;
	}
		
	XXBLtofind(nd->left,data);
	XXBLtofind(nd->right,data);
	return SUCCESS;
}

Status BST_search(BinarySortTreePtr s, ElemType x)//Ѱ��ֵ 
{
	XXBLtofind(s->root,x);
	if(YN==1)
		{
			printf("��ֵ(%d)����!!\n",x); 
		}
	if(YN==0)
		printf("��ֵ������!!\n");
	YN=0;
	return SUCCESS;
} 

NodePtr XXBLtofind2(NodePtr nd,ElemType data)//�ݹ�ǰ�����ȥѰ����ֵ����Ҷ��ָ�� 
{
	if(nd==NULL)
		return NULL;
	if(nd->value==data)
	{
		YN=1;
		return nd;
	}
		
	XXBLtofind(nd->left,data);
	XXBLtofind(nd->right,data);
	return NULL;
}

/*BST_search2(BinarySortTreePtr s, ElemType x)//Ѱ��ֵ����Ҷ��ָ�� 
{
	return XXBLtofind2(s->root,x);
} */

void visit(NodePtr p)//���ʺ��� 
{
	if(p==NULL)
		return;
	printf("%d ",p->value); 
	return;
}

Status BST_preorderI(BinarySortTreePtr s)//�޵ݹ�ǰ����� 
{	

	preOrder(s->root);
	return SUCCESS;
}

void preOrder(NodePtr T)//�޵ݹ�ǰ�����
{
    Node *stack[15];
    int top = -1;
    Node *p = T;
    while(p!=NULL||top!=-1){
        if(p!=NULL){
            stack[++ top] = p;
            printf("%d ",p->value); //��ջʱ���������
            p = p->left;
        }else{
            p = stack[top --];
            p = p->right;
        }
    }
}

/*NodePtr preorderI(NodePtr root)
{
	pushLStack(Z,root->value); 
	if(root->right!=NULL&&root->left!=NULL)
	{
		
	}
	if(root->left==NULL&&root->right!=0)
	{
		
	}
	if(root->left!=NULL&&root->right==0)
	{
		
	}
	if(root->left==NULL&&root->right==NULL)
	{
	
	}

}
*/
Status XXBL(NodePtr node)//�ݹ�ǰ����� 
{
	if(node==NULL)
		return ERROR;
	visit(node);
	XXBL(node->left);
	XXBL(node->right);
	return SUCCESS;
}
 
Status BST_preorderR(BinarySortTreePtr s)//�еݹ�ǰ����� 
{
	XXBL(s->root);
	return SUCCESS;
} 

Status BST_inorderI(BinarySortTreePtr s)//�޵ݹ��������
{
	inOrder(s->root);
	return SUCCESS;
} 

void inOrder(Node *T)
{
    Node *stack[15];
    int top = -1;
    Node *p = T;
    while(p!=NULL||top!=-1){
        if(p!=NULL){
            stack[++ top] = p;
            p = p->left;
        }else{
            p = stack[top --];
            printf("%d ",p->value);  //��ջʱ���������
            p = p->right;
        }
    }
}



Status ZXBL(NodePtr node)//�ݹ�������� 
{
	if(node==NULL)
		return ERROR;
	ZXBL(node->left);
	visit(node);
	ZXBL(node->right);
	return SUCCESS;
}

Status BST_inorderR(BinarySortTreePtr s)//�еݹ�������� 
{
	ZXBL(s->root);
	return SUCCESS;
}

Status BST_postorderI(BinarySortTreePtr s)//�޵ݹ������� 
{

	postOrder(s->root);
	return SUCCESS;
}
void postOrder(Node *T)
{
    Node *stack[15];
    int top = -1;
    int flagStack[15];   //��¼ÿ���ڵ���ʴ���ջ
    Node *p = T;
    while(p!=NULL||top!=-1){
        if(p!=NULL){     //��һ�η��ʣ�flag��1����ջ
            stack[++ top] = p;
            flagStack[top] = 1;   
            p = p->left;
        }else{//��p == NULL��
            if(flagStack[top] == 1){  //�ڶ��η��ʣ�flag��2��ȡջ��Ԫ�ص�����ջ
                p = stack[top];
                flagStack[top] = 2;
                p = p->right;
            }else{         //�����η��ʣ���ջ
                p = stack[top --];
                printf("%d ",p->value);    //��ջʱ���������
                p = NULL;      //p�ÿգ��Ա������ջ
            }
        }
    }
}

Status HXBL(NodePtr node)//�ݹ������� 
{
	if(node==NULL)
		return ERROR;
	HXBL(node->left);
	HXBL(node->right);
	visit(node);
	return SUCCESS;
}

Status BST_postorderR(BinarySortTreePtr s)//�еݹ������� 
{

	HXBL(s->root);
	return SUCCESS;
}

/*Status BST_levelOrder(BinarySortTreePtr s)//������� ����ʵ�� 
{
	LQueue Q1;//���� 
	LQueue *Q;
	Q=&Q1; 
	if(s==NULL)
		{
			printf("������\n");
			return ERROR; 
		}
	
	InitLQueue(Q);
	EnLQueue(Q,s->root->value);
	while(IsEmptyLQueue(Q))
	{	
		h1=BST_search2(s,GetHeadLQueue(Q));
		if(h1->left->value!=0)
			EnLQueue(Q,h1->left->value);
		if(h1->right->value!=0)
			EnLQueue(Q,h1->right->value);
		DeLQueue(Q);
		
	} 
	
	DestoryLQueue(Q);//���� 
	return SUCCESS;
}*/
Status BST_levelOrder(NodePtr root, void (*visit)(NodePtr))	//
{
    Queue *h=(Queue *)malloc(sizeof(Queue));
    Queue *tail=h, *p, *q;
    NodePtr r2;
    int n=0,i,j;
    h->root=root;
    h->next=NULL;
    n++;

    while(n!=0)
    {
        i=n;
        p=h;

        for(j=0;j<i;j++)
        {
            r2=p->root;
            if(r2->left!=NULL)
            {
                q=(Queue *)malloc(sizeof(Queue));
                q->root=r2->left;
                q->next=NULL;
                tail->next=(NodePtr)q;
                tail=q;
                n++;
            }
            if(r2->right!=NULL)
            {
                q=(Queue *)malloc(sizeof(Queue));
                q->root=r2->right;
                q->next=NULL;
                tail->next=(NodePtr)q;
                tail=q;
                n++;
            }
            p=(Queue *)p->next;
        }
        for(j=0;j<i;j++)
        {
            p=(Queue *)h->root;
            visit((NodePtr)p);
            h=(Queue *)h->next;
            //free(p);
            n--;
        }
    }
    free(h);
    return SUCCESS;
}



void menu()/*ѡ��˵�����*/
{
    system("color 0e");//��������������ɫ
	printf("\t\t\t  ******************************************************\n\n");
	printf("\t\t\t  ***************�������������ܲ˵�*********************\n");
	printf("\t\t\t     ----------------------   ----------------------  \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 1.��������         2.��������             *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 3.ɾ������         4.�ݹ�ǰ�����         *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 5.�ݹ��������     6.�ݹ�������         *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 7.����ǰ�����     8.�����������         *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 9.�����������     10.�������            *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 11.�˳�����                               * \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t     ----------------------   ----------------------  \n");
}

void sign()/*ѡ����*/ 
{
	printf("�����������ţ�"); 
	scanf("%s",dengluma);getchar();
	if(!strcmp("1",dengluma))
	{
		printf("����������Ҫ���������");
		scanf("%d",&x1); 
		getchar();
		BST_insert(s1,x1);
		printf("�������ֽ�����\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("2",dengluma))
	{
		printf("����������ҪѰ�ҵ�����");
		scanf("%d",&x2); 
		getchar();
		BST_search(s1,x2);
		printf("Ѱ�����ֽ�����\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("3",dengluma))
	{
		printf("����������Ҫɾ��������");
		scanf("%d",&x3);
		getchar();
		BST_delete(s1,x3);
		printf("ɾ����ɣ�\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("4",dengluma))
	{
		BST_preorderR(s1);
		printf("�ݹ�ǰ������ɹ���\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("5",dengluma))
	{
		BST_inorderR(s1);
		printf("�ݹ���������ɹ���\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("6",dengluma))
	{
		BST_postorderR(s1);
		printf("�ݹ��������ɹ���\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("7",dengluma))
	{
		BST_preorderI(s1);//����ǰ�����
		printf("����ǰ������ɹ���\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("8",dengluma))
	{
		BST_inorderI(s1);//�����������
		printf("������������ɹ���\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("9",dengluma))
	{
		BST_postorderI(s1);//�����������
		printf("������������ɹ���\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("10",dengluma))
	{
		
		BST_levelOrder(s1->root,visit);//������� 
		printf("��������ɹ���\n");
		printf("�û����������:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("11",dengluma))
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
	s1=&sa;
	L1=&LB1; 
	ElemType x,y;
	initLStack(Z);
	h1=(Node *)malloc(sizeof(Node));
	printf("���ڽ��г�ʼ��:");
	BST_init(s1);
	menu();
	sign();
	return 1;
} 
