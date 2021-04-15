#include<stdlib.h>
#include"../include/sq_string.h"


bool SubString(SString *sub,const SString *s,int pos,int len){
    if(pos+len-1 > s->length){
        return false;
    }

    for(int i = pos;i<pos+len;i++){
        sub->ch[i-pos+1] = s->ch[i];
    }
    sub->length = len;
    return true;
}


int Compare_String(const SString *s,const SString *t){
    for(int i = 1;i<s->length && i<t->length;i++){
        if(s->ch[i] != t->ch[i]){
            return s->ch[i] - t->ch[i];
        }
    }
    //扫描过的所有字符都相等，则长度长的串更大
    return s->length - t->length;
}

int Index(SString *s,SString *t){
    int i = 1,n = Str_Length(s),m = Str_Length(t);
    SString sub;
    while(i < n-m+1){
        SubString(&sub,s,i,m);
        if(Compare_String(&sub,t) != 0){
            ++i;
        }else{
            return i;
        }
    }
    return 0;
}


int Str_Length(const SString *s){
    if(s == NULL){
        return -1;
    }
    return s->length;
}

int Brute_Force(const SString *s,const SString *t){
    int i = 1,j = 1;
    while(i < s->length && j < t->length){
        if(s->ch[i] == t->ch[j]){
            ++i;
            ++j;
        }else{
            i = i-j+2;
            j = 1;
        }
    }
    if(j > t->length){
        return i - t->length;
    }else{
        return 0;
    }
}