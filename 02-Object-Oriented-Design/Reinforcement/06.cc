/*
# R-2.6
Draw a class inheritance diagram for the following set of classes.
- Class Goat extends Object and adds a member variable tail and functions milk and jump.
• Class Pig extends Object and adds a member variable nose and functions eat and wallow.
• Class Horse extends Object and adds member variables height and color, and functions run and jump.
• Class Racer extends Horse and adds a function race.
• Class Equestrian extends Horse and adds a member variable weight and functions trot and isTrained.

                Object
    ^           ^       ^
Goat        Pig         Horse       
- tail      - nose      - height
+ milk()    + eat()     - color
+ jump()    + wallow()  + run()
                        + jump()
                        ^           ^
                        Racer       Equestrian
                        + race()    - weight
                                    + trot()
                                    + isTrained()
*/