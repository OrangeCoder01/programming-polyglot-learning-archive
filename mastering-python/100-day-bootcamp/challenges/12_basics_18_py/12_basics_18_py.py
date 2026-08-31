import turtle
from random import randint

my_screen = turtle.Screen()
timmy_the_turtle = turtle.Turtle()

timmy_the_turtle.shape("turtle")
timmy_the_turtle.color("orange")


turtle.colormode(255)

# Challenge {2}: Make a dotted line
def dashed_line(distance):
    timmy_the_turtle.speed(0)
    pace = 5
    for _ in range(int(distance//(pace*2))):   
        timmy_the_turtle.pencolor("black")
        timmy_the_turtle.forward(pace)
        
        timmy_the_turtle.pencolor("white")
        timmy_the_turtle.forward(pace)
    

# Challenge {1}: Make a square rotation
def square_mov():
    for _ in range(4):
        timmy_the_turtle.right(90)
        dashed_line(100) 
        # timmy_the_turtle.forward(100)


# Challenge {3}: Make different polygon shapes with different colors:
def calculate_exterior_angle(n_sides):
    return 360 / n_sides
    
def draw_polygons(n_polygons):
    timmy_the_turtle.penup()
    timmy_the_turtle.goto(0, -300)
    timmy_the_turtle.pendown()
    
    for sides in range(3, n_polygons + 3):
        exterior_angle = calculate_exterior_angle(sides)
        
        r = randint(0, 255)
        g = randint(0, 255)
        b = randint(0, 255)    
           
        timmy_the_turtle.pencolor((r, g, b))
        
        for _ in range(sides):
            timmy_the_turtle.forward(150)
            timmy_the_turtle.left(exterior_angle)
            
           
# Challenge {4}: Random walk 
LIMIT_X = 350
LIMIT_Y = 300

def random_color():
    r = randint(0, 255)
    g = randint(0, 255)
    b = randint(0, 255)  
    return (r, g, b)
        
def random_step():
    timmy_the_turtle.speed(0)
    timmy_the_turtle.forward(randint(50, 80))
    x, y = timmy_the_turtle.position()
    
    if abs(x) > LIMIT_X or abs(y) > LIMIT_Y:
        timmy_the_turtle.undo() # Rollback movement if out of bounds
        
    
def random_direction():
    match randint(0, 3):
        case 0:
            timmy_the_turtle.left(90)
        case 1:
            timmy_the_turtle.right(90)
        case 2:
            timmy_the_turtle.left(180)
        case 3:
            timmy_the_turtle.right(180)
    random_step()
            
def random_walk():
    timmy_the_turtle.speed(0)
    
    timmy_the_turtle.penup()
    timmy_the_turtle.goto(0, 0) 
    timmy_the_turtle.pendown()
    timmy_the_turtle.pensize(15) 
    

    while True:
        timmy_the_turtle.color(random_color())      
        random_direction()

# Challenge {5}: Spirograph
def make_spirograph(n_circles):
    timmy_the_turtle.speed(0)
    angle = 360 / n_circles
    
    for _ in range(n_circles):    
        timmy_the_turtle.color(random_color())    
        timmy_the_turtle.left(angle)
        timmy_the_turtle.circle(100)
    


square_mov()
my_screen.update()
my_screen.reset()

draw_polygons(10)
my_screen.update()
my_screen.reset()

make_spirograph(100)
my_screen.update()
my_screen.reset()

random_walk()
my_screen.update()
my_screen.reset()

my_screen.exitonclick()                
                
