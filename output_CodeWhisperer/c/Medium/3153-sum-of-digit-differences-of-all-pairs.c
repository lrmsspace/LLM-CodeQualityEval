/*
 You are given an array nums consisting of positive integers where all integers have the same number of digits.
 The digit difference between two integers is the count of different digits that are in the same position in the two integers.
 Return the sum of the digit differences between all pairs of integers in nums.
 Example 1:
 Input: nums = [13,23,12]
 Output: 4
 Explanation:
 We have the following:
 - The digit difference between 13 and 23 is 1.
 - The digit difference between 13 and 12 is 1.
 - The digit difference between 23 and 12 is 2.
 So the total sum of digit differences between all pairs of integers is 1 + 1 + 2 = 4.
 Example 2:
 Input: nums = [10,10,10,10]
 Output: 0
 Explanation:
 All the integers in the array are the same. So the total sum of digit differences between all pairs of integers will be 0.
 Constraints:
 2 <= nums.length <= 105
 1 <= nums[i] < 109
 All integers in nums have the same number of digits.
*/

long long sumDigitDifferences(int* nums, int numsSize) {
    int i, j, k, l;
    long long sum = 0;
    int count[10][10] = {0};
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (i != j) {
                for (k = 0; k < 10; k++) {
                    if (nums[i] / (int)pow(10, k) % 10 != nums[j] / (int)pow(10, k) % 10) {
                        count[k][nums[i] / (int)pow(10, k) % 10]++;
                    }
                }
            }
        }
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            sum += count[i][j];
        }
    }
    return sum;    
}