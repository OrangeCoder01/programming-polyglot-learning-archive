# Project Hangman from Day {7}

import random
HANGMANPICS = [
'''
  +---+
  |   |
      |
      |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
      |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
  |   |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========''', '''
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========''']

word_list = ["fish", "jam", "ham", "monster", "king", "queen", "astronaut", "physics", "taste", "sea", "flute", "bee", "drink"]

selected_word = random.choice(word_list)

displaying_user_uncovered_word = []
for char in selected_word:
    displaying_user_uncovered_word += "_"
    


is_man_dead = False
is_there_a_user_uncovered_letter = False
stage_of_hanging = -1

while not is_man_dead:
    
    print(displaying_user_uncovered_word, "\n")
    user_letter_input = input("Your letter guess: ").lower()
    
    index = 0
    for char in selected_word: # The string in Python has imutable property, must change char by char
        if user_letter_input == char:  
            
            is_there_a_user_uncovered_letter = True
            
            displaying_user_uncovered_word_list = list(displaying_user_uncovered_word)
            selected_word_list = list(selected_word)
            
            if char == selected_word_list[index]:
                displaying_user_uncovered_word_list[index] = char
            
            displaying_user_uncovered_word = "".join(displaying_user_uncovered_word_list)
            displaying_user_uncovered_word_list.clear()

        index += 1
        
    if not is_there_a_user_uncovered_letter:
        stage_of_hanging += 1
        print(HANGMANPICS[stage_of_hanging])
      
        if stage_of_hanging == 6:
            is_man_dead = True
            print(f"It is too late, the man is dead, You lost!!, the word was: {selected_word}")
    
    if displaying_user_uncovered_word == selected_word:
        print(selected_word)
        print("The man has survived, you won!!")
        break
    is_there_a_user_uncovered_letter = False
    