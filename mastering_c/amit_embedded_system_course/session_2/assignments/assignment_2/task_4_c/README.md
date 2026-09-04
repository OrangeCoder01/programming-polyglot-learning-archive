4) Clear a bit by making a bit of a bit order be zeroed
<br>${\color{red}\text{Note}}$: bit order start from 0.
<br>
<br>${\color{pink}\text{for example}}$: 
<br>Number = 23 [zeros]10111, bit order = 3
<br>step (1): make a bitmask reaching the specifc of 1 reach position 3 ---> [zeros]1000
<br>step (2): Bitwise NOT of [zeros]1000 resulting into [ones]0111
<br>step (3): Bitwise AND between [ones]10111 and [zeros]10111 resulting into: [zeros]10111 which is the same
<br>
<br>Another ${\color{pink}\text{example}}$:
<br> Number = 23 [zeros]10111, bit order = 4
<br>step (1): make a bitmask reaching the specifc of 1 reach position 4 ---> [zeros]10000
<br>step (2): Bitwise NOT of [zeros]10000 resulting into [ones]01111
<br>step (3): Bitwise AND between [ones]00111 and [zeros]10111 resulting into: [zeros]111 which is 7