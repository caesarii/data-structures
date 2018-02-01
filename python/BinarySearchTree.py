from utils import log, formattedLog


class Node:
    def __init__(self, element):
        self.element = element
        self.leftChild = None
        self.rightChild = None


class BST:
    def __init__(self):
        self.root = None

    @property
    def tree(self):
        return self.root
    def insert(self, element):
        self.root = BST.insertIterative(element, self.root)

    @staticmethod
    def insertIterative(element, tree):

        if tree == None:
            # 空树
            tree = Node(element)
        else:
            if element < tree.element:
                tree.leftChild = BST.insertIterative(element, tree.leftChild)
            elif element > tree.element:
                tree.rightChild = BST.insertIterative(element, tree.rightChild)
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
        # 返回最小节点
        if tree == None:
            return None
        else:
            if tree.leftChild == None:
                return tree
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

    def delete(self, element):
        self._delete(element, self.root)

    def _delete(self, element, tree):
        if tree == None:
            log('ERROR: element not found')
        if element == tree.element:
            # 当前节点是目标节点
            log('target is found')
            if tree.leftChild and tree.rightChild:
                # 目标节点有两个子节点
                log('target hava two child')
                BST.log(tree)
                # 寻找右树的最小节点，这个节点必然没有左节点，用这个节点代替目标节点，更容易删除
                minChildOfRight = self._findMin(tree.rightChild)
                tree = minChildOfRight
                self._delete(tree.element, tree)
            else:
                log('tartget have one or zero child')
                # 目标节点只有 一个 或 0 个子节点
                if tree.leftChild == None:
                    tree = tree.rightChild
                elif tree.rightChild == None:
                    tree = tree.leftChild
                else:
                    log('target have zero child, we do nothing')
        elif element < tree.element:
            log('go left')
            # 在左树寻找目标节点
            tree.leftChild = self._delete(element, tree.leftChild)
        elif element > tree.element:
            log('go right')
            # 在右树寻找目标节点
            tree.rightChild = self._delete(element, tree.rightChild)
        return tree

    def clear(self):
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
        if tree != None:
            formattedLog(tree.element, n)
            BST.preorderTraversal(tree.leftChild, n + 1)
            BST.preorderTraversal(tree.rightChild, n + 1)
        else:
            return
    @staticmethod
    def log(tree):
        BST.preorderTraversal(tree, 0)


if __name__ == '__main__':
    BST = BST
    t = BST()
    t.insert(6)
    t.insert(2)
    t.insert(8)
    t.insert(1)
    t.insert(4)
    t.insert(3)
    t.insert(5)
    BST.log(t.tree)
    e = t.find(9)
    log('e', e)
    min = t.findMin()
    log('min', min)
    max = t.findMax()
    log('max', max)

    t.delete(4)

    # t.clear()
    BST.log(t.tree)
