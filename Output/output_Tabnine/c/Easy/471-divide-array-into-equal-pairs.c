/**https://leetcode.com/problems/divide-array-into-equal-pairs/ */
//You are given an integer array nums consisting of 2 * n integers.
//You need to divide nums into n pairs such that:
//	Each element belongs to exactly one pair.
//	The elements present in a pair are equal.
//Return true if nums can be divided into n pairs, otherwise return false.
// 
//Example 1:
//Input: nums = [3,2,3,2,2,2]
//Output: true
//Explanation: 
//There are 6 elements in nums, so they should be divided into 6 / 2 = 3 pairs.
//If nums is divided into the pairs (2, 2), (3, 3), and (2, 2), it will satisfy all the conditions.
//Example 2:
//Input: nums = [1,2,3,4]
//Output: false
//Explanation: 
//There is no way to divide nums into 4 / 2 = 2 pairs such that the pairs satisfy every condition.
// 
//Constraints:
//	nums.length == 2 * n
//	1 <= n <= 500
//	1 <= nums[i] <= 500
bool divideArray(int* nums, int numsSize) {
    // Initialize a frequency map to count the occurrence of each number
    int freq[501] = {0};
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }
    
    // Check if there is any number that occurs odd number of times
    for (int i = 1; i <= 500; i++) {
        if (freq[i] % 2!= 0) {
            return false;
        }
    }
    
    // Check if the sum of all numbers is even
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    if (sum % 2!= 0) {
        return false;
    }
    
    return true;  // If all conditions are satisfied, return true
    
}