#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "tuopu.h" 
using namespace std;

#define null 0
#define max_course_num  100  //���γ����� 

//������ 
int main(){
	queue q;
	Queue.queue_init(&q);
	AlGraph CGraph;
	CGraph=Graph.input();
	system("cls");
	Graph.output(CGraph);
	cout<<endl<<endl;
	Judgement.judgingcricle(&CGraph,&q);  //�ж��Ƿ��л� 
	if(!whethercricle){
			system("cls");
			Edit.layout(&CGraph,&q);
	}
	system("pause");
	return 0;
} 
