#include <iostream>
#include<stdio.h>  
#include<stdlib.h>
#include<string>
#include<math.h>
using namespace std; 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"���������ֵĸ�����"<<endl;
	int num;
	cin>>num;
	int shuzu[num];
	cout<<"������"<<num<<"�����֣��Կո������"<<endl; 
	for(int i=0;i<num;i++)
    scanf("%d",&shuzu[i]);
    int temp[num*2];
    int n=0;
    int sum=0;
    for(int i=0;i<num;i++)
    {
    for(int j=i+1;j<num;j++)
    {
     n+=j-1;
     abs(shuzu[i]-shuzu[j])>>temp[n];
     sum++;
    }
	n=num-1;
    }
	int minIndex=0;
	for(int i=0;i<sum;i++)
	{
		cout<<temp[i]<<" "<<endl;
	 if(temp[minIndex]>temp[i])//����ҵ���С��
        {  
            minIndex=i;//���¸�С��Ԫ�ص��±�
        }  
    }
	printf("��С��ֵ=%d\n",abs(temp[minIndex])); 
	return 0;
}
