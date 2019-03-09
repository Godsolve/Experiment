#include <iostream>  
#include <cstring>  
#define MAX 50+3  
using namespace std;  
typedef char Elem_Type;  
/*�ڵ� getRoot(ǰ������)

c=ǰ���һ���ַ�

pos=c�������е�λ��

len1=����pos��벿�ֳ���

len2=����pos�Ұ벿�ֳ���

�½��ڵ�r����r��Ԫ�ص���c

r�������=getRoot(ǰ��λ��1��ʼ��len1���Ȳ��֣�����posλ�õ���벿��)

r���Ҷ���=getRoot(ǰ��λ��len1��ʼ�Ұ벿�֣�����posλ�õ��Ұ벿��)

return r */ 
typedef struct BiTree  
{  
    Elem_Type data;//����  
    struct BiTree *Lchild;//����  
    struct BiTree *Rchild;//�Һ���  
}BiTree;      //Ҫ���ҵ�Ԫ��  ���ҵĵط�    ����ĳ���  
int Search_Num(Elem_Type num,Elem_Type *array,int len)  
{  
    for(int i=0; i<len; i++)  
       if(array[i] == num)  
         return i;  
    //return -1;//û���ҵ�  
}                     //ǰ�����         �������   �������鳤��  
BiTree *Resume_BiTree(Elem_Type *front,Elem_Type *center,int len)  
{    //ʹ�����Ľṹ����ǰ�����к��������б�����������
    if(len <= 0)  
      return NULL;  
    BiTree *temp = new BiTree;  
    temp->data = *front;  
    int index = Search_Num(*front,center,len);  
    temp->Lchild = Resume_BiTree(front+1,center,index);  
    temp->Rchild = Resume_BiTree(front+index+1,center+index+1,len-index-1);  
    return temp;  
}  
void PostOrderTraverse(BiTree *root)//�������  
{  
    if( root != NULL)  
    {  
        PostOrderTraverse(root->Lchild);  
        PostOrderTraverse(root->Rchild);  
        cout<<root->data;  
    }  
}  
int main(void)  
{  
    Elem_Type *preorder = new Elem_Type [MAX];//ǰ��  
    Elem_Type *inorder  = new Elem_Type [MAX];//����  
    cout<<"������ǰ�����У�"<<endl; 
	cin>>preorder;
	cout<<"�������������У�"<<endl;
	cin>>inorder;  
	cout<<"��������Ϊ��"<<endl;
    BiTree *root = Resume_BiTree(preorder,inorder,strlen(inorder));  
    PostOrderTraverse(root);  
    cout<<endl;  
    return 0;  
}  

