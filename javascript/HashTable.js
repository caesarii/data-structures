
const {log, ensure, hash, nextPrime} = require('./utils')
const List = require('./List')

class HashTable {
    constructor(length) {
        this.length = nextPrime(length)
        this.array = []
        for(let i = 0; i < this.length; i++) {
            this.array[i] = new List()
        }
    }
    
    set(key, value) {
        const index = hash(key, this.length)
        const list = this.array[index]
        list.append(value)
    }
    
    get(key) {
        const index = hash(key, this.length)
        const list = this.array[index]
        return list.elementAt(0)
    }
    
    has(key) {
        const index = hash(key, this.length)
        const list = this.array[index]
        return list.length !== 0
    }
    
    clear() {
        const len = this.length
        for(let i = 0; i < len; i++) {
            const list = this.array[i]
            list.clear()
        }
    }
}

if(require.main === module) {
    const h = new HashTable(100)
    h.set('name', 'qinghe')
    h.set('age', 14)
    log(h.get('age'))
    log(h.get('name'))
    log(h.has('name'))
}