const {log, ensure} = require('./utils')

class Node {
    constructor(element) {
        this.element = element
        this.next = null
        this.prev = null
    }
}

class DLList {
    constructor() {
        this.length = 0
        this.next = null
        this.tail = null
    }
    
    prepend(element) {
        const n = new Node(element)
        n.next = this.next
        
        if(this.next === null) {
            this.tail = n
        } else {
            this.next.prev = n
        }
        this.next = n
        
        this.length += 1
    }
    
    append(element) {
        const n = new Node(element)
        
        if(this.next == null) {
            this.next = n
        } else {
            this.tail.next = n
            n.prev = this.tail
        }
        
        this.tail = n
        this.length += 1
    }
    
    contains(element) {
        let contained = false
        let current = this.next
        while(current !== null) {
            if(current.element === element) {
                contained = true
                break
            }
            current = current.next
        }
        return contained
    }
    
    shift() {
        this.length -= 1
        const first = this.next
        let e
        if(first === null) {
            return -1
        } else {
            e = first.element
        }
        this.next = this.next.next
        this.next.prev = null
        return e
    }
    
    pop() {
        this.length -= 1
        const last = this.tail
        let e
        if(last === null) {
            return -1
        } else {
            e = last.element
        }
        this.tail.prev.next = null
        return e
    }
    
    insert(index, element) {
        if(index === 0) {
            this.prepend(element)
        }
        
        let i = 0
        let current = this.next
        while(current != null) {
            if(i === index - 1) {
                const n = new Node(element)
                n.next = current.next
                n.prev = current
                current.next = n
                return index
            }
            current = current.next
            i ++
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
    const list = new DLList()
    
    list.append(2)
    list.append(3)
    list.prepend(1)
    list.prepend(0)
    ensure(list.length === 4, 'test list length')
    list.log()
    
    ensure(list.contains(5) === false, 'test list contains 1')
    ensure(list.contains(3) === true, 'test list contains 2')
    
    list.insert(2, 2.5)
    list.log()
    
    list.shift()
    ensure(list.length === 3, 'test list shift 1')
    list.log()
    
    list.pop()
    list.log()
    
    
}