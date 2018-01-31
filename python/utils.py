log = print

def formattedLog(content, n):
    for i in range(n):
        content = '___|' + str(content)
    log(content)

