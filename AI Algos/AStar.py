from queue import PriorityQueue

G = {
    'A': [('B', 6), ('F', 3)],
    'B': [('A', 6), ('C', 3), ('D', 2)],
    'C': [('B', 3), ('D', 1), ('E', 5)],
    'D': [('B', 2), ('C', 1), ('E', 8)],
    'E': [('C', 5), ('D', 8), ('I', 5), ('J', 5)],
    'F': [('A', 3), ('G', 1), ('H', 7)],
    'G': [('F', 1), ('I', 3)],
    'H': [('F', 7), ('I', 2)],
    'I': [('E', 5), ('G', 3), ('H', 2), ('J', 3)],
    'J': [('E', 5), ('I', 3)],
}

H = {
    'A': 10,
    'B': 8,
    'C': 5,
    'D': 7,
    'E': 3,
    'F': 6,
    'G': 5,
    'H': 3,
    'I': 1,
    'J': 0
}

S = 'A'

open = PriorityQueue()
close = []

open.put((0+H['A'], '-', S))

terminate = False
target = 'J'

while not terminate:
    if open.empty():
        terminate = True
    else:
        v = open.get()
        my_list = list(v)
        my_list[0] -= H[v[2]]
        v = tuple(my_list)
        close.append(v)

        if v[2] == target:
            print("Target Found ===", v[2])
            terminate = True
        else:
            for i in G[v[2]]:
                if i[0] not in [j[1] for j in close]:
                    open.put((v[0] + i[1] + H[i[0]], v[2], i[0]))

print("Cost: ", close[-1][0])
for i in range(len(close)):
    if (i == len(close) - 1):
        print(close[i][2])
    else:
        print(close[i][2], end=" --> ")
