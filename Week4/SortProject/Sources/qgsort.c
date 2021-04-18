#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include <string.h>
#include <time.h>
#include "qgsort.h"

void insertSort(int *a,int n)//���������㷨
{
	int i,j,temp;
    for ( i = 1; i < n; i++)  //�����һ����Ϊ�������У����������±��һ��ʼ
    {
        temp=a[i];    //������������ȡһ����Ϊ���������֣������������е������бȽϣ��ҵ����ʵ�λ�ò�������
        for ( j = i; j>0 && a[j-1]> temp; --j)  //�ж�����Ϊ������j>0Ϊ����߽��жϣ�a[j-1]>tempΪ������ж�����
        {
            a[j]=a[j-1];
        }
        a[j]=temp;  //�ҵ����ʵ�λ�ò�������
    }

	
	
	
	/*int i,j,*temp;
	for (i=1;i<n;i++)
	{
		temp = a ;
		for(j=i-1;j>=0&&*temp<a[j];j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=*temp;
	}*/
}

void MergeArray(int *a,int begin,int mid,int end,int *temp)//�鲢���򣨺ϲ����飩
{
	//����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
	int i=begin;//������ 
	int j=mid+1;//������ 
	int k=0;//��ʱ�����ָ�� 
	while(i<=mid&&j<=end){
		if(a[i]<=a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	} 
	while(i<=mid){
		temp[k++]=a[i++];
	}
	while(j<=end){
		temp[k++]=a[j++];
	}
	k=0;
	while(begin<=end)
		a[begin++]=temp[k++];
}

void MergeSort(int *a,int begin,int end,int *temp)//�鲢����
{
	if(begin>=end)
		return;
	int mid = (begin+end)/2;
	MergeSort(a,begin,mid,temp);
	MergeSort(a,mid+1,end,temp);
	MergeArray(a,begin,mid,end,temp);
}

void QuickSort_Recursion(int *a, int begin, int end)//�������򣨵ݹ�棩
{
	int i=begin;
	int j=end;
	int temp=a[i];
	if(begin<end)
	{
		while(i<j)       //��i=jʱ����ѭ��
		{
		while((a[j]>=temp)&&(i<j))   //�����ұ�
		{
			j--;
		}
		a[i]=a[j];
		while((a[i]<=temp)&&(i<j))      //�������
		{
			i++;
		}
		a[j]=a[i];
		}
		a[i]=temp;
		//��һ�ֽ������ݹ���á�i-1��j+1����Ϊ�м����Ѿ��źã������ٴεݹ�
		QuickSort_Recursion(a,begin,i-1);
		QuickSort_Recursion(a,j+1,end);
	}	
	else
	return ;
}

void QuickSort(int *a,int size)//�������򣨷ǵݹ�棩
{



}

int Partition(int *a, int begin, int end)//�������������ţ�
{



}

void CountSort(int *a, int size , int max)//��������
{
  assert(a);
  int i=0;
	//ͨ��max��min�������ʱ��������Ҫ���ٵĿռ��С
	int max1 = a[0], min = a[0];
	for (i = 0; i < size; i++){
		if (a[i] > max1)
			max1 = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//ʹ��calloc�����鶼��ʼ��Ϊ0
	int range = max1 - min + 1;
	int *b = (int *)calloc(range, sizeof(int));
	//ʹ����ʱ�����¼ԭʼ������ÿ�����ĸ���
	for (i = 0; i < size; i++){
		//ע�⣺�����ڴ洢��Ҫ��ԭʼ������ֵ�ϼ�ȥmin�Ų������Խ������
		b[a[i] - min] += 1;
	}
	int j = 0;
	//����ͳ�ƽ�������¶�Ԫ�ؽ��л���
	for (i = 0; i < range; i++){
		while (b[i]--){
			//ע�⣺Ҫ��i��ֵ����min���ܻ�ԭ��ԭʼ����
			a[j++] = i + min;
		}
	}
	//�ͷ���ʱ����
	free(b);
	b = NULL;

}

int max(int *a,int len)
{
	int i,j=a[0];
	for(i=0;i<len;i++)
	{
		if(a[i]>j)
			j=a[i];
	}
	return j;
}

 // �������������λ��
int maxlength(int a[], int len)
{
    int bits = 1, p = 10, i;
    for(i=0; i<len; i++)
    {
        while(a[i]>=p)
        {
            p = p * 10;
            bits++;
        }
    }
    return bits;
}

// ����num�ĵ�posλ�����֣�pos=1Ϊ��λ
int getdigit(int num, int pos)
{
	int temp = 1, i;
    for(i=0; i<pos-1; i++)
        temp = temp * 10;
    return (num/temp) % 10;
 }

void RadixCountSort(int *a,int size)//������������
{
    int *bucket[10];        // ָ������, 0-9��ʮ��Ͱ
    int i,j,num,index;
    for(i=0; i<10; i++)
    {       // ָ�����飬ÿ��ָ�붼ָ��һ������Ϊlen+1��Ͱ
    	bucket[i] = (int *)malloc(sizeof(int) * (size+1)); // bucket Ͱ
        bucket[i][0] = 0; // indexΪ0����¼Ͱ�����ݸ���
    }
    int bit; // ������������ĳ��ȣ�bit=1Ϊ��λ
    for(bit = 1; bit<=maxlength(a, size); bit++) // �Ӹ�λ��ʼ�Ƚ�
    {
	    for(i=0; i<size; i++)    // ����
		{
       		num = getdigit(a[i], bit);
        	index = ++bucket[num][0];
	        bucket[num][index] = a[i];
        }
	    int index = 0;
        for(i=0; i<10; i++)     // �ռ�  
        {
            for(j=1; j<=bucket[i][0]; j++)
          		a[index++] = bucket[i][j]; // �ռ���ԭ������
	   		bucket[i][0] = 0;       // ��λ��ÿ��Ͱ�е����ݸ���
        }
    }
}

void ColorSort(int *a,int size)//��ɫ��0.1.2
{
	int p0 = 0 ,i=0;
		int p2 = size-1;
		for( i = 0; i < p2;++i){
			if(a[i] == 0) {
				//����ǰλ�ý�����p0λ��
				int tem = 0;
				tem = a[p0];
				a[p0] =a[i];
				a[i] = tem;
				++p0;
			}
			if(a[i] == 2) {
				//����β����p2ָ��ǰ��һλ��p0ָ�벻��
				int tem = 0;
				tem = a[p2];
				a[p2] = a[i];
				a[i] = tem;
				--i;
				--p2;
			}
		}

}

int main()
{
	int LEN;
	int i;
	int YN;
	int GBYD[50];
	int *temp1=GBYD;
	printf("���������鳤�ȣ�");
	clock_t start, finish;
	double  duration;  
 
	scanf("%d",&LEN);
	int a[100];
	for(i=0;i<LEN;i++)
	{
		printf("\n��%d��ֵ:",i+1);
		scanf("%d",&a[i]);
	}
	int *a1=a;
	printf("������ʹ�õķ�����1����������\n2����������\n3���鲢����\n4����������\n5����������\n6����ɫ����\n");
	scanf("%d",&YN);
	
	if(YN==1)
	{
		printf("\n1����������\n");
		start = clock();  
		insertSort(a1,LEN);
		for(i=0;i<LEN;i++)
		{
			printf("%d ",a[i]); 
		}
		finish = clock();  
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n��ʱ%f��",duration);
	}
	
	if(YN==2) 
	{
		printf("\n2����������\n");
		start = clock();  
		QuickSort_Recursion(a1,0,LEN-1);
		for(i=0;i<LEN;i++)
		{
			printf("%d ",a[i]); 
		}
		finish = clock();  
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n��ʱ%f��",duration);
	}
	
	if(YN==3) 
	{
		printf("\n3���鲢����\n");
		start = clock();  
		MergeSort(a1,0,LEN-1,temp1);
		for(i=0;i<LEN;i++)
		{
			printf("%d ",a[i]); 
		}
		finish = clock();  
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n��ʱ%f��",duration);
	}
	
	if(YN==4) 
	{
		printf("\n4����������\n");
		start = clock();  
		CountSort(a1,LEN ,max(a1,LEN));
		for(i=0;i<LEN;i++)
		{
			printf("%d ",a[i]); 
		}
		finish = clock();  
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n��ʱ%f��",duration);
	}
	
	if(YN==5) 
	{
		printf("\n5����������\n");
		start = clock();  
		RadixCountSort(a1,LEN);
		for(i=0;i<LEN;i++)
		{
			printf("%d ",a[i]); 
		}
		finish = clock();  
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n��ʱ%f��",duration);
	}
	
	if(YN==6) 
	{
		printf("\n6����ɫ����\n");
		for(i=0;i<LEN;i++)
		{
			if(!(a[i]==0||a[i]==1||a[i]==2))
				{
					printf("��ֵ��ȫΪ0��1��2���޷���ɫ����\n");
					exit(0);
				}
		}
		start = clock();  
		ColorSort(a1,LEN);
		for(i=0;i<LEN;i++)
		{
			printf("%d ",a[i]); 
		}
		finish = clock();  
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n��ʱ%f��",duration);
	}
	
	return 0;
}

