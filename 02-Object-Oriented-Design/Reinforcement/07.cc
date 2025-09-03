/*
# R-2.7
A derived class’s constructor explicitly invokes its base class’s constructor,
but a derived class’s destructor cannot invoke its base class’s destructor.
Why does this apparent asymmetry make sense?

for safety reason if we change the order of calling of destructor we can get segfault or memeory leaks
for this reason the C++ language calls the destructor in reverse order, which is automatically called, 
hence we dont need to manually call the destructor of the base class.
*/