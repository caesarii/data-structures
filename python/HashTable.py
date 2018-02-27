
from utils import log, hash, nextPrime
from List import List

class HashTable:
    def __init__(self, length):
        self.length = nextPrime(length)
        self.array = []
        for i in range(self.length):
            self.array.append(List())

    def set(self, key, value):
        index = hash(key, self.length)
        list= self.array[index]
        list.append(value)

    def get(self, key):
        index = hash(key, self.length)
        list = self.array[index]
        return list.elementAt(0)

    def has(self, key):
        index = hash(key, self.length)
        list = self.array[index]
        return list.length != 0

    def clear(self):
        len = self.length
        for i in range(len):
            list = self.array[i]
            list.clear()

if __name__ == '__main__':
    h = HashTable(100)
    h.set('name', 'qinghe')
    h.set('age', 14)
    log(h.get('age'))
    log(h.get('name'))
    log(h.has('name'))
    log(h.has('job'))