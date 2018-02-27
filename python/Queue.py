
from utils import log, ensure
from List import List

class Queue(List):
    def enqueue(self, element):
        self.append(element)

    def dequeue(self):
        return self.shift()

    def isEmpty(self):
        return self.length == 0

    def clear(self):
        while not self.isEmpty():
            self.dequeue()

if __name__ == '__main__':
    s = Queue()
    s.enqueue(0)
    s.enqueue(1)
    s.enqueue(2)
    s.dequeue()
    s.log()
    s.clear()
    s.log()
    log(s.isEmpty())