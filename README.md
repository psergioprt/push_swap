# 🔢 push_swap

**push_swap** is a core project at 42 that challenges you to sort data stored in stacks using a limited set of operations.  
The objective is to output the shortest possible sequence of moves that sorts a list of integers in ascending order.

---

## 🧩 Project Overview

- The program works with **two stacks**, usually named **A** and **B**.
- Initially, all integers are in stack A in an unsorted order.
- The goal is to sort stack A by applying a set of allowed operations that move or swap elements between and within the stacks.
- Allowed operations include:
  - **swap**: swap the first two elements of a stack.
  - **push**: move the top element from one stack to the other.
  - **rotate**: shift all elements of a stack up by one, moving the first element to the bottom.
  - **reverse rotate**: shift all elements down by one, moving the last element to the top.
- The fewer operations used, the better the score.

---

## 🔧 Features

- Input parsing and validation: checks for duplicates, non-numeric inputs, and overflow.
- Efficient sorting algorithms tailored for stacks.
- Handles different input sizes with optimized strategies:
  - Small sets: hardcoded efficient sequences.
  - Large sets: advanced algorithms to minimize operations.
- Optional **checker** program to verify the correctness of the sorting commands.

---

## ⚙️ Compilation

Use the provided Makefile to compile:

bash
make

## ▶️ Usage
- ./push_swap 9 2 5 7 3
- The program outputs a sequence of operations, e.g.:
pb
sa
ra
pa

If you have the checker program compiled, you can verify the solution:
./push_swap 9 2 5 7 3 | ./checker 9 2 5 7 3
checker will output OK if the sequence sorts correctly, or KO otherwise.

📌 Learning Outcomes

This project strengthens your grasp of:

    Algorithm design under constraints.

    Stack data structure manipulation.

    Writing efficient, optimized C code.

    Error handling and input validation.

    Problem-solving with limited operation sets.
