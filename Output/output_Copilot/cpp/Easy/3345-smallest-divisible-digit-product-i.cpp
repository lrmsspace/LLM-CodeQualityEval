/*
 You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.
 Example 1:
 Input: n = 10, t = 2
 Output: 10
 Explanation:
 The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.
 Example 2:
 Input: n = 15, t = 3
 Output: 16
 Explanation:
 The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.
 Constraints:
 1 <= n <= 100
 1 <= t <= 10
*/

class Solution {
public:
    int smallestNumber(int n, int t) {
        // If t is 10, the smallest number with a digit product divisible by 10 is 10
        if (t == 10) {
            return n <= 10 ? 10 : -1; // If n is less than or equal to 10, return 10, otherwise return -1
        }

        // Start checking from n
        for (int i = n; i <= 100; ++i) {
            int product = 1;
            int num = i;

            // Calculate the product of digits
            while (num > 0) {
                product *= (num % 10);
                num /= 10;
            }

            // Check if the product is divisible by t
            if (product % t == 0) {
                return i; // Return the first number found
            }
        }

        return -1; // If no such number is found, return -1
        
    }
};