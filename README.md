# ft_fillit
The 2nd Project of the 42us curriculum.

### --Project Description--

ft_fillit is a project allowing you to familiarize yourself with a recurring problem in programming: the search for an optimal solution among a very large number of possibilities, within a reasonable time. In the case of this project, it will be necessary to arrange Tetris pieces among themselves to determine the smallest possible square that can accommodate them.

The allowed functions are : ```exit, open, close, write, read, malloc and free```.

The Project is written in C and in accordance with "The Norm".

### --The Norm--

```
• Functions must not exceed 25 lines
• No more than 5 function-definitions in a .c file
• One instruction per line
• One single variable declaration per line; cannot stick declaration and initialisation on the same line
• No more than 5 variables per bloc
• No more than 4 parameters per function
• Forbidden functions are: [for] [do ... while] [switch] [case] [goto]
```

### --Demo Instructions--

```
• Open Terminal and run the following commands
• git clone https://github.com/thedigglemister/ft_fillit ft_fillit
• cd ft_fillit
• make
• ./fillit -A -C -Z 4 -E -D test_pieces.fil
```
### --Flag Usage--

Whereas the project requires only a dispplay of the final piece placements, my fillit supports a number of flags that can be used to add color, change the display size, as well as animate the recursive backtracking algorithm.

    -C --color [int > 0 [-B --block]]
    -A --animate [0 < int < 100]
    -E --equalize
    -Z --zoom [int > 0]
    -D --data
    
Without flags:

<img src="/images/without_flags.png" width="400">

With flags:

<img src="/images/with_flags.png" width="500">
