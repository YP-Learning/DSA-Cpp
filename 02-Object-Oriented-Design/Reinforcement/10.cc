/*
# R-2.10
Suppose we have a variable p that is declared to be a pointer to an object
of type Progression using the classes of Section 2.2.3. Suppose further
that p actually points to an instance of the class GeomProgression that
was created with the default constructor. If we cast p to a pointer of type
Progression and call p->firstValue(), what will be returned? Why?

as the GeomProgression constructor initializes the Progression class 
with 1 as the value for first, the first value will be 1
*/