#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 리스트에 새 노드를 삽입하는 함수 (리스트의 끝에 삽입)
void insert(Node** head, int data) {
    // 새 노드 할당
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // 리스트가 비어 있는 경우
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // 리스트의 끝을 찾아서 새 노드 연결
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 주어진 값을 가진 첫 번째 노드를 삭제하는 함수
void delete(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    // 헤드 노드가 삭제할 노드인 경우
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    // 삭제할 노드를 찾기
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // 값이 리스트에 없는 경우
    if (temp == NULL) return;

    // 노드 연결을 건너뛰고 삭제
    prev->next = temp->next;
    free(temp);
}

// 리스트의 모든 노드를 출력하는 함수
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 메인 함수
int main() {
    Node* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);

    printf("list: ");
    printList(head);

    printf("3 delate and list: ");
    delete(&head, 3);
    printList(head);

    printf("1 delate and list: ");
    delete(&head, 1);
    printList(head);

    // 동적 메모리 해제
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
