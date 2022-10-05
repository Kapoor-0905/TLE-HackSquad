import random

def spc(u, c):
    if u == 'stone':
        if c == 'paper':
            return -1
        elif c == 'scissors':
            return 1
        else:
            return 0
    elif u == 'paper':
        if c == 'stone':
            return 1
        elif c == 'scissors':
            return -1
        else:
            return 0
    else:
        if c == 'paper':
            return -1
        elif c == 'stone':
            return 1
        else:
            return 0

user = input()
#user = tolower(user)
l = ['stone', 'paper', 'scissors']
index = random.randint(0, 2)
comp = l[index]
print('Computer plays ', comp)
n = spc(user, comp)
if n == 1:
    print('User Won')
elif n == -1:
    print('User Lost')
else:
    print('It\'s a Tie')
