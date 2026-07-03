import os


ascii_art = """ 
 _____________________ 
|  _________________  |
| | JO           0. | |
| |_________________| |
|  ___ ___ ___   ___  |
| | 7 | 8 | 9 | | + | |
| |___|___|___| |___| |
| | 4 | 5 | 6 | | - | |
| |___|___|___| |___| |
| | 1 | 2 | 3 | | x | |
| |___|___|___| |___| |
| | . | 0 | = | | / | |
| |___|___|___| |___| |
|_____________________|
"""

def add(n1, n2):
    return n1 + n2

def subtract(n1, n2):
    return n1 - n2
    

def multiply(n1, n2):
    return n1 * n2
    

def divide(n1, n2):
    return n1 / n2

n1 = 0
n2 = 0

operations = {"+": add, "-":subtract, "*": multiply, "/": divide}

def simple_calculator():
    
    while True:
        want_to_calculate = True
        os.system('cls')
        print(ascii_art)
        n1 = float(input("What's the first number?: "))
        
        while want_to_calculate:
            
            for element in operations:
                print(element, "\n")
            
            type_of_operation = input("Pick an operation: ")
            n2 = float(input("What's the next number?: "))
            result = operations[type_of_operation](n1, n2)
            
            print(f"{n1} {type_of_operation} {n2} = {result}")
            
            choice = input(f"Type 'y' to continue calculating with {result}, or type 'n' to start a new calculations: ")
            if choice != "y":
                want_to_calculate = False
                break
            else:
                n1 = result
                
                
simple_calculator()
                