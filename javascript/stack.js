
const {log, ensure} = require('./utils')
const List = require('./List')

class Stack extends List {
    constructor() {
        super()
    }
    
    push(element) {
        this.prepend(element)
    }
    
    pop() {
        return this.shift()
    }
    
    isEmpty() {
        return this.length === 0
    }
    
    clear() {
        while(!this.isEmpty()) {
            this.pop()
        }
    }
}

if(require.main === module) {
    const s = new Stack()
    
    s.push(0)
    s.push(1)
    s.push(2)
    s.pop()
    s.log()
    s.clear()
    s.log()
    log(s.isEmpty())
}