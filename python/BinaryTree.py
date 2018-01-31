from utils import log, formattedLog

class Node:
    def __init__(self, element):
        self.element = element
        self.leftChild = None
        self.rightChild = None

class BinaryTree:
    def __init__(self):
        self.root = Node('/')

    @staticmethod
    def find(element, nodeList):
        for (i, node) in enumerate(nodeList):
            if node and node.element == element:
                return i
        return -1

    def addNode(self, node):
        elements = node.split('/')[1:]
        log('elements', elements)

        parent = self.root
        for element in elements:
            siblings = [parent.leftChild, parent.rightChild]
            index = BinaryTree.find(element, siblings)
            if index >= 0:
                # 已存在的节点
                current = siblings[index]
            else:
                # 新节点
                current = Node(element)
                if parent.leftChild == None:
                    # 挂载为 firstChild
                    parent.leftChild = current
                elif parent.rightChild == None:
                    parent.rightChild = current
                else:
                    log('不能创建新节点')

            parent = current

    def removeNode(self, node):
        elements = node.split('/')[1:]
        target = elements[-1]
        # log('elements', elements)

        parent = self.root
        for element in elements:
            current = None

            siblings = [parent.leftChild, parent.rightChild]

            index = BinaryTree.find(element, siblings)
            if index >= 0:
                # 当前节点
                current = siblings[index]

                # 当前节点就是目标节点
                if target == current.element:
                    # 删除目标节点的子节点
                    current.leftChild = None
                    current.rightChild = None
                    if index == 0:
                        # 目标节点是 leftChild
                        parent.leftChild = parent.rightChild
                        parent.rightChild = None
                    else:
                        # 目标节点是 rightChild
                        parent.rightChild = None
                    return
            else:
                log('要删除的节点不存在')

            parent = current

    @staticmethod
    def preorderTraversal(tree, n):
        if tree != None:
            formattedLog(tree.element, n)
            BinaryTree.preorderTraversal(tree.leftChild, n + 1)
            BinaryTree.preorderTraversal(tree.rightChild, n + 1)
        else:
            return

    def log(self):
        log(self.root)
        BinaryTree.preorderTraversal(self.root, 0)

if __name__ == '__main__':
    t = BinaryTree()
    t.addNode('/animal/cat/tom')
    t.addNode('/animal/rat/jerry')
    t.addNode('/plant/flower/rose')
    t.removeNode('/animal/cat')
    t.removeNode('/animal/rat/jerry')
    t.log()