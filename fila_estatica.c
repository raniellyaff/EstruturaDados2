#include <stdio.h>
#include  <stdlib.h>

#define CAP 10

typedef struct {
    int queue [CAP];
    int head;
    int tail;
    int qtd;
} Queue;

int is_full( Queue *q){
    return q->qtd == CAP;
}

void enqueue(Queue *q, int value){
    if(is_full(q)){
        printf("Fila cheia\n");
        return;
    }
    q->queue[q->tail % CAP] = value;
    q->tail++;
    q->qtd++;
}

int is_empty(Queue *q){
    return q->qtd == 0;
}

int dequeue(Queue *q){
    if(is_empty(q)){
        printf("Queue is empty\n");
        return 0;
    }
    int value = q->queue[q->head % CAP];
    q->head++;
    q->qtd--;
    return value;
}

void show(Queue *q){
    for(int i = q->head; i < q->tail; i++){
        printf("%d ", q->queue[i % CAP]);
    }
    printf("\n");
}

int main(){
    Queue q;
    q.head = 0;
    q.tail = 0;
    q.qtd = 0;
    Queue *pq = &q;
    for(int i = 0; i < 15; i++){
        enqueue(pq, i);
        show(pq);
    }
    for(int i = 0; i < 15; i++){
        printf("Valor removido: %d\n", dequeue(pq));
        show(pq);

    }
}
