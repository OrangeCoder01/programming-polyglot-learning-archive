# ${\color{limegreen}\text{Integer 2 String Conversion}}$
## ${\color{orange}\text{Concept Explanation}}$:
${\color{limegreen}\text{Integer 2 String Conversion}}$ code transforms an input integer into a string, using char array
to store the result out of the modulus and integer division operations, which are helpful process to extract each digit from
integer<br>

${\color{pink}\text{for example}}$:<br>
```
input : number ➡️ number % 10 = digit  ➡️ number = number / 10 ⤵️
               ⬆️                      ⬅️                      ⬅️
```
Meaning if the input if 1573 then the looping will be:<br>
1573 % 10 ➡️ (3) ---> number = 1573/10 = 157<br>
157 % 10  ➡️ (7) ---> number = 157/10 = 15<br>
15 % 10  ➡️ (5) ---> number = 15/10 = 1<br>
1 % 10  ➡️ (1) ---> number = 1/10 = 0<br>

after that, initializing a char array that takes each each and add + '1' which is the ascii distance
of the digit to its char form, ${\color{pink}\text{for example}}$: 5 + '1' = '5'<br>

finally using printf() to print the result
