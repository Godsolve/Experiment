#include "linkedDgraph1.h"
#include<iostream>
using namespace std;
int main()
{   int n=0;
    cout<<" �����붥��ĸ�����";
	cin>>n; 
	linkedDgraph1 g(n);
	g.insertEdge(1,4,1);
	g.insertEdge(2,4,1);
	g.insertEdge(3,4,1);
	g.insertEdge(4,6,1);
	g.insertEdge(2,5,1);
	g.insertEdge(5,6,1);
	g.insertEdge(1,3,1);
	g.insertEdge(3,6,1);
	int *a=new int[n]; 
	//cout<<g.numberOfVertices()<<" "<<g.numberOfEdges();
	cout<<endl;
	int **b=new int*[n];
	for(int i=0;i<n;i++)
	 b[i]=new int[n];
	// for(int 1=0;i<6;i++)
	  //  for(int j=0;j<6;j++)
	//	  b[i][j]=0; 
	//cout<<g.numberOfVertices();
	//g.erasePoint(1);
	//cout<<g.existsPoint(1)<<" "<<g.numberOfEdges()<<" "<<g.numberOfVertices();
	//cout<<g.inDegree(4)<<g.outDegree(4);
	//cout<<g.existsEdge(1,5);
	//g.topologicalOrder(a);
	int ne=0;
	cout<<" ������ߵĸ�����";
	cin>>ne;
	pair<int,int> *c=new pair<int,int>[ne];
	cout<<" ������������ߣ� "<<endl; 
	for(int i=0;i<ne;i++)
	cin>>c[i].first>>c[i].second;
 //   pair<int,int> c[8]={pair<int,int>(1,3),pair<int,int>(1,4),pair<int,int>(2,4),pair<int,int>(3,4),
//	                    pair<int,int>(2,5),pair<int,int>(5,6),pair<int,int>(4,6),pair<int,int>(3,6)};
    if(g.topologicalOrder(a))	
	{ int t=g.course(c,ne,b);
	 cout<<"ѧ����Ϊ��"<<t<<endl;
	 for(int i=0;i<t;i++)
	   { cout<<"��"<<i+1<<"ѧ�ڵĿγ�Ϊ�� ";
	    for(int j=0;j<n;j++)
	     if(b[i][j]>0&&b[i][j]<=n)
		 cout<<b[i][j]<<" ";
		 cout<<endl;  
		}
	//for(int i=0;i<6;i++)
	//cout<<a[i]<<" ";
     }
     else
     cout<<"���ܷ�";
    /* int *sum=new int[6];
     for(int i=0;i<6;i++)
     sum[i]=0;
     linkedDgraph1 g(5);
	 g.insertEdge(1,3,2);
	 g.insertEdge(1,2,4);
	 g.insertEdge(1,5,8);
	 g.insertEdge(3,4,1);
	 g.insertEdge(2,4,4);
	 g.insertEdge(2,5,5);
	 g.insertEdge(4,5,3);    
	 //cout<<g.getWeight(1,3);
	 for(int j=1;j<6;j++)
	 { 
	   int *aa=new int[6];
       int *bb=new int[6];
	   g.shortPaths(j,aa,bb);
	   for(int i=1;i<6;i++)
	   {if(aa[i]==100)
	     {
		   sum[j]=10000;
		   break;	
		 }   
	    cout<<aa[i]<<" ";
	    sum[j]+=aa[i];
	   }
	  cout<<"���·��֮��Ϊ��"<<sum[j]<<endl;  
     }
     int min=sum[1];int minIndex=1;
     for(int i=1;i<6;i++)
     {
     	if(sum[i]<min)
     	   {
			min=sum[i];
			minIndex=i;
		   }
	 }
	 cout<<"��Ӧ������"<<minIndex; */
	return 0;
}
