const log = console.log

const formattedLog = function(content, n) {
    for(let i = 0; i < n; i++) {
        content = '___|' + content
    }
    log(content)
}


class Node {
    constructor(element) {
        this.element = element
        this.leftChild = null
        this.rightChild = null
    }
}

class BinarySearchTree {
    constructor() {
        this.root = null
    }
    
    static find(element, nodeList) {
        // 在结点列表中查找指定元素的 index, 找不到返回 -1
        
        for(let i = 0; i < nodeList.length; i++) {
            const node = nodeList[i]
            if(node && node.element === element) {
                return i
            }
        }
        return -1
    }
    
    insert(element) {
        this.root = this._insertIterative(element, this.root)
    }
    
    _insertIterative(element, tree) {
        if(tree === null) {
            // 空树
            tree = new Node(element)
            log('空树', tree)
        } else {
            if(element < tree.element) {
                // 添加到左树
                tree.leftChild = this._insertIterative(element, tree.leftChild)
            } else if(element > tree.element) {
                // 添加到右树
                tree.rightChild = this._insertIterative(element, tree.rightChild)
            } else {
                log('elemetn is in the tree already')
            }
        }
        return tree
    }
    
    removeChild(child){
    
    }
    
    find
    
    
    _clearIterative(tree) {
        if(tree !== null) {
            this._clearIterative(tree.leftChild)
            this._clearIterative(tree.rightChild)
            tree.element = null
            tree.leftChild = null
            tree.rightChild = null
        
        } else {
            return
        }
    }
    
    clear(tree = this.root) {
        let tree = this.root
        this._clearIterative(tree)
    }
    
    _preorderTraversal(tree, n) {
        // preorder traversal
        if(tree !== null) {
            formattedLog(tree.element, n)
            this._preorderTraversal(tree.leftChild, n + 1)
            this._preorderTraversal(tree.rightChild, n + 1)
        } else {
            return
        }
    }
    
    log() {
        log(this.root)
        this._preorderTraversal(this.root, 0)
    }
}


if(require.main === module) {
    const t = new BinarySearchTree()
    t.insert(6)
    t.insert(2)
    t.insert(8)
    t.insert(1)
    t.insert(4)
    t.insert(3)
    t.insert(5)
    t.clear()
    t.log()
    
}