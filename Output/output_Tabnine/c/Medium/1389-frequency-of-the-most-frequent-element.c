/**https://leetcode.com/problems/frequency-of-the-most-frequent-element/ */
//The frequency of an element is the number of times it occurs in an array.
//You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.
//Return the maximum possible frequency of an element after performing at most k operations.
// 
//Example 1:
//Input: nums = [1,2,4], k = 5
//Output: 3
//Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
//4 has a frequency of 3.
//Example 2:
//Input: nums = [1,4,8,13], k = 5
//Output: 2
//Explanation: There are multiple optimal solutions:
//- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
//- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
//- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.
//Example 3:
//Input: nums = [3,9,6], k = 2
//Output: 1
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 105
//	1 <= k <= 105
int maxFrequency(int* nums, int numsSize, int k) {
    // Create a frequency map to store the frequency of each number
    int freq[10001] = {0};
    for (int num : nums) {
        freq[num]++;
    }
    
    // Initialize variables
    int maxFreq = 0;
    int maxCount = 0;
    
    // Iterate through the frequency map
    for (int i = 1; i <= 10000; i++) {
        // Calculate the number of operations needed to increment the current number by k
        int ops = k / freq[i];
        
        // Update the maximum frequency and count
        maxFreq = fmax(maxFreq, freq[i] + ops);
        maxCount = fmax(maxCount, freq[i] + ops);
        
        // Update the remaining operations for the next iteration
        k -= freq[i] * ops;
    }
    
    // Return the maximum possible frequency
    return maxCount;
    
}