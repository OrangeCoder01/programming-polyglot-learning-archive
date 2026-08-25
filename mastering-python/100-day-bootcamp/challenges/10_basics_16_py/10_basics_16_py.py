# Day 16: Learning OOP Python 

import turtle
import prettytable

yassin = turtle.Turtle()
yassin.shape("turtle")
my_screen = turtle.Screen()

#challenge {1} color the turtle
yassin.color("green")

#challenge {2} move the turtle by 100 paces
yassin.forward(100)
print(my_screen.canvheight)
my_screen.exitonclick()

# challenge {3} create PrettyTable object and call it "table"
table = prettytable.PrettyTable()

# Challenge {4} adding a list
table.add_column("Pokemon Name", ["Pikachu", "Squirtle", "Charmander"])
table.add_column("Type", ["Electric", "Water", "Fire"])
print(table)

# Challenge {5} Changing shape
table.align = "l"
print(table)