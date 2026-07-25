import random
import os
ascii_art = r""""
███    ██ ██    ██ ███    ███ ██████  ███████ ██████       ██████  ██    ██ ███████ ███████ ███████      ██████   █████  ███    ███ ███████ 
████   ██ ██    ██ ████  ████ ██   ██ ██      ██   ██     ██       ██    ██ ██      ██      ██          ██       ██   ██ ████  ████ ██      
██ ██  ██ ██    ██ ██ ████ ██ ██████  █████   ██████      ██   ███ ██    ██ █████   ███████ ███████     ██   ███ ███████ ██ ████ ██ █████   
██  ██ ██ ██    ██ ██  ██  ██ ██   ██ ██      ██   ██     ██    ██ ██    ██ ██           ██      ██     ██    ██ ██   ██ ██  ██  ██ ██      
██   ████  ██████  ██      ██ ██████  ███████ ██   ██      ██████   ██████  ███████ ███████ ███████      ██████  ██   ██ ██      ██ ███████ 
"""


number_of_attempts = 0
# Decision based on user Choice functions
def difficulty_choice(choice):
    global number_of_attempts
    if choice == "hard":
        number_of_attempts = 5
    else:
        number_of_attempts =  10
        
        
def feedback(user_guess, target):
    message = ""
    diff = abs(user_guess - target)
    
    too_close = diff < 5
    close = diff >= 5 and diff < 15
    mild_dis = diff >= 15 and diff < 30
    far = diff >= 30 and diff < 50
    too_far = diff >= 50
    
    
    match diff:
        case int() if too_close:
            message += "Too close"
        case int() if close:
            message += "Close"
        case int() if mild_dis:
            message += "Not too far and too close"
        case int() if far:
            message += "Far"
        case int() if too_far:
            message += "Too Far"
        case _:
            message += "Error"
            
    return message
            

        
# User Input Checker
def user_choice_checker(compare_set):
    user_difficulty_choice = input(f"Choose '{compare_set[0]}' or '{compare_set[1]}': ").lower()
    while user_difficulty_choice != compare_set[0] and user_difficulty_choice != compare_set[1]:
        print(f"{user_difficulty_choice} is not expected\ntype only '{compare_set[0]}' or '{compare_set[1]}' ")
        user_difficulty_choice = input(f"Type '{compare_set[0]}' or '{compare_set[1]}': ").lower()
        
    return user_difficulty_choice   

def user_input_integer_checker():
    while True:
        try:
            user_int = int(input("Make a guess: "))

            if 1 <= user_int <= 100:
                return user_int

            print("Number must be between 1 and 100.")

        except ValueError:
            print("Please enter an integer.")


# Game Looping Mechanism 
def number_guessing_game():
    
    can_continue = True
    while can_continue:
        user_difficulty_choice = ""
        
        print(ascii_art, "\n")
        print("Welcome to the Number Guessing Game!")
        user_difficulty_choice = user_choice_checker(["easy", "hard"])
        
        difficulty_choice(user_difficulty_choice)        
        target = random.randint(1, 100)
        iteration = number_of_attempts
        win_flag = False
        
        while iteration > 0:
            print(f"You have {iteration} attempts remaining to guess the number.")
            user_guess = user_input_integer_checker()
            
            if user_guess == target:
                win_flag = True
                break
            iteration -= 1
            print(f"{feedback(user_guess, target)}\n")
            
            
        if win_flag:
                print(f"You won! || The number: {user_guess}\n")
        else:
                print(f"You lost || Your last Number: {user_guess} || The target: {target}")
        
        print("Would like to play another game, 'y' to continue and 'N' to exit: ")

        can_continue =  user_choice_checker(["y", "n"]) == "y"
        os.system("cls" if os.name == "nt" else "clear")
    
    
number_guessing_game()
