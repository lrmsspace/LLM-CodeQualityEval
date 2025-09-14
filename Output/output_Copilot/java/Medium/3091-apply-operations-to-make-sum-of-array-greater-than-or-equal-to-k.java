/*
 You are given a positive integer k. Initially, you have an array nums = [1].
 You can perform any of the following operations on the array any number of times (possibly zero):
 Choose any element in the array and increase its value by 1.
 Duplicate any element in the array and add it to the end of the array.
 Return the minimum number of operations required to make the sum of elements of the final array greater than or equal to k.
 Example 1:
 Input: k = 11
 Output: 5
 Explanation:
 We can do the following operations on the array nums = [1]:
 Increase the element by 1 three times. The resulting array is nums = [4].
 Duplicate the element two times. The resulting array is nums = [4,4,4].
 The sum of the final array is 4 + 4 + 4 = 12 which is greater than or equal to k = 11.
 The total number of operations performed is 3 + 2 = 5.
 Example 2:
 Input: k = 1
 Output: 0
 Explanation:
 The sum of the original array is already greater than or equal to 1, so no operations are needed.
 Constraints:
 1 <= k <= 105
*/

class Solution {
    public int minOperations(int k) {
        int operations = 0;
        int sum = 1; // Initial sum is 1 (from the array [1])
        int maxElement = 1; // The maximum element in the array

        while (sum < k) {
            // If the current sum is less than k, we need to perform operations
            // We can either increase the max element or duplicate it
            if (maxElement < k - sum) {
                // If the max element is less than the remaining needed to reach k,
                // we can duplicate it
                sum += maxElement;
                operations++;
            } else {
                // Otherwise, we need to increase the max element
                maxElement++;
                sum += maxElement;
                operations++;
            }
        }

        return operations;
    }
}