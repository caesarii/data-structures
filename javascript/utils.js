
const log = console.log

const formattedLog = function(content, n) {
    for(let i = 0; i < n; i++) {
        content = '___|' + content
    }
    log(content)
}

const half = n => {
    return Math.floor(n / 2)
}

const max = function(...args) {
    log(args)
    let max = args[0]
    for(let i = 1; i < args.length; i++) {
        if(args[i] > max) {
            max = args[i]
        }
    }
    
    return max
}

const heapLog = (element, n) => {
    let found = false
    
    for(let i = 0; i < 30; i++) {
        if(n === Math.pow(2, i) - 1) {
            found = true
        }
    }
    if(element) {
        log(element)
    }
    // log('n', n, found)
    if(found) {
        log('___')
    }
}

const exchange = (list, i, j) => {
    // 交换 list 中索引为 i, j的元素
    const temp = list[i]
    list[i] = list[j]
    list[j] = temp
}

const ensure = (condition, message) => {
    if(condition) {
        log(message, 'succeed')
    } else {
        log(message, 'failed')
    }
}

const hash = (key, length) => {
    let hash = 0
    for(let i = 0; i < key.length; i++) {
        hash += key.charCodeAt(i)
    }
    // while(key !== '\0') {
    //     hash += key++
    // }
    return hash % length
}

const nextPrime = (length) => {
    if(length % 2 === 0) {
        length += 1
    }
    
    let isPrime = true
    while(true) {
        length += 2
        for(let i = 3; i * i <= length; i += 2) {
            if(length % i === 0) {
                isPrime = false;
                break
            }
        }
        if(isPrime) {
            return length
        }
    }
}

module.exports =  {
    ensure,
    log,
    formattedLog,
    max,
    heapLog,
    half,
    exchange,
    hash,
    nextPrime
}