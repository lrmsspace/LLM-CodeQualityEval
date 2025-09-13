/**https://leetcode.com/problems/sum-of-unique-elements/ */
//You are given an integer array nums. The unique elements of an array are the elements that appear exactly once in the array.
//Return the sum of all the unique elements of nums.
// 
//Example 1:
//Input: nums = [1,2,3,2]
//Output: 4
//Explanation: The unique elements are [1,3], and the sum is 4.
//Example 2:
//Input: nums = [1,1,1,1,1]
//Output: 0
//Explanation: There are no unique elements, and the sum is 0.
//Example 3:
//Input: nums = [1,2,3,4,5]
//Output: 15
//Explanation: The unique elements are [1,2,3,4,5], and the sum is 15.
// 
//Constraints:
//	1 <= nums.length <= 100
//	1 <= nums[i] <= 100
class Solution {
    public int sumOfUnique(int[] nums) {
        int[] count = new int[101]; // Initialize a count array to store the frequency of each number (1-100)
        for (int num : nums) {
            count[num]++; // Increment the count for each number in the input array
        }
        int sum = 0; // Initialize sum to 0
        for (int i = 1; i <= 100; i++) { // Iterate through the count array
            if (count[i] == 1) { // If the count is 1, it means the number is unique
                sum += i; // Add the unique number to the sum
            }
        }
        return sum; // Return the final sum of unique elements        
    }
}