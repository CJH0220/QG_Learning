//
// Created by eke_l on 2021/4/21.
//

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef int ElemType ;

typedef struct Node{
    ElemType value;//数值 
    struct Node *left, *right;//左儿子，右儿子 
}Node, *NodePtr;

typedef struct BinarySortTree{
    struct Node *root;  // 根结点 
} BinarySortTree, *BinarySortTreePtr;

typedef  struct StackNode //链表 
{
	NodePtr Root;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack //链栈 
{
	LinkStackPtr top;
	int	count ;
}LinkStack;

typedef struct Queue
{
    NodePtr root;
    NodePtr next;
}Queue;

/*队列 
/void InitLQueue(LQueue *Q);//初始化队列
void DestoryLQueue(LQueue *Q);//销毁队列 
Status IsEmptyLQueue(const LQueue *Q);//检查队列是否为空
ElemType GetHeadLQueue(LQueue *Q);//获得队头元素
Status EnLQueue(LQueue *Q, ElemType data);//入队操作
Status DeLQueue(LQueue *Q);//出队操作
*/ 
//链栈 
Status initLStack(LinkStack *s);//初始化栈
Status isEmptyLStack(LinkStack *s);//判断栈是否为空
Status pushLStack(LinkStack *s,Node *root);//入栈
Status popLStack(LinkStack *s,ElemType *data);//出栈
NodePtr preorderI(NodePtr root);
//树 
Status BST_init(BinarySortTreePtr s);//初始化树 
Status BST_insert(BinarySortTreePtr s, ElemType data);//插入值 

NodePtr Delete(NodePtr BST,ElemType x);//删除
NodePtr FindMin(NodePtr BST);//找最小 
Status BST_delete(BinarySortTreePtr s, ElemType x);//删除值 

Status XXBLtofind(NodePtr nd,ElemType data);//递归前序遍历去寻找数值 
Status BST_search(BinarySortTreePtr s, ElemType x);//寻找值 

NodePtr XXBLtofind2(NodePtr nd,ElemType data);//递归前序遍历去寻找数值返回叶子指针 
NodePtr  BST_search2(BinarySortTreePtr s, ElemType x);//寻找值返回叶子指针 

Status BST_preorderI(BinarySortTreePtr s);//无递归前序遍历
void preOrder(NodePtr T); 

Status BST_preorderR(BinarySortTreePtr s);//有递归前序遍历 

Status BST_inorderI(BinarySortTreePtr s);//无递归中序遍历 
void inOrder(Node *T);

Status BST_inorderR(BinarySortTreePtr s);//有递归中序遍历 

Status BST_postorderI(BinarySortTreePtr s);//无递归后序遍历
void postOrder(Node *T); 

Status BST_postorderR(BinarySortTreePtr s);//有递归后序遍历 

Status BST_levelOrder(NodePtr root, void (*visit)(NodePtr));//层序遍历 

NodePtr CreateTree(NodePtr root,ElemType x);//循环插入 初始化时循环插入 

void visit(NodePtr p);//访问函数

Status XXBL(NodePtr node);//递归前序遍历

Status ZXBL(NodePtr node);//递归中序遍历 

Status HXBL(NodePtr node);//递归后序遍历 

void menu(); 

void sign();

#endif //BINARYSORTTREE_BINARY_SORT_TREE_H
