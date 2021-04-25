#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_sort_tree.h"

BinarySortTreePtr s1;//树指针 
BinarySortTree sa;//树 
NodePtr h1;//叶指针 
StackNode LB1; //链表
StackNode *L1;
LinkStack *Z;//链栈 
ElemType x1,x2,x3,x4;//数值
ElemType *data;
//LQueue Q1;//队列 
//LQueue *Q;
ElemType YN,XS;//判断 
int ii=1;
char dengluma[20];//登陆嘛 

/*
void InitLQueue(LQueue *Q) //初始化队列
{
	StackNode *P =(StackNode *)malloc(sizeof(StackNode));
	Q->front=P;
	Q->front->next=NULL;
	Q->rear=Q->front;
	Q->length=0;
}

void DestoryLQueue(LQueue *Q)//销毁队列
{
	Q->length=0;
	free(Q->front);
	if(Q->front!=Q->rear)
		free(Q->rear);
}

Status IsEmptyLQueue(const LQueue *Q)//检查队列是否为空
{
	if(Q->length==0)
		return ERROR;
	return SUCCESS;
}

ElemType GetHeadLQueue(LQueue *Q)//得到队头元素 
{
	if(!IsEmptyLQueue(Q)) 
	{
		return 0;
	}
	return Q->rear->data;
}

Status EnLQueue(LQueue *Q, ElemType data)//入队操作
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

Status DeLQueue(LQueue *Q)//出队操作
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
//栈 
Status initLStack(LinkStack *s)//初始化栈
{
	s=(LinkStack *)malloc(sizeof(struct LinkStack));
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



Status pushLStack(LinkStack *s,Node *root)//入栈
{
	StackNode *tmp =(StackNode *)malloc(sizeof(StackNode));
	tmp->Root =root;
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
	ElemType tmp1;
	StackNode *stmp = s->top;
	tmp1 = s->top->Root->value;
	s->top = stmp->next;
	s->count --;
	printf("%d ",tmp1);
	return SUCCESS; 
}





Status BST_init(BinarySortTreePtr s)//初始化树
{
	
	int n;//结点总量多少
	int i=0;//循环变量 
	int x;//暂时顶替数值 
	printf("请输入您需要排序的数值总量：n（暂时只支持整数）\n n：");
	scanf("%d",&n);
	printf("请依次输入你所加入的结点的数值（用回车结束单个结点的输入）：\n");
	for(i=0;i<n;i++)
	{
		printf("第%d个结点：",i+1);
		scanf("%d",&x);
		s->root =  CreateTree(s->root,x);
	}
	return SUCCESS;
} 

NodePtr CreateTree(NodePtr root,ElemType x)//循环插入 
{
	if(!root)  //如果root结点为空，创建叶子结点
	{
		root = (NodePtr)malloc(sizeof(Node));
		root->value = x;
		root->left=root->right=NULL;
	}else
	{
		if(root->value==x)
			{
				printf("该值已存在或存在重复的数值!\n");
				return root;
			}
		if(root->value>x) 
			root->left = CreateTree(root->left,x);  //递归调用左
		else if(root->value<x)
			root->right = CreateTree(root->right,x);//递归调用右
	}
	return root;
}

Status BST_insert(BinarySortTreePtr s, ElemType data)//插入值
{
	s->root =  CreateTree(s->root,data);
	return SUCCESS;
} 

Status BST_delete(BinarySortTreePtr s, ElemType x)//删除值 
{
	Delete(s->root,x);
	return SUCCESS;
} 



NodePtr Delete(NodePtr BST,ElemType x)//删除 
{
	NodePtr p;
	if (BST == NULL) //如果树为空直接返回
		return NULL;
	else if (x < BST->value) //小于则左子树递归删除
		BST->left = Delete(BST->left, x);
	else if (x > BST->value) //大于则右子树递归删除
		BST->right = Delete(BST->right, x);
	else //等于则找到了要删除的结点
	{
		//如果被删除的结点有左、右两个孩子结点
		if (BST->left && BST->right)
		{
			//找到右子树的最小元素
			p = FindMin(BST->right);
			//替代被删除的结点
			BST->value= p->value;
			//在被删除结点的右子树中删除刚才找到的右子树的最小元素
			BST->right = Delete(BST->right, p->value);
		}
		//如果被删除结点只有一个孩子结点或没有孩子结点
		else
		{
			p = BST;
			if (BST->left == NULL) //有右孩子结点或没有孩子结点
				BST = BST->right;
			else if (BST->right == NULL) //有左孩子结点或没有孩子结点
				BST = BST->left;
			free(p); //释放结点
		}
	}
	return BST;
}

NodePtr FindMin(NodePtr BST)//找最小 
{
	if(BST == NULL) //树为空直接放回
		return NULL;
	else if(BST->left == NULL) //找到最左叶子结点并返回
		return BST;
	else
		return FindMin(BST->left); //沿左分支继续递归查找
}

Status XXBLtofind(NodePtr nd,ElemType data)//递归前序遍历去寻找数值 
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

Status BST_search(BinarySortTreePtr s, ElemType x)//寻找值 
{
	XXBLtofind(s->root,x);
	if(YN==1)
		{
			printf("该值(%d)存在!!\n",x); 
		}
	if(YN==0)
		printf("该值不存在!!\n");
	YN=0;
	return SUCCESS;
} 

NodePtr XXBLtofind2(NodePtr nd,ElemType data)//递归前序遍历去寻找数值返回叶子指针 
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

/*BST_search2(BinarySortTreePtr s, ElemType x)//寻找值返回叶子指针 
{
	return XXBLtofind2(s->root,x);
} */

