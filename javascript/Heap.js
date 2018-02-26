const {log, heapLog, half, exchange} = require('./utils')

class Heap {
    constructor(capacity) {
        this.elements = []
        this.capacity = capacity
        this.length = 0
    }
    
    insert(element) {
        // 插入元素
        const list = this.elements
        this.length ++
        this.elements[this.length] = element
    
        // 恢复堆序性质
        let current = this.length
        let parent = half(current)
        // TODO 插入第一个元素时 parent = 0, list[parent] = undefined, 这是个隐患
        log('parnet', parent, list[parent])
        // 上滤
        while (list[parent] > element) {
            // 交换当前元素与父元素，当前元素上浮，父元素下沉
            exchange(list, parent, current)
            
            current = half(current)
            parent = half(current)
        }
    }
    
    deleteMin() {
        let current = 1
        const list = this.elements
        const min = list[current]
        const last = list[this.length]
        // 交换最后一个元素与 min
        exchange(list, current, this.length)
        // 删除 min
        list[this.length] = undefined
        this.length --
        
        // 恢复堆序性质
        let child = current * 2
        while(child <= this.length) {
            // 使用子元素中的较小值
            if(child + 1 <= this.length && list[child + 1] < list[child]) {
                child += 1
            }
            // 下滤
            if(list[child] < last) {
                // 将子元素与当前元素交换，当前元素下沉，子元素上浮
                exchange(list, child, current)
                current = child
                child = current * 2
            } else {
                break
            }
        }
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





















