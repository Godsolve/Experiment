#include<stdlib.h>
#include<time.h> 
#define _DICT  
#include<iostream>  
using namespace std; 
template<class E, class K>  
class HashTable {  
public:  
HashTable(int divisor = 11);  
~HashTable() {delete [ ] ht; delete [] empty;}  
bool Search(const K& k, E& e) const;  
HashTable<E,K>& Insert(const E& e);  
void Output(ostream& out) const;  
private:  
int hSearch(const K& k) const;  
int D; // ɢ�к����ĳ���  
E *ht; // ɢ������  
bool *empty; // һά����  
};  
template<class E, class K>  
HashTable<E,K>::HashTable(int divisor)  
{// ���캯��  
D = divisor;  
// ����ɢ������  
ht = new E[D];  
empty = new bool[D];  
// ������Ͱ�ÿ�  
for (int i = 0; i < D; i++)  
empty[i] = true;  
}  
  
  
template<class E, class K>  
int HashTable<E,K>::hSearch(const K& k) const  
{// ����һ������ַ��  
// ������ڣ��򷵻�k��λ��  
// ���򷵻ز���㣨������㹻�ռ䣩  
int i = k%D; // ��ʼͰ  
int j = i; // ����ʼͰ����ʼ  
do {  
if (empty[j] || ht[j] == k) return j;  
j = (j + 1) % D; // ��һ��Ͱ  
} while (j!=i); // �ַ�����ʼͰ  
return j; // ���Ѿ���  
}  
  
  
template<class E, class K>  
bool HashTable<E,K>::Search(const K& k, E& e) const  
{// ������kƥ���Ԫ�ز�����e  
// ���������������Ԫ�أ��򷵻�f a l s e  
int b = hSearch(k);  
if (empty[b]|| ht[b] != k) return false;  
e = ht[b];  
return true;  
}  
  
  
template<class E, class K>  
HashTable<E,K>& HashTable<E,K>::Insert(const E& e)  
{// ��ɢ�б��в���  
K k = e; // ��ȡk e yֵ  
int b = hSearch(k);  
// ����Ƿ�����ɲ���  
if (empty[b])   
{  
empty[b] = false;  
ht[b] = e;  
return *this;  
}  
  
  
// ���ܲ���, ����Ƿ����ظ�ֵ�����  
//if (ht[b] == k) throw BadInput(); // ���ظ�  
  
  
}  
  
  
template<class E, class K>  
void HashTable<E,K>::Output(ostream& out) const    
{    
    for (int i = 0; i < D; i++)  
    {  
     if (!empty[i])  
        cout<<ht[i]<<" ";  
    }  
  
  
}    
//����<<     
template<class E, class K>  
ostream& operator<<(ostream& out, const HashTable<E,K>& x)    
{    
    x.Output(out);     
    return out;    
}    
  
  
//���������ã�  
#include<iostream>  
#include"dict.h"  
using namespace std;  
int main()  
{  
    SortedChain<int ,int> myChain;  
    myChain.DistinctInsert(10).DistinctInsert(20).DistinctInsert(3);  
    cout<<myChain<<endl;  
  
  
    HashTable<int,int> myHash;  
      
    myHash.Insert(10).Insert(1).Insert(4);  
     cout<<myHash<<endl;  
    return 0;  
}  
