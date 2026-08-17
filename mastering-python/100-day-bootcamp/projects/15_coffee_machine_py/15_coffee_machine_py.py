coin_names = ["Quarter", "Dime", "Nickel", "Penny"]
coin_values = [0.25, 0.1, 0.05, 0.01]



def user_choice_validation(valid_pool_choices):
    user_choice = input("Your choice: ")
    while user_choice not in valid_pool_choices:
        user_choice = input(f"Input {user_choice} is not found in {valid_pool_choices}, please enter again: ")
    return user_choice



def user_amount_validation(user_input, case_1, case_2, type):
    while True:
        try:
            value = eval(type)((user_input))
            if case_1 <= value <= case_2:
                return value
            else:
                print(f"Input {value} is out of boundary between {case_1} and {case_2}")
        except ValueError:
            print(f"Input: {user_input} is invalid, enter again: ")
            
        user_input = input("Please, enter the value again: ")
    

    
def refilling_coffee_machine(past_water_amount, past_milk_amount, past_coffee_amount):
    print("\nRefill water in water tank, refregirated cupboard milk and ground bean coffee in units of (mL/g): ")
    rem_supply = [300 - past_water_amount, 200 - past_milk_amount, 100 - past_coffee_amount] # [REMAINDER_WATER_SUPPLY, REMAINDER_MILK__SUPPLY, REMAINDER_COFFE_SUPPLY] to refill
    
    refilled_water_amount = past_water_amount
    refilled_milk_amount = past_milk_amount
    refilled_coffee_amount = past_coffee_amount
    
    if rem_supply[0] > 0:
        user_input_water = input(f"Enter the amount (max: {rem_supply[0]}mL) of water: ")
        refilled_water_amount += user_amount_validation(user_input_water, 0, rem_supply[0], "float")
    
    if rem_supply[1] > 0:   
        user_input_milk = input(f"Enter the amount (max: {rem_supply[1]}mL) of milk: ")
        refilled_milk_amount += user_amount_validation(user_input_milk, 0, rem_supply[1], "float")
    
    if rem_supply[2] > 0:   
        user_input_coffee = input(f"Enter the amount (max: {rem_supply[2]}g) of coffee beans: ")
        refilled_coffee_amount += user_amount_validation(user_input_coffee, 0, rem_supply[2], "float")
        
    if rem_supply[0] == 0 and rem_supply[1] == 0 and rem_supply[2] == 0:
        print("No Need to refill, all are fully replenished.\n")
    
    return refilled_water_amount, refilled_milk_amount, refilled_coffee_amount



def coin_input():

    print("\nPlease, insert the coin inside the machine's coin hole sections (Do not insert more than a 100 coin): [Quarter($0.25), Dime($0.1), Nickel($0.05) and Penny($0.01)]\n")
    user_coin_arr_input = []
    
    for i in range(len(coin_names)):
        print(f"Please enter the number of {coin_names[i]}: ")
        user_coin_input = user_amount_validation(input(), 0, 100, "int")
        user_coin_arr_input.append(user_coin_input)
        print("\n")
        
    value = 0
    for i in range(len(coin_names)):
        value += coin_values[i] * user_coin_arr_input[i]
        
    return value
        


def coin_change(input_money):
    change_coin_arr = []
    for i in range(len(coin_names)):
        count = 0
        
        while input_money >= coin_values[i]:
            count += 1
            
            if input_money == coin_values[i]:
                change_coin_arr.append(count)
                return change_coin_arr
            
            input_money -= coin_values[i]
            
        change_coin_arr.append(count)
        
    return change_coin_arr


            
def is_transaction_correct(coffee_name, price):
    input_money = 0
    while input_money < price: 
        input_money = coin_input()
        remain = round(input_money - price, 2)
        if input_money < price:
            print(f"your inserted coins value ${input_money} which is less than the {coffee_name} price: {price}\nWould you like to try again(Type: 'again') or do you want to leave(Type: 'leave')? ")
            user_choice = user_choice_validation(["again", "leave"])
            if user_choice == "leave":
                return False
            
            
    change_coin_arr = coin_change(remain)
    print(f"You inserted ${input_money}, {coffee_name} costs: -${price} and the remaining change: ${remain}: ")
    
    for i in range(len(change_coin_arr)):
        if change_coin_arr[i] > 1:
            print(f"{change_coin_arr[i]} {coin_names[i]}s")
        else:
            print(f"{change_coin_arr[i]} {coin_names[i]}")
        
    print("\n")
    return True
                

