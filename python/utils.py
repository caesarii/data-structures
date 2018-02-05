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

