import turtle
import time

turtleScreen = turtle.Screen()
turtleScreen.bgcolor("white")
turtleScreen.title("Euler's Spirals")

pen = turtle.Turtle()
pen.color("Green")

pen.speed(10)
def draw(degree):
    for x in range(1, 720):
        '''if x == 1:
            pen.up()
            pen.goto(-400, -350)
            pen.down()'''
        pen.left(degree * x)
        pen.forward(17)


degree = 6.969
draw(degree)
time.sleep(5)