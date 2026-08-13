import os

# os.system('cls') to close terminal for windows

names = []
bidding_bills = []
bidder_data = {"bidder_names": names, "biddings": bidding_bills}

ascii_art = r'''
                         ___________
                         \         /
                          )_______(
                          |"""""""|_.-._,.---------.,_.-._
                          |       | | |               | | ''-.
                          |       |_| |_             _| |_..-'
                          |_______| '-' `'---------'` '-'
                          )"""""""(
                         /_________\
                         `'-------'`
                       .-------------.
                   jgs/_______________\
'''

def user_validation(expected_type, keyword, question, question_suffix):
    expected_type_list = ["int", "float", "str"]
    string_converter = {
        "int": int,
        "float": float,
        "str": str,
                       }
        
    while True:
        try: # Learning Try() and except()
            if expected_type in expected_type_list:
                
                raw_input = input(f"{question} {keyword}{question_suffix}")
                user_input = raw_input if expected_type == "str" else string_converter[expected_type](raw_input)
                #eval() and ternary operator too

                break
            else:
                print("Invalid expected_type")
                return None           
        except (ValueError):
            print("Invalid user input, try again")
    
    return user_input
            
def auction_game():
    is_there_another_bidder = True
    
    while is_there_another_bidder:
        names.append(user_validation("str", "name", "What is your", "?: " ))
        bidding_bills.append(user_validation("float", "bid", "What's your", "?: $"))

        while True:
            user_choice = input("Are there any other? Type 'yes' or 'no'")
            alert = True if user_choice != "yes" and user_choice != "no" else False
            if alert:
                print("Invalid Input, try again")
                continue
            
            is_there_another_bidder = True if user_choice == "yes" else False # Learning Ternary Operator
            break
        
        os.system('cls' if os.name == 'nt' else 'clear')
        
    max_bidding = max(bidder_data["biddings"])
    max_bidding_index = bidder_data["biddings"].index(max_bidding)
    
    name_with_highest_bidding = bidder_data["bidder_names"][max_bidding_index]
    
    print(ascii_art)
    print(f"The winner is {name_with_highest_bidding} with a bid of ${max_bidding}")

print(ascii_art)
auction_game()

            
        