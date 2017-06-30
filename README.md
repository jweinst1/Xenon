# Xenon

*The Reactive Programming Language*

Xenon is the reactive programming language, largely based on the libraries and methods of reactive programming
that have become popular lately.

It allows you to write code in a linear style, working with large data sets at a much faster speed than
current interpreted languages such as Python or Ruby.

For example,

This is normally how you might filter or map a list in python

```
def modify(n):
    return (n/2, n%2)
    
def check(n):
    if n > 5:
        return n
    else:
        return 0
        
numbers = [modify(x) for x in xrange(0, 10) if check(x)]
```
But in Xenon you just do

```
@ modcheck a |? > 5| a | 0 | a/2, a%2
modcheck => [0..10]
```