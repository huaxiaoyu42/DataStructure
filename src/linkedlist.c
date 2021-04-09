#include<stdio.h>
#include<stdlib.h>
#include "../include/linkedlist.h"

bool InitList(LNode **L){
    *L = (LNode *)malloc(sizeof(LNode));
    if(*L == NULL){
        return false;
    } 
    (*L)->next = NULL;
    return true;
}

LNode* ListHeadInsert(LNode *l){
    ElemType x;
    LNode *s;
    scanf("%d",&x);

    while(x != 9999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = l->next;
        l->next = s;
        scanf("%d",&x);
    }

    return l;
}

LNode* ListTailInsert(LNode *l){
    ElemType x;
    LNode *s,*r=l;
    scanf("%d",&x);
    while(x != 9999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    r->next = NULL;
    return l;
}

LNode* GetElem(LNode *l, int i){
    int j = 1;
    LNode *p = l->next;
    if(i == 0){
        return l;
    }
    if(i < 1){
        return NULL;
    }
    while(p && j < i){
        p = p->next;
        j++;
    }
    return p;
}

LNode* LocateElem(LNode *l,ElemType e){
    LNode *p = l->next;
    while(p != NULL && p->data != e){
        p = p->next;
    }
    return p;
}

bool ListInsert(LNode *L,int i, ElemType e){
    if(i<1){    //位序从 1 开始，i < 1 为不合法 
        return false;
    }
    LNode *p; // 当前扫描到的结点
    int j = 0; // 当前扫描到的结点的位序
    p = L; // 将p指向头节点
    while(p != NULL && j < i - 1){  // 将p指向第i个结点的前一个结点
        p = p->next;
        j++;
    }
    if(p == NULL){ // i的值不合法
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
    
bool InsertNextNode(LNode *L, ElemType e){
    if(L == NULL){
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(ElemType));
    if( s == NULL){
        return false;
    }
    s->data = e;
    s->next = L->next;
    L->next = s;
    return true;
}

bool InsertPriorNode(LNode *L, ElemType e){
    if(L == NULL){
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL){
        return false;
    }
    s->next = L->next;
    L->next = s;
    s->data = L->data;
    L->data = e;
    return true;
}

bool ListDelete(LNode *l,int i,ElemType *e){
    if(i < 1){
        return false;
    }
    LNode *p = l;
    int j = 0;
    while(p != NULL && j < i - 1){
        p = p->next;
        j++;
    }
    if(p == NULL){
        return false;
    }

    LNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return true;


}

/**
 * 存在BUG，如果要删除的结点是最后一个，那么它就没有下一个结点。
*/
bool DeleteNode(LNode *p){
    if(p == NULL){
        return false;
    }
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}


void Delete_x(LNode *l,ElemType x){
    if(l->next == NULL){
        return;
    }
    LNode *p = l->next;
    if(p->data == x){
        l->next  = p->next;
        free(p);
        Delete_x(l,x);
    }else{
        Delete_x(l->next,x);
    }
}

void R_print_body(LNode *l){
    if(l->next != NULL){
        R_print_body(l->next);
    }
    if(l != NULL){
        printf("%d ",l->data);
    }
}

void Reverse_print(LNode *l){
    if(l != NULL){
        R_print_body(l->next);
    }
}

void Delete_min(LNode *l){
    LNode *p;
    if(l != NULL){
        p = l->next;
    }
    ElemType min = p->data;
    LNode *k = p;
    while(p != NULL){
        if(p->data < min){
            min = p->data;
            k = p;
        }
        p = p->next;
    }
    DeleteNode(k);

}

void Reverse_linkedlist(LNode *l){
    if(l == NULL){
        return;
    }

    LNode *cur = l->next; // 指向当前结点
    LNode *pre = NULL;   // 指向当前结点的前一个结点，当cur为第一个非头结点时，它为NULL
    LNode *tmp = NULL;  // 记住当前结点的下一个位置
    
    while(cur != NULL){
        tmp = cur->next;

        cur->next = pre; // 将当前结点的next指针指向前一个结点

        //向后移动
        pre = cur;
        cur = tmp;
    }
    //当cur为NULL时，pre指向新头的下一个
    l->next = pre;
}

void Sort_linkedlist(LNode *l){
    LNode *p = l->next;
    LNode *r = p->next;
    LNode *pre;
    p->next = NULL;
    p = r;
    while(p != NULL){
        r = r->next;
        pre = l;
        while(pre->next != NULL && pre->next->data < p->data){
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = r;
    }

}


void Range_delete(LNode *l,int min,int max){
    if(l == NULL){
        return;
    }
    LNode *p = l;
    LNode *k;
    while(p->next != NULL){
        if(p->next->data > min && p->next->data < max){
            k = p->next;
            p->next = k->next;
            free(k);
        }else{
            p = p->next;
        }

    }
}


void Print_and_delete_min(LNode *l){
    if(l == NULL){
        return;
    }
    LNode *pre;
    LNode *p;
    while(l->next != NULL){
        pre = l;
        p = l->next;
        while(p->next != NULL){
            if(p->next->data < pre->next->data){
                pre = p;
            }
            p = p->next;
        }
        printf("%d ",pre->next->data);
        LNode *tmp = pre->next;
        pre->next = tmp->next;
        free(tmp);
    }
}



void Split_linkedlist(LNode *l,LNode *a,LNode *b){
    if(l == NULL){
        return;
    }
    LNode *p = l->next;

    LNode *ra = a;
    LNode *rb = b;

    // 结点是否为奇数的标志，是为true
    bool flag = true;

    while(p != NULL){
        if(flag){
            ra->next = p;
            ra = p;
        }else{
            rb->next = p;
            rb = p;
        }
        p = p->next;
        flag = !flag;

    }
    ra->next = NULL;
    rb->next = NULL;

}

void Split_linkedlist_2(LNode *l,LNode *a,LNode *b){
    LNode *p = l->next;
    LNode *ra = a;
    LNode *rb = b;
    LNode *n = NULL;

    rb->next = NULL;

    bool flag = true;

    while(p != NULL){
        if(flag){
            ra->next = p;
            ra = p;
            p = p->next;
        }else{
            n = p->next;
            p->next = rb->next;
            rb->next = p;
            p = n;
        }

        flag = !flag;
    }

    ra->next = NULL;

}

void Delete_same(LNode *l){
    if(l == NULL){
        return;
    }
    LNode *a = l->next;
    LNode *b = a->next;

    while(b !=NULL){
        if(a->data == b->data){
            a->next = b->next;
            free(b);
            b = a->next;
        }else{
            a = a->next;
            b = a->next;
        }
    }
}

void Merge_linkedlist(LNode *a,LNode *b){
    if(a == NULL || b == NULL){
        return;
    }
    LNode *ra = a->next;
    LNode *rb = b->next;
    a->next = NULL;
    LNode *next;

    while(ra != NULL && rb != NULL){
        if(ra->data <= rb->data){
            next = ra->next;
            ra->next = a->next;
            a->next = ra;
            ra = next;
        }else{
            next = rb->next;
            rb->next = a->next;
            a->next = rb;
            rb = next;
        }
    }

    if(ra != NULL){
        rb = ra;
    }

    while(rb != NULL){
            next = rb->next;
            rb->next = a->next;
            a->next = rb;
            rb = next;
    }

}