import turtle, random

def check_integer(user_input):
    while True:
        try:
            return int(user_input)
        except ValueError:
            user_input = input(f"Input {user_input} is not a number, enter again: ")
    
    
def amount_validator(user_input):
    user_input = check_integer(user_input)
    
    while user_input not in range(2, 10):
        user_input = input(f"Input: {user_input} should be between (2 ~ 9), enter again: ")
        user_input = check_integer(user_input)
            
    return user_input




turtle_colors = ["black", "gray", "red", "orange", "yellow", "green", "blue", "purple", "pink", "brown", "cyan", "gold", "indigo", "violet"]

def random_color():
    color = random.choice(turtle_colors)
    turtle_colors.remove(color)
    return color
    
    

def draw_race_ground():
    referee_turtle = turtle.Turtle()
    referee_turtle.speed(1)
    referee_turtle.shape("turtle")
    referee_turtle.penup()
    referee_turtle.goto(350, -200)
    
    referee_turtle.setheading(90)
    referee_turtle.pendown()
    referee_turtle.pensize(10)
    
    referee_turtle.forward(400)
    referee_turtle.penup()
    
    referee_turtle.setposition(350, 240)
    referee_turtle.setheading(270)
    



def turtle_speed_varying(random_turtle):
    random_turtle.speed(random.randint(0, 10))


print("Welcome to turtle race:")
turtle_num = amount_validator(input("Please, enter the number of participant turtles in the race: "))

turtles_participants = []
y = -200
spacing = 400/ (turtle_num + 1)


for i in range(turtle_num):
    new_participant = turtle.Turtle()
    
    new_participant.shape("turtle")
    new_participant.color(random_color())
    new_participant.penup()
    
    current_y = y + (spacing * (i + 1))
    new_participant.goto(-350, current_y)
        
    turtles_participants.append(new_participant)

first_place_pos_x = -350

my_screen = turtle.Screen()
draw_race_ground()

while first_place_pos_x <= 350:
    for racing_turtle in turtles_participants:
        racing_turtle.forward(random.randint(1, 20))
        turtle_speed_varying(racing_turtle)
        x, _ = racing_turtle.position()
        if x >= first_place_pos_x:
            first_place_pos_x = x



for racing_turtle in turtles_participants:
    x, _ = racing_turtle.position()
    if x > 350:
        winning_turtle_color, _ = racing_turtle.color()
        print(f"The {winning_turtle_color} Turtle won! ")
        break


my_screen.exitonclick()
my_screen.mainloop()
