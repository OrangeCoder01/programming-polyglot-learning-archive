import turtle
timmy_the_turtle = turtle.Turtle()
timmy_the_turtle.shape("turtle")
timmy_the_turtle.speed(10)

my_screen = turtle.Screen()

def forward():
    timmy_the_turtle.forward(10)

def go_left():
    new_angle = timmy_the_turtle.heading() + 10
    timmy_the_turtle.setheading(new_angle)
    
def go_right():
    new_angle = timmy_the_turtle.heading() - 10
    timmy_the_turtle.setheading(new_angle)
    
def backward():
    timmy_the_turtle.back(10)
    
def clear():
    timmy_the_turtle.clear()
    timmy_the_turtle.penup()
    timmy_the_turtle.home()
    timmy_the_turtle.pendown()
    
# Controls:
# W -- Forwards
# S -- Backwards
# A -- Counter-Clockwise
# D -- Clockwise
# C -- Clear drawing
# k -- exit_program

my_screen.onkeypress(forward, "w")
my_screen.onkeypress(go_left, "a")
my_screen.onkeypress(go_right, "d")
my_screen.onkeypress(backward, "s")
my_screen.onkeypress(clear, "c")

my_screen.onkeypress(timmy_the_turtle.undo, "u")
my_screen.onkeypress(timmy_the_turtle.pendown, "Down")
my_screen.onkeypress(timmy_the_turtle.penup, "Up")

my_screen.listen()
my_screen.mainloop()

