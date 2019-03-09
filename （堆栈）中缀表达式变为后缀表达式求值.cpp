#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

//����ջ
struct{
    char data[MaxSize];
    int top;
}op;

//��ֵջ
struct{
    float data[MaxSize];
    int top;
}st;


//���������ʽexpת��Ϊ��׺���ʽpostexp
void trans(char exp[],char postexp[]){
    char ch;
    int i=0,j=0; //iɨ��exp���±�,jɨ��postexp���±�
    op.top=-1;
    ch=exp[i]; i++;
    while (ch != '\0')
    {
        switch(ch){
        case '(':    //������
            op.top++; op.data[op.top]=ch;
            break;
        case ')':   //������
            while(op.data[op.top]!='(')
            {
                postexp[j]=op.data[op.top]; j++;
                op.top--;
            }
            op.top--;
            break;
        case '+':   //Ϊ'+'��'-'ʱ�������ȼ�������ջ���κ�����������ȼ���ֱ��')'
        case '-':
            while (op.top!=-1 && op.data[op.top]!='(')
            {
                postexp[j]=op.data[op.top]; j++;
                op.top--;
            }
            op.top++; op.data[op.top]=ch;
            break;
        case '*':
        case '/':  //Ϊ'*'��'/'ʱ�������ȼ�������ջ��Ϊ'*'��'/'�����ȼ���ֱ��')'
            while(op.top!=-1 && op.data[op.top]!='('
                && (op.data[op.top]=='*' || op.data[op.top]=='/')){
                postexp[j]=op.data[op.top]; j++;
                op.top--;
            }
            op.top++; op.data[op.top]=ch;
            break;
        case ' ': break;  //���˿ո�
        default:
            while (ch>='0' && ch<='9')
            {
                postexp[j]=ch; j++;
                ch=exp[i]; i++;
            }
            i--;
            postexp[j]='#'; j++;
            //postexp[j]=' '; j++; //�ÿո��ʶһ����ֵ������

        }
        ch=exp[i]; i++;
    }

    while(op.top!=-1){ //��ʱ��expɨ����ϣ�ջ����ʱ��ջ����ŵ�postexp��
        postexp[j]=op.data[op.top]; j++;
        op.top--;
    }
    postexp[j]='\0'; //��postexp���ʽ��ӽ�����ʶ

}

//�Ժ�׺���ʽpostexp��ֵ
float compvalue(char postexp[]){
    float d;
    char ch;
    int i=0;
    st.top=-1;
    ch=postexp[i]; i++;
    while (ch!='\0')
    {
        switch(ch){
        case '+': st.data[st.top-1]=st.data[st.top-1]+st.data[st.top];
            st.top--; break;
        case '-': st.data[st.top-1]=st.data[st.top-1]-st.data[st.top];
            st.top--; break;
        case '*': st.data[st.top-1]=st.data[st.top-1]*st.data[st.top];
            st.top--; break;
        case '/':
            if(st.data[st.top]!=0)
                st.data[st.top-1]=st.data[st.top-1]/st.data[st.top];
            else{
                printf("\n\t�������!\n");
                exit(0);
            }
            st.top--; break;
        default:
            d=0;
            while (ch>='0' && ch<='9')
            {
                d=10*d+ch-'0';
                ch=postexp[i]; i++;
            }
            st.top++;
            st.data[st.top]=d;

        }
        ch=postexp[i]; i++;
    }
    return st.data[st.top];

}

void main()
{
    char exp[20]="(56-20)/(4-2)";
    char postexp[30];
    float f=0.0;

    //��exp���沨��ʽ,�õ�postexp
    trans(exp,postexp);
    //��postexp��ֵ
    f=compvalue(postexp);

    printf("%s = %.2f\n",exp,f);

}
