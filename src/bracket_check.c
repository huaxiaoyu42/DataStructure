#include<stdlib.h>
#include<stdio.h>

#define ElemType char 
#include"../include/sqstack.h"

bool bracket_check(char str[],int length){
    SqStack s;

    InitStack(&s);
    
    for(int i = 0;i<length;i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            Push(&s,str[i]);
        }else{
            if(stack_is_empty(&s)){
                return false;
            }

            char top_elem;
            Pop(&s,&top_elem);
            if(str[i] == ')' && top_elem != '('){
                return false;
            }
            if(str[i] == ']' && top_elem != '['){
                return false;
            }
            if(str[i] == '}' && top_elem != '{'){
                return false;
            }
        }
    }
    return true;
}


int main(){

    char arr[] = {'(','(','(',')',')',')'};

    bool res = bracket_check(arr,6);
    if(res){
        printf("OK\n");
    }else{
        printf("FUCK\n");  
    }
    return 0;
}