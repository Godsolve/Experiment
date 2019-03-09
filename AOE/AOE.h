#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <cstring> 
#include <queue> 
#include <stack> 
using namespace std; 
 
const int MAXN = 1010; //����������  
const int MAXM = 10010; //�������  
template<class T>
class AOE
{
	public:
        AOE();
        void init();
        void read_graph(int u, int v, int w, int id);
        void toposort();
        void CriticalPath();
        void read_case();
        void get(int p,int q);
    private:
    	int n, m; //��������������� 
    	int v,w,id,u;
        int cnt; 
        int first[MAXN], topo[MAXN]; //��ͷָ�� 
        int ind[MAXN], outd[MAXN]; //������ȣ����� 
        int tot; 
        int Ee[MAXN], El[MAXN], E[MAXN], L[MAXN]; 
        /*Ee��ʾ�¼�������ܷ���ʱ�䣬El��ʾ�¼����������ʱ��*/ 
        /*E��ʾ�������ܷ���ʱ�䣬L��ʾ����������ʱ��*/
    struct Edge 
{ 
    int v, w; 
    int id; 
    int next; 
}edge[MAXM];  
} ;

 
template<class T>
AOE<T>::AOE()
{
    
}

template<class T>
void AOE<T>::get(int p,int q)
{
	n=p;
	m=q;
}
template<class T>
void AOE<T>::init() 
{ 
    cnt = 0; 
    tot = 0; 
    memset(first, -1, sizeof(first));  //char�ͳ�ʼ������
    memset(ind, 0, sizeof(ind));       //ͷ�ļ���<string.h> �� <memory.h>
    memset(outd, 0, sizeof(outd));     //����ԭ�ͣ�void *memset(void *s , int ch , size_t  n )
    memset(Ee, 0, sizeof(Ee));         //memset(�ṹ��/������ , "�����滻���ַ��� , ǰn���ַ� );
    memset(E, 0, sizeof(E));           //�������ͣ���s�е�ǰn���ֽ���ch�滻���ҷ���s
    memset(L, 0, sizeof(L));           //�������ã���һ���ڴ�������ĳһ��������ֵ�������ڽϴ�ĶԽṹ�����������������
    
} 

template<class T>
void AOE<T>::read_graph(int u, int v, int w, int id) //int u, int v, int w, int id
{ 
    edge[cnt].v = v, edge[cnt].w = w, edge[cnt].id = id; 
    edge[cnt].next = first[u], first[u] = cnt++; 
} 

template<class T>
void AOE<T>::toposort() //��������  
{                       //��u��v)��E(e)  u�����������г�����v֮ǰ 
    queue<int> q; 
    for(int i = 0; i < n; i++) if(!ind[i]) q.push(i); //������ͼ��ѡһ�����Ϊ0�Ķ��㣬����� 
    while(!q.empty())          //�ظ�������ֱ��ͼ�в������� 
    {                          //��ͼ���Ժ����㣬���ж�����Ⱦ���Ϊ0�����ͼ���л� 
        int x = q.front(); 
		q.pop(); 
        topo[++tot] = x; 
        for(int e = first[x]; e != -1; e = edge[e].next) //ɾ�����������йصı� 
        { 
            int v = edge[e].v, w = edge[e].w; 
            if(--ind[v] == 0) q.push(v); 
            if(Ee[v] < Ee[x] + w) //�����������Eeֵ  
            { 
                Ee[v] = Ee[x] + w; 
            } 
        } 
    } 
} 
//�ҹؼ�·������� 
template<class T>
void AOE<T>::CriticalPath() 
{ 
    toposort(); 
    int top = tot; 
    for(int i = 0; i < n; i++) El[i] = Ee[n-1]; //��ʼ�������¼�����ٷ���ʱ��  
    while(top) //�����������󶥵�El��ֵ  
    { 
        int x = topo[top--]; 
        for(int e = first[x]; e != -1; e = edge[e].next) 
        { 
            int v = edge[e].v, w = edge[e].w; 
            if(El[x] > El[v] - w) 
            { 
                El[x] = El[v] - w; 
            } 
        } 
    } 
    for(int u = 0; u < n; u++) //���E,L�ؼ��  
    { 
        for(int e = first[u]; e != -1; e = edge[e].next) 
        { 
            int v = edge[e].v, id = edge[e].id, w = edge[e].w; //id�����ı��  
            E[id] = Ee[u], L[id] = El[v] - w; 
            if(E[id] == L[id]) //���  �ǹؼ��  
            { 
                printf("a%d : %d->%d\n", id, u, v); 
            } 
        } 
    } 
} 

template<class T>
void AOE<T>::read_case() 
{ 
    init();
    for(int i = 1; i <= m; i++) 
    { 
        int u, v, w; //�����룬Ȩֵ
		cout<<"a"<<i<<":"; 
        scanf("%d%d%d", &u, &v, &w); //��������룬Ȩֵ 
        read_graph(u,v,w,i); //read_graph 
        outd[u]++, ind[v]++; 
    } 
} 
#endif
