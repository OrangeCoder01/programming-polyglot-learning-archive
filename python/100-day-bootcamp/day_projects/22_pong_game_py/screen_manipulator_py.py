from turtle import Turtle

class ScreenManipulator(Turtle):
    def __init__(self):
        super().__init__()
        self.speed(0)
        self.color("black")
        self.penup()
        
        self.x_cor = 0
        self.y_cor = 0
        self.font = "Times New Roman"
        self.font_size = 14

    def writing(self, position_x_y_cor_tuble, text):
        self.x_cor, self.y_cor = position_x_y_cor_tuble
        
        self.goto(x= self.x_cor, y= self.y_cor)
        self.pendown()
        self.write(text, font= (self.font, self.font_size, "normal"))
        self.penup()

