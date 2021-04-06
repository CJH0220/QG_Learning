#include <stdio.h>
#include <stdlib.h>
#define n 50

typedef struct
{
	char a[n];
	int size;//表示栈中含有的元素数量
} stack;
char pop(stack *p)
{
	if (p->size == 0)
		printf("空栈");
	else
	{
		--(p->size);
		return p->a[p->size];
	}
}
char top(stack *p)
{
	if (p->size == 0)
		return '/0';//抛出/0字符代表空
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
int compare(char a)//用于比较优先级
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
void merge(float *a, float b, char c)//用于将两数字合并,注意前面的数字传地址
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
	stack *ysf = (stack*)malloc(sizeof(stack));//为表达式开辟一个stack
	ysf->size = 0;
	float num[50];//用于求值的数组
	int numpos = 0;//用于求值的数组位置//ps因为num这个栈用的操作非常的少，而stack没有泛化，所以没有采用栈
	printf("后缀表达式为:");
	while (bds[i] != '=')
	{
		if (bds[i] == '\0')
		{
			printf("表达式应该有 '=' ");
			return;
		}
		if (bds[i] <= '9'&&bds[i] >= '0')//为数字的情况，转换为1个数，如234
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
				double f_car = 0.1;//定义基数
				++i;
				while (bds[i] <= '9'&&bds[i] >= '0')
				{
					num[numpos] += ((bds[i] - '0')*f_car);
					f_car *= 0.1;
					++i;
				}
			}//计算小数点
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
					pop(ysf);//弹出右括号
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
	printf("\n运算结果为:%.2f\n", num[1]);
}
int main()
{
	stack *p;
	char bds[50];
	printf("请输入中缀表达式:"); 
	scanf("%s", bds);
	qiuzhi(bds);
	return 0;
}


