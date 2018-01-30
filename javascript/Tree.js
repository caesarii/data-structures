const log = console.log

// 在结点列表中查找指定元素的 index, 找不到返回 -1
function find(element, nodeList) {
    for(let i = 0; i < nodeList.length; i++) {
        const node = nodeList[i]
        if(node.element === element) {
            return i
        }
    }
    return -1
}

class Node {
    constructor(element) {
        this.element = element
        this.firstChild = null
        this.nextSibling = null
    }
}

class Tree {
    constructor() {
        this.root = new Node('/')
    }
    
    children(node) {
        const siblings = []
        
        const first = node.firstChild
        // log('first', first)
        if(first !== null) {
            // 该节点至少有一个子节点
            siblings.push(first)
            // 下一个兄弟节点
            let next = first.nextSibling
            while(next !== null) {
                siblings.push(next)
                next = next.nextSibling
            }
        }
        
        
        
        return siblings
    }
    
    addChild(child) {
        // child 描述了要添加的子节点从根节点开始完整的路径的字符串
        // 根节点用 / 表示
        // /animal/cat/tom
        
        // 元素列表
        let elements = child.split('/')
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
            
            // 获取当前节点的所有兄弟节点
            const siblings = this.children(parent)
            log('siblings', siblings)
            
            // 在当前层查找当前元素
            const index = find(element, siblings)
            if(index >= 0) {
                
                // 已有的节点
                current = siblings[index]
                log('已有的节点', current)
            } else {
                log('创建新节点', element)
                // 创建新节点
                current = new Node(element)
                // 挂载
                if(siblings.length === 0) {
                    // 挂载为父节点的第一个子节点
                    parent.firstChild = current
                    log('挂载 parent.first', parent)
                } else {
                    // 挂载到最后一个兄弟节点后面
                    siblings[siblings.length - 1].nextSibling = current
                    log('挂载 siblings.next', )
                }
            }
            
            parent = current
        }
        
        
    }
    removeChild() {
    
    }
    log() {
        log(this.root.firstChild.firstChild)
        
        // .firstChild.firstChild.firstChild
    }
}


if(require.main === module) {
    const t = new Tree()
    t.addChild('/animal/cat/tom')
    t.addChild('/animal/rat/jerry')
    t.log()
}

