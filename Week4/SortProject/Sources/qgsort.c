#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include <string.h>
#include <time.h>
#include "qgsort.h"

void insertSort(int *a,int n)//插入排序算法
{
	int i,j,temp;
    for ( i = 1; i < n; i++)  //假设第一个数为有序序列，所以数组下标从一开始
    {
        temp=a[i];    //从无序序列中取一个数为待插入数字，与有序序列中的数进行比较，找到合适的位置插入其中
        for ( j = i; j>0 && a[j-1]> temp; --j)  //判断条件为两个，j>0为数组边界判断，a[j-1]>temp为插入的判断条件
        {
            a[j]=a[j-1];
        }
        a[j]=temp;  //找到合适的位置插入其中
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

void MergeArray(int *a,int begin,int mid,int end,int *temp)//归并排序（合并数组）
{
	//数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
	int i=begin;//左序列 
	int j=mid+1;//右序列 
	int k=0;//临时数组的指针 
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

void MergeSort(int *a,int begin,int end,int *temp)//归并排序
{
	if(begin>=end)
		return;
	int mid = (begin+end)/2;
	MergeSort(a,begin,mid,temp);
	MergeSort(a,mid+1,end,temp);
	MergeArray(a,begin,mid,end,temp);
}

void QuickSort_Recursion(int *a, int begin, int end)//快速排序（递归版）
{
	int i=begin;
	int j=end;
	int temp=a[i];
	if(begin<end)
	{
		while(i<j)       //当i=j时结束循环
		{
		while((a[j]>=temp)&&(i<j))   //处理右边
		{
			j--;
		}
		a[i]=a[j];
		while((a[i]<=temp)&&(i<j))      //处理左边
		{
			i++;
		}
		a[j]=a[i];
		}
		a[i]=temp;
		//第一轮结束，递归调用。i-1和j+1是因为中间数已经排好，不用再次递归
		QuickSort_Recursion(a,begin,i-1);
		QuickSort_Recursion(a,j+1,end);
	}	
	else
	return ;
}

void QuickSort(int *a,int size)//快速排序（非递归版）
{



}

int Partition(int *a, int begin, int end)//快速排序（枢轴存放）
{



}

void CountSort(int *a, int size , int max)//计数排序
{
  assert(a);
  int i=0;
	//通过max和min计算出临时数组所需要开辟的空间大小
	int max1 = a[0], min = a[0];
	for (i = 0; i < size; i++){
		if (a[i] > max1)
			max1 = a[i];
		if (a[i] < min)
			min = a[i];
	}
	//使用calloc将数组都初始化为0
	int range = max1 - min + 1;
	int *b = (int *)calloc(range, sizeof(int));
	//使用临时数组记录原始数组中每个数的个数
	for (i = 0; i < size; i++){
		//注意：这里在存储上要在原始数组数值上减去min才不会出现越界问题
		b[a[i] - min] += 1;
	}
	int j = 0;
	//根据统计结果，重新对元素进行回收
	for (i = 0; i < range; i++){
		while (b[i]--){
			//注意：要将i的值加上min才能还原到原始数据
			a[j++] = i + min;
		}
	}
	//释放临时数组
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

 // 数组中最大数的位数
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

// 数据num的第pos位的数字，pos=1为个位
int getdigit(int num, int pos)
{
	int temp = 1, i;
    for(i=0; i<pos-1; i++)
        temp = temp * 10;
    return (num/temp) % 10;
 }

void RadixCountSort(int *a,int size)//基数计数排序
{
    int *bucket[10];        // 指针数组, 0-9的十个桶
    int i,j,num,index;
    for(i=0; i<10; i++)
    {       // 指针数组，每个指针都指向一个容量为len+1的桶
    	bucket[i] = (int *)malloc(sizeof(int) * (size+1)); // bucket 桶
        bucket[i][0] = 0; // index为0处记录桶中数据个数
    }
    int bit; // 数组中最大数的长度，bit=1为个位
    for(bit = 1; bit<=maxlength(a, size); bit++) // 从个位开始比较
    {
	    for(i=0; i<size; i++)    // 分配
		{
       		num = getdigit(a[i], bit);
        	index = ++bucket[num][0];
	        bucket[num][index] = a[i];
        }
	    int index = 0;
        for(i=0; i<10; i++)     // 收集  
        {
            for(j=1; j<=bucket[i][0]; j++)
          		a[index++] = bucket[i][j]; // 收集到原数组中
	   		bucket[i][0] = 0;       // 复位，每个桶中的数据个数
        }
    }
}

void ColorSort(int *a,int size)//颜色排0.1.2
{
	int p0 = 0 ,i=0;
		int p2 = size-1;
		for( i = 0; i < p2;++i){
			if(a[i] == 0) {
				//将当前位置交换至p0位置
				int tem = 0;
				tem = a[p0];
				a[p0] =a[i];
				a[i] = tem;
				++p0;
			}
			if(a[i] == 2) {
				//换到尾部，p2指针前进一位，p0指针不变
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
	printf("请输入数组长度：");
	clock_t start, finish;
	double  duration;  
 
	scanf("%d",&LEN);
	int a[100];
	for(i=0;i<LEN;i++)
	{
		printf("\n第%d个值:",i+1);
		scanf("%d",&a[i]);
	}
	int *a1=a;
	printf("请输入使用的方法：1、插入排序。\n2、快速排序。\n3、归并排序\n4、计数排序\n5、基数排序\n6、颜色排序\n");
	scanf("%d",&YN);
	
	if(YN==1)
	{
		printf("\n1、插入排序\n");
		start = clock();  
		insertSort(a1,LEN);
		for(i=0;i<LEN;i++)
		{
			printf("%d ",a[i]); 
		}
		finish = clock();  
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n用时%f秒",duration);
	}
	
	if(YN==2) 
	{
		printf("\n2、快速排序\n");
		start = clock();  
		QuickSort_Recursion(a1,0,LEN-1);
		for(i=0;i<LEN;i++)
		{
			printf("%d ",a[i]); 
		}
		finish = clock();  
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n用时%f秒",duration);
	}
	
	if(YN==3) 
	{
		printf("\n3、归并排序\n");
		start = clock();  
		MergeSort(a1,0,LEN-1,temp1);
		for(i=0;i<LEN;i++)
		{
			printf("%d ",a[i]); 
		}
		finish = clock();  
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n用时%f秒",duration);
	}
	
	if(YN==4) 
	{
		printf("\n4、计数排序\n");
		start = clock();  
		CountSort(a1,LEN ,max(a1,LEN));
		for(i=0;i<LEN;i++)
		{
			printf("%d ",a[i]); 
		}
		finish = clock();  
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n用时%f秒",duration);
	}
	
	if(YN==5) 
	{
		printf("\n5、基数排序\n");
		start = clock();  
		RadixCountSort(a1,LEN);
		for(i=0;i<LEN;i++)
		{
			printf("%d ",a[i]); 
		}
		finish = clock();  
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("\n用时%f秒",duration);
	}
	
	if(YN==6) 
	{
		printf("\n6、颜色排序\n");
		for(i=0;i<LEN;i++)
		{
			if(!(a[i]==0||a[i]==1||a[i]==2))
				{
					printf("数值不全为0，1，2，无法颜色排序。\n");
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
		printf("\n用时%f秒",duration);
	}
	
	return 0;
}

