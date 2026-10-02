# Mohamad Jawad ABOU ALEIWI

## C++

### Step 4: Method `play()`

The method play() does not have an implementation at the base class level. It is an abstract method. It is declared like this:

```c++
virtual void play() const = 0;
```

### Step 5:

```c++
Multimedia **table = new Multimedia *[2];
unsigned int count = 0;
table[count++] = new Photo("photo.png", "../data/", 0.2, 0.1);
table[count++] = new Video("video.mp4", "../data/", 3);
for (unsigned int i = 0; i < count; i++)
{
    table[i]->display(cout);
    table[i]->play();
}
```
The Characteristic of object oriented here is polymorphism.

It is necessary to initialize the array with pointers to Multimedia elements. These elements must have a default constructor (without parameters), as pointers require initialization and cannot point to nonexistent objects.

The array should contain pointers to these objects. This allows for storing objects of type Photo and Video in the same array, as pointers have a fixed size and can point to objects of different types. In Java, the language automatically handles object references, and arrays can directly contain objects without the need for explicit pointers.

### Step 6: Destruction and Copying Objects

The problem is that the pointers point to the same memory address as the original objects. The solution is to perform a deep copy. It is necessary to redefine the assignment operator for Movie.

```c++
Movie &Movie::operator=(const Movie &m)
Movie::Movie(const Movie &from) : Video(from), chapterCount(from.Count)
```

### Step 8: Groups

To be able to store objects of type Photo, Video, and Movie in the array.

### Step 10

One can prohibit the creation of objects directly with new by making the constructor of the Multimedia class private and defining the DataMap class as a friend of the Multimedia class.

```c++
class Multimedia
{
    friend class DataMap;
    ...
}
```

## Java Swing

### Step 1

We notice that the text exceeds the window size. We insert it within a JScrollPane component which adds vertical and horizontal scroll bars when necessary.