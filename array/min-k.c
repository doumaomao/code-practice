//Ѱ����������С��k����

//first ȫ����ȡǰk��
//���ÿ�������ʽ
int a[101],n;//����ȫ�ֱ�����������������Ҫ���Ӻ�����ʹ�� 
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
    //�������� 
    scanf("%d",&n); 
    for(i=1;i<=n;i++) 
                   scanf("%d",&a[i]); 
    quicksort(1,n); //����������� 
                             
    //��������Ľ�� 
    for(i=0;i<k;i++) 
        printf("%d ",a[i]); 
    return 0; 
} 

//second ð������n*k���Ӷ�
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

//thrid ������ά��һ������Ϊk������
//���ѣ���ȫ����������ָ���ڵ�Ĺؼ���ֵ�Ƕ��е����ؼ���ֵ��
//��ÿ���ڵ����ж��ӽڵ㣬��ؼ���ֵ����С������ӽڵ�Ĺؼ���ֵ��
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
	if(largest != index){//�����Ԫ�����������ݹ�
		swap(&arr[largest],&arr[index]);
		maxheap_balance(arr,largest,k);
	}
}

//�μ�http://bubkoo.com/2014/01/14/sort-algorithm/heap-sort/

