const {log, formattedLog} = require('./utils')

class Node {
    constructor(element) {
        this.element = element
        this.leftChild = null
        this.rightChild = null
    }
}

class BinaryTree {
    constructor() {
        this.root = new Node('/')
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
    
    addNode(node) {
        // 元素列表
        let elements = node.split('/')
        elements.splice(0, 1)
        // log('elements', elements)
    
        // 当前层的父节点
        let parent = this.root
        for(let i = 0; i < elements.length; i++) {
            // log('parent', parent, i)
            // 当前元素
            const element = elements[i]
        
            // 当前节点
            let current = null
        
            // 当前父节点的两个子节点
            const siblings = [parent.leftChild, parent.rightChild]
            // log('siblings', siblings)
        
            // 在当前层查找当前元素
            const index = BinaryTree.find(element, siblings)
            if(index >= 0) {
            
                // 已有的节点
                current = siblings[index]
                // log('已有的节点', current)
            } else {
                // log('创建新节点', element)
                // 创建新节点
                current = new Node(element)
                // 要创建新节点说明父节点左右子节点都为 null 或者 右节点为 null
                if(parent.leftChild === null) {
                    parent.leftChild = current
                } else if(parent.rightChild === null) {
                    parent.rightChild = current
                } else {
                    log('不能创建新节点')
                }
            }
        
            parent = current
        }
        
    }
    
    removeNode(node) {
        // /animal/cat/tom
        // 元素列表
        let elements = node.split('/')
        elements.splice(0, 1)
        const target = elements[elements.length - 1]
        // log('elements', elements)
        log('target', target)
    
        // 当前层的父节点
        let parent = this.root
        for(let i = 0; i < elements.length; i++) {
            // log('parent', parent, i)
            // 当前元素
            const element = elements[i]
        
            // 当前节点
            let current = null
        
            // 获取当前节点的所有兄弟节点
            const siblings = [parent.leftChild, parent.rightChild]
            // log('siblings', siblings)
        
            // 在当前层查找当前元素
            const index = BinaryTree.find(element, siblings)
            if(index >= 0) {
                // 已有的节点
                current = siblings[index]
                // 当前节点是要删除的节点
                if(target === current.element) {
                    log('current', current)
                    // 删除目标节点的所有子节点
                    current.leftChild = null
                    current.rightChild = null
                    // 删除目标节点
                    if(index === 0) {
                        // 目标节点是 leftChild
                        parent.leftChild = parent.rightChild
                        parent.rightChild = null
                        
                    } else {
                        // 目标节点是 rightChild
                        parent.rightChild = null
                        
                    }
                    return
                }
            } else {
                log('要删除的节点不存在')
            }
            parent = current
        }
    
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
        this._preorderTraversal(this.root, 0)
    }
}


if(require.main === module) {
    const t = new BinaryTree()
    t.addNode('/animal/cat/tom')
    t.addNode('/animal/cat/blackcat')
    t.addNode('/animal/rat/jerry')
    t.addNode('/plant/flower/rose')
    t.removeNode('/animal/cat/tom')
    t.log()
}
