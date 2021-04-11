#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AQueue.h"


void InitAQueue(AQueue *Q)//��ʼ������
{
	int i;
	for(i = 0; i < MAXQUEUE; i++)
        Q->data[i] = (void *)malloc(typeSize);
	Q->front=0;
	Q->rear=0;
	Q->length=0;
}

void DestoryAQueue(AQueue *Q)//���ٶ���
{
	int i = 0;
 	while (Q->length--)
         free(Q->data[i++]);
    printf("�˳��ɹ���\n");
	exit(1);
}

Status IsFullAQueue(const AQueue *Q)//�������Ƿ�����
{
	if (Q->length == MAXQUEUE)
         return TRUE;
     return FALSE;

}

Status IsEmptyAQueue(const AQueue *Q)//�������Ƿ�Ϊ��
{
	if(Q->length == 0)
		return FALSE;
	return TRUE;
}

Status GetHeadAQueue(AQueue *Q, void *e)//�鿴��ͷԪ��
{
	if (IsEmptyAQueue(Q)) 
		return FALSE;
     memcpy(e,Q->data[0],typeSize);
        return TRUE;
}

int LengthAQueue(AQueue *Q)//ȷ�����г���	
{
	return Q->length;
}

Status EnAQueue(AQueue *Q, void *data)//��Ӳ���
{
	 if (IsFullAQueue(Q)==1)
 	{
 		printf("���壡���������㻹��\n");
 		return FALSE;
 	}
	memcpy(Q->data[Q->rear],data,typeSize);
	Q->rear = (Q->rear +1) % MAXQUEUE; 
	Q->length++;
	return TRUE;
}

Status DeAQueue(AQueue *Q)//���Ӳ���
{
	if(IsEmptyAQueue(Q)==0)
	{
		printf("�����ǿյģ�\n");
		return FALSE;
	}
	Q->front = (Q->front +1 )%MAXQUEUE;
	Q->length--;
	return TRUE;
}

void ClearAQueue(AQueue *Q)//��ն���
{
	Q->front = 0;
	Q->rear = 0;
	Q->length = 0;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))//������������
{
	
	int i,j;
	if (IsEmptyAQueue(Q)==0)
     {
         puts("����Ϊ�գ�");
         return FALSE;
     }
	for (i = Q->front,j = Q->length;j > 0;j--)
	{
		foo(Q->data[i]) ;
		i = (i+1)%MAXQUEUE; 	 
	} 
		return TRUE;
}

void APrint(void *q)//������������ӡ�� 
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

//ѡ�����
void select(AQueue * Q)
{
    int i =0;
    void *t;

    puts("��ѡ����Ĳ���");
    switch(getInt())
    {
        case 1:DestoryAQueue(Q);
        case 2:if (IsEmptyAQueue(Q)) puts("����Ϊ��");
                else puts("���в�Ϊ��");
                break;
        case 3:if (IsFullAQueue(Q)) puts("��������");
                else puts("����δ��");
                break;
        case 4:if (GetHeadAQueue(Q,t))
                {
                    printf("�����ɹ�,ͷ�������Ϊ");
                    APrint(t);
                    printf("\n");
                }
                else puts("����ʧ��,����Ϊ��");
                break;
        case 5:i = LengthAQueue(Q);printf("���г���Ϊ%d\n",i);
                break;
        case 6:if (IsFullAQueue(Q)) puts("����ʧ��,��������");
                else {
                    setVoid(Q);
                    puts("�����ɹ�");
                }
                break;
        case 7:if (DeAQueue(Q)) puts("�����ɹ�");
                else puts("����ʧ�ܣ�����Ϊ��");
                break;
        case 8:ClearAQueue(Q);puts("�����");break;
        case 9:if (TraverseAQueue(Q,APrint)) puts("�����ɹ�");
                else puts("����ʧ��");
                break;
        case 10:system("cls");menu();break;
        default :puts("�������");
    }
    select(Q);

}

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
    else if (t[0] == 'e' && t[1] == '\0')
    {
        type = '*';
        typeSize = sizeof(char *);
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
void setVoid(AQueue * Q)
{
    char c[100];

    if (type == 'i')
    {
        int a = 0;
    
        puts("����������");
        a = getInt();
        EnAQueue(Q,&a);
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
        EnAQueue(Q,&c[0]);
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
        EnAQueue(Q,&d);
    }
    else if (type == 's')
    {
        puts("����������");
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
    puts("��ӭʹ�÷��Ͷ���(ѭ��)ADT����ϵͳ");
    puts("����Ҫ��ȡ������������:\n a.int��\t b.char�� \n c.double��\t d.string�� \n e.ָ����(ϵͳ���򵥴�����������)");
    setType();
    puts("ѡ����Բ�����");
    InitAQueue(Q);
    menu();
    select(Q);
    return 1;
}


