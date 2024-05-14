#include <stdio.h>
#include <stdlib.h>

// 큐의 노드 구조체 정의
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

// 큐 구조체 정의
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// 큐 초기화 함수
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// 새로운 노드 생성 함수
QueueNode* createNode(int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 큐에 요소를 인큐하는 함수
void enqueue(Queue* queue, int data) {
    QueueNode* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// 큐에서 요소를 디큐하는 함수
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return -1; // 예외 처리: 큐가 비어있는 경우
    }
    int data = queue->front->data;
    QueueNode* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

// 큐의 맨 앞 요소를 반환하는 함수 (디큐하지 않음)
int peek(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return -1; // 예외 처리: 큐가 비어있는 경우
    }
    return queue->front->data;
}

// 큐가 비어있는지 확인하는 함수
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// 메모리 해제 함수
void freeQueue(Queue* queue) {
    QueueNode* current = queue->front;
    while (current != NULL) {
        QueueNode* next = current->next;
        free(current);
        current = next;
    }
    free(queue);
}

int main() {
    // 큐 생성
    Queue* queue = createQueue();

    // 요소 인큐
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    // 큐의 맨 앞 요소 확인 및 디큐
    printf("Front element of the queue: %d\n", peek(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    // 큐가 비어있는지 확인
    printf("Is queue empty? %s\n", isEmpty(queue) ? "Yes" : "No");

    // 큐의 모든 요소 디큐
    while (!isEmpty(queue)) {
        printf("Dequeued element: %d\n", dequeue(queue));
    }

    // 메모리 해제
    freeQueue(queue);

    return 0;
}
