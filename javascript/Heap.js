const {log, heapLog} = require('./utils')

class Heap {
    constructor(capacity) {
        this.elements = []
        this.capacity = capacity
        this.length = 0
    }
    
    insert(element) {
        if(this.length === 0) {
            // 插入第一个元素
            this.elements[1] = element
            this.length ++
        } else {
            this.length ++
            // 此处 index 的最小值是 2, 保证 parentIndex 最小值是 1
            let index = this.length
            let parentIndex = Math.floor(index / 2)
            let parent = this.elements[parentIndex]
            while (parent > element) {
                // 将 parent 元素下移
                this.elements[index] = parent
                // index 变成之前的 parent
                index = Math.floor(index / 2)
                parentIndex = Math.floor(index / 2)
                parent = this.elements[parentIndex]
            }
            // 插入元素
            this.elements[index] = element
        }
    }
    
    deleteMin() {
        let current = 1
        const min = this.elements[current]
        // 因为第一个元素忽略, 所以 length 是最后一个元素的索引
        const last = this.elements[this.length]
        // 删除最后一个元素
        this.elements[this.length] = undefined
    
        let child = current * 2
        while(child <= this.length) {
            // 使用子元素中的较小值
            if(child + 1 <= this.length && this.elements[child + 1] < this.elements[child]) {
                child += 1
            }
    
            if(this.elements[child] < last) {
                // 将子元素上浮
                this.elements[current] = this.elements[child]
                current = child
                child = current * 2
            } else {
                break
            }
        }
    
        // 插入 last
        log('last', last)
        this.elements[current] = last
        return min
    }
    
    isFull() {
        return this.capacity === this.length
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





















