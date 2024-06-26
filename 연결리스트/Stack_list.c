#include <stdio.h>
#include <stdlib.h>

// 스택의 노드 구조체 정의
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// 스택 구조체 정의
//stack 구조체는 스택의 최상단 노드를 나타냄 top은 스택의 맨위노드
typedef struct Stack {
    StackNode* top;
} Stack;

// 스택 초기화 함수
//top을 null설정
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// 새로운 노드 생성 함수
//data를 설정하고 next포인터를 null로 초기화
StackNode* createNode(int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 스택에 요소를 푸시하는 함수
//스택이 비어있으면, top을 새노드로 설정
// 비어있지않으면, next 포이너를 현재 top으로 설정하고 top을 새 노드로 업뎃
void push(Stack* stack, int data) {
    StackNode* newNode = createNode(data);
    if (stack->top == NULL) {
        stack->top = newNode;
    } else {
        newNode->next = stack->top;
        stack->top = newNode;
    }
}

// 스택에서 요소를 팝하는 함수
// top의 데이터를 저장하고 top을 다음노드로 업데이트
//제거한 노드를 해제하고 데이터를 반환
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1; // 예외 처리: 스택이 비어있는 경우
    }
    int data = stack->top->data;
    StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// 스택의 맨 위 요소를 반환하는 함수 (팝하지 않음)
int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1; // 예외 처리: 스택이 비어있는 경우
    }
    return stack->top->data;
}

// 스택이 비어있는지 확인하는 함수
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// 메모리 해제 함수
//top부터 시작하여 모든노드를 해제 후 구조체 자체를 해제
void freeStack(Stack* stack) {
    StackNode* current = stack->top;
    while (current != NULL) {
        StackNode* next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}

int main() {
    // 스택 생성
    Stack* stack = createStack();

    // 요소 푸시
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    // 스택의 맨 위 요소 확인 및 팝
    printf("Top element of the stack: %d\n", peek(stack));
    printf("Popped element: %d\n", pop(stack));

    // 스택이 비어있는지 확인
    printf("Is stack empty? %s\n", isEmpty(stack) ? "Yes" : "No");

    // 스택의 모든 요소 팝
    while (!isEmpty(stack)) {
        printf("Popped element: %d\n", pop(stack));
    }

    // 메모리 해제
    freeStack(stack);

    return 0;
}
