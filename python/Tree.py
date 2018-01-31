from utils import log, formattedLog


class Node:
    def __init__(self, element):
        self.element = element
        self.firstChild = None
        self.nextSibling = None

class Tree:
    def __init__(self):
        self.root = Node('/')

    @staticmethod
    def children(node):
        # 获取指定节点的所有子节点
        siblings = []
        first = node.firstChild
        if first != None:
            # 第一个子节点
            siblings.append(first)
            # 下一个
            next = first.nextSibling
            while next != None:
                siblings.append(next)
                next = next.nextSibling

        return siblings

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
            current = None

            siblings = Tree.children(parent)

            index = Tree.find(element, siblings)
            if index >= 0:
                # 已存在的节点
                current = siblings[index]
            else:
                # 新节点
                current = Node(element)
                if len(siblings) == 0:
                    # 挂载为 firstChild
                    parent.firstChild = current
                else:
                    # 挂载到最后一个兄弟节点
                    siblings[-1].nextSibling = current

            parent = current

    def removeChild(self, node):
        elements = node.split('/')[1:]
        target = elements[-1]
        # log('elements', elements)

        parent = self.root
        for element in elements:
            current = None

            siblings = Tree.children(parent)

            index = Tree.find(element, siblings)
            if index >= 0:
                # 当前节点
                current = siblings[index]

                # 当前节点就是目标节点
                if target == current.element:
                    # 删除目标节点的子节点
                    current.firstChild = None
                    if index == 0:
                        # 目标节点是 firstChild
                        parent.firstChild = current.nextSibling
                    else:
                        # 目标节点不是 firstChild
                        siblings[index - 1].nextSibling = current.nextSibling
                    return
            else:
                log('要删除的节点不存在')

            parent = current

    @staticmethod
    def preorderTraversal(node, n):
        formattedLog(node.element, n)
        current = node.firstChild
        while current != None:
            Tree.preorderTraversal(current, n + 1)
            current = current.nextSibling

    def log(self):
        Tree.preorderTraversal(self.root, 0)

if __name__ == '__main__':
    t = Tree()
    t.addNode('/animal/cat/tom')
    t.addNode('/animal/rat/jerry')
    t.addNode('/plant/flower/rose')
    t.removeChild('/animal/cat')
    t.removeChild('/animal/rat/jerry')
    t.log()