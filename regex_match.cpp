#include <iostream>
#include <regex>
using namespace std;

int main() {
    string str = "sigalhu233";

    regex r("[a-z0-9]+");
    cout<<"������ʽ��[a-z0-9]+"<<endl;
    if(regex_match(str,r))
        cout<<"�ַ�����"<<str<<" ƥ��ɹ���"<<endl;
    else
        cout<<"�ַ�����"<<str<<" ƥ��ʧ�ܣ�"<<endl;

    cout<<endl<<"������ʽ��\\d+"<<endl;
    if(regex_match(str,regex("\\d+")))
        cout<<"�ַ�����"<<str<<" ƥ��ɹ���"<<endl;
    else
        cout<<"�ַ�����"<<str<<" ƥ��ʧ�ܣ�"<<endl;

    cout<<endl<<"������ʽ��\\d+"<<endl;
    if(regex_match(str.begin()+7,str.end(),regex("\\d+")))
        cout<<"�ַ�����"<<&str[7]<<" ƥ��ɹ���"<<endl;
    else
        cout<<"�ַ�����"<<&str[7]<<" ƥ��ʧ�ܣ�"<<endl;

    smatch sm;
    cout<<endl<<"������ʽ��([a-z]+)(\\d+)"<<endl;
    if(regex_match(str.cbegin()+5,str.cend(),sm,regex("([a-z]+)(\\d+)"))){
        cout<<"�ַ�����"<<&str[5]<<" ƥ��ɹ���"<<endl;
        cout<<"ƥ���ַ���������"<<sm.size()<<endl;
        cout<<"�ֱ�Ϊ��";
        for(auto aa:sm)
            cout<<aa.str()<<" ";
        cout<<endl;
    } else
        cout<<"�ַ�����"<<&str[5]<<" ƥ��ʧ�ܣ�"<<endl;

    cmatch cm;
    cout<<endl<<"������ʽ��([a-z]+)(\\d+)"<<endl;
    if(regex_match(str.c_str(),cm,regex("([a-z]+)(\\d+)"))){
        cout<<"�ַ�����"<<str<<" ƥ��ɹ���"<<endl;
        cout<<"ƥ���ַ���������"<<cm.size()<<endl;
        cout<<"�ֱ�Ϊ��";
        for(auto aa:cm)
            cout<<aa.str()<<" ";
        cout<<endl;
    } else
        cout<<"�ַ�����"<<str<<" ƥ��ʧ�ܣ�"<<endl;
    return 0;
}

