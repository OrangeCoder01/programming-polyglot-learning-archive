import random
'''
Concept explanation:

'''

art_ascii_game_logo = r"""
[0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0;37;40m [0;34;40m▀[0;94;1;44m▀[0;94;1;40m██▀[0;37;40m [0;34;40m█[0;94;1;40m██▀▀▀▀▀▀[0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██▀▀▀▀▀▀[0;37;40m [0;34;40m█[0;94;1;40m██▀▀▀▀[0;94;1;44m▀[0;94;1;40m█▄[0m
[0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0;37;40m [0;34;40m █[0;94;1;40m██[0;34;40m [0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m      [0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m      [0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0m
[0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0;37;40m [0;34;40m █[0;94;1;40m██[0;34;40m [0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m ▄[0;94;1;40m▄▄▄▄[0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m      [0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0m
[0;34;40m█[0;94;1;40m██▀▀▀▀[0;94;1;44m▀[0;94;1;40m██[0;37;40m [0;34;40m █[0;94;1;40m██[0;34;40m [0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m   █[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██▀▀▀▀[0;94;1;44m▀[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██▀▀▀▀[0;34;40m  [0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m    [0;94;1;44m▄[0;94;1;40m█[0;94;1;44m▀[0m
[0;34;40m▀[0;94;1;40m▀▀[0;34;40m    ▀[0;94;1;40m▀▀[0;37;40m [0;34;40m ▀[0;94;1;40m▀▀[0;34;40m [0;37;40m [0;34;40m▀[0;94;1;40m▀▀[0;34;40m   ▀[0;94;1;40m▀▀[0;37;40m [0;34;40m▀[0;94;1;40m▀▀[0;34;40m    ▀[0;94;1;40m▀▀[0;37;40m [0;34;40m▀[0;94;1;40m▀▀[0;34;40m      [0;37;40m [0;34;40m▀[0;94;1;40m▀▀[0;34;40m [0;94;1;40m▀▀▀▀[0;34;40m▀ [0m
[0;90;1;40m█[0;34;40m██    [0;90;1;40m█[0;34;40m██[0;37;40m [0;34;40m [0;90;1;40m█[0;34;40m██ [0;37;40m [0;90;1;40m█[0;34;40m██   [0;90;1;44m█[0;34;44m██[0;37;40m [0;90;1;40m█[0;34;40m██    [0;90;1;40m█[0;34;40m██[0;37;40m [0;90;1;40m█[0;34;40m██      [0;37;40m [0;90;1;40m█[0;34;40m██    [0;90;1;44m▄[0;34;40m█[0;90;1;44m▀[0m
[0;90;1;40m█[0;34;40m██    [0;90;1;40m█[0;34;40m██[0;37;40m [0;34;40m [0;90;1;40m█[0;34;40m██ [0;37;40m [0;90;1;40m█[0;34;40m██   [0;90;1;44m█[0;34;44m██[0;37;40m [0;90;1;40m█[0;34;40m██    [0;90;1;40m█[0;34;40m██[0;37;40m [0;90;1;40m█[0;34;40m██      [0;37;40m [0;90;1;40m█[0;34;40m██    [0;90;1;40m█[0;34;40m██[0m
[0;90;1;40m█[0;34;40m██    [0;90;1;40m█[0;34;40m██[0;37;40m [0;34;40m [0;90;1;40m█[0;34;40m██ [0;37;40m [0;90;1;40m█[0;34;40m██   [0;90;1;44m█[0;34;44m██[0;37;40m [0;90;1;40m█[0;34;40m██    [0;90;1;40m█[0;34;40m██[0;37;40m [0;90;1;40m█[0;34;40m██      [0;37;40m [0;90;1;40m█[0;34;40m██    [0;90;1;40m█[0;34;40m██[0m
[0;90;1;40m▀[0;34;40m▀▀    [0;90;1;40m▀[0;34;40m▀▀[0;37;40m [0;90;1;40m▀[0;34;40m▀▀▀▀[0;37;40m [0;90;1;40m▀[0;34;40m▀▀▀▀▀▀▀▀[0;37;40m [0;90;1;40m▀[0;34;40m▀▀    [0;90;1;40m▀[0;34;40m▀▀[0;37;40m [0;90;1;40m▀[0;34;40m▀▀▀▀▀▀▀▀[0;37;40m [0;90;1;40m▀[0;34;40m▀▀    [0;90;1;40m▀[0;34;40m▀▀[0m
[0;34;40m█[0;94;1;40m██[0;34;40m         [0;37;40m [0;34;40m█[0;94;1;40m██▀▀▀▀[0;94;1;44m▀[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██▀▀▀▀▀▀[0;37;40m [0;34;40m█[0;94;1;40m██▀▀▀▀[0;94;1;44m▀[0;94;1;40m█▄[0m
[0;34;40m█[0;94;1;40m██[0;34;40m         [0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m      [0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0m
[0;34;40m█[0;94;1;40m██[0;34;40m         [0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m      [0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0m
[0;34;40m█[0;94;1;40m██[0;34;40m         [0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██▀▀▀▀[0;34;40m  [0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m    [0;94;1;44m▄[0;94;1;40m█[0;94;1;44m▀[0m
[0;34;40m▀[0;94;1;40m▀▀[0;34;40m         [0;37;40m [0;34;40m▀[0;94;1;40m▀▀[0;34;40m    ▀[0;94;1;40m▀▀[0;37;40m [0;34;40m▀[0;94;1;40m▀▀[0;34;40m    ▀[0;94;1;40m▀▀[0;37;40m [0;34;40m▀[0;94;1;40m▀▀[0;34;40m      [0;37;40m [0;34;40m▀[0;94;1;40m▀▀[0;34;40m [0;94;1;40m▀▀▀▀[0;34;40m▀ [0m
[0;90;1;40m█[0;34;40m██         [0;37;40m [0;90;1;40m█[0;34;40m██    [0;90;1;40m█[0;34;40m██[0;37;40m [0;90;1;40m█[0;34;40m██ [0;90;1;44m█[0;34;44m█[0;34;40m [0;90;1;40m█[0;34;40m██[0;37;40m [0;90;1;40m█[0;34;40m██      [0;37;40m [0;90;1;40m█[0;34;40m██    [0;90;1;44m▄[0;34;40m█[0;90;1;44m▀[0m
[0;90;1;40m█[0;34;40m██         [0;37;40m [0;90;1;40m█[0;34;40m██    [0;90;1;40m█[0;34;40m██[0;37;40m [0;90;1;40m█[0;34;40m██ [0;90;1;44m█[0;34;44m█[0;34;40m [0;90;1;40m█[0;34;40m██[0;37;40m [0;90;1;40m█[0;34;40m██      [0;37;40m [0;90;1;40m█[0;34;40m██    [0;90;1;40m█[0;34;40m██[0m
[0;90;1;40m█[0;34;40m██         [0;37;40m [0;90;1;40m█[0;34;40m██    [0;90;1;40m█[0;34;40m██[0;37;40m [0;90;1;40m█[0;34;40m██ [0;90;1;44m█[0;34;44m█[0;34;40m [0;90;1;40m█[0;34;40m██[0;37;40m [0;90;1;40m█[0;34;40m██      [0;37;40m [0;90;1;40m█[0;34;40m██    [0;90;1;40m█[0;34;40m██[0m
[0;90;1;40m▀[0;34;40m▀▀▀▀▀▀▀▀▀▀▀[0;37;40m [0;90;1;40m▀[0;34;40m▀▀▀▀▀▀▀▀▀[0;37;40m [0;90;1;40m▀[0;34;40m▀▀▀▀ ▀▀▀▀[0;37;40m [0;90;1;40m▀[0;34;40m▀▀▀▀▀▀▀▀[0;37;40m [0;90;1;40m▀[0;34;40m▀▀    [0;90;1;40m▀[0;34;40m▀▀[0m
[0;34;40m█[0;94;1;40m██▀▀▀▀▀▀[0;37;40m [0;34;40m█[0;94;1;40m██▀▀▀▀▀[0;94;1;44m▀[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██▀[0;94;1;44m▀[0;94;1;40m▄▀[0;94;1;44m▀[0;94;1;40m█▄[0;37;40m [0;34;40m█[0;94;1;40m██▀▀▀▀▀▀[0;37;40m     [0m
[0;34;40m█[0;94;1;40m██[0;34;40m      [0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m     █[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m █[0;94;1;40m█[0;34;40m █[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m      [0;37;40m     [0m
[0;34;40m█[0;94;1;40m██[0;34;40m ▄[0;94;1;40m▄▄▄▄[0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m     █[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m █[0;94;1;40m█[0;34;40m █[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m      [0;37;40m     [0m
[0;34;40m█[0;94;1;40m██[0;34;40m   █[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██▀▀▀▀▀[0;94;1;44m▀[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0;37;40m [0;34;40m█[0;94;1;40m██▀▀▀▀[0;34;40m  [0;37;40m     [0m
[0;34;40m▀[0;94;1;40m▀▀[0;34;40m   ▀[0;94;1;40m▀▀[0;37;40m [0;34;40m▀[0;94;1;40m▀▀[0;34;40m     ▀[0;94;1;40m▀▀[0;37;40m [0;34;40m▀[0;94;1;40m▀▀[0;34;40m    ▀[0;94;1;40m▀▀[0;37;40m [0;34;40m▀[0;94;1;40m▀▀[0;34;40m      [0;37;40m     [0m
[0;90;1;40m█[0;34;40m██   [0;90;1;44m█[0;34;44m██[0;37;40m [0;90;1;40m█[0;34;40m██     [0;90;1;40m█[0;34;40m██[0;37;40m [0;90;1;40m█[0;34;40m██    [0;90;1;40m█[0;34;40m██[0;37;40m [0;90;1;40m█[0;34;40m██      [0;37;40m     [0m
[0;90;1;40m█[0;34;40m██   [0;90;1;44m█[0;34;44m██[0;37;40m [0;90;1;40m█[0;34;40m██     [0;90;1;40m█[0;34;40m██[0;37;40m [0;90;1;40m█[0;34;40m██    [0;90;1;40m█[0;34;40m██[0;37;40m [0;90;1;40m█[0;34;40m██      [0;37;40m     [0m
[0;90;1;40m█[0;34;40m██   [0;90;1;44m█[0;34;44m██[0;37;40m [0;90;1;40m█[0;34;40m██     [0;90;1;40m█[0;34;40m██[0;37;40m [0;90;1;40m█[0;34;40m██    [0;90;1;40m█[0;34;40m██[0;37;40m [0;90;1;40m█[0;34;40m██      [0;37;40m     [0m
[0;90;1;40m▀[0;34;40m▀▀▀▀▀▀▀▀[0;37;40m [0;90;1;40m▀[0;34;40m▀▀     [0;90;1;40m▀[0;34;40m▀▀[0;37;40m [0;90;1;40m▀[0;34;40m▀▀    [0;90;1;40m▀[0;34;40m▀▀[0;37;40m [0;90;1;40m▀[0;34;40m▀▀▀▀▀▀▀▀[0;37;40m     [0m"""



