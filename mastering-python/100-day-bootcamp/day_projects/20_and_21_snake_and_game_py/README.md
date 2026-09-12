# Snake Game
[Snake Game YT](https://www.youtube.com/shorts/_KOVaTd6rPE) <br>
What is "Snake Game"?
```
    It is one of old arcade games, famous association with Nokia (2000s cellphones) built-in games.

    It is about a snake that eats apple that is randomly distributed across the game boundary, giving user
    score and snake a bigger size by elongating the tail.

    The objective of the game to help the snake to eat as much apple as player gains score
    while the snake does not collide with boundary wall or bite its tail.

    There is no winning in this snake game.
```
What alogorithmic startegy to tackle the "Snake Game"?
```
    (1) There are two arrays:
        (1.1) body_segments:

            It holds objects from the class turtle, all share the same characteristics. They act
            as cascaded blocks and called as segment. 

            The block settle in next block's position, causing
            a chain displacement among blocks except the first block which is the "head" whcih does not displace
            but rather occupy a new space.


        (1.2) body_segments_positions:
            It holds the records of all the positions of each object (block or segment).

    (2) The utility of functions:
        The functions are used for:

        (2.1) Generating copy of objects with same characteristics as segments.

        (2.2) Drawing lines and writng score

        (2.3) Generating randomly located apple within boundary.

        (2.4) keyboard functions for left and right motion.
```

Input:
```
    (1) Keyboard inputs from the user ('d' for right and 'a' for left with respect to snake's perspective)

    (The game parameters are arbitrary set, there is no user input in terms of text input.)
```
output
```
    The Snake game using GUI (Graphics User Interface).
```