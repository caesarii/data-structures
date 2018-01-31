from utils import log, formattedLog

class Node:
    def __init__(self, element):
        self.element = element
        self.leftChild = None
        self.rightChild = None

class BinarySearchTree:
    def __init__(self):
        self.root = None

    @property
    def _root(self):
        return self.root

    def insert(self, element):
        self.root = BinarySearchTree.insertIterative(element, self.root)

    @staticmethod
    def insertIterative(element, tree):
        bst = BinarySearchTree
        if tree == None:
            # 空树
            tree = Node(element)
        else:
            if element < tree.element:
                tree.leftChild = bst.insertIterative(element, tree.leftChild)
            elif element > tree.element:
                tree.rightChild = bst.insertIterative(element, tree.rightChild)
            else:
                log('element is in the tree already')
        return tree

    def find(self, element):
       return self._find(element, self.root)

    def _find(self, element, tree):
        if tree == None:
            return None
        elif element < tree.element:
            return self._find(element, tree.leftChild)
        elif element > tree.element:
            return self._find(element, tree.rightChild)
        else:
            return tree.element

    def findMin(self):
        return self._findMin(self.root)

    def _findMin(self, tree):
        if tree == None:
            return None
        else:
            if tree.leftChild == None:
                return tree.element
            else:
                return self._findMin(tree.leftChild)

    def findMax(self):
        return self._findMax(self.root)

    def _findMax(self, tree):
        if tree == None:
            return None
        else:
            if tree.rightChild == None:
                return tree.element
            else:
                return self._findMax(tree.rightChild)

    def clear(self, tree):
        self._clear(self.root)

    def _clear(self, tree):
        if tree != None:
            self._clear(tree.leftChild)
            self._clear(tree.rightChild)
            tree.element = None
            tree.leftChild = None
            tree.rightChild = None
        else:
            return

    @staticmethod
    def preorderTraversal(tree, n):
        bst = BinarySearchTree
        if tree != None:
            formattedLog(tree.element, n)
            bst.preorderTraversal(tree.leftChild, n + 1)
            bst.preorderTraversal(tree.rightChild, n + 1)
        else:
            return

    def log(self):
        BinarySearchTree.preorderTraversal(self.root, 0)

if __name__ == '__main__':
    t = BinarySearchTree()
    t.insert(6)
    t.insert(2)
    t.insert(8)
    t.insert(1)
    t.insert(4)
    t.insert(3)
    t.insert(5)
    e = t.find(9)
    log('e', e)
    min = t.findMin()
    log('min', min)
    max = t.findMax()
    log('max', max)
    # t.clear()
    t.log()