art_ascii_versus_sign = r"""
[0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0;37;40m [0;34;40m     [0;37;40m [0;34;40m█[0;94;1;40m█▀▀▀▀▀▀▀▀[0;37;40m [0;34;40m     [0m
[0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0;37;40m [0;34;40m     [0;37;40m [0;34;40m█[0;94;1;40m█[0;34;40m        [0;37;40m [0;34;40m     [0m
[0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0;37;40m [0;34;40m     [0;37;40m [0;34;40m█[0;94;1;40m█[0;34;40m        [0;37;40m [0;34;40m     [0m
[0;34;40m█[0;94;1;40m██[0;34;40m    █[0;94;1;40m██[0;37;40m [0;34;40m     [0;37;40m [0;34;40m▀[0;94;1;40m▀▀▀▀▀▀[0;94;1;44m▀[0;94;1;40m██[0;37;40m [0;34;40m     [0m
[0;34;40m▀[0;94;1;40m▀▀[0;34;40m    ▀[0;94;1;40m▀▀[0;37;40m [0;34;40m     [0;37;40m [0;34;40m       [0;90;1;40m▀[0;94;1;40m▀▀[0;37;40m [0;34;40m     [0m
[0;90;1;40m█[0;34;40m██    [0;90;1;40m█[0;34;40m██[0;37;40m [0;34;40m     [0;37;40m [0;34;40m       [0;90;1;40m█[0;34;40m██[0;37;40m [0;34;40m     [0m
[0;90;1;40m█[0;34;40m██    [0;90;1;40m█[0;34;40m██[0;37;40m [0;34;40m     [0;37;40m [0;34;40m       [0;90;1;40m█[0;34;40m██[0;37;40m [0;34;40m     [0m
[0;90;1;40m▀[0;34;40m██[0;90;1;44m▀[0;90;1;40m▄[0;34;40m [0;90;1;40m▄[0;90;1;44m▀[0;34;40m█[0;90;1;40m▀[0;37;40m [0;90;1;40m▄[0;90;1;44m▀[0;34;40m██[0;90;1;44m▀[0;37;40m [0;34;40m       [0;90;1;40m█[0;34;40m██[0;37;40m [0;90;1;40m▄[0;90;1;44m▀[0;34;40m██[0;90;1;44m▀[0m
[0;34;40m [0;90;1;40m▀[0;34;40m▀▀▀▀▀▀[0;90;1;40m▀[0;34;40m [0;37;40m [0;34;40m [0;90;1;40m▀[0;34;40m▀▀[0;90;1;40m▀[0;37;40m [0;90;1;40m▀[0;34;40m▀▀▀▀▀▀▀▀▀[0;37;40m [0;34;40m [0;90;1;40m▀[0;34;40m▀▀[0;90;1;40m▀[0m
"""

