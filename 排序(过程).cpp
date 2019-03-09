#include<iostream>
using namespace std;
template<class T>
class sort
	{
	public:
		sort(T *,int);
       void printarray()
	   {
	   	 for(int i=0;i<n;i++)
	   	  {
			 cout<<a[i];
	   	  cout<<" ";
	   }cout<<endl;
	   }
		void selectSort()
		{ int min,indexofMin;
		  for(int i=0;i<n-1;i++)
          { min=a[i];indexofMin=i;bool b=false;
		    for(int j=i+1;j<n;j++)
             {if(min>a[j])
               { min=a[j];//�ѽ�С��ֵ����min�� 
                 indexofMin=j;//��¼��Сֵ��λ�� 
			   }
             }
           a[indexofMin]=a[i];//���һ�αȽϺ󽻻���Ӧ��λ�� 
           a[i]=min;
           printarray();
		  }
		}
		void bubbleSort()
		{ int t;
		  for(int i=0;i<n;i++)
		 {  bool  b=false;//����һ���ж��Ƿ������Ǵ�ն˵�ֵ 
		     for(int j=n-1;j>i;j--)
		     { if(a[j-1]>a[j])//��С��ֵ��ǰ�潻�� 
			  {
			 	t=a[j];
			 	a[j]=a[j-1];
			 	a[j-1]=t;
			 	b=true;//�����Ļ��ı�bool�͵�ֵ 
			  }
			 }
			 if(!b)
			 break;//û�н����Ļ��˳�ѭ�� 
		     printarray();
		}}
		void insertSort()
		{ for(int i=1;i<n;i++)
		{
			int t=a[i];
			int j;
			for(j=i-1;j>=0&&t<a[j];j--)
			  a[j+1]=a[j];
			a[j+1]=t;
			printarray();
		 } 
		} 
/*
*�����ݵ����λ��,�����������
*/
int maxbit(int *a,int) 
{
    int d=1; //��������λ��
    int p=10;
    for(int i=0;i<n;++i)
    {
        while(a[i]>=p)
        {
            p*=10;
            ++d;
        }
    }
    return d;
}
void radixsort() //��������
{
    int d=maxbit(a,n);
    int tmp[n];
    int count[10]; //������
    int i,j,k;
    int radix=1;
    for(i=1;i<=d;i++) //����d������
    {
        for(j=0;j<10;j++)
            count[j] = 0; //ÿ�η���ǰ��ռ�����
        for(j=0;j<n;j++)
        {
            k=(a[j]/radix)%10; //ͳ��ÿ��Ͱ�еļ�¼��
            count[k]++;
        }
        for(j=1;j<10;j++)
            count[j]=count[j - 1]+count[j]; //��tmp�е�λ�����η����ÿ��Ͱ
        for(j=n-1;j>=0;j--) //������Ͱ�м�¼�����ռ���tmp��
        {
            k=(a[j]/radix)%10;
            tmp[count[k]-1]=a[j];
            count[k]--;
        }
        for(j=0;j<n;j++) //����ʱ��������ݸ��Ƶ�data��
            a[j]=tmp[j];
        radix=radix*10;
        printarray();
    }
}
private:
	T *a;
	int n;};
template<class T>
sort<T>::sort(T *b,int arrayLength)
{ 
  if(n<1)
  {
  	cout<<"enter a correct number:";
  }
  a=&b[0];
  n=arrayLength;
} 
int main()
{  cout<<"enter a number:";
   int n;
   cin>>n; 
   int a[n];
   for(int i=0;i<n;i++)
   cin>>a[i];
   sort<int> w(a,n);
   int q;
   cout<<"��ѡ��һ������ʽ��1��ѡ������ 2��ð������ 3���������� 4����������";
   cin>>q;
   switch(q)
   {
   	case(1):
   		w.selectSort();
   		break;
   	case(2):
   		w.bubbleSort();
   		break;
   	case(3):
	   w.insertSort();
	   break;
	  case(4):
	  w.radixsort(); }
	
}
