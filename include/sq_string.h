#ifndef SQ_STRING_H
#define SQ_STRING_H

#include<stdbool.h>

#define MAXLEN 255




typedef struct{
    char ch[MAXLEN];
    int length;
}SString;


/**
 * 动态分配内存的串
*/
typedef struct{
    char *ch;
    int length;
}HString;

/**
 * 求子串，用sub返回串s的第pos个字符起长度为len的子串
*/
bool SubString(SString *sub,SString s,int pos,int len);


/**
 * 比较两个串
 * 若s>t：返回值 > 0
 * 若s=t：返回值=0
 * 若s<t：返回值<0
*/
int Compare_String(SString *s,SString *t);

/**
 * 定位操作，若主串s中存在与t相同的子串，则返回它在主串s中第一次出现的位置。否则返回0
*/

int Index(SString *s,SString *t);

/**
 * 返回串的长度
*/
int Str_Length(const SString *s);

/**
 * 朴素模式匹配
*/
int Brute_Force(const SString *s,const SString *t);
#endif