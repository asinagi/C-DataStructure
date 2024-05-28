class QueueNode:
    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.front = None
        self.rear = None

    def createNode(self, data):
        return QueueNode(data)

    def enqueue(self, data):
        newNode = self.createNode(data)
        print(f"{data} 인큐")
        if self.rear is None:
            self.front = newNode
            self.rear = newNode
        else:
            self.rear.next = newNode
            self.rear = newNode
        self.printQueue()

    def dequeue(self):
        if self.front is None:
            print("큐가 비어있음")
            return -1
        data = self.front.data
        print(f"{data} 디큐")
        self.front = self.front.next
        if self.front is None:
            self.rear = None
        self.printQueue()
        return data

    def peek(self):
        if self.front is None:
            print("큐가 비어있음")
            return -1
        return self.front.data

    def isEmpty(self):
        return self.front is None

    def printQueue(self):
        if self.front is None:
            print("큐가 비어있음")
            return
        current = self.front
        print("큐 상태: ", end="")
        while current:
            print(f"{current.data}", end="")
            if current.next:
                print(" -> ", end="")
            current = current.next
        print(" -> None")

    def freeQueue(self):
        while self.front is not None:
            self.dequeue()
        print("큐 메모리 해제 완료")

if __name__ == "__main__":
    # 큐 생성
    queue = Queue()

    # 요소 인큐
    queue.enqueue(1)
    queue.enqueue(2)
    queue.enqueue(3)

    # 큐의 맨 앞 요소 확인 및 디큐
    print(f"큐의 맨 앞 요소: {queue.peek()}")
    print(f"디큐된 요소: {queue.dequeue()}")

    # 큐가 비어있는지 확인
    print(f"큐가 비어있는가? {'Yes' if queue.isEmpty() else 'No'}")

    # 큐의 모든 요소 디큐
    while not queue.isEmpty():
        queue.dequeue()

    # 메모리 해제
    queue.freeQueue()
