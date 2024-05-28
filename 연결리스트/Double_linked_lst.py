class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def createNode(self, data):
        return Node(data)

    def insertAtHead(self, data):
        newNode = self.createNode(data)
        print(f"{data} 삽입 (head)")
        if self.head is None:
            self.head = newNode
            self.tail = newNode
            print(f"헤드와 테일: {data}")
        else:
            newNode.next = self.head
            self.head.prev = newNode
            self.head = newNode
            print(f"새 헤드: {data}, 다음: {newNode.next.data}")
        self.printList()

    def insertAtTail(self, data):
        newNode = self.createNode(data)
        print(f"{data} 삽입 (tail)")
        if self.tail is None:
            self.head = newNode
            self.tail = newNode
            print(f"헤드와 테일: {data}")
        else:
            newNode.prev = self.tail
            self.tail.next = newNode
            self.tail = newNode
            print(f"새 테일: {data}, 이전: {newNode.prev.data}")
        self.printList()

    def deleteNode(self, data):
        print(f"{data} 삭제")
        current = self.head
        while current is not None:
            if current.data == data:
                if current.prev is not None:
                    current.prev.next = current.next
                    print(f"{current.prev.data} -> {current.next.data if current.next else '없음'}")
                else:
                    self.head = current.next
                    print(f"새 헤드: {self.head.data if self.head else '없음'}")

                if current.next is not None:
                    current.next.prev = current.prev
                else:
                    self.tail = current.prev
                    print(f"새 테일: {self.tail.data if self.tail else '없음'}")
                    
                current = None
                self.printList()
                return
            current = current.next
        print(f"{data} 없음")
        self.printList()

    def printList(self):
        current = self.head
        print("리스트: ", end="")
        while current:
            print(f"{current.data} -> ", end="")
            current = current.next
        print("NULL")

    def printListForward(self):
        current = self.head
        print("정방향: ", end="")
        while current:
            print(f"{current.data} ", end="")
            current = current.next
        print()

    def printListBackward(self):
        current = self.tail
        print("역방향: ", end="")
        while current:
            print(f"{current.data} ", end="")
            current = current.prev
        print()

    def freeList(self):
        current = self.head
        while current:
            next_node = current.next
            print(f"{current.data} 메모리 해제")
            del current
            current = next_node
        self.head = None
        self.tail = None

if __name__ == "__main__":
    # 이중 연결 리스트 생성
    list = DoublyLinkedList()

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
