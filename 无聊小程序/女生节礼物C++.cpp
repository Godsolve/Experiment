#include <iostream>
#include <cstring>
#include<stdio.h>
#include <cmath>
#include <stdlib.h>
#include<windows.h>
//#include <queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float f(float x, float y, float z) {  
    float a = x * x + 9.0f / 4.0f * y * y + z * z - 1;  
    return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z;  
}  
  
float h(float x, float z) {  
    for (float y = 1.0f; y >= 0.0f; y -= 0.001f)  
        if (f(x, y, z) <= 0.0f)  
            return y;  
    return 0.0f;  
}  

int main() {
	cout<<"����һ�����Գ���Գ��Ů��������\n"<<endl;
	Sleep (1500);
	cout<<"������Ҫ�Ȼش�һ����������յ�����\n"<<endl;
	Sleep (1500);
	cout<<"��ô��������ǣ�\n"<<endl;
	Sleep (1500);
	cout<<"���ǲ���Ů���ӣ�(�� �� ����)\n"<<endl;
	string str;
	cin>>str;
	if(str=="��")cout<<"\n�Բ����������ֻ�͸�������~\n"<<endl;
	if(str=="����")cout<<"\n�Բ����������ֻ�͸�Ů����~\n"<<endl;
	Sleep (4500);
	cout<<"����������ģ�����������ר������һ���˵ģ�\n"<<endl;
	Sleep (2000);
	
/*	void color(short x) //�Զ��庯���ݲ����ı���ɫ   
    {
    if(x>=0 && x<=15)//������0-15�ķ�Χ��ɫ  
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);    //ֻ��һ���������ı�������ɫ   
    else//Ĭ�ϵ���ɫ��ɫ  
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  
    }
	//system("color 95");
*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);  
    printf("Ů  ");
    Sleep (1500);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 | FOREGROUND_INTENSITY | 4 | BACKGROUND_INTENSITY);  
    printf("��  ");
    Sleep (1500);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1 | FOREGROUND_INTENSITY | 13 | BACKGROUND_INTENSITY);  
    printf("��  ");
    Sleep (1500);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6 | FOREGROUND_INTENSITY | 3 | BACKGROUND_INTENSITY);  
    printf("��  ");
    Sleep (1500);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN| FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_INTENSITY);  
    printf("��  ");
    Sleep (1500);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | 5 | BACKGROUND_INTENSITY);  
    printf("��  \n\n\n");
    Sleep (1500);
   
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_INTENSITY);  
    printf("�Ժ����ҪС�ĵ�Ŷ\n\n\n");
    Sleep (2500);
    cout<<"��Ϊ���ҵ�����ס��һ��ǿ��\n\n"<<endl;
    Sleep (2500);
    cout<<"��ʱ���ܰ�����ߣ��͵�������\n\n"<<endl;
	Sleep (2500);
	cout<<"�������Ҿͻᰮ����\n\n"<<endl;
	Sleep (2500);
	  
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  
    for (float z = 1.5f; z > -1.5f; z -= 0.05f) {  
        for (float x = -1.5f; x < 1.5f; x += 0.025f) {  
            float v = f(x, 0.0f, z);  
            if (v <= 0.0f) {  
                float y0 = h(x, z);  
                float ny = 0.01f;  
                float nx = h(x + ny, z) - y0;  
                float nz = h(x, z + ny) - y0;  
                float nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);  
                float d = (nx + ny - nz) * nd * 0.5f + 0.5f;  
                putchar(".:-=+*#%@"[(int)(d * 5.0f)]);  
            }  
            else  
                putchar(' ');  
        }  
        putchar('\n');  
    }  
    system("pause");
	return 0;
}
