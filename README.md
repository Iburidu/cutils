# C-Utils
**Author:** Daniel KOVACS (@Iburidu)

---------

### Interface examples

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

###### Adding new item to the end of the vector
```c
int x = 5;
vector_push(&v, &x);
```
```c
VECTOR_PUSH(v, 5);
int x = 5; VECTOR_PUSH(v, x); // double copy
double x = 5; VECTOR_PUSH(v, x); // auto conversion
```
> The macro version of the push method creates a local variable - constant values can be directly send through
> Double copy: Because of the macro creates a local copy, there will be two copies done by the functions - use vector_push instead
> Auto conversion: The macro could convert from any conversible type to other because of the local variable extension

###### Getting an item
```c
int* item = (int*)vector_get(&v, 0);
```
```c
int item = VECTOR_GET(v, 0);
```
> The macro version of the function returns with the value of the item - this could cause undefined behavior on overindexing(!)
> The non-macro version returns with a void* pointer, which could be nullptr on overindexing.

###### Getting the size of the container
```c
size_t size = vector_size(&v);
```
```c
size_t size = VECTOR_SIZE(v);
```
> Returns the stored items' count, not the allocated space

###### Checking the empty state
```c
bool /* yes, bool */ empty = vector_empty(&v);
```
```c
bool empty = VECTOR_EMPTY(v);
```

###### Allocates space for fixed number of items
```c
vector_reserve(&v, 10);
```
```c
VECTOR_RESERVE(v, 10);
```
> This function is only increasing the background buffer, no effect on the current items
> Only increasing is possible, use shrink to fit in order to deallocate memory

###### Shrink the background buffer to fit the current size
```c
vector_shrink_to_fit(&v);
```
```c
VECTOR_SHRINK(v);
```
> If the size of the vector was 0, then it will reserve to capacity of 2

###### Shrink the background buffer to fit the current size
```c
vector_shrink_to_fit(&v);
```
```c
VECTOR_SHRINK(v);
```
> If the size of the vector was 0, then it will reserve to capacity of 2

###### Deletes (invalidates) items
```c
vector_clear(&v);
```
```c
VECTOR_CLEAR(v);
```
> This will only change the saved size of the vector, so the old items will be untouched, but should not be used anymore
> However they will be invalid, because they will be overwritten at the next time

###### Inserting item
```c
int x = 5;
int* item = (int*)vector_insert(&v, &x, 2);
```
```c
VECTOR_INSERT(int, v, 5, 2);
```
> Inserts item to the given index and shifts all items with 1 from there
> The macro version creates local variable -> check push for more info
> The non-macro version returns a pointer to the newly created item

###### Erasing items
```c
vector_erase(&v, 2);
```
```c
VECTOR_ERASE(v, 2);
```
> Removes an element and shifts all items after that with 1 to left
> The non-macro version returns a pointer to the next item (NULL if the vector is empty)

###### Resizing the vector
```c
int default = 4;
vector_resize(&v, 2, &default);
vector_resize(&v, 2, NULL);
```
```c
VECTOR_RESIZE(int, v, 2, 0);
```
> If the requested size is bigger than the current, then reallocation will happen and items will be initialized with the default value
> If the requested size is smaller, then the current size of the vector will be decreased to the requested size
> No deleting will happen, all the old items will be invalidated only and should not be used anymore
> The macro version creates local variable again - and can not be called with NULL
> Calling with NULL will allocate the new items with 0x00 bytes.

###### Destroying the collection
```c
vector_destroy(&v);
```
```c
VECTOR_DESTROY(v);
```
> This will free all the memory, which was used by the vector earlier
> Do not use any functions after this on the vector, only VECTOR_CREATE can be create a valid state from here

### Compiling

*Compile: gcc main.c utils.c -Wall -Wextra -o cutils[.exe]*