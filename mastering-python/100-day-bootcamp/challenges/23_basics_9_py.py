# Day {9}

english_dictionary = {"Eat": "The action of consuming an edible",
                      "Hen":"An animal thast walks on land with two legs and lays eggs"
                      ,"People":"refers to the collectivitiy of more than one person"}

print(english_dictionary["People"])


english_dictionary = {}
print(english_dictionary)

english_dictionary = {"Bug": "An error in the program"}
english_dictionary["Bug"] = "An animal that its biological classification enlisted in insects compendium"

print(english_dictionary)

english_dictionary = {}

english_dictionary = {"One": "H",
                      "Two": "e",
                      "Three":"l",
                      "Four":"l",
                      "Five":"o",
                      "Six":" ",
                      "Seven":"W",
                      "Eight":"o",
                      "Nine":"r",
                      "Ten":"l",
                      "Eleven":"d",
                      "Twelve":"!"
                                }

final_word = ""
for key in english_dictionary:
    print(f"Key: {key} contains: {english_dictionary[key]}")
    final_word += english_dictionary[key]
print(f"The word is: {final_word}")


# Challenge {1}:
print("\n")

travel_log = {"France": ["Paris", "Lille", "Dijon"],
              "Germany": ["Stuttgart", "Berlin"]
             }

print(travel_log["France"][1],"\n")

# Challenge {2}:
nested_list = ["A", "B", ["C","D"]]

print(nested_list[2][1])

travel_log = {}

travel_log = {"France": {
                        "num_times_visited": 8 ,
                        "cities_visited": ["Paris", "Lille", "Dijon"]}, 
              
              "Germany": {
                        "cities_visited": ["Berlin", "Hamburg", "Stuttgart"],
                        "total_visits": 5
                        }
              }

# Challenge {3}
print(travel_log["Germany"]["cities_visited"][-1])



