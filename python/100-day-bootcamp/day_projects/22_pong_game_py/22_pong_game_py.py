import turtle
from screen_manipulator_py import ScreenManipulator
my_screen = turtle.Screen()
writting_turtle = ScreenManipulator()
writting_turtle.writing(text= "Hello World", position_x_y_cor_tuble= (-20, 280))

writting_turtle.color("red")
writting_turtle.goto(90,-90)

my_screen.exitonclick()
