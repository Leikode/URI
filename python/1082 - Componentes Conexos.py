def dfs(G, node, visited):
    if node not in visited:
        visited.append(node)
        try:
            for neighbour in G[node]:
                dfs(G, neighbour, visited)
        except:
            pass


def createGraph(n):
    G = {}
    for i in range(n):
        b = input().split()

        if b[0] not in G:
            G[b[0]] = []
        if b[1] not in G:
            G[b[1]] = []

        G[b[0]].append(b[1])
        G[b[1]].append(b[0])
    return G


def printAnswer(components, alphabet, a):

    components = sorted([sorted(x) for x in components])

    aux = []

    try:
        aux = [alphabet[x] for x in range(0, max(list(map(lambda x: alphabet.index(x[-1]), components))))
               if alphabet[x] not in sum(components, [])]
    except:
        pass

    aux += [alphabet[x + len(aux) + len(sum(components, []))]
            for x in range(abs(len(aux) + len(sum(components, [])) - a))]

    l = 0

    ans = []

    for i in components:
        l += 1
        ans.append([])
        for j in i:
            ans[-1].append(j)

        if aux and alphabet.index(j) > alphabet.index(aux[0]):
            while alphabet.index(j) > alphabet.index(aux[0]):
                ans.append([])
                ans[-1].append(aux[0])
                aux.remove(aux[0])
                l += 1

                if not aux:
                    break

    for i in aux:
        ans.append([])
        ans[-1].append(i)

    l += len(aux)

    for i in sorted(ans):
        for j in i:
            print(j, end=",")
        print()

    print(f"{l} connected components")


alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
            'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

n = int(input())

k = 1

for i in range(n):
    a = input().split()
    G = createGraph(int(a[1]))

    visited = []
    components = []
    pos = 0

    for node in G:
        if node not in visited:
            dfs(G, node, visited)
            components.append(visited[pos:])
            pos += len(visited) - pos

    print(f"Case #{k}:")
    printAnswer(components, alphabet, int(a[0]))
    print()

    k += 1

# 12
