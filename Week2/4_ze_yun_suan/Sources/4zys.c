#include <stdio.h>
#include <stdlib.h>
#define n 50

typedef struct
{
	char a[n];
	int size;//��ʾջ�к��е�Ԫ������
} stack;
char pop(stack *p)
{
	if (p->size == 0)
		printf("��ջ");
	else
	{
		--(p->size);
		return p->a[p->size];
	}
}
char top(stack *p)
{
	if (p->size == 0)
		return '/0';//�׳�/0�ַ������
	else
	{
		return p->a[p->size - 1];
	}
}
int empty(stack *p)
{
	return p->size == 0;
}
void push(stack *p, char b)
{
	p->a[p->size] = b;
	++p->size;
}
int compare(char a)//���ڱȽ����ȼ�
{
	int i;
	switch (a)
	{
	case '+':
		i = 1;
		break;
	case '-':
		i = 1;
		break;
	case '*':
		i = 2;
		break;
	case '/':
		i = 2;
		break;
	default:
		i = 0;
		break;
	}
	return i;
}
void merge(float *a, float b, char c)//���ڽ������ֺϲ�,ע��ǰ������ִ���ַ
{
	if (c == '-')
	{
		(*a) -= b;
	}
	else if (c == '+')
	{
		(*a) += b;
	}
	else if (c == '*')
	{
		(*a) *= b;
	}
	else
		(*a) /= b;
}
void qiuzhi(char *bds)
{
	int i = 0;
	stack *ysf = (stack*)malloc(sizeof(stack));//Ϊ���ʽ����һ��stack
	ysf->size = 0;
	float num[50];//������ֵ������
	int numpos = 0;//������ֵ������λ��//ps��Ϊnum���ջ�õĲ����ǳ����٣���stackû�з���������û�в���ջ
	printf("��׺���ʽΪ:");
	while (bds[i] != '=')
	{
		if (bds[i] == '\0')
		{
			printf("���ʽӦ���� '=' ");
			return;
		}
		if (bds[i] <= '9'&&bds[i] >= '0')//Ϊ���ֵ������ת��Ϊ1��������234
		{
			num[++numpos] = 0;
			while (bds[i] <= '9'&&bds[i] >= '0')
			{
				num[numpos] *= 10;
				num[numpos] += (bds[i] - '0');
				++i;
			}
			if (bds[i] == '.')
			{
				double f_car = 0.1;//�������
				++i;
				while (bds[i] <= '9'&&bds[i] >= '0')
				{
					num[numpos] += ((bds[i] - '0')*f_car);
					f_car *= 0.1;
					++i;
				}
			}//����С����
		}
		else
		{
			if (empty(ysf))
				push(ysf, bds[i]);
			else
			{
				if (bds[i] == '(')
					push(ysf, bds[i]);
				else if (bds[i] == ')')
				{
					while (top(ysf) != '(')
					{
						merge(&num[numpos - 1], num[numpos], top(ysf));
						printf("%c", pop(ysf));
						--numpos;
					}
					pop(ysf);//����������
				}
				else
				{
					while (compare(bds[i])<=compare(top(ysf)))
					{
						merge(&num[numpos - 1], num[numpos], top(ysf));
						printf("%c", pop(ysf));
						--numpos;
					}
					push(ysf, bds[i]);
				}
			}
			++i;
		}
	}
	while (!empty(ysf))
	{
		merge(&num[numpos - 1], num[numpos], top(ysf));
		printf("%c", pop(ysf));
		--numpos;
	}
	printf("\n������Ϊ:%.2f\n", num[1]);
}
int main()
{
	stack *p;
	char bds[50];
	printf("��������׺���ʽ:"); 
	scanf("%s", bds);
	qiuzhi(bds);
	return 0;
}