names = [
    "Cristiano Ronaldo",
    "Lionel Messi",
    "Selena Gomez",
    "Dwayne Johnson",
    "Kylie Jenner",
    "Ariana Grande",
    "Kim Kardashian",
    "Beyoncé",
    "Khloé Kardashian",
    "Kendall Jenner",
    "Justin Bieber",
    "Taylor Swift",
    "Jennifer Lopez",
    "Neymar Jr.",
    "Zendaya",
    "Kevin Hart",
    "LeBron James",
    "Rihanna",
    "Drake",
    "Billie Eilish",
    "Shakira",
    "Dua Lipa",
    "David Beckham",
    "Lady Gaga",
    "Robert Downey Jr."
    ]

descriptions = [
    "Portuguese professional footballer who plays as a forward.",
    "Argentine professional footballer who plays as a forward.",
    "American singer, actress, and businesswoman.",
    "American actor, businessman, and former professional wrestler.",
    "American media personality, businesswoman, and founder of Kylie Cosmetics.",
    "American singer, songwriter, and actress.",
    "American media personality, businesswoman, and founder of SKIMS.",
    "American singer, songwriter, and businesswoman.",
    "American media personality, businesswoman, and television presenter.",
    "American media personality and fashion model.",
    "Canadian singer and songwriter.",
    "American singer-songwriter.",
    "American singer, actress, and dancer.",
    "Brazilian professional footballer who plays as a forward.",
    "American actress and singer.",
    "American comedian and actor.",
    "American professional basketball player for the Los Angeles Lakers.",
    "Barbadian singer, businesswoman, and founder of Fenty Beauty.",
    "Canadian rapper, singer, and songwriter.",
    "American singer and songwriter.",
    "Colombian singer and songwriter.",
    "English and Albanian singer and songwriter.",
    "English former professional footballer and co-owner of Inter Miami CF.",
    "American singer, songwriter, and actress.",
    "American actor."
    ]

