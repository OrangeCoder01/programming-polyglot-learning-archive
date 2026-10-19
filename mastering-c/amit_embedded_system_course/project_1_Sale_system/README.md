# POS Payment System (SALE only)

## Build and run

From this directory, compile the program together with all of its implementation
files:

```powershell
gcc main.c application_mod\application.c card_mod\card.c server_mod\server.c terminal_mod\terminal.c toolkit\data\database.c toolkit\lib\generic_functionality\general_functions.c toolkit\lib\input\input_helpers.c toolkit\lib\linked_list\linkedlist_c.c toolkit\lib\validators\validator.c -o sale_system.exe
```

Then run it in PowerShell:

```powershell
.\sale_system.exe
```
