#include <iostream>

using namespace std;

template<class T>
class Term
{
    friend SparseMatrix<T>;
private:
    int row, column;
    T value;
};
template<class T>
void SparseMatrix<T>::Transpose(SparseMatrix<T>& b) const
{//��*this����ת�ã�ת�ú�ľ���洢��b��
    if (terms > b.MaxTerms) throw NoMem();

    b.rows = columns;
    b.columns = rows;
    b.terms = terms;

    int *ColSize, *RowNext;
    ColSize = new int[columns + 1];
    RowNext = new int[columns + 1];

    //����ÿһ�е�Ԫ������
    for (int i = 1; i <= columns; i++)
        ColSize[i] = 0;
    for (int i = 0; i < terms; i++)
        ColSize[a[i].column]++;

    //����ÿһ�еĿ�ʼλ��
    RowNext[1] = 0;
    for (int i = 2; i <= columns; i++)
        RowNext[i] = RowNext[i - 1] + ColSize[i - 1];

    for (int i = 0; i < terms; i++) {
        int j = RowNext[a[i].column]; //b��a[i]��λ��,a��Term������
        RowNext[a[i].column]++;
        b.a[j].column = a[i].row;
        b.a[j].row = a[i].column;
        b.a[j].value = a[i].value;
    }

    delete[] ColSize;
    delete[] RowNext;
}
template<class T>
void SparseMatrix<T>::Add(const SparseMatrix<T>& b, SparseMatrix<T>& c) const
{//��*this��b��ӣ��õ��ľ������c��
    if (rows != b.rows || columns != b.columns)
        throw SizeMismatch();   //���󲻼���

    //���þ���c������
    c.rows = rows;
    c.columns = columns;
    c.terms = 0; //��ʼ������

    //���嵽*this��b��ָ��
    int ct = 0, cb = 0;

    //�ƶ�*this��b��ָ��
    while (ct < terms && cb < b.terms) {
        //���������������ֵ
        int it = a[ct].row * columns + a[ct].column;
        int ib = b.a[cb].row * columns + b.a[cb].column;

        if (it < ib) {
            c.Append(a[ct]);
            ct++;
        }
        else if (it == ib) {
            if (a[ct].value + b.a[cb].value) { 
                //�����Ӳ�Ϊ0����ӵ�c����
                Term<T> temp;
                temp.column = a[ct].column;
                temp.row = a[ct].row;
                temp.value = a[ct].value + b.a[cb].value;
                c.Append(temp);
            }
            ct++;
            cb++;
        }
        else {
            c.Append(b.a[cb]);
            cb++;
        }
    }

    for (; ct < terms; ct++)
        c.Append(a[ct]);
    for (; cb < b.terms; cb++)
        c.Append(b.a[cb]);
}
