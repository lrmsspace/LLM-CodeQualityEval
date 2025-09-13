/**https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/ */
//Given an integer k, return the minimum number of Fibonacci numbers whose sum is equal to k. The same Fibonacci number can be used multiple times.
//The Fibonacci numbers are defined as:
//	F1 = 1
//	F2 = 1
//	Fn = Fn-1 + Fn-2 for n > 2.
//It is guaranteed that for the given constraints we can always find such Fibonacci numbers that sum up to k.
// 
//Example 1:
//Input: k = 7
//Output: 2 
//Explanation: The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ... 
//For k = 7 we can use 2 + 5 = 7.
//Example 2:
//Input: k = 10
//Output: 2 
//Explanation: For k = 10 we can use 2 + 8 = 10.
//Example 3:
//Input: k = 19
//Output: 3 
//Explanation: For k = 19 we can use 1 + 5 + 13 = 19.
// 
//Constraints:
//	1 <= k <= 109
int findMinFibonacciNumbers(int k) {
    // Initialize the first two Fibonacci numbers
    int fib1 = 1, fib2 = 1;
    
    // Count the number of Fibonacci numbers needed to sum up to k
    int count = 2;
    
    // While the sum of the current Fibonacci numbers is less than or equal to k
    while (fib1 + fib2 <= k) {
        // Update the current Fibonacci numbers
        int temp = fib2;
        fib2 = fib1 + fib2;
        fib1 = temp;
        
        // Increment the count of Fibonacci numbers
        count++;
    }
    
    // Return the minimum number of Fibonacci numbers needed to sum up to k
    return count;
    
}