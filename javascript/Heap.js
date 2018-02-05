const {log, heapLog} = require('./utils')

class Heap {
    constructor(capacity) {
        this.elements = []
        this.capacity = capacity
        this.length = 0
    }
    
    insert(element) {
        if(this.length === 0) {
            this.elements[1] = element
            this.length += 1
            return
        }
        
        this.length ++
        let index = this.length
        while (true) {
            const parentIndex = Math.floor(index / 2)
            const parent = this.elements[parentIndex]
            if(parent && parent > element) {
                this.elements[index] = parent
                index = Math.floor(index / 2)
            } else {
                this.elements[index] = element
                return
            }
        }
    }
    
    deleteMin() {
        let current = 1
        const min = this.elements[current]
        const last = this.elements[this.length]
        this.elements[this.length] = undefined
        
        this.length -= 1
        
        while(true) {
            let child = current * 2
            if(child <= this.length) {
                if(child + 1 <= this.length && this.elements[child + 1] < this.elements[child]) {
                    child += 1
                }
                if(this.elements[child] < last) {
                    this.elements[current] = this.elements[child]
                    current = child
                } else {
                    break
                }
            } else {
                break
            }
        }
        
        this.elements[current] = last
        return min
    }
    
    log() {
        this.elements.forEach((e, i) => {
            heapLog(e, i)
        })
    }
}


if(require.main === module) {
    const heap = new Heap(100)
    heap.insert(13)
    heap.insert(14)
    heap.insert(16)
    heap.insert(19)
    heap.insert(21)
    heap.insert(19)
    heap.insert(68)
    
    heap.insert(65)
    heap.insert(26)
    
    
    heap.insert(32)
    
    heap.insert(31)
    
    heap.log()
    
    heap.deleteMin()

    heap.log()
    
}





















