
const {log, ensure} = require('./utils')
const List = require('./List')

class Queue extends List {
    constructor() {
        super()
    }
    
    enqueue(element) {
        this.append(element)
    }
    
    dequeue() {
        return this.shift()
    }
    
    isEmpty() {
        return this.length === 0
    }
    
    clear() {
        while(!this.isEmpty()) {
            this.dequeue()
        }
    }
}

if(require.main === module) {
    const s = new Queue()
    
    s.enqueue(0)
    s.enqueue(1)
    s.enqueue(2)
    s.dequeue()
    s.log()
    s.clear()
    s.log()
    log(s.isEmpty())
}