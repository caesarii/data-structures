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
                return


    def deleteMin(self):
        # deleteMin 其实使用 last 代替 min, 然后恢复 heap 的堆序性质
        current = 1
        min = self.elements[current]
        last = self.elements[self.length]
        # 删除 min
        self.elements[current] = last
        # 删除最后一个元素
        self.elements[self.length] = None

        self.length -= 1

        # child = current * 2
        # # 当前节点有子节点
        # while child <= self.length:
        #     if child + 1 <= self.length and self.elements[child + 1] < self.elements[child]:
        #         # 当前节点有右子节点. 如果右儿子更小则用右儿子
        #         child += 1
        #
        #     # 下滤: 如果当前节点较小的子节点小于 last, 说明 last 不能放在当前位置
        #     # 所以将较小的子节点上浮
        #     # 空位下移一层
        #     if self.elements[child] < last:
        #         # 交换当前元素与其子元素
        #         e = self.elements[current]
        #         self.elements[current] = self.elements[child]
        #         self.elements[child] = e
        #         # 对子节点进行检测
        #         current = child
        #     else:
        #         # 子元素大于当前元素 跳出循环
        #         break

        while True:
            # 子节点
            child = current * 2
            # 当前节点有子节点
            if child <= self.length:
                # 当前节点有右子节点
                if child + 1 <= self.length and self.elements[child + 1] < self.elements[child]:
                    # 如果右儿子更小则用右儿子
                    child += 1

                # 下滤: 如果当前节点较小的子节点仍然小于 last, 说明 last 不能放在当前位置
                # 所以将较小的子节点上浮
                # 空位下移一层
                if self.elements[child] < last:
                    self.elements[current] = self.elements[child]
                    current = child
                else:
                     #
                     break

            else:
                break

        self.elements[current] = last
        return min


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
        for (i, e) in enumerate(self.elements):
            heapLog(e, i)
        log('\n')


if __name__ == '__main__':
    heap = Heap(100)
    heap.insert(13)
    heap.insert(14)
    heap.insert(16)
    heap.insert(19)
    heap.insert(21)
    heap.insert(19)
    heap.insert(68)

    heap.insert(65)
    heap.insert(26)


    heap.insert(32)

    heap.insert(31)

    heap.log()

    heap.deleteMin()
    #
    #
    heap.log()


