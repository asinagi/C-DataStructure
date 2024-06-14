
#include <stdio.h>
#include <stdlib.h>

// 쓰레드 이진 트리 노드 구조체
typedef struct ThreadedTreeNode {
    int data;
    struct ThreadedTreeNode* left;
    struct ThreadedTreeNode* right;
    int leftThread;  // leftThread가 1이면 left는 왼쪽 자식이 아닌 인오더 전임자를 가리킴
    int rightThread; // rightThread가 1이면 right는 오른쪽 자식이 아닌 인오더 후임자를 가리킴
} ThreadedTreeNode;

// 새로운 노드 생성 함수
ThreadedTreeNode* createNode(int data) {
    ThreadedTreeNode* newNode = (ThreadedTreeNode*)malloc(sizeof(ThreadedTreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->leftThread = 1;
    newNode->rightThread = 1;
    return newNode;
}

// 노드 삽입 함수
ThreadedTreeNode* insert(ThreadedTreeNode* root, int data) {
    ThreadedTreeNode* ptr = root;
    ThreadedTreeNode* parent = NULL;
    while (ptr != NULL) {
        if (data == ptr->data) {
            return root; // 중복된 데이터는 삽입하지 않음
        }
        parent = ptr;
        if (data < ptr->data) {
            if (ptr->leftThread == 0) {
                ptr = ptr->left;
            } else {
                break;
            }
        } else {
            if (ptr->rightThread == 0) {
                ptr = ptr->right;
            } else {
                break;
            }
        }
    }

    ThreadedTreeNode* newNode = createNode(data);

    if (parent == NULL) {
        root = newNode; // 새로운 노드가 루트가 됨
    } else if (data < parent->data) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->leftThread = 0;
        parent->left = newNode;
    } else {
        newNode->right = parent->right;
        newNode->left = parent;
        parent->rightThread = 0;
        parent->right = newNode;
    }

    return root;
}

// 인오더 순회 함수
void inorder(ThreadedTreeNode* root) {
    ThreadedTreeNode* ptr = root;
    if (root == NULL) {
        return;
    }

    // 가장 왼쪽 노드로 이동
    while (ptr->leftThread == 0) {
        ptr = ptr->left;
    }

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        // 오른쪽 서브트리 탐색
        if (ptr->rightThread == 1) {
            ptr = ptr->right;
        } else {
            ptr = ptr->right;
            while (ptr != NULL && ptr->leftThread == 0) {
                ptr = ptr->left;
            }
        }
    }
}

// 메인 함수
int main() {
    ThreadedTreeNode* root = NULL;

    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}
