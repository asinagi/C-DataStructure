#include <stdio.h>
#include <stdlib.h>

// 큐의 노드 구조체 정의
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

// 큐 구조체 정의
// front 는 큐의 맨 앞 노드를 가리키고, rear는 큐의 마지막 노드를 가리키는 포인터
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// 큐 초기화 함수
//front 와 rear를 null
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// 새로운 노드 생성 함수
//data를 설정하고 next 포인터를 널로 초기화
QueueNode* createNode(int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 큐에 요소를 인큐하는 함수
//큐가 비어 있으면 front와 rear를 새 노드로 설정
// 아니라면, rear의 next 포인터를 새 노드로 설정- rear를 새 노드로 업뎃
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
//front의 데이터를 저장-다음노드로 업뎃
//비어 있다면 rear도 null로 설정
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
//front 가 널이면 큐가 비어있다는 것임
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// 메모리 해제 함수
// 모든 노드를 해제한 후 큐 자체를 해제
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