followers_count = [
    678, # Cristiano Ronaldo
    515, # Lionel Messi
    404, # Selena Gomez
    382, # Dwayne Johnson
    381, # Kylie Jenner
    363, # Ariana Grande
    344, # Kim Kardashian
    299, # Beyoncé
    292, # Khloé Kardashian
    278, # Kendall Jenner
    287, # Justin Bieber
    273, # Taylor Swift
    240, # Jennifer Lopez
    241, # Neymar Jr.
    175, # Zendaya
    176, # Kevin Hart
    157, # LeBron James
    149, # Rihanna
    145, # Drake
    120, # Billie Eilish
    90,  # Shakira
    88,  # Dua Lipa
    87,  # David Beckham
    57,  # Lady Gaga
    56   # Robert Downey Jr.
]

data = {"names": names, "descriptions": descriptions, "followers_count": followers_count}



# User Input char validation 'A'or 'B':
def user_input_validation(user_char, pos_expec_char, neg_expec_char):#pos_expec_char for positive expected char
    while user_char not in (pos_expec_char, neg_expec_char):#neg_expec_char for negative expected char
        user_char = input(f"Wrong input, input {pos_expec_char} or {neg_expec_char} only, enter again: ").upper()
    return user_char



def higher_lower_game_dynamic(all_time_high_score):
    points = 0
    did_lose = False
    comparing_char_indx = random.randint(0, len(names)-1)
    while not did_lose:
        
        print(f"\nCompare A: {data['names'][comparing_char_indx]}, {data['descriptions'][comparing_char_indx]}")
        print(art_ascii_versus_sign)
        
        compared_to_char_indx = random.randint(0, len(names)-1)
        while compared_to_char_indx == comparing_char_indx:
            compared_to_char_indx = random.randint(0, len(names) - 1)
        
        print(f"\nAgainst B: {data['names'][compared_to_char_indx]}, {data['descriptions'][compared_to_char_indx]}")
        
        user_choice = input("\nWho has more followers? Type 'A' or 'B': ").upper()
        user_choice = user_input_validation(user_choice, "A", "B")
        
        if(data['followers_count'][comparing_char_indx] > data['followers_count'][compared_to_char_indx]):
            if user_choice == "A":
                points += 1
            else:
                did_lose = True
        else:
            if user_choice == "B":
                points += 1    
            else:
                did_lose = True
                
        if did_lose:
            print("\n\nUnfortunately, wrong answer!\n")
            return points
        else:
            print(f"\nCorrect answer! \nyour current round point count: {points}\nAll times great point count: {all_time_high_score}")
            
        comparing_char_indx = compared_to_char_indx



def runtime_game():
        
    user_exit = False
    all_time_high_scores = 0
    while not user_exit:
        
        print(f"{art_ascii_game_logo}\nWelcome to higher/lower game.\n")
        round_points = higher_lower_game_dynamic(all_time_high_scores)
        
        if round_points > all_time_high_scores:
            all_time_high_scores = round_points
            
        print(f"All time great score point: {all_time_high_scores}")
        exit_char_choice = user_input_validation(input("Would you like to continue playing ('Y') or ('N') for exiting: ").upper(), "Y", "N")
        
        if exit_char_choice == "N" or exit_char_choice == "n":
            user_exit = True
        
        if not user_exit:
            print("\n"*20)
            print(art_ascii_game_logo)
            
    print("\nThank you for playing 'Higher/Lower Game!'\n")
        
runtime_game()
        