void visit(NodePtr p)//访问函数 
{
	if(p==NULL)
		return;
	printf("%d ",p->value); 
	return;
}

Status BST_preorderI(BinarySortTreePtr s)//无递归前序遍历 
{	

	preOrder(s->root);
	return SUCCESS;
}

void preOrder(NodePtr T)//无递归前序遍历
{
    Node *stack[15];
    int top = -1;
    Node *p = T;
    while(p!=NULL||top!=-1){
        if(p!=NULL){
            stack[++ top] = p;
            printf("%d ",p->value); //入栈时，访问输出
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
Status XXBL(NodePtr node)//递归前序遍历 
{
	if(node==NULL)
		return ERROR;
	visit(node);
	XXBL(node->left);
	XXBL(node->right);
	return SUCCESS;
}
 
Status BST_preorderR(BinarySortTreePtr s)//有递归前序遍历 
{
	XXBL(s->root);
	return SUCCESS;
} 

Status BST_inorderI(BinarySortTreePtr s)//无递归中序遍历
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
            printf("%d ",p->value);  //出栈时，访问输出
            p = p->right;
        }
    }
}



Status ZXBL(NodePtr node)//递归中序遍历 
{
	if(node==NULL)
		return ERROR;
	ZXBL(node->left);
	visit(node);
	ZXBL(node->right);
	return SUCCESS;
}

Status BST_inorderR(BinarySortTreePtr s)//有递归中序遍历 
{
	ZXBL(s->root);
	return SUCCESS;
}

Status BST_postorderI(BinarySortTreePtr s)//无递归后序遍历 
{

	postOrder(s->root);
	return SUCCESS;
}
void postOrder(Node *T)
{
    Node *stack[15];
    int top = -1;
    int flagStack[15];   //记录每个节点访问次数栈
    Node *p = T;
    while(p!=NULL||top!=-1){
        if(p!=NULL){     //第一次访问，flag置1，入栈
            stack[++ top] = p;
            flagStack[top] = 1;   
            p = p->left;
        }else{//（p == NULL）
            if(flagStack[top] == 1){  //第二次访问，flag置2，取栈顶元素但不出栈
                p = stack[top];
                flagStack[top] = 2;
                p = p->right;
            }else{         //第三次访问，出栈
                p = stack[top --];
                printf("%d ",p->value);    //出栈时，访问输出
                p = NULL;      //p置空，以便继续退栈
            }
        }
    }
}

Status HXBL(NodePtr node)//递归后序遍历 
{
	if(node==NULL)
		return ERROR;
	HXBL(node->left);
	HXBL(node->right);
	visit(node);
	return SUCCESS;
}

Status BST_postorderR(BinarySortTreePtr s)//有递归后序遍历 
{

	HXBL(s->root);
	return SUCCESS;
}

/*Status BST_levelOrder(BinarySortTreePtr s)//层序遍历 队列实现 
{
	LQueue Q1;//队列 
	LQueue *Q;
	Q=&Q1; 
	if(s==NULL)
		{
			printf("空树！\n");
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
	
	DestoryLQueue(Q);//销毁 
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



void menu()/*选择菜单界面*/
{
    system("color 0e");//换背景和字体颜色
	printf("\t\t\t  ******************************************************\n\n");
	printf("\t\t\t  ***************二叉排序树功能菜单*********************\n");
	printf("\t\t\t     ----------------------   ----------------------  \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 1.插入数字         2.查找数字             *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 3.删除数字         4.递归前序遍历         *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 5.递归中序遍历     6.递归后序遍历         *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 7.迭代前序遍历     8.迭代中序遍历         *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 9.迭代后序遍历     10.层序遍历            *   \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t      * 11.退出程序                               * \n");
	printf("\t\t\t      *********************************************  \n");
	printf("\t\t\t     ----------------------   ----------------------  \n");
}

void sign()/*选择栏*/ 
{
	printf("请输入操作序号："); 
	scanf("%s",dengluma);getchar();
	if(!strcmp("1",dengluma))
	{
		printf("请输入你需要插入的数：");
		scanf("%d",&x1); 
		getchar();
		BST_insert(s1,x1);
		printf("插入数字结束！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("2",dengluma))
	{
		printf("请输入你需要寻找的数：");
		scanf("%d",&x2); 
		getchar();
		BST_search(s1,x2);
		printf("寻找数字结束！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("3",dengluma))
	{
		printf("请输入你需要删除的数：");
		scanf("%d",&x3);
		getchar();
		BST_delete(s1,x3);
		printf("删除完成！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("4",dengluma))
	{
		BST_preorderR(s1);
		printf("递归前序遍历成功！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("5",dengluma))
	{
		BST_inorderR(s1);
		printf("递归中序遍历成功！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("6",dengluma))
	{
		BST_postorderR(s1);
		printf("递归后序遍历成功！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("7",dengluma))
	{
		BST_preorderI(s1);//迭代前序遍历
		printf("迭代前序遍历成功！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("8",dengluma))
	{
		BST_inorderI(s1);//迭代中序遍历
		printf("迭代中序遍历成功！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("9",dengluma))
	{
		BST_postorderI(s1);//迭代后序遍历
		printf("迭代后序遍历成功！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("10",dengluma))
	{
		
		BST_levelOrder(s1->root,visit);//层序遍历 
		printf("层序遍历成功！\n");
		printf("敲击任意键返回:");
		getchar();
		system("cls");
		menu();
		sign();
	}
	if(!strcmp("11",dengluma))
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
	s1=&sa;
	L1=&LB1; 
	ElemType x,y;
	initLStack(Z);
	h1=(Node *)malloc(sizeof(Node));
	printf("现在进行初始化:");
	BST_init(s1);
	menu();
	sign();
	return 1;
} 
