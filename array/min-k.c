//寻找数组中最小的k个数

//first 全排序，取前k个
//采用快速排序方式
int a[101],n;//定义全局变量，这两个变量需要在子函数中使用 
void quicksort(int left,int right)
{
	int i,j,t,temp;
	if(left > right)
		return;

	temp = a[left];
	i = left;
	j = right;
	while(i!=j)
	{
		while(a[j]>=temp&&i<j)
			j--;
		while(a[i]<=temp&&i<j)
			i++;
		if(i<j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
			
		}
	}
	a[left]=a[i];
	a[i]=temp;

	quicksort(left,i-1);
	quicksort(i+1,right);
}
int main()
{
	 int i,j,t; 
    //读入数据 
    scanf("%d",&n); 
    for(i=1;i<=n;i++) 
                   scanf("%d",&a[i]); 
    quicksort(1,n); //快速排序调用 
                             
    //输出排序后的结果 
    for(i=0;i<k;i++) 
        printf("%d ",a[i]); 
    return 0; 
} 

//second 冒泡排序n*k复杂度
for(int i=10;i<k;i++)
{
	for(int j=i+1;j<n;j++)
	{
		if(a[i]>a[j])
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
}

//thrid 堆排序。维护一个容量为k的最大堆
//最大堆：完全二叉树，是指根节点的关键字值是堆中的最大关键字值，
//且每个节点若有儿子节点，其关键字值都不小于其儿子节点的关键字值。
void k_min(int *arr,int len, int k)
{
	int i;
	build_maxheap(arr,k);
	for(i=k;i<len;i++)
	{
		if(arr[i]<arr[0])
		{
			arr[0]  = arr[i];
			maxheap_balance(arr,0,k);
		}
	}
}

void build_maxheap(int *arr,int k)
{
	int i;
	if(arr==NULL || k<=1)
		return;
	for(i=k/2+1;i>=0;--i)
		maxheap_balance(arr,i,k);
}

void maxheap_balance(int *arr,int index,int k)
{
	int l=LEFT(index);
	int r=RIGHT(index);
	int largest;
	if(l<k && arr[l]>arr[index])
		largest=l;
	else
		largest=index;
	if(r<k&& arr[r]>arr[largest])
		largest=r;
	if(largest != index){//将最大元素提升，并递归
		swap(&arr[largest],&arr[index]);
		maxheap_balance(arr,largest,k);
	}
}

//参见http://bubkoo.com/2014/01/14/sort-algorithm/heap-sort/

