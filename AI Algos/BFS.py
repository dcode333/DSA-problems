
def BFS(start, G, target):
    open = []
    close = []
    open.append(('-', start))
    breaker = False
    while not breaker:

        v = open.pop(0)
        close.append(v)

        if v[1] == target:
            print("Target achieved: ", v[1])
            breaker = True
        else:
            for i in G[v[1]]:
                if i not in [x[1] for x in close]:
                    open.append((v[1], i))

        if len(open) == 0:
            breaker = True
    return [open, close]


Graph = {
    'A': ['B', 'C'],
    'B': ['A', 'F', 'D'],
    'C': ['A', 'D', 'E', 'G'],
    'F': ['B'],
    'D': ['B', 'C'],
    'E': ['C'],
    'G': ['C']
}

result = BFS("A", Graph, "F")
print("Open List:", result[0])
print("Close List:", result[1])
