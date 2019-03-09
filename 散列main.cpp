#ifndef _DICT     
#define _DICT  
#include<iostream>  
using namespace std;  
template<class E,class K> class SortedChain;  
template <class E ,class K>  
class SortedChainNode  
{  
friend class SortedChain<E,K>;  
private:  
K data;  
SortedChainNode<E,K> *link;  
};  
//E��ʾ����Ԫ�ص���������, K���������������õ��Ĺؼ���  
template<class E ,class K>  
class SortedChain  
{  
public:  
SortedChain() {first =0;}  
~SortedChain(){ }  
bool IsEmpty() const {return first ==0;}  
//int Length() const;  
bool Search(const K& k , E& e) const;  
SortedChain<E ,K>& Delete(const K& k , E& e);  
//SortedChain<E ,K>& Insert(const E& e);  
SortedChain<E ,K>& DistinctInsert(const E& e);  
void Output(ostream& out) const;  
private:  
SortedChainNode<E ,K> *first;  
};  
template<class E, class K>  
bool SortedChain<E,K>::Search(const K& k, E& e) const  
{// ������kƥ���Ԫ�أ��������e  
// ���û��ƥ���Ԫ�أ��򷵻�f a l s e  
SortedChainNode<E,K> *p =first;  
// ������k��ƥ���Ԫ��  
for (;p&& p->data < k;p = p->link);  
// ��֤�Ƿ���kƥ��  
if (p && p->data == k) // ��k��ƥ��  
{e = p->data; return true;}  
return false; // ��������ƥ���Ԫ��  
}  
  
  
template<class E, class K>  
SortedChain<E,K>& SortedChain<E,K>  
::Delete(const K& k, E& e)  
{// ɾ����k��ƥ���Ԫ��  
// ������ɾ����Ԫ�ط���e  
// ���������ƥ��Ԫ�أ��������쳣B a d I n p u t  
SortedChainNode<E,K> *p = first,  
*tp = 0; //����p  
// ������k��ƥ���Ԫ��  
for (; p && p->data < k; tp = p,p = p->link;)  
  
  
// ��֤�Ƿ���kƥ��  
if (p && p->data == k) {// �ҵ�һ����ƥ���Ԫ��  
e = p->data; // ����d a t a��  
// ��������ɾ��p��ָ���Ԫ��  
if (tp) tp->link = p->link;  
else first = p->link; // p�����׽ڵ�  
delete p;  
}  
  
  
return *this;  
  
  
}  
  
  
template<class E, class K>  
SortedChain<E,K>& SortedChain<E,K>::DistinctInsert(const E& e)  
{// ������в����ڹؼ�ֵ��e��ͬ��Ԫ�أ������e  
  
  
SortedChainNode<E,K> *p = first, *tp = 0; // ����p  
// �ƶ�tp �Ա��e ���뵽t p֮��  
for (; p && p->data < e; tp = p, p = p->link);  
// ���ؼ�ֵ�Ƿ��ظ�  
//if (p && p->data == e)  return NULL;  
// ��û�г����ظ��ؼ�ֵ, �����һ���ؼ�ֵΪe���½ڵ�  
SortedChainNode<E,K> *q = new SortedChainNode<E,K>;  
q->data = e;  
// ���½ڵ���뵽t p֮��  
q->link = p;  
if (tp) tp->link = q;  
else first = q;  
return *this;  
}  
  
  
template<class E, class K>  
void SortedChain<E,K>::Output(ostream& out) const    
{// ������Ԫ�����������     
SortedChainNode<E,K> *current;    
for (current=first; current; current = current->link)    
out<<current->data<<" ";    
}    
  
  
//����<<     
template<class E, class K>  
ostream& operator<<(ostream& out, const SortedChain<E,K>& x)    
{    
    x.Output(out);     
    return out;    
}    
  
  
#endif  
  
  
#include<iostream>  
#include"dict"  
using namespace std;  
int main()  
{  
    SortedChain<int ,int> myChain;  
    myChain.DistinctInsert(10).DistinctInsert(20).DistinctInsert(3);  
    cout<<myChain<<endl;  
    return 0;  
} 
