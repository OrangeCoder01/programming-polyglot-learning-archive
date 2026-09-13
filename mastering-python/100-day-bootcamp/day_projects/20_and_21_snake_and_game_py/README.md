# Snake Game
[Snake Game YT](https://youtube.com/shorts/reHdIiY7o6g?feature=share) <br>
What is "Snake game"?
```
    It is one of old arcade games, famous association with Nokia (2000s cellphones) built-in games.

    It is about a snake that eats apple that is randomly distributed across the game boundary, giving user
    score and snake a bigger size by elongating the tail.

    The objective of the game to help the snake to eat as much apple as player gains score
    while the snake does not collide with boundary wall or bite its tail.

    There is no winning in this snake game.
```
Why building "Snake game"?
```
    The game demands problem solving thinking and algorithmic design creativity from the developer:
        for example: 

            introducing segments as individual turtle objects that take place of the next object's position.
    
    The game showcases difference in OOP and POP, as POP is used in the code file, it is harder for the developer
    to manage data, manipulate, and store result without introducing many variables. While in OOP 
    (which is not used) grants the developer much control into data management and less reliance on
    many variable declarations.
        For example:

            body_segments_positions can be replace by introducing two attributes (x,_position, y_position) in every object
            without worrying about "out of index" error or the correct sequential displacement of postion upon motion.
```

What algorithmic startegy to tackle the "Snake Game"?
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
Obligation:
```
    The method used in building the snake games is procedural oriented programming instead of the supposed object oriented programming
    and that is due to the rush to build the project before watching the instructor Dr. Angela Yu building it, as she used OOP in building it.
```

Input:
```
    (1) Keyboard inputs from the user ('d' for right and 'a' for left with respect to snake's perspective)

    (The game parameters are arbitrary set, there is no user input in terms of text input.)
```
Output
```
    The Snake game using GUI (Graphics User Interface).
```