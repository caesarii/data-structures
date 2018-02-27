
from utils import log, ensure

class Node:
    def __init__(self, element):
        self.element = element
        self.next = None

class List:
    def __init__(self):
        self.next = None
        self.tail = None
        self.length = 0

    def prepend(self, element):
        node = Node(element)
        node.next = self.next
        self.next = node

        self.length += 1
        return self.length

    def append(self, element):
        node = Node(element)
        if self.length == 0:
            self.next = node
        else:
            self.tail.next = node

        self.tail = node
        self.length += 1
        return self.length

    def shift(self):
        if self.length == 0:
            return -1
        else:
            e = self.next.element
            self.next = self.next.next
        self.length -= 1
        return e

    def contains(self, target):
        current = self.next
        while current != None:
            if current.element == target:
                return True
            current = current.next
        return False

    def indexOf(self, target):
        index = 0
        current = self.next
        while current != None:
            if current.element == target:
                return index
            current = current.next
            index += 1
        return -1

    def elementAt(self, index):
        i = 0
        current = self.next
        while current != None:
            if i == index:
                return current.element
            current = current.next
            i += 1
        return None

    def insert(self, index, element):
        i = 0
        current = self.next
        while current != None:
            if i == index - 1:
                n = Node(element)
                n.next = current.next
                current.next = n
                return index
            current = current.next
            i += 1
        return -1

    def change(self, index, element):
        i = 0
        current = self.next
        while current != None:
            if i == index:
                current.element = element
                return index
            current = current.next
            i += 1
        return -2

    def clear(self):
        while self.length != 0:
            self.shift()


    def log(self):
        current = self.next
        while current != None:
            log(current.element)
            current = current.next

if __name__ == '__main__':
    lst = List()

    lst.append(2)
    lst.append(3)
    lst.prepend(1)
    lst.prepend(0)
    ensure(lst.length == 4, 'test list length')
    lst.log()

    ensure(lst.contains(5) == False, 'test list contains 1')
    ensure(lst.contains(3) == True, 'test list contains 2')

    i = lst.indexOf(3)
    ensure(i == 3, 'test list indexOf')

    e = lst.elementAt(2)
    ensure(e == 2, 'test list elementAt')

    lst.insert(2, 2.5)
    ensure(lst.indexOf(2.5) == 2, 'test list insert')

    lst.change(4, 5)
    ensure(lst.indexOf(5) == 4, 'test list change')

    lst.shift()
    ensure(lst.length == 3, 'test list shift 1')
    ensure(lst.elementAt(0) == 1, 'test list shift 2')

    lst.clear()
    ensure(lst.length == 0, 'test list clear')




