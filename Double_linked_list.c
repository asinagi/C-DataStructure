#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
//prev 는 이전 노드를 가리키는 포인터 *이중연결이므로 노드가 두개
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// 리스트 구조체 정의
// 해당 구조체는 리스트의 시작과 끝을 나타냄
// head는 시작, tail 은 끝을 가리키는 포인터
typedef struct DoublyLinkedList {
    Node* head;
    Node* tail;
} DoublyLinkedList;

// 새로운 노드 생성 함수
//data 를설정하고 next와 prev포인터를 null (동적으로 할당 및 데이터 초기화)
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// 리스트 초기화 함수
//head와 tail을 널로 설정
DoublyLinkedList* createDoublyLinkedList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// 노드를 리스트의 앞에 삽입하는 함수
// 비어있다면, head와 tail을 새노드로 설정
// 비어있지 않다면, head를 앞에 삽입-포인터를 적절히 업데이트
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
// 리스트가 비어있으면, head와 tail을 새노드로 설정
//아니라면, 새 노드를 tail 뒤에 삽입하고 포인터를 업데이트
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
//리스트를 순회하며 특정 데이터를 찾음
//찾으면 이전 노드와 다음 노드를 연결하고 현재 노드를 리스트에서 삭제
//현재 노드가 head나 tail이면 포인터를 업뎃
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
// head부터 시작, next를 따라 데이터를 출력
void printListForward(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 리스트의 모든 노드를 역방향으로 출력하는 함수
//tail부터 시작, prev포인터를 따라 데이터 출력
void printListBackward(DoublyLinkedList* list) {
    Node* current = list->tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// 메모리 해제 함수
//head부터 시작하여 모든 노드를 해제 후 리스트를 해제
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
