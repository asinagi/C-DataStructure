#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
// next = 다음노드, prev = 이전노드
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// 리스트 구조체 정의
// 첫번째 노드를 가리키는 head
typedef struct DoublyCircularLinkedList {
    Node* head;
} DoublyCircularLinkedList;

// 새로운 노드 생성 함수
// data 설정 동적으로 할당, next와 prev 포인터를 자신에게 가리키도록 초기화
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

// 리스트 초기화 함수
//head를 null
DoublyCircularLinkedList* createDoublyCircularLinkedList() {
    DoublyCircularLinkedList* list = (DoublyCircularLinkedList*)malloc(sizeof(DoublyCircularLinkedList));
    list->head = NULL;
    return list;
}

// 노드를 리스트의 앞에 삽입하는 함수
//리스트가 비면, head를 새 노드로
//아니라면 새 노드를 head앞에 삽입- 포인터업뎃
void insertAtHead(DoublyCircularLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* tail = list->head->prev;
        newNode->next = list->head;
        newNode->prev = tail;
        list->head->prev = newNode;
        tail->next = newNode;
        list->head = newNode;
    }
}

// 노드를 리스트의 뒤에 삽입하는 함수
//리스트가 비면 head를 새 노드로
//아니라면 새노드를 tail 뒤에 삽입
void insertAtTail(DoublyCircularLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* tail = list->head->prev;
        newNode->next = list->head;
        newNode->prev = tail;
        tail->next = newNode;
        list->head->prev = newNode;
    }
}

// 리스트에서 특정 데이터를 가진 노드를 삭제하는 함수
//리스트가 비면, 바로 반환
//순회하면서 데이터를 찾고, 이전노드를 다음노드와 연결하여 현재 노드를 리스트에서 제거
//현재 노드가 head 라면 head를 다음 노드로 업뎃
//삭제할 노드가 마지막 노드라면 head를 null로 설정
void deleteNode(DoublyCircularLinkedList* list, int data) {
    if (list->head == NULL) {
        return;
    }
    Node* current = list->head;
    do {
        if (current->data == data) {
            if (current->next == current) {
                list->head = NULL;
            } else {
                Node* prev = current->prev;
                Node* next = current->next;
                prev->next = next;
                next->prev = prev;
                if (current == list->head) {
                    list->head = next;
                }
            }
            free(current);
            return;
        }
        current = current->next;
    } while (current != list->head);
}

// 리스트의 모든 노드를 순방향으로 출력하는 함수
void printListForward(DoublyCircularLinkedList* list) {
    if (list->head == NULL) { //노드가 비면 비었다고 출력
        printf("List is empty\n");
        return;
    }
    Node* current = list->head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head);
    printf("\n");
}

// 리스트의 모든 노드를 역방향으로 출력하는 함수
void printListBackward(DoublyCircularLinkedList* list) {
    if (list->head == NULL) { 
        //노드가 비면 비었다고 출력
        printf("List is empty\n");
        return;
    }
    Node* current = list->head->prev;
    do {
        printf("%d ", current->data);
        current = current->prev;
    } while (current->next != list->head);
    printf("\n");
}

// 메모리 해제 함수
//모든 노드를 해제하여 동적 메모리 반환, 
//head부터 시작해 모든 노드해제-리스트 해제
void freeList(DoublyCircularLinkedList* list) {
    if (list->head == NULL) {
        free(list);
        return;
    }
    Node* current = list->head;
    do {
        Node* next = current->next;
        free(current);
        current = next;
    } while (current != list->head);
    free(list);
}

int main() {
    // 이중 원형 연결 리스트 생성
    DoublyCircularLinkedList* list = createDoublyCircularLinkedList();

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
