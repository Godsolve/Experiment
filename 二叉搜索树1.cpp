//2��	���ռ���¼��Ķ�����ǰ�����к���������(��Ԫ�ظ�����ͬ)������ö������ĺ������С�
//*3�������������Ĺ����Լ����������������
#include<iostream>
using namespace std;

template<class T>
struct binaryTreeNode
{
	T element;
	binaryTreeNode<T> *leftChild,*rightChild;
	binaryTreeNode(){leftChild=rightChild=NULL;}
	binaryTreeNode(T theElement):element(theElement)
	{
		
		leftChild=rightChild=NULL;
	}
	binaryTreeNode(T theElement,binaryTreeNode *theLeftChild,binaryTreeNode *theRightChild):element(theElement)
	{
		
		leftChild=theLeftChild;
		rightChild=theRightChild;
	}
 };
template<class K,class E>
class binarySearchTree
{
	public:
	  binarySearchTree() {root = NULL; treeSize = 0;}
      bool empty()  {return treeSize == 0;}
      int size() {return treeSize;}
      pair<K, E>* find( K theKey);
      void insert( pair<K, E> thePair);
      void erase(K theKey);
      void inOrderOutput();
    private:
    	int treeSize;
    	binaryTreeNode<pair<K,E> > *root;   
    	void inOrder(binaryTreeNode<pair<K,E> >* t);
};
template<class K, class E>
 void binarySearchTree<K,E>::inOrderOutput()
 {
 	inOrder(root);
 }
 template<class K, class E>
 void binarySearchTree<K,E>::inOrder(binaryTreeNode<pair<K,E> >* t)
 {	// �������
   if (t != NULL)
   {
      inOrder(t->leftChild);
      cout<<t->element.first<<"  "<<t->element.second<<"      ";
      inOrder(t->rightChild);
   }
 }
template<class K, class E>
void binarySearchTree<K,E>::insert( pair<K, E> thePair)
{//����thepair�������������ؼ�����ͬ�����ԣ��򸲸� 
   binaryTreeNode<pair<K, E> > *p = root,
                                *pp = NULL;
   while (p != NULL)
   {// ���Ԫ�� p->element
      pp = p;
      // �ƶ�p������һ�����ӽڵ� 
      if (thePair.first < p->element.first)
         p = p->leftChild;
      else
         if (thePair.first > p->element.first)
            p = p->rightChild;
         else
         {// ���Ǿ�ֵ 
            p->element.second = thePair.second;
            return;
         }
   }

   // �����½ڵ㣬Ȼ����pp���� 
   binaryTreeNode<pair<K, E> > *newNode
                 = new binaryTreeNode<pair<K, E> > (thePair);
   if (root != NULL) //������ǿ� 
      if (thePair.first < pp->element.first)
         pp->leftChild = newNode;
      else
         pp->rightChild = newNode;
   else
      root = newNode; // ���������� 
   treeSize++;
}

template<class K, class E>
void binarySearchTree<K,E>::erase(K theKey)
{// ɾ���ؼ���Ϊthekey������ 

   // ���ҹؼ���Ϊthekey�Ľڵ� 
   binaryTreeNode<pair<K, E> > *p = root,
                                     *pp = NULL;
   while (p != NULL && p->element.first != theKey)
   {// ��p�ƶ�������һ�����ӽڵ� 
      pp = p;
      if (theKey < p->element.first)
         p = p->leftChild;
      else
         p = p->rightChild;
   }
   if (p == NULL)
      return; // û��ƥ�������򷵻� 


   // ��p����������ʱ 
   if (p->leftChild != NULL && p->rightChild != NULL)
   {// ��p����������Ѱ�����Ԫ�� 
      binaryTreeNode<pair<K, E> > *s = p->leftChild,
                                       *ps = p; //psΪp�ĸ��� 
      while (s->rightChild != NULL)
      {// �ƶ������Ԫ��
         ps = s;
         s = s->rightChild;
      }

      // �����Ԫ��s�ƶ���p
      binaryTreeNode<pair<K, E> > *q =
         new binaryTreeNode<pair<K, E> >
             (s->element, p->leftChild, p->rightChild);
      if (pp == NULL)
         root = q;
      else if (p == pp->leftChild)
              pp->leftChild = q;
           else
              pp->rightChild = q;
      if (ps == p) pp = q;
      else pp = ps;
      delete p;
      p = s;
   }

   // p���ֻ��һ������ 
   // �Ѻ���ָ������p 
   binaryTreeNode<pair<K, E> > *c;
   if (p->leftChild != NULL)
      c = p->leftChild;
   else
      c = p->rightChild;

  
   if (p == root)
      root = c;
   else
   {// ������ͷŵĽڵ�ĸ��������� 
      if (p == pp->leftChild)
         pp->leftChild = c;
      else pp->rightChild = c;
   }
   treeSize--;
   delete p;
}
int main()
{
	binarySearchTree<int,int> a;
	pair<int, int> p;
	int m,n,number;
	cout<<"������Ҫ����ĸ�����";
	cin>>number;
	for(int i=0;i<number;i++)
	{
	  cout<<"������ؼ��֣�";
	  cin>>m;
	  cout<<"������ֵ��";
	  cin>>n;
	  p.first=m;p.second=n;
	  a.insert(p);	
	}

	cout<<"a�Ľڵ�����"<<a.size()<<endl;
	cout<<"a�ĺ��������"; 
	a.inOrderOutput();
    cout<<endl;
    int temp;
    cout<<"��������Ҫɾ���Ľڵ�Ĺؼ��֣�";
    cin>>temp;
    a.erase(temp);
	cout<<"a�ĺ��������"; 
	a.inOrderOutput();
    cout<<endl;
    int mm,nn;
    cout<<"��������Ҫ����Ľڵ�ؼ���:"<<endl; 
    cin>>mm;
    cout<<"��������Ҫ����Ľڵ�ֵ:"<<endl;
    cin>>nn;
    p.first=mm;p.second=nn;
	a.insert(p);
    cout<<"a�Ľڵ�����"<<a.size()<<endl;
	cout<<"a�ĺ��������"; 
	a.inOrderOutput();
    cout<<endl;
	
	return 0;
}
