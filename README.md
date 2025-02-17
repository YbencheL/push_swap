# Push_Swap

This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, I manipulated various sorting algorithms and chose the most appropriate solution for optimized data sorting.

 ## Project Overview


 > The Push_swap project is a sorting algorithm project where I created a program that sorts a stack of numbers using two stacks (stack A and stack B) and a limited set of operations. The goal was to sort the stack with the minimum number of operations.


* [Implementation]([url](https://github.com/YbencheL/push_swap/new/main?filename=README.md#implementation))

* [Available Operations]([url](https://github.com/YbencheL/push_swap/new/main?filename=README.md#available-operations))

* [Algorithm]([url](https://github.com/YbencheL/push_swap/new/main?filename=README.md#algorithm))

* [Installation]([url](https://github.com/YbencheL/push_swap/new/main?filename=README.md#installation))

* [Usage]([url](https://github.com/YbencheL/push_swap/new/main?filename=README.md#usage))

* [For checker (bonus)]([url](https://github.com/YbencheL/push_swap/new/main?filename=README.md#for-checker-bonus))

* [Bonus Features]([url](https://github.com/YbencheL/push_swap/new/main?filename=README.md#bonus-features))

* [Project Structure]([url](https://github.com/YbencheL/push_swap/new/main?filename=README.md#project-structure))

* [Error Management]([url](https://github.com/YbencheL/push_swap/new/main?filename=README.md#error-management))


## Project Overview


### Implementation

*Data Structure*

```
typedef struct s_list
{
    int             value;
    int             index;
    struct s_list   *next;
}                   t_list;
```

### Available Operations


**sa**: Swap the first two elements of stack A

**sb**: Swap the first two elements of stack B*

**ss**: sa and sb at the same time*

**pa**: Push the first element of stack B onto stack A*

**pb**: Push the first element of stack A onto stack B*

**ra**: Rotate stack A (first element becomes last)*

**rb**: Rotate stack B (first element becomes last)*

**rr**: ra and rb at the same time*

**rra**: Reverse rotate stack A (last element becomes first)*

**rrb**: Reverse rotate stack B (last element becomes first)*

**rrr**: rra and rrb at the same time


# Algorithm


I implemented different sorting strategies based on the size of the input:

For 3 numbers: Custom algorithm using maximum 2-3 operations.
For 5 numbers: Optimized algorithm using the previous sorting 3 function functions.
For larger sets: Implemented an efficient algorithm using chunks creating two function push to b and push to a pushing all numbers that belong to the smallest range first then pushing back the largest or second to largest numbers back to stack .

### Installation


```
git clone <repository-url>
cd push_swap
make
```


### Usage


```
./push_swap 2 1 3 6 5 8
```


### For checker (bonus):


```
./checker 2 1 3 6 5 8
```


# Bonus Features


I implemented a checker program that:

Takes the stack A as an argument
Reads instructions from standard input
Executes these instructions
Displays "OK" if the stack is sorted, "KO" if it's not
Performance
My implementation achieves the following average operations:

3 numbers: ≤ 3 operations
5 numbers: ≤ 12 operations
100 numbers: ≤ 700 operations
500 numbers: ≤ 5500 operations

### Project Structure


```
.
├── Makefile
├── push_swap.h
├── bonus/
│   ├── checker_bonus.c
│   └── get_next_line/
├── code/
│   ├── actions1.c
│   ├── actions2.c
│   ├── error_utils.c
│   ├── extra_utils.c
│   ├── push_swap.c
│   ├── sorting_algo.c
│   ├── super_actions.c
│   └── utils.c
└── src/
    ├── ft_atoi.c
    ├── ft_lstsize.c
    ├── ft_memcpy.c
    ├── ft_split.c
    ├── ft_strcmp.c
    ├── ft_strdup.c
    ├── ft_strlen.c
    └── ft_substr.c
```

## Error Management


The program handles various error cases:

Non-numeric arguments
Numbers bigger than INT_MAX or smaller than INT_MIN
Duplicate numbers
Invalid instructions (for checker)

### Contributing


This was part of my 42 school curriculum project. However, if you notice any bugs or improvements, feel free to open an issue.
