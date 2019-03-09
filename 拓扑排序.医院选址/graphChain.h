#ifndef graphChain_
#define graphChain_

#include "graphNode.h"
#include<iostream>
using namespace std;
template<class T>
class graphChain
{
	public:
		graphChain();
		//~graphChain();
		void erase(T theElement);
		bool empty() {return listSize==0;}
        int size(){return listSize;}
        T getElement(int theIndex);
        int getWeight(int theIndex);
        int indexOf(const T& theElement);
        void insert(T theElement,int theWeight);
        void insertHead(T theElement,int theWeight);
        graphNode<T> * first(){return firstNode;}
        graphNode<T> * last(){return lastNode;}
        
	class iterator
	{
		public:
			iterator(graphNode<T>* theNode=NULL)
			{ node=theNode;
			}
			T& operator*() const {return node->element;}
			T* operator->() const{return &node->element;}
	        iterator& operator++()
			{
				node=node->next;
				return *this;
			}
			iterator& operator--()
			{
				node=node->pre;
				return *this;
			}
			bool operator!=(const iterator right)const
			{
				return node !=right.node;
			}
			bool operator==(const iterator right)const
			{
				return node==right.node;
			}
			
		private:
				graphNode<T>* node;
	};
//******************************************************* 
	iterator begin()//ͷָ�� 
			{
			  return iterator(firstNode);
			}
			
	iterator end()//βָ�� 
			{
				return iterator(lastNode);
			}
			
    private:
	int listSize;
	graphNode<T> *firstNode;
	graphNode<T> *lastNode; 
		
}; 
template<class T>
graphChain<T>::graphChain()
{
	listSize=0;
	firstNode=lastNode=NULL;
}
template<class T>
T graphChain<T>::getElement(int theIndex) 
	{ 
	  if(theIndex<listSize)
	  {
	  	graphNode<T>* currentNode=firstNode;
	  	for(int i=0;i<theIndex;i++)
		  {
		  	currentNode=currentNode->next;
		  }
		return currentNode->element;
	  }  
	  else
	  {
	  	cout<<"enter a correct number:";
	  }
	}
	template<class T>
int graphChain<T>::getWeight(int theIndex) 
	{ 
	  if(theIndex<listSize)
	  {
	  	graphNode<T>* currentNode=firstNode;
	  	for(int i=0;i<theIndex;i++)
		  {
		  	currentNode=currentNode->next;
		  }
		return currentNode->weight;
	  }  
	  else
	  {
	  	cout<<"enter a correct number:";
	  }
	}
template<class T>
int graphChain<T>::indexOf(const T& theElement) 
{
        graphNode<T>* currentNode=firstNode;
		int i=0;
		while(currentNode!=NULL&&currentNode->element!=theElement)
		{   currentNode=currentNode->next;
		    i++;
		}		
		if(currentNode==NULL)//���Ա��в����ڴ�Ԫ�� 
		return -1; 
		else
		return i;
}
template<class T>	
void graphChain<T>::erase(T theElement)
{   if(listSize<=0)//������Ա�Ϊ�� 
	      cout<<"it's empty"<<endl;
	    else if(listSize==1)//�������ֻ��һ��Ԫ�� 
          { if(firstNode->element==theElement)//����ͷΪ��Ҫɾ����Ԫ��ʱ 
		    {
			 firstNode=lastNode=NULL;
		     listSize--;
			}
			else
			cout<<"there is not theElement"<<endl;
	      }
	    else//���Ԫ�ص���� 
		{ if(firstNode->element==theElement)//�����һ��Ԫ��ΪҪɾ����Ԫ�� 
		   {firstNode=firstNode->next;
		    firstNode->pre=NULL;
		    listSize--;
		   }
		  else if(lastNode->element==theElement)//������һ��Ԫ��ΪҪɾ����Ԫ�� 
		    {lastNode=lastNode->pre;
		     lastNode->next=NULL;
		     listSize--;
		    }
		  else{//������� 
		 graphNode<T>* currentNode=firstNode->next;
		 graphNode<T>* p=firstNode;
		 while(currentNode!=NULL&&currentNode->element!=theElement)//Ԫ�ز���Ⱦͼ���ѭ�� 
		  { 
		    currentNode=currentNode->next;
			p=p->next;	
	      } 
		 if(currentNode==NULL)//������Ա���û�����Ԫ�� 
		 cout<<"there is no thelement in it"<<endl;
		 else
		  {currentNode->pre->next=currentNode->next;
		   currentNode->next->pre=currentNode->pre;
		   //p->next=currentNode->next;
		   listSize--; 
		  }
	    }
		}
	    
}
template<class T>
void graphChain<T>::insert(T theElement,int theWeight)
	{ if(firstNode==NULL)
	   { 
	     firstNode=new graphNode<T>(theElement,theWeight,firstNode,NULL);
	     lastNode=firstNode;
	   } 
	  else
	  {
	  	graphNode<T>* currentNode=new graphNode<T>(theElement,theWeight,NULL,NULL);
	  	firstNode->pre=currentNode;
        currentNode->next=firstNode;
        firstNode=currentNode;
	  }
	  listSize++;
	}
template<class T>
void graphChain<T>::insertHead(T theElement,int theWeight)
{   T element=theElement;int weight=theWeight;
    graphNode<T> *t=new graphNode<T>(element,weight);
	if(firstNode==NULL)
	firstNode=lastNode=t;
	else
	{  graphNode<T> *q=firstNode->next;
	  firstNode->next=t;
	  t->next=q;	
	}
	listSize++;
} 

#endif
