#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 6

#define DataType int
#define TRUE 1
#define FALSE -1

typedef struct {
    DataType data[MAXSIZE];
    int head;
    int tail;
    int size;
    int count;
} Queue;

Queue *createQueue(int size) {
    Queue *q = (Queue*)malloc(sizeof(Queue));

    if(!q) {
        printf("创建失败\n");
        return NULL;
    }
    q->head = -1;
    q->tail = -1;
    q->size = size;
    return q;
}

DataType isFull(Queue *q) {
    return ((q->tail + 1) % q->size) == q->head;
}

DataType isEmpty(Queue *q) {
    return q->head == -1;
}

DataType deQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("空列为空\n");
        return FALSE;
    }
    if (q->head == q->tail) {
        q->head = -1;
        q->tail = -1;
        return TRUE;
    }

    q->head = (q->head + 1) % q->size;
    return TRUE;
}

DataType enQueue(Queue *q, int value) {
    if (isFull(q)) {
        return FALSE;
    }
    if (isEmpty(q)) {
        q->head = 0;
    }
    q->tail = (q->tail + 1) % q->size;
    q->data[q->tail] = value;

    return TRUE;
}

int front(Queue *q) {
    if (isEmpty(q))
        return FALSE;

    return q->data[q->head];
}

int rear(Queue *q) {
    if (isEmpty(q))
        return FALSE;

    return q->data[q->tail];
}


void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("空队列\n");
        return;
    }
    printf("打印队列数据元素: \n");
    int start = q->head;
    int end = q->tail;

    while(start != end) {
        printf("%d ", q->data[start]);
        start = (start + 1) % q->size;
    }
    printf("%d ", q->data[end]);
    printf("\n");
}

int main() {

    Queue *q = createQueue(6);
    enQueue(q, 0);
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 5);

    printQueue(q);

    deQueue(q);
    deQueue(q);
    deQueue(q);

    printQueue(q);

    enQueue(q, 6);
    enQueue(q, 7);
    enQueue(q, 8);

    printQueue(q);

    free(q);
    return 0;
}