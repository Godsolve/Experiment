#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <cstring> 
#include <queue> 
#include <stack> 
#include "AOE.h"
using namespace std; 

int n, m; //��������������� 
int cnt; 

int main() 
{ 
    cout<<"�����붥������ͱߵ�������"<<endl; 
    AOE<int> aoe; 
    while(~scanf("%d%d", &n, &m)) 
    { 
        aoe.get(n,m);
        aoe.read_case(); 
        printf("\n�ؼ�·��:\n"); 
        aoe.CriticalPath(); 
    } 
    return 0; 
} 
