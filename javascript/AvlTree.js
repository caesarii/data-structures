const {log, max} = require('./utils')

class Node {
    constructor(element) {
        this.element = element
        this.leftChild = null
        this.rightChild = null
        this.height = 0
    }
}


class Avl {
    constructor() {
        this.root = null
    }
    
    static height(node) {
        if(node === null) {
            return -1
        } else {
            return node.height
        }
    }
    
    static rotateSingleLeft(tree) {
        const subtree = tree.leftChild
        tree.leftChild = subtree.rightChild
        tree.rightChild = subtree
        
        subtree.height = max(Avl.height(subtree.leftChild), Avl.height(subtree.rightChild)) + 1
        tree.height = max(Avl.height(tree.leftChild), subtree.height) + 1
        return tree
    }
    
    static rotateSingleRight(tree) {
    
    }
    
    static rotateDoubleLeft(tree) {
        tree.leftChild = Avl.rotateSingleRight(tree.leftChild)
        
        return Avl.rotateSingleLeft(tree)
    }
    
    static rotateDoubleRight(tree) {
    
    }
    
    insert(element, tree = this.root) {
        // 插入第一个节点
        if(tree === null) {
            tree = new Node(element)
        }
        
        // 插入节点
        if(element < tree.element) {
            // 插入到左树
            tree.left = this.insert(element, tree.leftChild)
            
            // 高度差
            const diff = Avl.height(tree.leftChild) - Avl.height(tree.rightChild)
            if(diff === 2) {
                if(element < tree.leftChild.element) {
                    tree = Avl.rotateSingleLeft(tree)
                } else {
                    tree = Avl.rotateDoubleLeft(tree)
                }
            }
        } else if(element > tree.element) {
            tree.right = this.insert(element, tree.rightChild)
            const diff = Avl.height(tree.rightChild) - Avl.height(tree.leftChild)
            if(diff === 2) {
                if(element > tree.rightChild.element) {
                    tree = Avl.rotateSingleLeft(tree)
                } else {
                    tree = Avl.rotateDoubleRight(tree)
                }
            }
        } else {
            log('element is in the tree already, we will do nothing')
        }
        
        tree.height = max(Avl.height(tree.leftChild, tree.rightChild)) + 1
        return tree
    }
    
    del(element) {
    
    }
    
    retrieve(element) {
    
    }
    
    find(element, tree = this.root) {
    
    }
    
    findMin(tree = this.root) {
    
    }
    
    findMax(tree = this.root) {
    
    }
    
    clear() {
    
    }
}
