
const log = console.log

const formattedLog = function(content, n) {
    for(let i = 0; i < n; i++) {
        content = '___|' + content
    }
    log(content)
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
    log(element)
    // log('n', n, found)
    if(found) {
        log('___')
    }
}

module.exports =  {
    log,
    formattedLog,
    max,
    heapLog,
}