rec3 = 0
rec4 = 0


def hanoi3num(n, origem, destino, trabalho):
    global rec3

    rec3 += 1
    if n == 1:
        return rec3
    hanoi3num(n-1, origem, trabalho, destino)
    hanoi3num(n-1, trabalho, destino, origem)
    return rec3


def hanoi4num(n, origem, destino, trabalho1, trabalho2):
    global rec4

    if n == 0:
        return rec4
    if n == 1:
        rec4 += 1
        return rec4
    hanoi4num(n-2, origem, trabalho1, trabalho2, destino)
    rec4 += 3
    hanoi4num(n-2, trabalho1, destino, origem, trabalho2)
    return rec4


def gera_matriz(dim_colunas):
    global rec3
    global rec4
    matriz = []
    linha1 = []
    linha2 = []
    for c in range(1, dim_colunas):
        linha1.append('%d' % c)
    for c in range(1, dim_colunas):
        rec3 = 0
        rec4 = 0
        qtd_rec3 = hanoi3num(c, 'A', 'C', 'B')
        qtd_rec4 = hanoi4num(c, 'A', 'D', 'B', 'C')
        dif = qtd_rec3 - qtd_rec4
        linha2.append('%d' % dif)
    matriz.append(linha1)
    matriz.append(linha2)
    return matriz


def escreve_matriz(matriz, n):
    for x in range(2):
        for y in range(n-1):
            print(matriz[x][y], end=" ")
        print()


discos = int(input())


saida = gera_matriz(discos+1)
escreve_matriz(saida, discos+1)
