const log = console.log

const formattedLog = function(content, n) {
    for(let i = 0; i < n; i++) {
        content = '___|' + content
    }
    log(content)
}


class Node {
    constructor(element) {
        this.element = element
        this.leftChild = null
        this.rightChild = null
    }
}

class BinaryTree {
    constructor(element) {
    
    }
    
    addChild() {
    
    }
    
    removeChild() {
    
    }
    
    log() {
        
    }
}
