#include<stdlib.h>
#include<stdio.h>
#include "../include/linked_queue.h"

int main(){

    LinkQueue q;
    initqueue(&q);

    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);

    int a,b,c;
    dequeue(&q,&a);
    dequeue(&q,&b);
    dequeue(&q,&c);

    printf("a -> %d\n",a);
    printf("b -> %d\n",b);
    printf("c -> %d\n",c);


    return 0;
}