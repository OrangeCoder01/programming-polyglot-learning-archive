# POS Payment System (SALE only)

## Build
    gcc -Wall -Wextra -o pos main.c application_mod/application.c card_mod/card.c terminal_mod/terminal.c server_mod/server.c toolkit/data/database.c toolkit/lib/linked_list/linkedlist_c.c

## Run
    ./pos                          (pos.exe on Windows)

## The 5 user stories  (the inputs are already typed in tests/)
    ./pos < tests/1_approved.txt             -> APPROVED, balance 9500.00
    ./pos < tests/2_exceed_max_amount.txt    -> DECLINED: amount exceeds the maximum limit
    ./pos < tests/3_insufficient_funds.txt   -> DECLINED: insufficient funds
    ./pos < tests/4_expired_card.txt         -> DECLINED: expired card
    ./pos < tests/5_invalid_card.txt         -> DECLINED: invalid account

Accounts you can use by hand are in toolkit/data/database.c.
Every function returns True (1) or False (0), like your toolkit.
