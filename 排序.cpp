#include <iostream>
#include <stdio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//��ʱ��ֹ��ѡ������
void selectionSort(int a[],int n)
{
  bool sorted = false;
  for(int size=n;!sorted&&(size-1);size--)
  {
    int indexOfMax=0;
    sorted = true;  //�������Ԫ��
    for(int i=1;i<size;i++)
       if(a[indexOfMax]<a[i]) indexOfMax=i;
       else sorted=false;  //����
    swap(a[indexOfMax],a[size-1]);
  }
}

//��ʱ��ֹ��ð������
bool bubble(int a[],int n)
{//������a��0��n-1���е����Ԫ���Ƶ����Ҷ�
  bool swapped = false;//ĿǰΪֹδ����
  for(int i=0;i<n-1;i++)
  if(a[i]>a[i+1])
  {
  	swap(a[i],a[i+1]);
  	swapped=true;//���� 
   } 
   return swapped;
}
void bubbleSort(int a[],int n)
{
	for(int i=n;i>1&&bubble(a,i);i--);
}

//��������
void insert(int a[],int n,const int& x)
{//��x������������a��0��n-1�� 
	int i;
	for(i=n-1;i>=n&&x<a[i];i--) a[i+1]=a[i];
	a[i+1]=x;
}
void insertionSort(int a[],int n)
{//ʵʩ�������� 
	for(int i=1;i<n;i++)
	{//��a��i�����뵽a��0��i-1���� 
		int t=a[i];
		int j;
		for(j=i-1;j>=0&&t<a[j];j--) a[j+1]=a[j];
		a[j+1]=t;
	}
}

//��������
int maxbit(int data[], int n)   
{  //�����ݵ����λ��,�����������
    int d = 1; //��������λ��  
    int p = 10;  
    for(int i = 0; i < n; ++i)  
    {  
        while(data[i] >= p)  
        {  
            p *= 10;  
            ++d;  
        }  
    }  
    return d;  
}  
void radixSort(int data[], int n)   
{  //�������� 
    int d = maxbit(data, n);  
    int tmp[n];  
    int count[10]; //������  
    int i, j, k;  
    int radix = 1;  
    for(i = 1; i <= d; i++) //����d������  
    {  
        for(j = 0; j < 10; j++)  
            count[j] = 0; //ÿ�η���ǰ��ռ�����  
        for(j = 0; j < n; j++)  
        {  
            k = (data[j] / radix) % 10; //ͳ��ÿ��Ͱ�еļ�¼��  
            count[k]++;  
        }  
        for(j = 1; j < 10; j++)  
            count[j] = count[j - 1] + count[j]; //��tmp�е�λ�����η����ÿ��Ͱ  
        for(j = n - 1; j >= 0; j--) //������Ͱ�м�¼�����ռ���tmp��  
        {  
            k = (data[j] / radix) % 10;  
            tmp[count[k] - 1] = data[j];  
            count[k]--;  
        }  
        for(j = 0; j < n; j++) //����ʱ��������ݸ��Ƶ�data��  
            data[j] = tmp[j];  
        radix = radix * 10;  
    }  
}  

//��������
void quickSort(int a[], int l, int r)  
{  //ͨ��һ������Ҫ��������ݷָ�ɶ����������֣�
//����һ���ֵ��������ݶ�������һ���ֵ��������ݶ�ҪС��
//Ȼ���ٰ��˷����������������ݷֱ���п�����������������̿��Եݹ���У�
//�Դ˴ﵽ�������ݱ����������
    if (l< r)  
    {        
        int i = l, j = r, x = a[l];  
        while (i < j)  
        {  
            while(i < j && a[j]>= x) // ���������ҵ�һ��С��x����  
                j--;   
            if(i < j)  
                a[i++] = a[j];  
            while(i < j && a[i]< x) // ���������ҵ�һ�����ڵ���x����  
                i++;   
            if(i < j)  
                a[j--] = a[i];  
        }  
        a[i] = x;  
        quickSort(a, l, i - 1); // �ݹ����  
        quickSort(a, i + 1, r);  
    }  
} 

void merge(int *a,int start,int end,int *result)
{
    int left_length = (end - start + 1) / 2 + 1;//�󲿷����������Ԫ�صĸ���
    int left_index = start;
    int right_index = start + left_length;
    int result_index = start;
    while(left_index < start + left_length && right_index < end+1)
    {
        //�Էֱ��Ѿ��ź�������������������кϲ�
        if(a[left_index] <= a[right_index])
            result[result_index++] = a[left_index++];
        else
            result[result_index++] = a[right_index++];
    }
    while(left_index < start + left_length)
        result[result_index++] = a[left_index++];
    while(right_index < end+1)
        result[result_index++] = a[right_index++];
}

//�鲢���� 
void mergeSort(int *a, int start, int end, int *result)
{
    if(1 == end - start)//���������ֻ������Ԫ�أ����������Ԫ�ؽ�������
    {
        if(a[start] > a[end])
        {
            int temp  = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
        return;
    }
    else if(0 == end - start)//���ֻ��һ��Ԫ�أ���������
        return;
    else
    {
        //�������������䣬�ֱ�������������������
        mergeSort(a,start,(end-start+1)/2+start,result);
        mergeSort(a,(end-start+1)/2+start+1,end,result);
        //��ʼ�鲢�Ѿ��ź����start��end֮�������
        merge(a,start,end,result);
        //���������������ݸ��Ƶ�ԭʼ������ȥ
        for(int i = start;i <= end;++i)
            a[i] = result[i];
    }
}


int main()
{
  int a[100];
  cout<<"�����������������Ϊ��"<<endl;
  int n;
  cin>>n;
  cout<<"����������Ԫ�أ�"<<endl;
  for(int i=0;i<n;i++) cin>>a[i];
  cout<<"���������������Ϊ��[";
  for(int i=0;i<n;i++) cout<<a[i]<<" ";
  cout<<"]"<<endl;
  
  selectionSort(a,n);
  cout<<"ѡ������������Ϊ��"<<"[";
  for(int i=0;i<n;i++) cout<<a[i]<<" ";
  cout<<"]"<<endl;
  
  bubbleSort(a,n);
  cout<<"ð������������Ϊ��"<<"[";
  for(int i=0;i<n;i++) cout<<a[i]<<" ";
  cout<<"]"<<endl;
  
  insertionSort(a,n);
  cout<<"��������������Ϊ��"<<"[";
  for(int i=0;i<n;i++) cout<<a[i]<<" ";
  cout<<"]"<<endl;
  
  radixSort(a,n); 
  cout<<"��������������Ϊ��"<<"[";
  for(int i=0;i<n;i++) cout<<a[i]<<" ";
  cout<<"]"<<endl;
  
  quickSort(a,0,n-1);
  cout<<"��������������Ϊ��"<<"[";
  for(int i=0;i<n;i++) cout<<a[i]<<" ";
  cout<<"]"<<endl;
  
  const int length = n;
  int result[length];
  mergeSort(a,0,length-1,result);
  cout<<"�鲢����������Ϊ��"<<"[";
  for(int i=0;i<n;i++) cout<<a[i]<<" ";
  cout<<"]"<<endl;
  return 0;
} 
