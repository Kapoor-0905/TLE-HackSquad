t = int(input())
for i in range(0,t):
    x = int(input())
    disnt = 100
    dis = x - disnt
    cop = (x*10)/100
    coup = x - cop
    if(dis > coup):
        print(int(cop))
    elif(coup > dis):
        print(int(disnt))
    else:
        print(int(disnt))
