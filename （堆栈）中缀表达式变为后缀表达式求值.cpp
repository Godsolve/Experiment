#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

//符号栈
struct{
    char data[MaxSize];
    int top;
}op;

//数值栈
struct{
    float data[MaxSize];
    int top;
}st;


//将算术表达式exp转换为后缀表达式postexp
void trans(char exp[],char postexp[]){
    char ch;
    int i=0,j=0; //i扫描exp的下标,j扫描postexp的下标
    op.top=-1;
    ch=exp[i]; i++;
    while (ch != '\0')
    {
        switch(ch){
        case '(':    //左括号
            op.top++; op.data[op.top]=ch;
            break;
        case ')':   //右括号
            while(op.data[op.top]!='(')
            {
                postexp[j]=op.data[op.top]; j++;
                op.top--;
            }
            op.top--;
            break;
        case '+':   //为'+'或'-'时，其优先级不大于栈顶任何运算符的优先级，直到')'
        case '-':
            while (op.top!=-1 && op.data[op.top]!='(')
            {
                postexp[j]=op.data[op.top]; j++;
                op.top--;
            }
            op.top++; op.data[op.top]=ch;
            break;
        case '*':
        case '/':  //为'*'或'/'时，其优先级不大于栈顶为'*'或'/'的优先级，直到')'
            while(op.top!=-1 && op.data[op.top]!='('
                && (op.data[op.top]=='*' || op.data[op.top]=='/')){
                postexp[j]=op.data[op.top]; j++;
                op.top--;
            }
            op.top++; op.data[op.top]=ch;
            break;
        case ' ': break;  //过滤空格
        default:
            while (ch>='0' && ch<='9')
            {
                postexp[j]=ch; j++;
                ch=exp[i]; i++;
            }
            i--;
            postexp[j]='#'; j++;
            //postexp[j]=' '; j++; //用空格标识一个数值串结束

        }
        ch=exp[i]; i++;
    }

    while(op.top!=-1){ //此时，exp扫描完毕，栈不空时出栈并存放到postexp中
        postexp[j]=op.data[op.top]; j++;
        op.top--;
    }
    postexp[j]='\0'; //给postexp表达式添加结束标识

}

//对后缀表达式postexp求值
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
                printf("\n\t除零错误!\n");
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

    //求exp的逆波兰式,得到postexp
    trans(exp,postexp);
    //对postexp求值
    f=compvalue(postexp);

    printf("%s = %.2f\n",exp,f);

}
