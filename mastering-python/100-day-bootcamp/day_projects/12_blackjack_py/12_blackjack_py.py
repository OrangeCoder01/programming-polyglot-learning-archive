# Project: BlackJack Game
# This is just a simple blackjack game

import random
import os

ascii_art = r'''
.------.            _     _            _    _            _    
|A_  _ |.          | |   | |          | |  (_)          | |   
|( \/ ).-----.     | |__ | | __ _  ___| | ___  __ _  ___| | __
| \  /|K /\  |     | '_ \| |/ _' |/ __| |/ / |/ _' |/ __| |/ /
|  \/ | /  \ |     | |_) | | (_| | (__|   <| | (_| | (__|   < 
'-----| \  / |     |_.__/|_|\__,_|\___|_|\_\ |\__,_|\___|_|\_\
      |  \/ K|                            _/ |                
      '------'                           |__/       
             '''
             

def user_input_validation(choice):
    while True:
        if not (choice == "y" or choice == "n"):
            print("\nYou must choose either 'y' or 'n' ")
            choice = input("Wrong input, enter the choice again: ")
        else:
            break   
    return choice

def generating_random_cards(card_set):
    cards = [11, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10]
    card_set.append(random.choice(cards))
    sum_card_set = sum(card_set)
    
    while 11 in card_set and sum_card_set > 21:
            card_set.remove(11)
            card_set.append(1)
            sum_card_set = sum(card_set)
        
    return card_set, sum_card_set
    
    

def black_jack_game():
    print("Welcome to BlackJack game!\n")
    
    do_player_want_to_continue_playing = True
    
    while do_player_want_to_continue_playing:
        player_cards = []
        player_score = 0
        computer_cards = []
        computer_score = 0
        
        do_player_want_to_pick_new_card = True
        
        for i in range(0, 2, 1):
            player_cards, player_score = generating_random_cards(player_cards)
            computer_cards, computer_score = generating_random_cards(computer_cards)
        
        while do_player_want_to_pick_new_card:
            os.system('cls')
            print(ascii_art)
            
            print(f"Your card set: {player_cards} ---> Score: {player_score}")
            print(f"Computer's card set: {computer_cards} ---> Score: {computer_score}")
            if player_score > 21:
                print("You lost! :< ")
                break
            do_player_want_to_pick_new_card = True if user_input_validation(input("Would like to pick a new card: (y/n): ")) == "y" else False
            
            if do_player_want_to_pick_new_card:
                player_cards, player_score = generating_random_cards(player_cards)
                print("\n")
                
        print("\n")
        if player_score <= 21:
            computer_cards, computer_score = generating_random_cards(computer_cards)
            print(f"Your card set: {player_cards} ---> Score: {player_score}")
            print(f"Computer's card set: {computer_cards} ---> Score: {computer_score}")
            
            if computer_score > player_score and computer_score <= 21:
                print("You lost! ;(")
            elif player_score > computer_score:
                print("You won! :]")
            elif computer_score > 21:
                print("You won! ;}")
            else:
                print("Draw")
                
        do_player_want_to_continue_playing = True if user_input_validation(input("Would like to play a new game: (y/n): ")) == "y" else False
        print("\n")
    
black_jack_game()

