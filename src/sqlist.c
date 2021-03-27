#include <stdio.h>

#include "../include/sqlist.h"

#define REVERSE           \
    while (pre < tail)    \
    {                     \
        tmp = a[pre];     \
        a[pre] = a[tail]; \
        a[tail] = tmp;    \
        pre++;            \
        tail--;           \
    };

/**
 * 
 * 初始化顺序表，将data中的每个元素值为零
 * 
*/
void InitList(SqList *L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L->data[i] = 0;
    }
    L->length = 0;
}

void ListInsert(SqList *L, int i, ElemType e)
{
    for (int j = L->length; j >= i; j--)
    {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
}

bool ListDelete(SqList *L, int i, ElemType *e)
{
    if (i < 1 || i > L->length)
    {
        return false;
    }
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++)
    {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return true;
}

ElemType GetElem(SqList *L, int i)
{
    return L->data[i - 1];
}

int LocateElem(SqList *L, ElemType e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}

ElemType DelMin(SqList *L)
{
    ElemType min = L->data[0];
    int min_index = 0;

    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] < min)
        {
            min_index = i;
            min = L->data[i];
        }

        L->data[min_index] = L->data[L->length - 1];
        L->length--;
        return min;
    }
}

bool ReverseList(SqList *L)
{
    int pre = 0;
    int tail = L->length - 1;
    ElemType tmp;

    while (pre < tail)
    {
        tmp = L->data[pre];
        L->data[pre] = L->data[tail];
        L->data[tail] = tmp;
        pre++;
        tail--;
    }
}

/**
 * 对长度为n的顺序表L，编写一个时间复杂度为 O(n)、空间复杂度为 O(1)的算法,
 * 该算法删除线性表中所有值为 x 的数据元素。
*/

void Del_X(SqList *L, ElemType x)
{
    int l = 0;
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] != x)
        {
            L->data[l] = L->data[i];
            l++;
        }
    }
    L->length = l;
}

void Del_bt_s_t(SqList *L, int s, int t)
{

    if (s >= t || s < 0 || t > L->length - 1)
    {

        printf("error!\n");
        return;
    }

    int l = 0;

    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] <= s || L->data[i] >= t)
        {
            L->data[l] = L->data[i];
            l++;
        }
    }
    L->length = l;
}

void Del_Dup(SqList *L)
{

    int pre = 0;
    int tail = 1;
    int l = 0;

    while (tail <= L->length - 1)
    {
        if (L->data[pre] != L->data[tail])
        {
            L->data[l] = L->data[pre];
            l++;
        }
        pre++;
        tail++;
    }
    L->data[l] = L->data[L->length - 1];
    l++;
    L->length = l;
}

bool Merge(SqList a, SqList b, SqList *c)
{
    if (a.length + b.length > c->length)
    {
        return false;
    }
    int i = 0, j = 0, k = 0;
    while (i < a.length && j < b.length)
    {
        if (a.data[i] < b.data[j])
        {
            c->data[k++] = a.data[i++];
        }
        else
        {
            c->data[k++] = b.data[j++];
        }
    }
    while (i < a.length)
    {
        c->data[k++] = a.data[i++];
    }
    while (j < b.length)
    {
        c->data[k++] = b.data[j++];
    }
    c->length = k;
    return true;
}

void Reverse_two_list(ElemType a[], int left, int right, int arraySize)
{
    int pre = 0;
    int tail = arraySize - 1;
    ElemType tmp;

    REVERSE;

    pre = 0;
    tail = left - 1;

    REVERSE;

    pre = left;
    tail = right + left - 1;

    REVERSE;
}

void SearchExchangeInsert(SqList *l, ElemType x)
{
    int low = 0, high = l->length - 1, mid;

    while (low < high)
    {
        mid = (low + high) / 2;
        if (l->data[mid] == x)
        {
            break;
        }
        else if (l->data[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (l->data[mid] && mid != l->length - 1)
    {
        ElemType tmp = l->data[mid];
        l->data[mid] = l->data[mid + 1];
        l->data[mid + 1] = tmp;
    }

    if (low > high)
    {
        int i;
        for (i = l->length - 1; i > high; i--)
        {
            l->data[i + 1] = l->data[i];
        }
        l->data[i + 1] = x;
    }
}


void MoveList(SqList *l, int p){

    int *a = l->data;

    int pre,tail;
    ElemType tmp;

    pre = 0;
    tail = l->length - 1;
    REVERSE

    pre = 0;
    tail = l->length - 1 -p;
    REVERSE

    pre = l->length - p;
    tail = l->length - 1;
    REVERSE

}

ElemType MidMumber(int a[],int b[],int n){
    int h1,t1,m1;
    int h2,t2,m2;
    h1 = h2 = 0;
    t1 = t2 = n - 1;
    
    while(h1 != t1 || h2 != t2){
        m1 = (h1 + t1 )/2;
        m2 = (h2 + t2 )/2;
        if(a[m1] == b[m2]){
            return a[m1];
        }
        if(a[m1] < b[m2]){
            if((h1 + t1)%2 == 0){
                h1 = m1;
                t2 = m2;
            }else{
                h1 = m1 +1;
            }
        }else{
            if((h2 + t2)%2 == 0){
                t1 = m1;
                t2 = m2;
            }else{
                t1 = m1;
                t2 = m2 + 1;
            }
        }
    }

    return a[h1] < b[h2] ? a[h1] : b[h2];
}