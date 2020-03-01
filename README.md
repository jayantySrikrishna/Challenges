# Challenges

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
