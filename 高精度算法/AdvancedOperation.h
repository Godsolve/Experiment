#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include<string.h>  
#define MaxLen 200 
using namespace std;
FILE *fpRead1,*fpRead2,*fp;	
template<class T>
class AdvancedOperation
{
//	int a[],int b[],int c[],int n,int m
	public:
		AdvancedOperation();
		void add();
		void sub();
		void multi();
		int SubStract(int a[], int b[], int n, int m );
		int divide();
		void translate();
	private:
	    int i;
		int c[3000];
		char numberN[1500], numberM[1500];	
		int* a;
		int* b;
		int* r;
		int n, m;
};
template<class T>
AdvancedOperation<T>::AdvancedOperation()
{
    
}
template<class T>
void AdvancedOperation<T>::translate()
{
	//�ļ���ȡ������������ 
	fpRead1 = fopen("E:\\C++\\�߾����㷨\\data1.txt", "r");
	if (fpRead1 == NULL){  
        cout<<"Open File Failed."<<endl;  
        exit(0);  
    } 
    //�õ��ļ������ݵĳ��� 
    fseek(fpRead1,0,SEEK_SET);
    fseek(fpRead1,0,SEEK_END);
    long length1=ftell(fpRead1);// length1�����ļ��ĳ���
    
    fseek(fpRead1,0,SEEK_SET);     //�ļ���λ�÷ŵ���ͷ
	for(i=0;i<length1;i++){   
	    fscanf(fpRead1, "%s", &numberN[i]); //��ȡ�������� 
    }  	
    
    fpRead2 = fopen("E:\\C++\\�߾����㷨\\data2.txt", "r");
    if (fpRead2 == NULL){  
        cout<<"Open File failed.\n";  
        exit(0);  
    } 
    //�õ��ļ������ݵĳ��� 
    fseek(fpRead2,0,SEEK_SET);
    fseek(fpRead2,0,SEEK_END);
    long length2=ftell(fpRead2);// length2�����ļ��ĳ���
    
    fseek(fpRead2,0,SEEK_SET);  //�ļ���λ�÷ŵ���ͷ 
	for(i=0;i<length2;i++){  
    fscanf(fpRead2, "%s", &numberM[i]);  //��ȡ�������� 
    }  	
	    n = strlen(numberN);m = strlen(numberM);
		a=new int[n];b=new int[m];              //���������ݵȳ����м����� 
		int i, j;
		for (i = 0, j = n - 1; i < n; i++, j--) {//���ַ�����ת��Ϊ���������� 
			a[i] = numberN[j] - '0';
		}
		for (i = 0, j = m - 1; i < m; i++, j--) {//���ַ�����ת��Ϊ���������� 
			b[i] = numberM[j] - '0';
		}
		cout<<"aΪ��";
		for(i=n-1;i>=0;i--)cout<<a[i];
		cout<<endl;
		cout<<"bΪ��";
		for(i=m-1;i>=0;i--)cout<<b[i];
		cout<<endl<<endl;
	
}
template<class T>
void AdvancedOperation<T>::add()
{
		//cout<<"m="<<m<<" n="<<n<<endl;
		r=new int[3000];
		for(i=0;i<3000;i++)r[i]=0;
		
		    if(n>=m)
		{
			for(i=0;i<m;i++)
		    r[i]=a[i]+b[i];
		    
		    for(i=m;i<n;i++){
		    	r[i]+=a[i];
			}
	    }
	        else
	    {
	    	for(i=0;i<n;i++)
		    r[i]=a[i]+b[i];
		    for(i=n;i<m;i++)
			r[i]+=b[i]; 
		}
	
		for (i = 0; i < n + m; i++) {  //��λ�Ĵ��� 
		    if (r[i] >= 10) {
				r[i + 1] += r[i] / 10;
				r[i] %= 10;         
			}
		}
		int j;
		for ( j = 2999; j > 0; j--) {  //�Ӻ���ǰ�����������һλ��Ϊ��ʱ����Ϊ���������������һλ��ԭ����ȫΪ0�� 
			if (r[j] != 0)
				break;
		}
		fp=fopen("E:\\C++\\�߾����㷨\\add.txt","w");
		for (i = j; i >= 0; i--) {
			printf("%d", r[i]);
			fprintf(fp,"%d",r[i]);
		}
		printf("\n");
}
template<class T>
void AdvancedOperation<T>::sub()
{
	    int j;
		for(i=0;i<3000;i++)r[i]=0;
		if(n>=m)                          //���Ƚϣ��ֱ�����������ڼ�������ͱ���������С�ڼ�������������� 
		{                                 //������������ڼ������� 
			for(i=0;i<m;i++)
		    r[i]=a[i]-b[i];
		    for(i=m;i<n;i++)r[i]+=a[i];
	    }
	    else if(n<m)                     //����������С�ڼ������� 
	    {
	    	for(i=0;i<n;i++)
		    r[i]=a[i]-b[i];
		    for(i=n;i<m;i++)r[i]-=b[i]; 
		}
		//for (j = 2999; j > 0; j--) {  //�Ӻ���ǰ�����������һλ��Ϊ��ʱ����Ϊ���������������һλ��ԭ����ȫΪ0�� 
		//	if (r[j] != 0)
		//		break;
		//}  
		for (i = 0; i < j; i++) {  //��λ�Ĵ��� 
		    if (r[i] < 0) {
				r[i + 1] - 1;
				r[i] += 10;         
			}
		}
		for (j = 2999; j > 0; j--) {  //�Ӻ���ǰ�����������һλ��Ϊ��ʱ�� 
			if (r[j] != 0)            //��Ϊ���������������һλ��ԭ����ȫΪ0��
				break;
		}
		fp=fopen("E:\\C++\\�߾����㷨\\sub.txt","w");
        for (i = j; i >= 0; i--) {
			printf("%d", r[i]);
			fprintf(fp,"%d",r[i]);
		}
		printf("\n");
}
template<class T>
void AdvancedOperation<T>::multi()
{
		int j;
	    for (i = 0; i < 3000; i++) r[i] = 0; 
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				r[i + j] += a[i] * b[j];    //���ݳ˷��������������� 
			}
		}
		for (i = 0; i < n + m; i++) {  //��λ�Ĵ��� 
			if (r[i] >= 10) {
				r[i + 1] += r[i] / 10;
				r[i] %= 10;         
			}
		}
		for (j = 2999; j > 0; j--) {  //�Ӻ���ǰ�����������һλ��Ϊ��ʱ����Ϊ���������������һλ��ԭ����ȫΪ0�� 
			if (r[j] != 0)
				break;
		}
		fp=fopen("E:\\C++\\�߾����㷨\\multi.txt","w");
		for (i = j; i >= 0; i--) {
			printf("%d", r[i]);
			fprintf(fp,"%d",r[i]);
		}
		printf("\n");
}
template<class T>
int AdvancedOperation<T>::SubStract(int a[], int b[], int n, int m )
{
	int i;  
    if( n < m )  
        return -1;  
    if( n == m )  
    {                        //�ж�a > b  
        for( i=n-1; i>=0; i-- )  
        {  
            if( a[i] > b[i] )   //������������������������  
                break;  
            else if( a[i] < b[i] ) //���򷵻�-1  
                return -1;  
        }  
    }  
    for( i=0; i<=n-1; i++ )  //�ӵ�λ��ʼ������  
    {  
        a[i] -= b[i];  
        if( a[i] < 0 )          //��a<0������Ҫ��λ  
        {  
            a[i] += 10;         //��1��10  
            a[i+1]--;           //��λ��1  
        }  
    }
    
    for( i=n-1; i>=0; i-- )       //���ҽ�������λ  
        if( a[i] )               //���λ��һ����Ϊ0  
            return (i+1);       //�õ�λ��������  
    
    return 0;                  //������ȵ�ʱ�򷵻�0  
}
template<class T>
int AdvancedOperation<T>::divide()
{
	int j; 
    int nTimes;                 //���������λ��  
    int nTemp;                  //Subtract��������ֵ  
    for (i = 0; i < 3000; i++) r[i] = 0;   //�������ȫ������
	//int temp[n];                //temp�����ݴ�a�������ݣ�����������
	//for(j=0;j<n;j++)temp[j]=a[j]; 
 
        if( n < m )   //���������С�ڳ��������Ϊ0  
        {  
            cout<<"0"<<endl;    
        }  
        nTimes = n - m;    //���λ��  
        for ( i=n-1; i>=0; i-- )    //����������ʹ�ó����ͱ�����λ�����  
        {  
            if ( i>=nTimes )  
                b[i] = b[i-nTimes];  
            else                     //��λ��0  
                b[i] = 0;  
        }  
        m = n;  
        for(j=0; j<=nTimes; j++ )      //�ظ����ã�ͬʱ��¼���ɹ��Ĵ�������Ϊ��  
        {  
            while((nTemp = SubStract(a,b + j,n,m - j)) >= 0)  
            {  
                n = nTemp;      //�������  
                r[nTimes-j]++; //ÿ�ɹ���һ�Σ����̵���Ӧλ��1  
            }  
        }  
  
        //������  
        for( i=2999; r[i]==0 && i>=0; i-- );//������λ0  
        if( i>=0 ) 
		      {
                for( ; i>=0; i-- )  
                cout<<r[i];
			  }
        else  
            cout<<"0";  
        cout<<endl; 
        cout<<"����Ϊ��";
		for( i=n-1; i>=0; i-- )cout<<a[i];
        cout<<endl; 
        
        fp=fopen("E:\\C++\\�߾����㷨\\divide.txt","w");
		for (i = j-1; i >= 0; i--) {
			fprintf(fp,"%d",r[i]);
		}
		printf("\n");
		fprintf(fp,"\n%s","����Ϊ��");
		for( i=n-1; i>=0; i-- )fprintf(fp,"%d",a[i]);
		printf("\n");
		
        return 0; 
}
#endif
