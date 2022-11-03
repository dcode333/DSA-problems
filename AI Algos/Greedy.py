from queue import PriorityQueue


def greedy(graph, hn, start, target):
    open = PriorityQueue()
    close = set()
    open.put(('/', start, hn[start]))
    popper = ()
    while True:
        popper = open.get()
        close.add(popper)
        if popper[1] == target:
            print("Target found", popper[1])
            break
        for i in graph[popper[1]]:
            open.put((popper[1], i, hn[i]))
    while popper[0] != '/':
        for i in close:
            if popper[0] == i[1]:
                print(popper[1], end='<-')
                popper = i
                break
    print(popper[1])


graph = {
    'A': ['B', 'C'],
    'B': ['D'],
    'C': ['E'],
    'D': ['E'],
    'E': ['G'],
}

hn = {
    'A': 20,
    'B': 15,
    'C': 20,
    'D': 3,
    'E': 5,
    'G': 0,
}

greedy(graph, hn, "A", "G")
