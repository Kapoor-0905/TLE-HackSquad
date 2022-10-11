def arthmetic():
    print("Press 1 for addition")
    print("Press 2 for subtraction")
    print("Press 3 for Multiplication")
    print("Press 4 for divide")
    print("")
    print("")
    while(True):
        user= int(input("Choose an arthemetic operation \n "))
        if(user==1):
            a=int(input("Enter the first number "))
            b=int(input("Enter the Second number "))
            add=a+b
            print(add)
        elif(user==2):
            a=int(input("Enter the first number "))
            b=int(input("Enter the Second number "))
            sub=a-b
            print(sub)
        elif(user==3):
            a=int(input("Enter the first number "))
            b=int(input("Enter the Second number "))
            mul=a*b
            print(mul)
        elif(user==4):
            a=int(input("Enter the first number "))
            b=int(input("Enter the Second number "))
            div=a/b
            print(div)
        else:
            print("Bhai Dekh ke number daal😅, kya kar raha h, kaha dhyan h 😥 ")

arthmetic()
