<div align="center">
<img width=1000 hiegth=400 src="https://github.com/Mou-SED/LogosD/blob/master/push_swapD.png">
</div>

<hr/>

This project asks you to sort data on two stack (Stack_A, Stack_B), with a limited set of instructions, in as few moves as possible.

- In the sorting process, we should work the logic around some operations determined by the subject. Please find below the list of operations:

```
- sa :swap 'a' - swap the first 2 elements at the top of stack_a.
- sb :swap 'b' - swap the first 2 elements at the top of stack_b.
- ss :sa and sb at the same time.
- pa :push 'a' - take the first element at the top of 'b' and put it at the top of 'a'.
- pb :push 'b' - take the first element at the top of 'a' and put it at the top of 'b'.
- ra :rotate 'a' - shift up all elements of stack 'a' by 1.
- rb :rotate 'b' - shift up all elements of stack 'b' by 1.
- rr :ra and rb at the same time.
- rra :reverse rotate 'a' - shift down all elements of stack 'a' by 1.
- rrb :reverse rotate 'b' - shift down all elements of stack 'b' by 1.
- rrr :rra and rrb at the same time.

```

### Input of program
- List of integers
```sh
./push_swap [list of integers]
```
- This list must not have duplicates.
- This numbers must be encoded in 4 bytes.

### Output of program

- ( sa || ra || rra || sb... ) based on the algorithm and the instructions that must sort the list of integers.

```sh

	./push_swap [list of integers]
output:
	ra
	rra
	sa
	sb
	rrb
	pb
	pb...
```
## What is a Stack?
A stack is a linear data structure in which insertions and deletions are allowed only at the end, called the top of the stack.

## Why Linked List?
Use Linked List when the size of the stack is not known in advance.