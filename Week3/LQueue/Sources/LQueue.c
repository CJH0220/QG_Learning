#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LQueue.h"


void InitLQueue(LQueue *Q)//��ʼ������
{
	Node *P=(Node *)malloc(sizeof(Node));
	Q->front=P;
	Q->front->data=(void *)malloc(typeSize);
	Q->front->next=NULL;
	Q->rear=Q->front;
	Q->rear->data=(void *)malloc(typeSize);	
	Q->length=0;
}

void DestoryLQueue(LQueue *Q)//���ٶ���
{
	Q->length=0;
	free(Q->front);
	if(Q->front!=Q->rear)
		free(Q->rear);
	printf("�˳��ɹ���\n");
	exit(1);
}

Status IsEmptyLQueue(const LQueue *Q)//�������Ƿ�Ϊ��
{
	if(Q->length==0)
		return FALSE;
	return TRUE;
}

Status GetHeadLQueue(LQueue *Q, void *e)//�鿴��ͷԪ��
{
	if (!IsEmptyLQueue(Q)) 
		return FALSE;
	memcpy(e,Q->front->data,typeSize);
        return TRUE;
}
int LengthLQueue(LQueue *Q) //ȷ�����г���
{
	return Q->length;	
}
Status EnLQueue(LQueue *Q, void *data)//��Ӳ���
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

Status DeLQueue(LQueue *Q)//���Ӳ���
{
	if(!IsEmptyLQueue(Q)) 
	{
		printf("�����ǿյģ�\n");
		return FALSE;
	}
	Q->rear=Q->rear->next;
	Q->length--;
	return TRUE;
}

void ClearLQueue(LQueue *Q)//��ն���
{
	Q->front=Q->rear;
	free(Q->rear);
	Q->length=0; 
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))//������������
{
	if(IsEmptyLQueue(Q)==0) 
	{
		printf("�����ǿյģ�\n");
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

void LPrint(void *q)//��������
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

//��ӡ�˵�
void menu()
{
	puts("************************************************\n");
    puts("\t\t1.ɾ�����в��˳�ϵͳ");
    puts("\t\t2.�ж϶����Ƿ�Ϊ��");
    puts("\t\t3.�ж϶����Ƿ�����");
    puts("\t\t4.���ͷ�������");
    puts("\t\t5.��������ִ泤��");
    puts("\t\t6.��Ӳ���");
    puts("\t\t7.���Ӳ���");
    puts("\t\t8.��ն���");
    puts("\t\t9.�������в�����Ԫ��");
    puts("\t\t10.��ռ�¼");
    puts("************************************************\n");
}

//ѡ�����
void select(LQueue * Q)
{
    int i =0;
    void *t;

    puts("��ѡ����Ĳ���");
    switch(getInt())
    {
        case 1:DestoryLQueue(Q);
        		break;
        case 2:if (!IsEmptyLQueue(Q)) puts("����Ϊ��");
                else puts("���в�Ϊ��");
                break;
        case 3:printf("�ù���ʧЧ��\n");
                break;
        case 4:if (GetHeadLQueue(Q,t))
                {
                    printf("�����ɹ�,ͷ�������Ϊ");
                    LPrint(t);
                    printf("\n");
                }
                else puts("����ʧ��,����Ϊ��");
                break;
        case 5:i = LengthLQueue(Q);printf("���г���Ϊ%d\n",i);
                break;
        case 6:
                    setVoid(Q);
                    puts("�����ɹ�");
                break;
        case 7:if (DeLQueue(Q)) puts("�����ɹ�");
                else puts("����ʧ�ܣ�����Ϊ��");
                break;
        case 8:ClearLQueue(Q);puts("�����");break;
        case 9:if (TraverseLQueue(Q,LPrint)) puts("�����ɹ�");
                else puts("����ʧ��");
                break;
        case 10:system("cls");menu();break;
        default :puts("�������");
    }
    select(Q);
}

//ȷ������
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
        puts("�����������������");
        setType();
    }

}

//���int
int getInt()
{
    char in[11];
    int t;
    s_gets(in,11);
    t = atoi(in);
    if (t == 0) {
            if (in[1] != 0 || in[2] != '\0')
            {
                printf("����������������룡\n");
                t = getInt();
            }
    }
    return t;
}

//��ȡ��������
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

//������ݲ���
void setVoid(LQueue * Q)
{
    char c[100];

    if (type == 'i')
    {
        int a = 0;
        puts("����������");
        a = getInt();
        EnLQueue(Q,&a);
    }
    else if (type == 'c')
    {
        puts("����������");
        s_gets(c,3);
        if (c[2] != '\0')
        {
            puts("���ʹ�������������");
            s_gets(c,3);
        }
        EnLQueue(Q,&c[0]);
    }
    else if (type == 'd')
    {
        double d;
        puts("����������");
        s_gets(c,100);

skip :  d = atof(c);
        if (d == 0 ) {
            int i = 0;
            while (c[i++] != '\0')
            {
                if (c[i] != '0' && c[i] != '.')
                {
                    puts("�����������������\n");
                    s_gets(c,100);
                    goto skip;
                }
            }
        }
        EnLQueue(Q,&d);
    }
    else if (type == 's')
    {
        puts("����������");
        s_gets(c,100);
        EnLQueue(Q,&c);
    }
}

 int main()
{
    LQueue * Q;
    Q = (LQueue *)malloc(sizeof(LQueue));
    puts("��ӭʹ�÷��Ͷ���(����)ADT����ϵͳ");
    puts("����Ҫ��ȡ������������:\n a.int��\t b.char�� \n c.double��\t d.string�� \n");
    setType();
    puts("ѡ����Բ�����");
    InitLQueue(Q);
    menu();
    select(Q);
    return 1;
}



