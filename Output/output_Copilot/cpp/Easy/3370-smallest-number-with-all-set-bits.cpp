/*
 You are given a positive number n.
 Return the smallest number x greater than or equal to n, such that the binary representation of x contains only set bits
 Example 1:
 Input: n = 5
 Output: 7
 Explanation:
 The binary representation of 7 is "111".
 Example 2:
 Input: n = 10
 Output: 15
 Explanation:
 The binary representation of 15 is "1111".
 Example 3:
 Input: n = 3
 Output: 3
 Explanation:
 The binary representation of 3 is "11".
 Constraints:
 1 <= n <= 1000
*/

class Solution {
public:
    int smallestNumber(int n) {
        // Start from n and find the next number with all set bits
        for (int i = n; ; ++i) {
            int num = i;
            bool allSetBits = true;

            // Check if all bits in the binary representation are set
            while (num > 0) {
                if (num & 1 == 0) {
                    allSetBits = false;
                    break;
                }
                num >>= 1; // Right shift to check the next bit
            }

            if (allSetBits) {
                return i; // Return the first number found with all set bits
            }
        }
        return -1; // This line will never be reached, but it's good practice to have a return statement
        
    }
};