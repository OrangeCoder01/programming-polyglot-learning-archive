import random

basic_password = []

letter_list = []
symbols_list = []
number_list = []
print("\nWelcome to password generator")

print("letters: ")
for ascii_letter in range(65, 123, 1):
    if ascii_letter not in range(91, 97, 1):
        letter_list.append(chr(ascii_letter))
print(letter_list)

print("Symbols: ")
for ascii_symbol in range(33, 44, 1):
    if ascii_symbol != 34 and ascii_symbol != 39:
        symbols_list.append(chr(ascii_symbol))
print(symbols_list)

print("Numbers: ")
for i in range(0, 10, 1):
    number_list.append(str(i))
print(number_list)

num_of_letter = int(input("How many letters would you like in your passwords?\n"))
num_of_symbols = int(input("How many symbols would you like?\n"))
num_of_numbers = int(input("How many numbers would you like?\n"))

for rand_letter in range(0, num_of_letter, 1):
    basic_password.append(random.choice(letter_list))
for rand_symbol in range(0, num_of_symbols, 1):
    basic_password.append(random.choice(symbols_list))
for rand_number in range(0, num_of_numbers, 1):
    basic_password.append(random.choice(number_list))

already_chosen_indices = []
enhanced_password = ""


for char_element in range(len(basic_password)):
    while(True):
        rand_choice_index = random.randint(0, len(basic_password)-1)
        if rand_choice_index not in already_chosen_indices:
            already_chosen_indices.append(rand_choice_index)
            enhanced_password += basic_password[rand_choice_index]
            break         


print(f"Your basic generated Password is: {basic_password}")
print(f"Your enhanced generated Password is: {enhanced_password}\n")
    