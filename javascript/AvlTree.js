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
        subtree.rightChild = tree
        
        tree.height = max(Avl.height(tree.leftChild), Avl.height(tree.rightChild)) + 1
        subtree.height = max(Avl.height(subtree.leftChild), tree.height) + 1
        return subtree
    }
    
    static rotateSingleRight(tree) {
        const subtree = tree.rightChild
        tree.rightChild = subtree.leftChild
        subtree.leftChild = tree
    
        tree.height = max(Avl.height(tree.rightChild), Avl.height(tree.leftChild)) + 1
        subtree.height = max(Avl.height(subtree.rightChild), tree.height) + 1
        return subtree
    }
    
    static rotateDoubleLeft(tree) {
        tree.leftChild = Avl.rotateSingleRight(tree.leftChild)
        return Avl.rotateSingleLeft(tree)
    }
    
    static rotateDoubleRight(tree) {
        tree.rightChild = Avl.rotateSingleLeft(tree.leftChild)
        return Avl.rotateSingleRight(tree)
    }
    
    insert(element) {
        if(this.root === null) {
            this.root  = new Node(element)
        } else {
            this._insert(element, this.root)
        }
    }
    
    _insert(element, tree) {
        log('tree', tree)
        if(tree === null) {
            tree = new Node(element)
            return tree
        }
        
        // 插入节点
        if(element < tree.element) {
            // 插入到左树
            tree.leftChild = this._insert(element, tree.leftChild)
            
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
            tree.right = this._insert(element, tree.rightChild)
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
    log() {
        log(this.root)
    }
}


if(require.main === module) {
    const avl = new Avl()
    avl.insert(5)
    avl.insert(4)
    avl.insert(3)
    avl.log()
}