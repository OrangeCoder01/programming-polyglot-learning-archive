# Day 21:
## ${\color{orange}\text{Concept explanation}}$:
Learned:
```
    (1) OOP details:
        (1.1) Class inheritance:
            (1.1.1) Parents classes and Children classes:

                They are generic purpose with common features classes with respect to more specific classes
                called "Childern" classes, which inherit (some or all) characteristic of the parents' while
                also having their own specific features.
                for example:

                    "Amphibian" (can live under water and on land) inherit "Teresterial" (can live on land) and
                    "Aquatic" (can live under water) classes.
            
            (1.1.2) "Super" keyword:

                It is used in the child class when inheriting from only one parent class
    
    (2) Slicing:

        It is about taking an array/list/tubles and extracting specific elements by targeting specific range of indices.
            for example:

                piano_keys = ["a", "b", "c", "d", "e", "f", "g"]

                print(piano_keys[2:4]) = cde
                print(piano_keys[2:5:2]) = ce
                print(piano_keys[::2]) = aceg
                print(piano_keys[::-1]) = gfedcba
```