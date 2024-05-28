import ConLst
import Double_Circular_linkedlst as cir
import Double_linked_lst as d_link
import queue
import Stack

while True:
    r = int(input("연결리스트는 1, 이중연결리스트는 2, 원형리스트는 3, 큐는 4, 스택은 5번을 입력하시오: "))
    if r == 1:
        lst = ConLst.LinkedList()
    elif r == 2:
        lst = d_link.DoublyLinkedList()
    elif r == 3:
        lst = cir.DoublyCircularLinkedList()
    elif r == 4:
        lst = queue.Queue()
    elif r == 5:
        lst = Stack.Stack()
    else:
        print("올바른 번호를 입력하시오")
        break

    while True:
        action = input("삽입: i, 삭제: d, 출력: p, 종료: q: ").lower()
        if action == 'i':
            data = int(input("삽입할 데이터: "))
            if r in [1, 2, 3]:
                lst.insertAtHead(data)
            elif r == 4:
                lst.enqueue(data)
            elif r == 5:
                lst.push(data)
        elif action == 'd':
            data = int(input("삭제할 데이터: "))
            if r in [1, 2, 3]:
                lst.deleteNode(data)
            elif r == 4:
                lst.dequeue()
            elif r == 5:
                lst.pop()
        elif action == 'p':
            if r in [1, 2, 3]:
                lst.printListForward()
            elif r == 4:
                lst.printQueue()
            elif r == 5:
                lst.printStack()
        elif action == 'q':
            break
        else:
            print("올바른 명령을 입력하시오")