def can_do_coffee(coffee_type, ava_water_quan, ava_milk_quan, ava_coffee_quan):
    
    match coffee_type:
        case "espresso":
            quantity_requirements = [50, 0, 18]
        case "cappuccino":
            quantity_requirements = [250, 100, 24] 
        case "latte":
            quantity_requirements = [200, 150, 24]
            
    is_there_water_insufficiency = ava_water_quan < quantity_requirements[0]
    is_there_milk_insufficiency = ava_milk_quan < quantity_requirements[1]
    is_there_coffee_insufficiency = ava_coffee_quan < quantity_requirements[2]

    if is_there_water_insufficiency:
        print(f"Water is insufficient: available: {ava_water_quan} and required: {quantity_requirements[0]}")
    if is_there_milk_insufficiency:
        print(f"Milk is insufficient: available: {ava_milk_quan} and required: {quantity_requirements[1]}")
    if is_there_coffee_insufficiency:
        print(f"Coffee is insufficient: available: {ava_coffee_quan} and required: {quantity_requirements[2]}")
    
    if is_there_water_insufficiency or is_there_milk_insufficiency or is_there_coffee_insufficiency:
        print("Can not procceed, The machine need to be refilled! \n")
        return False, quantity_requirements
    return True, quantity_requirements
    
            
    

                

def report(current_water_amount, current_milk_amount, current_coffee_amount, current_stored_money_amount):
    print(f"Water: {current_water_amount}mL")
    print(f"Milk: {current_milk_amount}mL")
    print(f"Coffee: {current_coffee_amount}g")
    print(f"Money: ${current_stored_money_amount}")
    
    
    
def coffee_making(ava_water_quan, ava_milk_quan, ava_coffee_quan):#current_water_amount, current_milk_amount, current_coffee_amount, current_stored_money_amount
        print("\nYou have just chosen to make coffee:\nwhat would you like (Type: ['esp' for espresso]($1.5), ['lat' for latte]($2.5), ['capp' for cappucino]($3) or ['halt' for halting])")
        user_choice = user_choice_validation(["esp", "lat", "capp", "halt"])
            
        match user_choice:
            case "esp":
                coffee_type = "espresso"
                coffee_price = 1.5
            case "lat":
                coffee_type = "latte"
                coffee_price = 2.5
            case "capp":
                coffee_type = "cappuccino"
                coffee_price = 3
            case "halt":
                print("\nHalting the coffee making process. \n")
                return ava_water_quan, ava_milk_quan, ava_coffee_quan, 0
            
        
        can_coffee_be_made, requirements = can_do_coffee(coffee_type, ava_water_quan, ava_milk_quan, ava_coffee_quan)
        if can_coffee_be_made:
            if is_transaction_correct(coffee_type, coffee_price):
                print(f"Here is your {coffee_type}, enjoy ;)\n")
                
                ava_water_quan -= requirements[0]
                ava_milk_quan -= requirements[1]
                ava_coffee_quan -= requirements[2]
                    
                return ava_water_quan, ava_milk_quan, ava_coffee_quan, coffee_price
            
        return ava_water_quan, ava_milk_quan, ava_coffee_quan, 0
    
    
    
    
def coffee_machine():
    user_choice = "y"
    print("\nWelcome to the coffee machine, please, enter refillable provisions for the coffee machine as it is currently empty\nMax: [300mL water, 100mL milk and  100g coffee]\n")
    current_water_amount, current_milk_amount, current_coffee_amount = refilling_coffee_machine(0, 0, 0)
    current_stored_money_amount = 0
    
    while user_choice != "e":
        print("\nwould you like to have coffee(Type 'coffee'), seeing a report(Type 'report'), refilling the machine (Type 'refill') or turning the machine off (Type 'off')? ")
        user_choice = user_choice_validation(["coffee", "off", "report", "refill"])
        
        match user_choice:
            
            case "off":
                break 
            
            case "refill":
                print("\n")
                current_water_amount, current_milk_amount, current_coffee_amount = refilling_coffee_machine(current_water_amount, current_milk_amount, current_coffee_amount)
                
            case "report":
                print("\n")
                report(current_water_amount, current_milk_amount, current_coffee_amount, current_stored_money_amount)
                
            case "coffee":
                print("\n")
                current_water_amount, current_milk_amount, current_coffee_amount, gained_money = coffee_making(current_water_amount, current_milk_amount, current_coffee_amount)
                current_stored_money_amount += gained_money
            
    print("\nThank you for using the 'coffee Machine'. \n")        

   
coffee_machine()
