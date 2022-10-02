from turtle import *
import turtle as tur

ws = tur.Turtle()
 
color= ['yellow','orange','blue','cyan','green'] #each side of star with respective colors
 
tur.pensize(4)
tur.penup()
tur.setpos(-90,30)
tur.pendown()
for i in range(5):
    tur.pencolor(color[i])
    tur.forward(200)
    tur.right(144)
 
tur.penup()
tur.setpos(80,-140)
tur.pendown()
 
tur.pencolor("Black")
tur.done()
