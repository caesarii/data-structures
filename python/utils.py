log = print

def formattedLog(content, n):
    for i in range(n):
        content = '___|' + str(content)
    log(content)

def heapLog(element, n):
    breakpoint = [2 ** i - 1 for i in range(30)]
    if element != None:
        log(element, end=' ')
        if n in breakpoint:
            log('\n')

def ensure(condition, message):
    if condition:
        log(message, 'succeed')
    else:
        log(message, 'failed')

def hash(key, length):
    hash = 0
    for char in key:
        hash += ord(char)

    return hash % length

def nextPrime(length):
    if length % 2 == 0:
        length += 1

    isPrime = True
    while True:
        length += 2
        i = 3
        while i * i <= length:
            if length % i == 0:
                isPrime = False
                break
            i += 2
        if isPrime:
            return length