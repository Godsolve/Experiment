//BinaryTree.h----������ָ����Ķ�����
#pragma once
#include "LinkedQueue.h"
#include <string>
#include "xcept.h"
#include <stack> 
#include <iostream> 
using namespace std;
using std::string;
int _count;
template <class T> class BinaryTree;
template <class T> class MaxHeap;
template<class E, class K> class BSTree;
template <class T>
class BinaryTreeNode
{
 friend class BinaryTree<T>;
 friend class MaxHeap<T>;
 friend BSTree<T,int>;
public:
 BinaryTreeNode(){LeftChild = RightChild = Parent = 0;}
 BinaryTreeNode(const T& e)
 {
  data = e;
  LeftChild = RightChild = 0;
 }
 BinaryTreeNode(const T& e, BinaryTreeNode *l, BinaryTreeNode *r)
 {
  data = e;
  LeftChild = l;
  RightChild = r;
 }
 BinaryTreeNode(const T& e, BinaryTreeNode *l, BinaryTreeNode *r, BinaryTreeNode *m)
 {
  data = e;
  LeftChild = l;
  RightChild = r;
  Parent = m;
 }
 T getData(){ return this->data;}
private:
 T data;
 BinaryTreeNode<T> *LeftChild;
 BinaryTreeNode<T> *RightChild;
 BinaryTreeNode<T> *Parent;
};
template <class T>
class BinaryTree
{
 friend BSTree<T,int>;
public:
 BinaryTree(){root = 0;}
 ~BinaryTree(){};
 bool IsEmpty()const
 {return ((root)? false:true);}
 bool Root(T& x)const;
 void MakeTree(const T& element, BinaryTree<T>& left, BinaryTree<T>& right);
 void PreOrder(void(*visit)(BinaryTreeNode<T> *u)) //�ݹ�ǰ�����
 {PreOrder(visit, root);}
 void InOrder(void(*visit)(BinaryTreeNode<T> *u))  //�ݹ��������
 {InOrder(visit, root);}
 void PostOrder(void(*visit)(BinaryTreeNode<T> *u)) //�ݹ�������
 {PostOrder(visit, root);}
 void LevelOrder(void(*visit)(BinaryTreeNode<T> *u));    //������
 int Size(){_count = 0; PreOrder(Add1, root); return _count;}   //���ؽڵ���
 int Height()const {return Height(root);}       //���ض������ĸ߶�
 void PreOutput() {PreOrder(Output, root); cout << endl;}  
    void InOutput() {InOrder(Output, root); cout << endl;}
    void PostOutput() {PostOrder(Output, root); cout << endl;}
    void LevelOutput() {LevelOrder(Output); cout << endl;}
 BinaryTreeNode<T>* PreorderSearch(T target){return PreorderSearch(root, target);}
 string Trace(BinaryTreeNode<T>* Node,string cc);
private:
 BinaryTreeNode<T>* PreorderSearch(BinaryTreeNode<T>* pTree, T target);
    void PreOrder(void(*visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t);
 void InOrder(void(*visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t);
 void PostOrder(void(*visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t);
 static void Add1(BinaryTreeNode<T> *t){_count++;}
 int Height(BinaryTreeNode<T> *t) const;
 static void Output(BinaryTreeNode<T> *t) {cout << t->data << " ";}
    BinaryTreeNode<T> *root;
};
//ǰ�����  
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::PreorderSearch(BinaryTreeNode<T>* pTree, T target) { 
    stack<BinaryTreeNode<T>*> treeStack; 
    do { 
        while(pTree != 0) { 
   if (pTree->data == target && !pTree->LeftChild && !pTree->RightChild)
    return pTree;
            if(pTree->RightChild != 0) { 
                treeStack.push(pTree->RightChild); 
            } 
            pTree = pTree->LeftChild; 
        } 
        if(!treeStack.empty()) { 
            pTree = treeStack.top(); 
            treeStack.pop(); 
        } 
    }while(!treeStack.empty() || pTree != 0); 
    return 0;
}
// �жϲ����ظ��ڵ�
template <class T>
bool BinaryTree<T>::Root(T& x)const
{
 if(root)
 {
  x = root->data;
  return true;
 }
 else 
  return false;
}
//������
template <class T>
void BinaryTree<T>::MakeTree(const T& element, BinaryTree<T>& left, BinaryTree<T>& right)
{
 root = new BinaryTreeNode<T>(element, left.root, right.root);
 root->Parent = 0;
 if (left.root && right.root)
 {
  left.root->Parent = root;
  right.root->Parent = root;
 }
 else if (!left.root && right.root)
 {
  right.root->Parent = root;
 }
 else if (left.root && !right.root)
 {
  left.root->Parent = root;
 }
 left.root = right.root = 0;
}
//ǰ��
template <class T>
void BinaryTree<T>::PreOrder(void(*visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{
 if (t)
 {
  visit(t);
  PreOrder(visit, t->LeftChild);
  PreOrder(visit, t->RightChild);
 }
}
//����
template <class T>
void BinaryTree<T>::InOrder(void(*visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{
 if(t)
 {
  InOrder(visit, t->LeftChild);
  visit(t);
  InOrder(visit, t->RightChild);
 }
}
//����
template <class T>
void BinaryTree<T>::PostOrder(void(*visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{
 if(t)
 {
  PostOrder(visit, t->LeftChild);
  PostOrder(visit, t->RightChild);
  visit(t);
 }
}
template <class T>
void BinaryTree<T>::LevelOrder(void(*visit)(BinaryTreeNode<T> *u))
{//������
 LinkedQueue<BinaryTreeNode<T>*> Q;
 BinaryTreeNode<T> *t;
 t = root;
 while (t)
 {
  visit(t);
  if (t->LeftChild) Q.Add(t->LeftChild);
  if (t->RightChild) Q.Add(t->RightChild);
  try {Q.Delete(t);}
        catch (OutOfBounds) {return;}
 }
}
//�������ĸ߶�
template <class T>
int BinaryTree<T>::Height(BinaryTreeNode<T> *t) const
{
   if (!t) return 0;               
   int hl = Height(t->LeftChild);  
   int hr = Height(t->RightChild); 
   if (hl > hr) return ++hl;
   else return ++hr;
}
//�ݹ����ĳһ֧��,��ĳһ�ַ����б���
template <class T>
string BinaryTree<T>::Trace(BinaryTreeNode<T>* Node,string cc)
{
    if(Node->Parent)
    {
        if(Node->Parent->LeftChild == Node)
        {
            cc="1"+cc;
        }
        if(Node->Parent->RightChild==Node)
        {
            cc="0"+cc;
        }
        cc=Trace(Node->Parent,cc);
    }
    return cc;
}

// BSTree.h
// unbalanced binary search trees
#ifndef BSTree_
#define BSTree_
#include "BinaryTree.h"
#include "xcept.h"
template<class E, class K>
class BSTree : public BinaryTree<E> {
   public:
      bool Search(const K& k, E& e) const;
      BSTree<E,K>& Insert(const E& e);
      BSTree<E,K>& InsertVisit
                   (const E& e, void(*visit)(E& u));
      BSTree<E,K>& Delete(const K& k, E& e);
      void Ascend() {InOutput();}
};
template<class E, class K>
bool BSTree<E,K>::Search(const K& k, E &e) const
{
   BinaryTreeNode<E> *p = root;
   while (p) 
      if (k < p->data) p = p->LeftChild;
      else if (k > p->data) p = p->RightChild;
           else {
                 e = p->data;
                 return true;}
   return false;
}
template<class E, class K>
BSTree<E,K>& BSTree<E,K>::Insert(const E& e)
{
   BinaryTreeNode<E> *p = root,
                     *pp = 0;    
 
   while (p) {
      pp = p;
   
      if (e < p->data) p = p->LeftChild;
      else if (e > p->data) p = p->RightChild;
           else throw BadInput(); 
      }

   BinaryTreeNode<E> *r = new BinaryTreeNode<E> (e);
   if (root) {
      if (e < pp->data) pp->LeftChild = r;
      else pp->RightChild = r;}
   else 
        root = r;
   return *this;
}
template<class E, class K>
BSTree<E,K>& BSTree<E,K>::InsertVisit
               (const E& e, void(*visit)(E& u))
{
   BinaryTreeNode<E> *p = root, 
                     *pp = 0;  
   while (p) {
      pp = p;
      if (e < p->data) p = p->LeftChild;
      else if (e > p->data) p = p->RightChild;
           else {
                 visit(p->data);
                 return *this;};
      }
   BinaryTreeNode<E> *r = new BinaryTreeNode<E> (e);
   if (root) {
      if (e < pp->data) pp->LeftChild = r;
      else pp->RightChild = r;}
   else 
        root = r;
   return *this;
}
template<class E, class K>
BSTree<E,K>& BSTree<E,K>::Delete(const K& k, E& e)
{
   BinaryTreeNode<E> *p = root,
                     *pp = 0;   
   while (p && p->data != k){
      pp = p;
      if (k < p->data) p = p->LeftChild;
      else p = p->RightChild;
      }
   if (!p) throw BadInput();
   e = p->data;

   if (p->LeftChild && p->RightChild) {
  
      BinaryTreeNode<E> *s = p->LeftChild,
                        *ps = p;
      while (s->RightChild) {
         ps = s;
         s = s->RightChild;}
      p->data = s->data;
      p = s;
      pp = ps;}
   BinaryTreeNode<E> *c;
   if (p->LeftChild) c = p->LeftChild;
   else c = p->RightChild;
   if (p == root) root = c;
   else {
         if (p == pp->LeftChild)
              pp->LeftChild = c;
         else pp->RightChild = c;}
   delete p;
   return *this;
}
#endif
 
//Huffman.h----��������
#ifndef HUFFMAN_H_
#define HUFFMAN_H_
#include "BinaryTree.h"
#include "MinHeap.h"
template <class T>
class Huffman
{
public:
 operator T()const {return weight;}
 BinaryTree<char> HuffmanTree(T a[], char ch[], int n);
private:
 BinaryTree<char> tree;
 T weight;
};
template <class T>
BinaryTree<char> Huffman<T>::HuffmanTree(T a[], char ch[], int n)
{//����Ȩ��a[0:n-1]�����������
 Huffman<T> *w = new Huffman<T>[n + 1];
 BinaryTree<char> z, zero;
 for (int i = 1; i < n + 1; i++)
 {
  z.MakeTree(ch[i - 1], zero, zero);
  w[i].weight = a[i - 1];
  w[i].tree = z;
 }
 //����������С��
 MinHeap<Huffman<T>> H(1);
 H.Initialize(w, n, n);
 //�����е������Ϻϲ�
 Huffman<T> x, y;
 for (int i = 1; i < n; i++)
 {
  H.DeleteMin(x);
  H.DeleteMin(y);
  z.MakeTree(i, x.tree, y.tree);
  x.weight += y.weight;
  x.tree = z;
  H.Insert(x);
 }
 H.DeleteMin(x);
 H.Deactivate();
 delete []w;
 return x.tree;
}
#endif
 
//LinkedQueue.h
#ifndef LINKEDQUEUE_H_
#define LINKEDQUEUE_H_
#include "xcept.h"
template <class T> class LinkedQueue;
template <class T>
class Node
{
 friend class LinkedQueue<T>;
private:
 T data;
 Node<T> *link;
};

template<class T>
class LinkedQueue {
   public:
      LinkedQueue() {front = rear = 0;} 
      ~LinkedQueue();
      bool IsEmpty() const
           {return ((front) ? false : true);}
      bool IsFull() const;
      T First() const; 
      T Last() const; 
      LinkedQueue<T>& Add(const T& x);
      LinkedQueue<T>& Delete(T& x);
   private:
      Node<T> *front; 
      Node<T> *rear;
};
template<class T>
LinkedQueue<T>::~LinkedQueue()
{
   Node<T> *next;
   while (front) {
      next = front->link; 
      delete front; 
      front = next;
      }
}
template<class T>
bool LinkedQueue<T>::IsFull() const
{
   Node<T> *p;
   try {p = new Node<T>;
        delete p;
        return false;}
   catch (NoMem) {return true;}
}
template<class T>
T LinkedQueue<T>::First() const
{
   if (IsEmpty()) throw OutOfBounds();
   return front->data;
}
template<class T>
T LinkedQueue<T>::Last() const
{
   if (IsEmpty()) throw OutOfBounds();
   return rear->data;
}
template<class T>
LinkedQueue<T>& LinkedQueue<T>::Add(const T& x)
{//���
   Node<T> *p = new Node<T>;
   p->data = x;
   p->link = 0;
   if (front) rear->link = p; 
   else front = p;             
   rear = p;
   return *this;
}
template<class T>
LinkedQueue<T>& LinkedQueue<T>::Delete(T& x)
{//ɾ��
   if (IsEmpty()) throw OutOfBounds();
   x = front->data;
   Node<T> *p = front;
   front = front->link;
   delete p;
   return *this;
}
 
#endif

//MaxHeap.h----���ѵ�ʵ��
#ifndef MAXHEAP_H_
#define MAXHEAP_H_
#include "xcept.h"
#include "LinkedQueue.h"
#include "swap.h"
#include "BinaryTree.h"
#include <iostream>
using namespace std;
template <class T>
class MaxHeap
{
public:
 MaxHeap(){root = 0;}
 ~MaxHeap(){Free();}
 void MakeHeap(const T& element, MaxHeap<T>& left, MaxHeap<T>& right);
 T Max(){  if (!root) throw OutOfBounds(); return root.data;}
 MaxHeap<T>& Insert(T x);          //�������в���Ԫ��
 MaxHeap<T>& DeleteMax(T& x);       //��������ɾ�����ڵ㲢������ֵ���ص�x��
 void Initialize(T a[], int n);                 //��ʼ������
 MaxHeap<T>& Meld(MaxHeap<T>& x){    //�ϲ����������
                Meld(root,x.root);
                return *this;}
 void PreOrder(void(*visit)(BinaryTreeNode<T> *u)) //�ݹ�ǰ�����
 {PreOrder(visit, root);}
 void InOrder(void(*visit)(BinaryTreeNode<T> *u))  //�ݹ��������
 {InOrder(visit, root);}
 void PostOrder(void(*visit)(BinaryTreeNode<T> *u)) //�ݹ�������
 {PostOrder(visit, root);}
 void LevelOrder(void(*visit)(BinaryTreeNode<T> *u));    //������
 void PreOutput(){PreOrder(Output, root); cout << endl;}  
    void InOutput(){InOrder(Output, root); cout << endl;}
    void PostOutput(){PostOrder(Output, root); cout << endl;}
    void LevelOutput(){LevelOrder(Output); cout << endl;}        //ǰ�к������
 void Free(){PostOrder(Free, root); root = 0;}     //��������ͷ�һ���������нڵ�
 void HeapSort(T a[], int n);     //������aԪ�ؽ��ж�����
private:
 BinaryTreeNode<T> *root;
 static void Output(BinaryTreeNode<T> *t) {cout << t->data << " ";}
 void PreOrder(void(*visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t);
 void InOrder(void(*visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t);
 void PostOrder(void(*visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t);
 void Meld(BinaryTreeNode<T> * &x, BinaryTreeNode<T> *y);
 static void Free(BinaryTreeNode<T> *t){delete t;}
};
template <class T>
void MaxHeap<T>::Initialize(T a[], int n)
{
    LinkedQueue<BinaryTreeNode<T>*> Q;
    Free(root);
 for (int i = 0; i < n; i++)
 {
  BinaryTreeNode<T> *q = new BinaryTreeNode<T>(a[i]);
  Q.Add(q);
 }
 BinaryTreeNode<T> *b, *c;
 for (int i = 1; i <= n - 1; i++)
 {
     Q.Delete(b).Delete(c);
  Meld(b, c);
  Q.Add(b);
 }
 if (n)
  Q.Delete(root);
}
template <class T>
MaxHeap<T>& MaxHeap<T>::Insert(T x)
{//�������в���Ԫ��x�������ز���Ԫ�غ������
    BinaryTreeNode<T> *temp = new BinaryTreeNode<T>(x);
 Meld(root, temp);
 return *this;
}
template <class T>
MaxHeap<T>& MaxHeap<T>::DeleteMax(T& x)
{//ɾ�������е����Ԫ�أ�������ɾ��Ԫ�غ������
 if (!root) throw OutOfBounds();
 x = root->data;
 BinaryTreeNode<T> *heap1 = root->LeftChild;
 BinaryTreeNode<T> *heap2 = root->RightChild;
 delete root;
 root = heap1;
 Meld(root, heap2);
 return *this;
}

template <class T>
void MaxHeap<T>::MakeHeap(const T& element, MaxHeap<T>& left, MaxHeap<T>& right)
{//����������
    root = new BinaryTreeNode<T>(element, left.root, right.root);
 left.root = right.root = 0;
}
template <class T>
void MaxHeap<T>::PreOrder(void(*visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{//ǰ�����
 if (t)
 {
  visit(t);
  PreOrder(visit, t->LeftChild);
  PreOrder(visit, t->RightChild);
 }
}
template <class T>
void MaxHeap<T>::InOrder(void(*visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{//�������
 if(t)
 {
  InOrder(visit, t->LeftChild);
  visit(t);
  InOrder(visit, t->RightChild);
 }
}
template <class T>
void MaxHeap<T>::PostOrder(void(*visit)(BinaryTreeNode<T> *u),BinaryTreeNode<T> *t)
{//�������
 if(t)
 {
  PostOrder(visit, t->LeftChild);
  PostOrder(visit, t->RightChild);
  visit(t);
 }
}
template <class T>
void MaxHeap<T>::LevelOrder(void(*visit)(BinaryTreeNode<T> *u))
{//������
 LinkedQueue<BinaryTreeNode<T>*> Q;
 BinaryTreeNode<T> *t;
 t = root;
 while (t)
 {
  visit(t);
  if (t->LeftChild) Q.Add(t->LeftChild);
  if (t->RightChild) Q.Add(t->RightChild);
  try {Q.Delete(t);}
        catch (OutOfBounds) {return;}
 }
}
template <class T>
void MaxHeap<T>::Meld(BinaryTreeNode<T> * &x, BinaryTreeNode<T> *y)
{//�ϲ����������
   if (!y) return;   //yΪ��
   if (!x)
   {//xΪ��
    x = y;
    return;
   }
   
   if (x->data < y->data)
    Swap(x, y);
    Meld(x->RightChild, y);
 if (!x->LeftChild)
 {
  x->LeftChild = x->RightChild;
  x->RightChild = 0;
 }
}
template <class T>
void MaxHeap<T>::HeapSort(T a[], int n)
{//������
 MaxHeap<T> H;
 H.Initialize(a, n);
 T x;
 for (int i = n-1; i >= 0; i--)
 {
  H.DeleteMax(x);
  a[i] = x;
 }
}
#endif


