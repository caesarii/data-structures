
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

module.exports =  {
    ensure,
    log,
    formattedLog,
    max,
    heapLog,
    half,
    exchange,
}