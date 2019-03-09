
#include <iostream>

using namespace std;

template<class T>

struct Node//�ڵ㶨�� 

{

  T data;

  Node<T> *next;

};

template<class T>

class LinkList  //���������� 

{

  Node<T> *head;

  public:

  LinkList();

  LinkList(T a[], int n);

  ~LinkList();  //�������� 

  int ListLength();

  T Get(int pos);

  int Locate(T item);

  void PrintLinkList();

  void Insert(int i, T item);

  T Delete(int i);

  void Invert();

  void Merge(LinkList<T> &L1,LinkList<T> &L2);

};

template<class T>

LinkList<T>::LinkList() 

{  //���캯�� 

  head=new Node<T>;

  head->next=NULL;

}

template<class T>

LinkList<T>::LinkList(T a[], int n)

{  //���캯�����ڶ������� 

  Node<T> *s, *r;

  head=new Node<T>;

  r=head;

  for(int i=0; i<n; i++)

  {

    s=new Node<T>;

    s->data=a[i];

    r->next=s;

    r=s;

  }

  r->next=NULL;

}

template<class T>

int LinkList<T>::ListLength()
{  //�õ������� 
  Node<T> *p;

  int num = 0;

  p = head -> next;

  while(p)
  {
    p = p-> next;
    num++;
  }
  return num;
}

template<class T>

T LinkList<T>::Get(int pos)

{  //�õ�Ԫ������λ�� 

  Node<T> *p;

  p = head -> next;

  int j=1;

  while(p && j<pos)

  {

    p=p->next;

    j++;

  }

  if(!p) {cerr<<"����λ�÷Ƿ�";exit(1);}

  else return p->data;

}

template<class T>

int LinkList<T>::Locate(T item)

{  //�õ���λ�õ�Ԫ�� 

  Node<T> *p;

  p=head->next;

  int j=1;

  while(p && p->data!=item)

  {

    p=p->next;

    j++;

  }

  if(p) return j;

  else return 0;

}

template<class T>

void LinkList<T>::PrintLinkList()
{  //��ӡԪ�� 
  Node<T> *p;
  p=head->next;
  while(p)
  {
    cout<<p->data<<"  ";
    p=p->next;
  }
  cout<<endl;
}

template<class T>
void LinkList<T>::Insert(int i, T item)
{   //����Ԫ�� 
  Node<T> *p,*s;

  p=head;

  int j=0;

  while(p && j < i-1)

  {

    p=p -> next;

    j++;

  }

  if(!p) {cerr<<"����λ�÷Ƿ�"; exit(1);}

  else {

    s=new Node<T>;

    s->data=item;

    s->next=p->next;

    p->next=s;

  }

}

template<class T>

T LinkList<T>::Delete(int i)
{  //ɾ��Ԫ�� 
  Node<T> *p,*q;
  T x;
  p=head;
  int j=0;
  while(p && j<i-1)
  {
    p=p->next;

    j++;

  }

  if(!p || !p->next) {cerr<<"ɾ��λ�÷Ƿ�";exit(1);}

  else

  {

    q=p->next;

    x=q->data;

    p->next=q->next;

    delete q;

    return x;

  }

} 

template<class T>

LinkList<T>::~LinkList()

{  //������������������LinkList 

  Node<T> *p,*q;

  p=head;

  while(p)

  {

    q=p;

    p=p->next;

    delete q;

  }

  head=NULL;

}

template<class T>

void LinkList<T>::Invert()

{  //������Ԫ�ط��� 

Node<T> *p,*q;

p=head->next;

head->next=NULL;

while(p!=NULL)

{

q=p;

p=p->next;

q->next=head->next;

head->next=q;

}

}

template<class T>

void LinkList<T>::Merge(LinkList<T> &L1,LinkList<T> &L2)

{  //�ϲ����������Ԫ�� 

Node<T> *p1,*p2,*p3;

p1=L1.head->next;

p2=L2.head->next;

p3=L1.head;

while((p1!=NULL)&&(p2!=NULL))

{

if((p1->data)<(p2->data))

{

p3->next=p1;

p1=p1->next;

p3=p3->next;

}

else

{

p3->next=p2;

p2=p2->next;

p3=p3->next;

}

}

if(p1!=NULL) p3->next=p1;

if(p2!=NULL) p3->next=p2;

delete L2.head;//�ϲ���ɺ�ɾ���ڶ������� 

L2.head=NULL;

}

int main()

{

int a[]={1,2,5,7,8,9,6};;

int b[]={9,8,6,5,2,7,3}; 
LinkList<int> c(a,7);
cout<<"������Ԫ���ǣ�"<<endl;
c.PrintLinkList();
cout<<"������ĳ����ǣ�"<<c.ListLength()<<endl;
int k;
bool f=true;
while(f)
{
cout<<"��ѡ����Ҫ���еĲ�����"<<endl;
cout<<"1.����Ԫ��  2.ɾ��Ԫ��  3.����ָ��Ԫ��  \n4.����ָ��λ��Ԫ��  5.�������  6.����ϲ�  7.�˳�"<<endl;
cin>>k;
int m,p;
switch(k)
   {
	case 1:
		cout<<"��Ҫ�����λ�ü�Ԫ�أ�"<<endl;
		cin>>m;
		cin>>p;
		cout<<"�ڵ�"<<m<<"��λ�ò���ֵΪ"<<p<<"��Ԫ�أ�"<<endl;
        c.Insert(m,p);
        c.PrintLinkList();
        break;
    case 2:
    	cout<<"��Ҫɾ��ɾ���ڼ�λԪ�أ�"<<endl;
    	int o;
		cin>>o; 
		cout<<"ɾ��˳���ĵ�"<<o<<"��Ԫ�أ�"<<endl;
        c.Delete(o);
    	c.PrintLinkList();
    	break;
    case 3:
    	cout<<"��Ҫ����ʲôԪ�أ�"<<endl;
    	int i;
    	cin>>i;
    	cout<<"�������Ԫ��Ϊ"<<i<<"���ǵ�"<<c.Locate(i)<<"��Ԫ��"<<endl;
    	break;
    case 4:
    	cout<<"��Ҫ�����ĸ�λ�õ�Ԫ�أ�"<<endl;
    	int u;
    	cin>>u;
        cout<<"������ĵ�"<<u<<"��Ԫ���ǣ�"<<c.Get(u)<<endl;
        break;
    case 5:
    	c.Invert();
        cout<<"������Ԫ���ǣ�"<<endl;
        c.PrintLinkList();
        break;
    case 6: 
        LinkList<int> d(b,7);
        cout<<"�ڶ�������Ԫ���ǣ�"<<endl;
        d.PrintLinkList();
        c.Merge(c,d);
        cout<<"�ϲ����Ԫ���ǣ�"<<endl;
        c.PrintLinkList();
        break;
    Default:
	    f=false;
	    break;
    }
}
}
