#include<iostream>
#include<stdlib.h>
#include<time.h> 
using namespace std;
template<class K,class E>
struct pairNode
{
	typedef pair< K, E> pairType;
	pair< K,E> element;
	pairNode< K,E> *next;
	
   pairNode(pairType thePair):element(thePair){}
   pairNode(pairType thePair, pairNode<K,E>* theNext)
            :element(thePair){next=theNext;}
};
template<class K,class E>
class sortedChain
{
	public:
		sortedChain(){firstNode=NULL;dSize=0;}
		~sortedChain();
		
		bool empty(){return dSize == 0;}
        int size() {return dSize;}
		pair< K,E> *find(K theKey);
		void insert(pair< K,E> thePair);
		void erase(K theKey);
		void output(ostream& out);
	protected:
		pairNode<K,E> *firstNode;//ָ������ͷ�� 
		int dSize;//�������Ը��� 
};
template<class K, class E>
sortedChain<K,E>::~sortedChain()
{// �������� 
   while (firstNode != NULL)
   {
      pairNode<K,E>* nextNode = firstNode->next;
      delete firstNode;
      firstNode = nextNode;
   }
}
template<class K, class E>
pair<K,E>* sortedChain<K,E>::find(K theKey) 
{
   pairNode<K,E>* currentNode = firstNode;

  //�����ؼ���ΪtheKey������ 
   while (currentNode != NULL && 
          currentNode->element.first != theKey)
      currentNode = currentNode->next;

   //�ж��Ƿ�ƥ�� 
   if (currentNode != NULL && currentNode->element.first == theKey)
      return &currentNode->element;

   // ��ƥ������� 
   return NULL;
}
template<class K, class E>
void sortedChain<K,E>::insert(pair<K, E> thePair)
{
   pairNode<K,E> *p = firstNode,
                *tp = NULL; 
   // �ƶ�ָ��tp��ʹthePair���Բ���tp���� 
   while (p != NULL && p->element.first < thePair.first)
   {
      tp = p;
      p = p->next;
   }
   // �ж��Ƿ���ƥ������ԣ�����У��򸲸� 
   if (p != NULL && p->element.first == thePair.first)
   {
      p->element.second = thePair.second;
      return;
   }
   // ���û�У����½��ڵ㣬������ 
   pairNode<K,E> *newNode = new pairNode<K,E>(thePair, p); 
   if (tp == NULL) firstNode = newNode;
   else tp->next = newNode;
   //���ȼ�һ 
   dSize++;
   return;
}
template<class K, class E>
void sortedChain<K,E>::erase(K theKey)
{// ɾ���ؼ���ΪtheKey������ 
   pairNode<K,E> *p = firstNode,
                *tp = NULL; // tp trails p
   // �����ؼ���ΪtheKey������ 
   while (p != NULL && p->element.first < theKey)
   {
      tp = p;
      p = p->next;
   }
   // �ж��Ƿ�ƥ�� �����ƥ����ɾ�� 
   if (p != NULL && p->element.first == theKey)
   {
      if (tp == NULL) firstNode = p->next;  
      else tp->next = p->next;
      delete p;
      dSize--;
   }
}
template<class K, class E>
void sortedChain<K,E>::output(ostream& out)
{// ��element��������� 
   for (pairNode<K,E>* currentNode = firstNode;
                       currentNode != NULL;
                       currentNode = currentNode->next)
      out << currentNode->element.first << " "
          << currentNode->element.second << "   ";
}

// ����<<
template <class K, class E>
ostream& operator<<(ostream& out, sortedChain<K,E>& x)
   {x.output(out); return out;}
   

 template <class K> class hash;

template<>
class hash<string>
{
   public:
      size_t operator()(const string theKey) const
      {// 
         unsigned long hashValue = 0; 
         int length = (int) theKey.length();
         for (int i = 0; i < length; i++)
            hashValue = 5 * hashValue + theKey.at(i);
    
         return size_t(hashValue);
      }
};

template<>
class hash<int>
{
   public:
      size_t operator()(const int theKey) const
      {return size_t(theKey);}
};

template<>
class hash<long>
{
   public:
      size_t operator()(const long theKey) const
      {return size_t(theKey);}
};
 

   
template <class K,class E>
class hashChains
{
	public:
      hashChains(int theDivisor = 11)
      {
         divisor = theDivisor;
         dSize = 0;
         table = new sortedChain<K,E> [divisor];
      }

      ~hashChains(){delete [] table;}

      bool empty() {return dSize == 0;}
      int size()  {return dSize;}

      pair< K, E>* find( K& theKey) 
         {return table[hash(theKey) % divisor].find(theKey);
		   //return table[theKey%divisor].find(theKey);
		 }

      void insert( pair< K, E>& thePair)
      {
        int homeBucket = (int) hash(thePair.first) % divisor;
        // int homeBucket = (thePair.first) % divisor;
         int homeSize = table[homeBucket].size();
         table[homeBucket].insert(thePair);
         if (table[homeBucket].size() > homeSize)
            dSize++;
      }

      void erase(K& theKey)
         {table[hash(theKey) % divisor].erase(theKey);
		    // table[theKey%divisor].erase(theKey);
		 }

      void output(ostream& out) 
      {
         for (int i = 0; i < divisor; i++)
         {
         	cout<<i<<": "; 
         	if (table[i].size() == 0)
               cout << "NULL" << endl;
            else
               cout << table[i] << endl;
         }
            
      }


   protected:
      sortedChain<K, E>* table;  // ��ϣ��
      hash<K> hash;              // hashmap 
      int dSize;                 // Ԫ�ظ���
      int divisor;               // divisor
};
 // ���ز�����<<
template <class K, class E>
ostream& operator<<(ostream& out, hashChains<K,E>& x)
   {x.output(out); return out;}

int main()
{
	hashChains<int,int> z(961);
	pair<int, int> p;
    int a; 
	
	srand((int)time(0)); 
	for(int i=0;i<500;i++)
	{
		a=p.first=rand();p.second=rand();
		z.insert(p);
	}

	cout<<z.size()<<endl;
	cout<<z<<endl;
	cout<<"Ѱ�� "<<" "<<a%961<<":"<<z.find(a)->first<<"  "<<z.find(a)->second<<endl;
	
	return 0;
} 



