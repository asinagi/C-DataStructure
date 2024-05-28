class StackNode:
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.top = None

    def createNode(self, data):
        return StackNode(data)

    def push(self, data):
        newNode = self.createNode(data)
        print(f"{data} 푸시")
        if self.top is None:
            self.top = newNode
        else:
            newNode.next = self.top
            self.top = newNode
        self.printStack()

    def pop(self):
        if self.top is None:
            print("스택이 비어있음")
            return -1
        data = self.top.data
        print(f"{data} 팝")
        self.top = self.top.next
        self.printStack()
        return data

    def peek(self):
        if self.top is None:
            print("스택이 비어있음")
            return -1
        return self.top.data

    def isEmpty(self):
        return self.top is None

    def printStack(self):
        if self.top is None:
            print("스택이 비어있음")
            return
        current = self.top
        print("스택 상태: ", end="")
        while current:
            print(f"{current.data}", end="")
            if current.next:
                print(" -> ", end="")
            current = current.next
        print(" -> None")

    def freeStack(self):
        while self.top is not None:
            self.pop()
        print("스택 메모리 해제 완료")

if __name__ == "__main__":
    # 스택 생성
    stack = Stack()

    # 요소 푸시
    stack.push(1)
    stack.push(2)
    stack.push(3)

    # 스택의 맨 위 요소 확인 및 팝
    print(f"스택의 맨 위 요소: {stack.peek()}")
    print(f"팝된 요소: {stack.pop()}")

    # 스택이 비어있는지 확인
    print(f"스택이 비어있는가? {'Yes' if stack.isEmpty() else 'No'}")

    # 스택의 모든 요소 팝
    while not stack.isEmpty():
        stack.pop()

    # 메모리 해제
    stack.freeStack()
