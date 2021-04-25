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
    ElemType value;//��ֵ 
    struct Node *left, *right;//����ӣ��Ҷ��� 
}Node, *NodePtr;

typedef struct BinarySortTree{
    struct Node *root;  // ����� 
} BinarySortTree, *BinarySortTreePtr;

typedef  struct StackNode //���� 
{
	NodePtr Root;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack //��ջ 
{
	LinkStackPtr top;
	int	count ;
}LinkStack;

typedef struct Queue
{
    NodePtr root;
    NodePtr next;
}Queue;

/*���� 
/void InitLQueue(LQueue *Q);//��ʼ������
void DestoryLQueue(LQueue *Q);//���ٶ��� 
Status IsEmptyLQueue(const LQueue *Q);//�������Ƿ�Ϊ��
ElemType GetHeadLQueue(LQueue *Q);//��ö�ͷԪ��
Status EnLQueue(LQueue *Q, ElemType data);//��Ӳ���
Status DeLQueue(LQueue *Q);//���Ӳ���
*/ 
//��ջ 
Status initLStack(LinkStack *s);//��ʼ��ջ
Status isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
Status pushLStack(LinkStack *s,Node *root);//��ջ
Status popLStack(LinkStack *s,ElemType *data);//��ջ
NodePtr preorderI(NodePtr root);
//�� 
Status BST_init(BinarySortTreePtr s);//��ʼ���� 
Status BST_insert(BinarySortTreePtr s, ElemType data);//����ֵ 

NodePtr Delete(NodePtr BST,ElemType x);//ɾ��
NodePtr FindMin(NodePtr BST);//����С 
Status BST_delete(BinarySortTreePtr s, ElemType x);//ɾ��ֵ 

Status XXBLtofind(NodePtr nd,ElemType data);//�ݹ�ǰ�����ȥѰ����ֵ 
Status BST_search(BinarySortTreePtr s, ElemType x);//Ѱ��ֵ 

NodePtr XXBLtofind2(NodePtr nd,ElemType data);//�ݹ�ǰ�����ȥѰ����ֵ����Ҷ��ָ�� 
NodePtr  BST_search2(BinarySortTreePtr s, ElemType x);//Ѱ��ֵ����Ҷ��ָ�� 

Status BST_preorderI(BinarySortTreePtr s);//�޵ݹ�ǰ�����
void preOrder(NodePtr T); 

Status BST_preorderR(BinarySortTreePtr s);//�еݹ�ǰ����� 

Status BST_inorderI(BinarySortTreePtr s);//�޵ݹ�������� 
void inOrder(Node *T);

Status BST_inorderR(BinarySortTreePtr s);//�еݹ�������� 

Status BST_postorderI(BinarySortTreePtr s);//�޵ݹ�������
void postOrder(Node *T); 

Status BST_postorderR(BinarySortTreePtr s);//�еݹ������� 

Status BST_levelOrder(NodePtr root, void (*visit)(NodePtr));//������� 

NodePtr CreateTree(NodePtr root,ElemType x);//ѭ������ ��ʼ��ʱѭ������ 

void visit(NodePtr p);//���ʺ���

Status XXBL(NodePtr node);//�ݹ�ǰ�����

Status ZXBL(NodePtr node);//�ݹ�������� 

Status HXBL(NodePtr node);//�ݹ������� 

void menu(); 

void sign();

#endif //BINARYSORTTREE_BINARY_SORT_TREE_H
