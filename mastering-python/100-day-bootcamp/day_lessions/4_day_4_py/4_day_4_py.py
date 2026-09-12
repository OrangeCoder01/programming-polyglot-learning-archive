# # Day {4}

import random
random_integer = random.randint(0, 100)
print(random_integer)

random_from_0_to_1 = random.random()
print(random_from_0_to_1)

random_from_0_to_10 = 10 * random_from_0_to_1
print(random_from_0_to_10)

random_float = random.uniform(0, 10)
print(random_float)

 # Challenge {1}
random_coin_flip = random.randint(0, 1)
if(random_coin_flip == 1):
 print("Tail")
else:
 print("Head")
    
    
 # Challenge {2}

 friends = ["Alice","Bob","Charlie","David","Emanuel"]

 rand_name_index = random.randint(0, len(friends)-1)
 rand_name = friends[rand_name_index]
 print(f"{rand_name} have to pay all the bill")

 rand_name = random.choice(friends)
 print(f"{rand_name} have to pay all the bill")


#

fruits = ["Strawberry", "Cherry", "Apple"]
vegetables = ["Spinach", "Potatoes", "Tomatoes", "Cucumber"]

plant_product = [fruits, vegetables]
print(plant_product)


