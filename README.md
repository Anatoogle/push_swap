# push_swap

A sorting algorithm project from the 42 curriculum focused on stack manipulation, optimization, and algorithmic efficiency.

## About

Push_swap is a project at 42 that challenges students to sort a list of integers using two stacks and a limited set of operations.

The goal is to:
- Sort numbers with the minimum number of operations
- Design efficient algorithms
- Improve understanding of data structures and complexity
- Work with parsing, memory management, and edge cases in C

## Project Rules

You have:
- Stack **A** (contains random integers)
- Stack **B** (initially empty)

You must sort Stack A in ascending order using only the allowed operations.

## Allowed Operations

### Swap
- `sa` — swap first 2 elements of stack A
- `sb` — swap first 2 elements of stack B
- `ss` — `sa` and `sb` at the same time

### Push
- `pa` — push top element from B to A
- `pb` — push top element from A to B

### Rotate
- `ra` — shift up all elements of A by 1
- `rb` — shift up all elements of B by 1
- `rr` — `ra` and `rb` at the same time

### Reverse Rotate
- `rra` — shift down all elements of A by 1
- `rrb` — shift down all elements of B by 1
- `rrr` — `rra` and `rrb` at the same time

---

## Features

- Argument parsing and validation
- Duplicate detection
- Error handling
- Stack implementation using linked lists
- Optimized sorting strategies
- Small-size sorting optimization
- Large dataset sorting
- Memory leak free

---

## Algorithms

### Small Inputs
For very small stacks:
- Hardcoded optimal sorting
- Minimal instruction count

### Large Inputs
For larger datasets:
- During this project, I learned about different sorting approaches such as Radix Sort and chunk-based algorithms.
- For my implementation, I chose to study and rebuild the algorithm explained in this article:
- https://medium.com/@ayogun/push-swap-c1f5d2d41e97

- After studying the algorithm, I rebuilt the logic entirely in C and adapted it to fit my own project structure and implementation style.

---

## Compilation

### Available rules:
```bash
make
make bonus
make clean
make fclean
make re
```

---

## Example

```bash
./push_swap 2 1 3 6 5 8
```
- Output:
- `sa`
- `pb`
- `ra`
- `pa`

## Compliance

This project was developed in compliance with the requirements and constraints of the 42 network, respecting the imposed coding standards, allowed functions, and project guidelines.
