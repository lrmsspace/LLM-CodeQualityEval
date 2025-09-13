/*
 You are given an integer array nums.
 Any positive divisor of a natural number x that is strictly less than x is called a proper divisor of x. For example, 2 is a proper divisor of 4, while 6 is not a proper divisor of 6.
 You are allowed to perform an operation any number of times on nums, where in each operation you select any one element from nums and divide it by its greatest proper divisor.
 Return the minimum number of operations required to make the array non-decreasing.
 If it is not possible to make the array non-decreasing using any number of operations, return -1.
 Example 1:
 Input: nums = [25,7]
 Output: 1
 Explanation:
 Using a single operation, 25 gets divided by 5 and nums becomes [5, 7].
 Example 2:
 Input: nums = [7,7,6]
 Output: -1
 Example 3:
 Input: nums = [1,1,1,1]
 Output: 0
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 106
*/

int minOperations(int* nums, int numsSize) {
    int operations = 0;
    int prev = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < prev) {
            // If the current number is less than the previous, we need to divide it
            // by its greatest proper divisor until it is at least as large as prev.
            int current = nums[i];
            while (current < prev) {
                // Find the greatest proper divisor
                int divisor = 1;
                for (int j = 2; j * j <= current; j++) {
                    if (current % j == 0) {
                        divisor = current / j;
                        break;
                    }
                }
                if (divisor == 1) {
                    // If no proper divisor found, we cannot make it non-decreasing
                    return -1;
                }
                current /= divisor;
                operations++;
            }
            nums[i] = current; // Update the current number after division
        }
        prev = nums[i]; // Update previous number for next iteration
    }

    return operations;    
}