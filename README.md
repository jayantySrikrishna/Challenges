# Challenges

# Last3digits

Per is obsessed with factorials. He likes to calculate them, estimate them, read about them, draw them, dream about them and fight about them. He even has the value of 12!=47900160012!=479001600 tattooed on his back.

He noticed a long time ago that factorials have many trailing zeroes and also wrote a program to calculate the number of trailing zeroes. For example 12!12! ends with 600, so it has 2 trailing zeroes. Now he wants to make one step further, look at the 3 digits right before the trailing zeroes. In the case of 12!12!, the last 3 digits before the trailing zeroes are 016016.

Task
Given an integer nn, find the last 3 digits before the trailing zeroes in n!n!. If there are fewer then 3 such digits, find all of them.

Input
The input contains one line with one integer nn (1≤n≤100000001≤n≤10000000).

Output
Output one line with the 3 digits before trailing zeroes of n!n!. If there are fewer than 3 such digits, output all of them.

Sample Input 1	Sample Output 1
5                 12
Sample Input 2	Sample Output 2
14                912


# Polish Notation
One way of representing mathematical expressions is with Polish (or prefix) notation, initially developed by Jan Łukasiewicz (1878–1956) for use in logic. In this notation, the operator appears before its operands. For example, rather than writing

                                3 + 4 ∗ 73 + 4 ∗ 7
using so-called infix notation, we could write the equivalent expression in Polish notation

                                + 3 ∗ 4 7+ 3 ∗ 4 7
In this example, the addition applies to the values of the two following expressions, ‘33’ and ‘∗ 4 7∗ 4 7’. Further, the multiplication applies to two values that follow it, 44 and 77.

In general, we can write an expression in Polish notation using the following rules:

A constant integer is an expression (e.g. 33).

A lowercase single character is an expression (a variable, e.g. xx).

If AA and BB are expressions and OO is an operator, then the following is an expression: ‘O A BO A B’. The meaning of this expression in infix notation is ‘A O BA O B’.

The operators that can occur are all binary: addition (++), subtraction (−−), and multiplication (∗∗).

Polish notation has the advantage of being easy to parse for a computer. Write a program that reads an expression in Polish notation, simplifies the expression as much as possible, and prints it out in Polish notation. The simplification procedure is just replacing subexpressions that contain no variables with their values wherever possible.

Input
Input consists of several test cases (at most 55). Each test case is described by a single line containing an expression. The expression is a sequence of space-separated tokens (integers, operators, and single-character lowercase variables). Each expression is correctly formatted in Polish notation, with at most 20482048 symbols (operators and operands combined). Integer constants are in the range [−10,10][−10,10].

Output
For each case, display the case number followed by the simplified expression in Polish notation, in the same format as the input. Do not modify the expression other than the simplification step described earlier. All intermediate computations fit within a signed 3232-bit integer. Follow the format of the sample output.

Sample Input 1	                      Sample Output 1
+ 3 4                                    Case 1: 7
- x x                                    Case 2: - x x
* - 6 + x -6 - - 9 6 * 0 c               Case 3: * - 6 + x -6 - 3 * 0 c
