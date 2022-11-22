from queue import PriorityQueue


def A_Star(start, G, hn, target):
    open = PriorityQueue()
    close = []
    open.put((0, '-', start))
    breaker = False

    while not breaker:
        popper = open.get()
        close.append(popper)

        if popper[2] == target:
            print("Target Found ===", popper[2])
            breaker = True
        else:
            for i in G[popper[2]]:
                if i[0] not in [j[1] for j in close]:
                    open.put((popper[0] + i[1]+hn[i[0]], popper[2], i[0]))
                if open.empty():
                    breaker = True
    popper = close[-1]
    cost = close[-1][0]
    while popper[1] != '-':
        for i in close:
            if popper[1] == i[2]:
                cost -= hn[i[2]]
                popper = i
                break
    return cost


Graph = {
    'A': [('B', 8), ('C', 2)],
    'B': [('A', 8), ('D', 2)],
    'C': [('A', 2), ('E', 5), ('G', 20)],
    'D': [('B', 2), ('E', 5), ('F', 8)],
    'E': [('D', 5), ('C', 5), ('G', 14)],
    'G': [('C', 20), ('E', 14)],
    'F': [('D', 8)],
}

hn = {
    'A': 20,
    'B': 15,
    'C': 20,
    'D': 10,
    'E': 5,
    'F': 3,
    'G': 0,
}
cost = A_Star("A", Graph, hn, "D")
print("Cost: ", cost)
