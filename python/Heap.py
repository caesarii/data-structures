from math import floor, pow
from utils import log, heapLog
class Heap:
    def __init__(self, capacity):
        self.elements = [None for i in range(capacity)]
        self.capacity = capacity
        self.length = 0
    def insert(self, element):
        # 插入第一个元素
        if self.length == 0:
            self.elements[1] = element
            self.length += 1
            return

        self.length += 1
        index = self.length
        while True:
            parentIndex = floor(index / 2)
            parent = self.elements[parentIndex]
            if parent and parent > element:
                self.elements[index] = parent
                index = floor(index / 2)
            else:
                self.elements[index] = element
                log('\n')
                return


    def deleteMin(self):
        pass

    def findMin(self):

        pass

    def destory(self):
        pass

    def makeEmpty(self):
        pass


    def isEmpty(self):

        pass


    def isFull(self):

        pass

    def log(self):
        breakpoint = [2**i - 1 for i in range(10)]
        # log(breakpoint)
        for (i, e) in enumerate(self.elements):
            heapLog(e, i)


if __name__ == '__main__':
    heap = Heap(100)
    heap.insert(13)
    heap.insert(21)
    heap.insert(16)
    # heap.log()
    heap.insert(19)
    # heap.log()
    heap.insert(68)
    # heap.log()
    #
    heap.insert(24)
    heap.insert(31)



    heap.log()