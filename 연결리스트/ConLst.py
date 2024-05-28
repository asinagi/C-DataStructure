class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = Node(data)
        print(f"{data} 삽입")
        if self.head is None:
            self.head = new_node
            print(f"헤드: {data}")
        else:
            last = self.head
            while last.next:
                last = last.next
            last.next = new_node
            print(f"{last.data} -> {new_node.data}")
        self.print_list()

    def delete(self, key):
        print(f"{key} 삭제")
        temp = self.head

        if temp is not None and temp.data == key:
            self.head = temp.next
            print(f"헤드 삭제, 새 헤드: {self.head.data if self.head else '없음'}")
            temp = None
            self.print_list()
            return

        prev = None
        while temp is not None and temp.data != key:
            prev = temp
            temp = temp.next

        if temp is None:
            print(f"{key} 없음")
            return

        prev.next = temp.next
        print(f"{prev.data} -> {temp.next.data if temp.next else '없음'}")
        temp = None
        self.print_list()

    def print_list(self):
        temp = self.head
        print("리스트: ", end="")
        while temp:
            print(f"{temp.data} -> ", end="")
            temp = temp.next
        print("NULL")

if __name__ == "__main__":
    llist = LinkedList()
    llist.insert(1)
    llist.insert(2)
    llist.insert(3)
    llist.insert(4)
    llist.delete(3)
    llist.delete(1)
