import turtle
import colorsys

pen = turtle.Turtle()
screen = turtle.Screen()
screen.bgcolor('black')
pen.speed(10)

n = 36
h = 0

for x in range(360):
    pen.color(colorsys.hsv_to_rgb(h, 1, 0.9))
    h += 1/n
    pen.left(145)
    for y in range(5):
        pen.forward(300)
        pen.left(150)
