#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// 리스트 구조체 정의
typedef struct DoublyLinkedList {
    Node* head;
    Node* tail;
} DoublyLinkedList;

// 새로운 노드 생성 함수
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// 리스트 초기화 함수
DoublyLinkedList* createDoublyLinkedList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// 노드를 리스트의 앞에 삽입하는 함수
void insertAtHead(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

// 노드를 리스트의 뒤에 삽입하는 함수
void insertAtTail(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->tail == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// 리스트에서 특정 데이터를 가진 노드를 삭제하는 함수
void deleteNode(DoublyLinkedList* list, int data) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                list->head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                list->tail = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

// 리스트의 모든 노드를 순방향으로 출력하는 함수
void printListForward(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 리스트의 모든 노드를 역방향으로 출력하는 함수
void printListBackward(DoublyLinkedList* list) {
    Node* current = list->tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// 메모리 해제 함수
void freeList(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    // 이중 연결 리스트 생성
    DoublyLinkedList* list = createDoublyLinkedList();

    // 노드 삽입
    insertAtHead(list, 1);
    insertAtHead(list, 2);
    insertAtTail(list, 3);
    insertAtTail(list, 4);

    // 리스트 출력
    printf("List forward: ");
    printListForward(list);
    printf("List backward: ");
    printListBackward(list);

    // 노드 삭제
    deleteNode(list, 2);
    deleteNode(list, 4);

    // 리스트 출력
    printf("List forward after deletion: ");
    printListForward(list);
    printf("List backward after deletion: ");
    printListBackward(list);

    // 메모리 해제
    freeList(list);

    return 0;
}
