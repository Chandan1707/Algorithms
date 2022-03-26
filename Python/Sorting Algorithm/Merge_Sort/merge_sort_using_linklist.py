import sys
sys.path.insert(0, '/home/chandan/Documents/Data Structure and Algorithm/Python/Linked List')
from Singly_Linked_List import LinkedList,Node


def split(lst, pos):

        current = lst.index_at_pos(pos-1)
        new_lst = LinkedList()
        new_lst.head = current.next
        new_lst.tail = lst.tail
        lst.tail = current
        lst.tail.next = None
        return lst, new_lst


def merge(lst1, lst2):
    lst = LinkedList()
    while lst1.head is not None and lst2.head is not None:
        if lst1.head.info < lst2.head.info:
            if lst.head is None:
                lst.head = lst.tail = lst1.head

            else:
                lst.tail.next = lst1.head
                lst.tail = lst.tail.next
            lst1.head = lst1.head.next
        else:
            if lst.head is None:
                lst.head = lst.tail = lst2.head
            else:
                lst.tail.next = lst2.head
                lst.tail = lst.tail.next
            lst2.head = lst2.head.next

    if lst1.head:
        if lst.head is None:
            lst.head = lst1.head
            lst.tail = lst1.tail

        else:
            lst.tail.next = lst1.head
            lst.tail = lst1.tail
    if lst2.head:
        if lst.head is None:
            lst.head = lst2.head
            lst.tail = lst2.tail

        else:
            lst.tail.next = lst2.head
            lst.tail = lst2.tail
    return lst


def merge_sort(lst, n):
    if n <= 1:
        return lst
    mid = n // 2
    left, right = split(lst, mid)
    left = merge_sort(left, mid)
    right = merge_sort(right, n-mid)
    lst = merge(left, right)
    return lst


if __name__ == '__main__':
    lst = LinkedList()
    a = int(input('\nEnter # input :'))
    b = None
    for i in range(a):
        b = int(input('add :'))
        lst.add_node(b)

    print('\nBefore Sort', lst)
    lst = merge_sort(lst, a)
    print('\nAfter Sort', lst)
