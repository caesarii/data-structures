
const log = console.log

const formattedLog = function(content, n) {
    for(let i = 0; i < n; i++) {
        content = '___|' + content
    }
    log(content)
}


export {
    log,
    formattedLog
}