#include <stdio.h>

#include"../include/linearlist.h"

typedef enum {
    false,
    true
} bool;



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

bool ReverseList(SqList *L){
    int pre = 0;
    int tail = L->length -1;
    ElemType tmp;

    while(pre < tail){
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

void Del_X(SqList *L, ElemType x){
    int l = 0;
    for(int i = 0; i < L->length; i++){
        if(L->data[i] != x){
            L->data[l] = L->data[i];
            l++;
        }
    }
    L->length = l;
}

void Del_bt_s_t(SqList *L,int s, int t ){
    
    if(s >= t || s < 0 || t > L->length-1){

        printf("error!\n");
        return;
    }

    int l = 0;

    for(int i = 0; i< L->length; i++){
        if(L->data[i] <= s || L->data[i] >= t){
            L->data[l] = L->data[i];
            l++;
        }
    }
    L->length = l;
}

void Del_Dup(SqList *L){

    int pre = 0;
    int tail = 1;
    int l = 0;

    while(tail <= L->length-1){
        if(L->data[pre] != L->data[tail]){
            L->data[l] = L->data[pre];
            l++;
        }
        pre++;
        tail++;
    }
    L->data[l] = L->data[L->length-1];
    l++;
    L->length = l;
}

bool Merge(SqList a, SqList b,SqList *c){
    if(a.length + b.length > c->length){
        return false;
    }
    int i = 0, j = 0, k = 0;
    while(i<a.length && j < b.length){
       if(a.data[i] < b.data[j]){
           
       } 
    }
}


