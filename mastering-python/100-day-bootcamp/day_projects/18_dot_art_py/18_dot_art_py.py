import random, turtle, colorgram, os
from PIL import Image

script_dir = os.path.dirname(os.path.abspath(__file__))
img = Image.open(os.path.join(script_dir, "damien_hirst_dot_painting.jpg"))# It is a way to find the image (works for windows, but not sure for other operating systems)

turtle.colormode(255)

colors = colorgram.extract(img, 30)
rgb_color = [(c.rgb.r, c.rgb.g, c.rgb.b) for c in colors]


my_screen = turtle.Screen()
timmy_the_artist_turtle = turtle.Turtle()
timmy_the_artist_turtle.shape("turtle")
timmy_the_artist_turtle.pensize(15)
timmy_the_artist_turtle.speed(0)



def random_color():
    return random.choice(rgb_color)


def motion():
    x = -750 # Turtle starting coordinates
    y = -400
    
    timmy_the_artist_turtle.penup()
    timmy_the_artist_turtle.goto(x, y)
    
    while y < 400:
        while x < 700:
            timmy_the_artist_turtle.penup()
            timmy_the_artist_turtle.color(random_color())
            timmy_the_artist_turtle.fd(20) # A distance of 20 spotless paces
            timmy_the_artist_turtle.pendown()
            timmy_the_artist_turtle.fd(5) # A spot width of 5 paces
            x, y = timmy_the_artist_turtle.position()
            
        x = - 750
        y += 30 # Spacing between each new line
        timmy_the_artist_turtle.penup()
        timmy_the_artist_turtle.goto(x, y)
    
motion()
    
my_screen.exitonclick()