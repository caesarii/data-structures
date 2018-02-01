
const {log, formattedLog} = require('./utils')

class Node {
    constructor(element) {
        this.element = element
        this.next = null
    }
}

class List {
    constructor() {
        // 头结点
        this.next = null
        // 尾节点
        this.tail = null
        
        this.length = 0
    }
    
    prepend(element) {
        // 添加元素
        const node = new Node(element)
        // 将新节点链接到之前的头结点
        node.next = this.next
        // 更新头结点
        this.next = node
        
        this.length ++
        return this.length
    }
    
    append(element) {
        // 追加元素
        const node = new Node(element)
        if(this.length === 0) {
            // 指定头结点
            this.next = node
        } else {
            // 将新节点连接到之前的尾节点
            this.tail.next = node
        }
        
        // 更新尾节点
        this.tail = node
        
        this.length ++
        return this.length
    }
    
    shift() {
        // 删除头部元素
        let e
        if(this.length === 0) {
            return -1
        } else {
            e = this.next.element
            this.next = this.next.next
        }
        this.length --
        return e
    }
    
    unshift() {
        // 删除尾部元素
        // 使用双向链表
    }
    
    contains(target) {
        let current = this.next
        while(current !== null) {
            if(current.element === target) {
                return true
            }
            current = current.next
        }
        return false
    }
    
    indexOf(target) {
        let index = 0
        let current = this.next
        while(current !== null) {
            if(current.element === target) {
                return index
            }
            current = current.next
            index++
        }
        return -1
    }
    
    elementAt(index) {
        let i = 0;
        let current = this.next
        while(current !== null) {
            if(i === index) {
                return current.element
            }
            current = current.next
            i++
        }
        return null
    }
    
    insert(index, element) {
        // 在指定索引后插入元素
        let i = 0
        let current = this.next
        while(current !== null) {
            if(i === index) {
                const n = new Node(element)
                n.next = current.next
                current.next = n
                return index + 1
            }
            current = current.next
            i++
        }
        return -1
    }
    
    change(index, element) {
        // 改变指定索引处的元素的值
        let i = 0
        let current = this.next
        while(current !== null) {
            if(i === index) {
                current.element = element
                return index
            }
            current = current.next
            i++
        }
        return -1
    }
    
    clear() {
        while(this.next !== null) {
            this.shift()
        }
    }
    
    log() {
        let current = this.next
        while(current !== null) {
            log(current.element)
            current = current.next
        }
    }
}

if(require.main = module) {
    const list = new List()
    
    list.append(2)
    list.append(3)
    list.prepend(1)
    list.prepend(0)
    // list.shift()
    const contained = list.contains(5)
    log(contained)
    
    const i = list.indexOf(3)
    log('i', i)
    
    const e = list.elementAt(2)
    log('e', e)
    
    list.insert(2, 2.5)
    list.insert(4, 4)
    
    list.change(4, 5)
    
    list.clear()
    
    list.log()
}