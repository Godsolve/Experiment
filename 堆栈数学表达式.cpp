#include<iostream>  
#include<stack>  
#include<string>  
#include <stdlib.h>
using namespace std;  
int priority(int state,char a)  
{//������������ȼ��ĺ�����ע��state��ʾ�����״̬��  
//state=1��ʾ��δ��ջ��state=0��ʾջ�����ȼ���ע��  
//��ֻ�ԡ�����������  
    int result;  
    switch (a){  
    case '+':  
    case '-':  
        result = 1;  
        break;  
    case '*':  
    case '/':  
        result = 2;  
        break;  
    case '(':  
        if (state == 0)  
            result = 3;  
        else  
            result = 0;  
        break;  
    case '#':  
        result = 0;  
        break;  
    default:  
        break;  
    }  
    return result;  
}  
double calculate(char op, double op1, double op2)  
{  
    double result;  
    switch (op){  
    case '+':  
        result = op1 + op2;  
        break;  
    case '-':  
        result = op1 - op2;  
        break;  
    case '*':  
        result = op1*op2;  
        break;  
    case '/':  
        result = op1 / op2;  
        break;  
    default:  
        break;  
    }  
    return result;  
}  
int main()  
{  
    string s;  
    while (cin >> s){//���Զ�������  
        stack<char> operation;//��Ų�������ջ  
        stack<double> operand;//��Ų�������ջ  
        operation.push('#');//�Ƚ���#��ѹջ  
        string num;//��Ų�����  
        for (int i = 0; i < s.length(); i++){  
            if (isdigit(s[i])){//��������  
                while (isdigit(s[i]) || s[i] == '.'){//����������ȡ��ȫ  
                    num.push_back(s[i]);  
                    i++;  
                }  
                double a = atof(num.c_str());//string->double  
                operand.push(a);//��������ջ  
                num.clear();//num����Ա��´�ʹ��  
                i--;//λ�û�ԭ  
            }  
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '('){//���������  
                if (priority(0, s[i])>priority(1, operation.top()))//���ȼ��Ƚ�  
                    operation.push(s[i]);//>,ֱ����ջ  
                else{  
                    while (priority(0, s[i]) <= priority(1, operation.top())){//<,��ջ�����м���ֱ��>  
                        char temp = operation.top();  
                        operation.pop();  
                        double op2 = operand.top();  
                        operand.pop();  
                        double op1 = operand.top();  
                        operand.pop();  
                        operand.push(calculate(temp, op1, op2));  
                    }  
                    operation.push(s[i]);//��Ҫ��������������ջ  
                }  
            }  
            else if (s[i] == ')'){//ɨ�赽������  
                while (operation.top() != '('){//��ջֱ��������  
                    char temp = operation.top();  
                    operation.pop();  
                    double op2 = operand.top();  
                    operand.pop();  
                    double op1 = operand.top();  
                    operand.pop();  
                    operand.push(calculate(temp, op1, op2));  
                }  
                operation.pop();//��������ջ  
            }  
            else{//�Ƿ��ַ��Ĵ���  
                cout << "error!" << endl;  
                return 0;  
            }  
        }  
        while (operation.top() != '#'){//ɨβ����  
            char temp = operation.top();  
            operation.pop();  
            double op2 = operand.top();  
            operand.pop();  
            double op1 = operand.top();  
            operand.pop();  
            operand.push(calculate(temp, op1, op2));  
        }  
        cout << operand.top() << endl;//������  
    }  
    return 0;  
}
