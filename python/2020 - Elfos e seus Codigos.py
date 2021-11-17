cont = [1]
ini = 1


def mudmat(s):  # 13
    res = ""
    s = list(map(int, s))
    for h in range(len(s)):  # 13 1 10 8 5 4 18
        if(s[h] != 27):
            aux = mat[0][s[h]-1]  # 13 10 2
            mat[0].remove(aux)
            mat[0].append(aux)
            for i in range(26):
                if(i == (aux-1)):
                    kek = mat[1][i]
                    mat[1].remove(kek)
                    mat[1].append(kek)
                    res += kek
                    i = 26
        else:
            res += " "
    pala.append(res)


while(True):
    try:
        a = int(input())
        mat = []
        lin = []
        mat.append([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
                   15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26])
        for k in range(65, 91):
            lin.append(chr(k))
        mat.append(lin)
        pala = []
        for i in range(a):
            s = input()
            s = s.split(" ")
            mudmat(s)
        if(ini != 1):
            print("")
        print("LISTA #%d:" % cont[0])
        cont[0] += 1
        pala.sort()
        for j in pala:
            print(j)
        ini = 0
    except EOFError:
        break
