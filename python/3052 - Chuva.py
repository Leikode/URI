import sys


def chuva(mtx, i, j):
    mtx[i][j] = 'o'

    if i + 1 < len(mtx) and mtx[i + 1][j] == '.':
        chuva(mtx, i + 1, j)
    elif i + 1 < len(mtx) and mtx[i + 1][j] == '#':
        if j - 1 != -1 and mtx[i][j - 1] != 'o':
            chuva(mtx, i, j - 1)
        if j + 1 < len(mtx[0]) and mtx[i][j + 1] != 'o':
            chuva(mtx, i, j + 1)

    return mtx


n, m = [int(x) for x in input().split()]

mtx = []
for i in range(n):
    a = input()
    mtx.append(list(a))

i = 0
j = [x for x in range(len(mtx[0])) if mtx[0][x] == 'o'][0]

sys.setrecursionlimit(5000)
chuva(mtx, i, j)

for i in mtx:
    aux = ''
    for j in i:
        aux += j
    print(aux)
