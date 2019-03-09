#include<iostream>
//using std::cout;
//using std::cin;
//using std::endl;
using namespace std;

const int MAX = 10;

template<class T>
void Subset(T list[],bool exists[], int k, int m)
{//list ȫ����exists �ж��Ƿ�������Ӽ��ڣ�k �ݹ������m �ݹ��յ�
    if(k == m-1) {
        //���ﵽ�յ�ʱ���������exists[i]�Ƿ�Ϊ0�ж��Ƿ��ڼ�����
        int i = 0;
        exists[k] = 0;
        cout<<"{";
        for(i=0; i<m-1; i++)
            if(exists[i]) cout << list[i] << ' ';
        if(exists[i]) cout << list[i];
        cout <<"}"<< endl;
        exists[k] = 1;
        cout<<"{";
        for(i=0; i<m-1; i++)
            if(exists[i]) cout << list[i] << ',';
        if(exists[i]) cout << list[i] << "}"<<endl;
        //cout<<"}";
        return;
    }
    exists[k] = 0;//����list[k]�����Ӽ���
    Subset(list,exists,k+1,m);
    exists[k] = 1;//����list[k]���Ӽ���
    Subset(list,exists,k+1,m);
}

int main()
{
    char ch[MAX];
    bool exists[MAX] = {0};
    int i = 0;
    while(i<MAX){
        cin.get(ch[i]);
        if(ch[i] == ' ' || ch[i] == '\n')
            break;
        i++;
    }
    //cout<<"{ }";
    Subset(ch,exists,0,i);
    //cout<<"..."<<endl;
}
