<p align="center">
	<img alt="GitHub Repo stars" src="https://img.shields.io/github/stars/ferri17/push_swap?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/ferri17/push_swap" />
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/ferri17/push_swap?color=red" />
	<img alt="GitHub last commit (by committer)" src="https://img.shields.io/github/last-commit/ferri17/push_swap" />
	<img alt="MacOS compatibility" src="https://img.shields.io/badge/macOS-compatible-brightgreen.svg" />
</p>

<h3 align="center">Push swap (42 School)</h3>

  <p align="center">
    Push swap is a project about stack sorting algorithms. Using only 2 stacks and a initial set of numbers 
    it must sort all numbers in ascendant order in the smallest number of instructions possible.
    <br/>
  </p>
</div>

<!-- ABOUT THE PROJECT -->
## About The Project
<img width="700" alt="Screenshot 2023-09-24 at 23 25 34" src="https://github.com/ferri17/push_swap/assets/19575860/a239668a-c2c0-4618-b4b2-8025abacb686">

**Push swap** takes any set of numbers as arguments and prints every instruction needed to sort all numbers. 
There are 2 stacks, stack A and stack B. Initially all numbers are pushed into stack A, stack B remains empty. 
Push swap needs to find the smallest set of instructions to sort the numbers with the help of stack B. The limited 
set of instructions that can be used to sort the stack are these:

- **sa (swap a)**: *Swap the first 2 elements at the top of stack a.
  Do nothing if there is only one or no elements.*
  
- **sb (swap b)**: *Swap the first 2 elements at the top of stack b.
  Do nothing if there is only one or no elements.*
  
- **ss**: *sa and sb at the same time.*
  
- **pa (push a)**: *Take the first element at the top of b and put it at the top of a.
  Do nothing if b is empty.*
  
- **pb (push b)**: *Take the first element at the top of a and put it at the top of b.
  Do nothing if a is empty.*
  
- **ra (rotate a)**: *Shift up all elements of stack a by 1.
  The first element becomes the last one.*
  
- **rb (rotate b)**: *Shift up all elements of stack b by 1.
  The first element becomes the last one.*
  
- **rr**: *ra and rb at the same time.*
  
- **rra (reverse rotate a)**: *Shift down all elements of stack a by 1.
  The last element becomes the first one.*
  
- **rrb (reverse rotate b)**: *Shift down all elements of stack b by 1.
  The last element becomes the first one.*
  
- **rrr**: *rra and rrb at the same time.*

<!-- HOW TO USE -->
## How to use

The program can be executed like this `./push_swap 5 0 -1 2 3` or `./push_swap "5 0 -1 2 3"`

In order to test if push swap is correctly sorting the numbers **another executable was created, the checker.** This second
program needs to be executed after push swap through a pipe and passing the same arguments as the first. **It will read
the set of instructions sent by push swap** and check if that set **correctly sorts the numbers**, it should be executed like this:

`ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG`

If push swap printed a correct set of instructions the checker prints 'OK', if the set doesn't sort the numbers it will print 'KO'.
In case there is an error in the arguments, like duplicated numbers, it prints 'Error'.

<!-- GETTING STARTED -->
## Getting Started
In order to run the program first clone the repository:
```bash
git clone git@github.com:ferri17/push_swap.git
```
Open the folder:
```bash
cd push_swap/
```
Compile the program:
```bash
make
```
Run the program:
```bash
./push_swap "3 1 2"
```
To compile the checker program use:
```bash
make bonus
```
