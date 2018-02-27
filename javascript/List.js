
const {log, ensure, formattedLog} = require('./utils')

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
        // 在指定索引插入元素
        let i = 0
        let current = this.next
        while(current !== null) {
            if(i === index - 1) {
                const n = new Node(element)
                n.next = current.next
                current.next = n
                return index
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
        while(this.length !== 0) {
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
    ensure(list.length === 4, 'test list length')
    list.log()
    
    ensure(list.contains(5) === false, 'test list contains 1')
    ensure(list.contains(3) === true, 'test list contains 2')
    
    
    const i = list.indexOf(3)
    ensure(i === 3, 'test list indexOf')
    
    const e = list.elementAt(2)
    ensure(e === 2, 'test list elementAt')
    
    list.insert(2, 2.5)
    ensure(list.indexOf(2.5) === 2, 'test list insert')
    
    list.change(4, 5)
    ensure(list.indexOf(5) === 4, 'test list change')
    
    list.shift()
    ensure(list.length === 3, 'test list shift 1')
    ensure(list.elementAt(0) === 1, 'test list shift 2')
    
    list.clear()
    ensure(list.length === 0, 'test list clear')
    
}