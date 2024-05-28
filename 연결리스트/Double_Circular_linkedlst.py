class Node:
    def __init__(self, data):
        self.data = data
        self.next = self
        self.prev = self

class DoublyCircularLinkedList:
    def __init__(self):
        self.head = None

    def createNode(self, data):
        return Node(data)

    def insertAtHead(self, data):
        newNode = self.createNode(data)
        print(f"{data} 삽입 (head)")
        if self.head is None:
            self.head = newNode
        else:
            tail = self.head.prev
            newNode.next = self.head
            newNode.prev = tail
            self.head.prev = newNode
            tail.next = newNode
            self.head = newNode
        self.printListForward()

    def insertAtTail(self, data):
        newNode = self.createNode(data)
        print(f"{data} 삽입 (tail)")
        if self.head is None:
            self.head = newNode
        else:
            tail = self.head.prev
            newNode.next = self.head
            newNode.prev = tail
            tail.next = newNode
            self.head.prev = newNode
        self.printListForward()

    def deleteNode(self, data):
        print(f"{data} 삭제")
        if self.head is None:
            print("리스트가 비어있음")
            return
        current = self.head
        while True:
            if current.data == data:
                if current.next == current:
                    self.head = None
                else:
                    prev = current.prev
                    next = current.next
                    prev.next = next
                    next.prev = prev
                    if current == self.head:
                        self.head = next
                print(f"{data} 노드 삭제됨")
                self.printListForward()
                return
            current = current.next
            if current == self.head:
                break
        print(f"{data} 없음")
        self.printListForward()

    def printListForward(self):
        if self.head is None:
            print("리스트가 비어있음")
            return
        current = self.head
        print("정방향: ", end="")
        while True:
            print(f"{current.data}", end="")
            current = current.next
            if current != self.head:
                print(" -> ", end="")
            else:
                break
        print(" -> (head)")

    def printListBackward(self):
        if self.head is None:
            print("리스트가 비어있음")
            return
        current = self.head.prev
        print("역방향: ", end="")
        while True:
            print(f"{current.data}", end="")
            current = current.prev
            if current != self.head.prev:
                print(" -> ", end="")
            else:
                break
        print(" -> (tail)")

    def freeList(self):
        if self.head is None:
            return
        current = self.head
        while True:
            next_node = current.next
            print(f"{current.data} 메모리 해제")
            del current
            current = next_node
            if current == self.head:
                break
        self.head = None

if __name__ == "__main__":
    # 이중 원형 연결 리스트 생성
    list = DoublyCircularLinkedList()

    # 노드 삽입
    list.insertAtHead(1)
    list.insertAtHead(2)
    list.insertAtTail(3)
    list.insertAtTail(4)

    # 리스트 출력
    list.printListForward()
    list.printListBackward()

    # 노드 삭제
    list.deleteNode(2)
    list.deleteNode(4)

    # 리스트 출력
    list.printListForward()
    list.printListBackward()

    # 메모리 해제
    list.freeList()
