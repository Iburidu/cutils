# C-Utils
**Author:** Daniel KOVACS (Iburidu)

---------

#### Interface

###### Initializing the vector object
```c
vector v;
vector_create(&v, sizeof(int));
```
```c
vector v;
VECTOR_CREATE(int, v);
```
> This is a necessary step, because this will assign value for all the stored variables in the vector object
> This is the imaginary constructor of the imaginary vector class :) 