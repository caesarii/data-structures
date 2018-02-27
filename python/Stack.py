
from utils import log, ensure
from List import List

class Stack(List):
    def push(self, element):
        self.prepend(element)

    def pop(self):
        return self.shift()

    def isEmpty(self):
        return self.length == 0

    def clear(self):
        while not self.isEmpty():
            self.pop()

if __name__ == '__main__':
    s = Stack()

    s.push(0)
    s.push(1)
    s.push(2)
    s.pop()
    s.log()
    s.clear()
    s.log()
    log(s.isEmpty())

