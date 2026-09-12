import turtle, random

body_segments = []
body_segments_postions = []
    

def segmenting_new_snake_body():
    global body_segments
    
    segment = turtle.Turtle()
    segment.shape("square")
    segment.color("white")
    segment.shapesize(1, 1, 1)
    segment.speed(0)
    segment.penup()
    
    if body_segments:
        x, y = body_segments[-1].position()
        segment.setposition(x, y)
    
    body_segments.append(segment)
    return segment




head_snake = segmenting_new_snake_body()





def serpentine_whole_segment_alignment():
    global body_segments_postions
    body_segments_postions = []
    
    for i in range(len(body_segments) - 1, 0, -1):
        body_segments[i].goto(body_segments[i - 1].position())
        body_segments_postions.append(body_segments[i].pos())
        
    head_snake.forward(20)





my_screen = turtle.Screen()
my_screen.bgcolor("black")
my_screen.setup(width= 600, height= 600)
my_screen.title("Snake Game")


hidden_turtle = turtle.Turtle()
hidden_turtle.speed(0)
hidden_turtle.shape("square")
hidden_turtle.color("black")
hidden_turtle.pencolor("white")



boundary_turtle = turtle.Turtle()
boundary_turtle.speed(0)
boundary_turtle.shape("square")
boundary_turtle.color("black")
boundary_turtle.pencolor("white")
boundary_turtle.penup()




def game_boundary():
    boundary_turtle.penup()
    boundary_turtle.goto(-300, -300)
    boundary_turtle.pendown()
    boundary_turtle.pencolor("white")

    for _ in range(4):
        boundary_turtle.forward(600)
        boundary_turtle.left(90)
        
    boundary_turtle.penup()
            
    
    


apple_turtle = turtle.Turtle()
apple_turtle.shape("square")
apple_turtle.color("red")
apple_turtle.shapesize(0.2, 0.2, 0.2)
apple_turtle.penup()






def write(text, x, y, size, color):
    hidden_turtle.penup()
    hidden_turtle.goto(x, y)
    hidden_turtle.pencolor(f"{color}")
    hidden_turtle.write(f"{text}", font= ("Times New Roman", size, "normal"))
    hidden_turtle.goto(1000, 1000)

def go_left():
    new_angle = head_snake.heading() + 90
    head_snake.setheading(new_angle)
    
def go_right():
    new_angle = head_snake.heading() - 90
    head_snake.setheading(new_angle)

def generate_apple():
    x = random.randint(-290, 290)
    y = random.randint(-290, 290)
    apple_turtle.setposition(x, y)
    




my_screen.onkeypress(go_left, 'a')
my_screen.onkeypress(go_right, 'd')
my_screen.listen()

write("Score: 0", -20, 280, 15, "white")
score = 0

generate_apple()





def game_loop():
    global score
    
    serpentine_whole_segment_alignment()
    x_s, y_s = head_snake.pos()
    x_a, y_a = apple_turtle.pos()   
    
    diff_x = abs(x_a - x_s) 
    diff_y = abs(y_a - y_s) 

    if( diff_x < 10 and diff_y < 10 ):
        generate_apple()
        segmenting_new_snake_body()
        score += 1
        hidden_turtle.clear()
        write(f"Score: {score}", -20, 280, 15, "white")
        
    if((abs(x_s) >= 290 or abs(y_s) >= 290) or ((x_s, y_s) in body_segments_postions)):
        write("Game Over!", -20, 0, 15, "red")
        return 0
    my_screen.ontimer(game_loop, 100)
    
    
game_boundary()
boundary_turtle.goto(-1000, -1000)

game_loop()
my_screen.exitonclick()
my_screen.mainloop()


