#include<stdio.h>

#include<malloc.h>

typedef int ElemType;

typedef struct LNode{

ElemType data;

struct LNode *lchild,*rchild;

}LNode,*TLNode;

void create(TLNode * Tree){  //����

ElemType e;

scanf("%d",&e);

if(e==0)

*Tree=NULL;

else{

(*Tree)=(TLNode)malloc(sizeof(LNode));

(*Tree)->data=e;

printf("input %d lchild: ",e);

create(&(*Tree)->lchild);


  printf("input %d rchild: ",e);

  create(&(*Tree)->rchild);

}

}

void print1(TLNode Tree){  //�������

if(Tree!=NULL){

printf("%d-",Tree->data);

print1(Tree->lchild);

print1(Tree->rchild);

}

}

void print2(TLNode Tree){  //�������

if(Tree!=NULL){

print2(Tree->lchild);

printf("%d-",Tree->data);

print2(Tree->rchild);

}

}

void print3(TLNode Tree){  //�������

if(Tree!=NULL){

print3(Tree->lchild);

print3(Tree->rchild);

printf("%d-",Tree->data);

}

}

int leaf=0;  //��Ҷ�ӽڵ���

int depth(TLNode Tree){  //���

int s1,s2;

if(Tree==NULL)

return 0;

else{

s1=depth(Tree->lchild);

s2=depth(Tree->rchild);

if(s1==0 && s2==0) leaf++;

return (s1>s2?s1:s2)+1;

}

}

int Cnode(TLNode Tree){  //�ܽ��

int s1,s2;

if(Tree==NULL)

return 0;

else{

s1=Cnode(Tree->lchild);

s2=Cnode(Tree->rchild);

return s1+s2+1;

}

}

int main(){

TLNode Tree;

printf("input ���ڵ�:   ");

create(&Tree);

printf("�������:");

print1(Tree);
printf("\n");
printf("�������");

print2(Tree);
printf("\n"); 
printf("�������");

print3(Tree);
printf("\n");
printf("\n��  ��:%d \n",depth(Tree));

printf("�ܽ����:%d \n",Cnode(Tree));

printf("Ҷ�ӽ����:%d\n",leaf);
return 0;

}

