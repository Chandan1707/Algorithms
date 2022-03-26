class Node:
    def __init__(self, val):
        self.info = val
        self.next = None

    def __repr__(self):
        msg = f'< Node : {self.info} >'
        return msg


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def __repr__(self):
        lst = []
        current = self.head
        while current is not None:
            if current is self.head:
                lst.append(f'[head : {current.info}]')
            elif current is self.tail:
                lst.append(f'[Tail : {current.info}]')
            else:
                lst.append(current.info)
            current = current.next
        return f'{lst}'

    def add_node(self, val):
        new_node = Node(val)
        if self.head is None:
            self.head = self.tail = new_node
            return
        self.tail.next = new_node
        self.tail = self.tail.next

    def index_at_pos(self, pos):
        current = self.head
        i = 0
        while i < pos:
            i += 1
            current = current.next
        return current


if __name__ == '__main__':
    lst = LinkedList()
    a = int(input('\nEnter # input :'))
    b = None
    for i in range(a):
        b = int(input('add :'))
        lst.add_node(b)
    print(lst)
