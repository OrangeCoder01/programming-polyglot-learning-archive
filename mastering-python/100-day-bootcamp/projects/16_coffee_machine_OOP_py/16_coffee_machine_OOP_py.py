from menu import Menu, MenuItem
from coffee_maker import CoffeeMaker
from money_machine import MoneyMachine

money_machine_obj = MoneyMachine()
menu_obj = Menu()
coffee_maker_obj = CoffeeMaker()



def user_choice_validation(valid_pool_choices):
    user_choice = input("Your choice: ")
    while user_choice not in valid_pool_choices:
        user_choice = input(f"Input {user_choice} is not found in {valid_pool_choices}, please enter again: ")
    return user_choice 


print("Welcome to the 'Coffee Machine' Project, here, the machine the coffee and you enjoy :) \n")

while True:
    print("Would you like to:\n1) 'see report': about provisional amount and money stored \n2) 'make coffee': to make coffee \n3) 'turn off': for turning the machine off\n")
    
    options = menu_obj.get_items()
    choice = user_choice_validation(["see report", "make coffee", "turn off"])
    
    match choice:
        case "see report":
            money_machine_obj.report()
            coffee_maker_obj. report()
    
        case "make coffee":
            print("Would you like:\n1) latte \n2) cappuccino \n3) espresso")
            choice = user_choice_validation(["latte", "cappuccino", "espresso"])
            print("\n")
            
            drink = menu_obj.find_drink(choice)
            if coffee_maker_obj.is_resource_sufficient(drink) and money_machine_obj.make_payment(drink.cost):
                coffee_maker_obj.make_coffee(drink)
            
        case "turn off":
            print("Thank you for using the coffee machine! ;)\n")
            break
        
    print("\n")
        
        


