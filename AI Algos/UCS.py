from queue import PriorityQueue


def UCS(start, G, target):
    open = PriorityQueue()
    close = []
    open.put((0, '-', start))
    breaker = False

    while not breaker:
        v = open.get()
        close.append(v)

        if v[2] == target:
            print("Target Found ===", v[2])
            breaker = True
        else:
            for i in G[v[2]]:
                if i[0] not in [j[1] for j in close]:
                    open.put((v[0] + i[1], v[2], i[0]))
                if open.empty():
                    breaker = True
    return close


Graph = {
    'A': [('B', 8), ('C', 2)],
    'B': [('A', 8), ('D', 2)],
    'C': [('A', 2), ('E', 5), ('G', 20)],
    'D': [('B', 2), ('E', 5), ('F', 8)],
    'E': [('D', 5), ('C', 5), ('G', 14)],
    'G': [('C', 20), ('E', 14)],
    'F': [('D', 8)],
}

cost = UCS("A", Graph, "D")[-1][0]
print("Cost: ", cost)


