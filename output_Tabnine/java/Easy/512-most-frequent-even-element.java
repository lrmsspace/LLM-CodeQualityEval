/**https://leetcode.com/problems/most-frequent-even-element/ */
//Given an integer array nums, return the most frequent even element.
//If there is a tie, return the smallest one. If there is no such element, return -1.
// 
//Example 1:
//Input: nums = [0,1,2,2,4,4,1]
//Output: 2
//Explanation:
//The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
//We return the smallest one, which is 2.
//Example 2:
//Input: nums = [4,4,4,9,2,4]
//Output: 4
//Explanation: 4 is the even element appears the most.
//Example 3:
//Input: nums = [29,47,21,41,13,37,25,7]
//Output: -1
//Explanation: There is no even element.
// 
//Constraints:
//	1 <= nums.length <= 2000
//	0 <= nums[i] <= 105
class Solution {
    public int mostFrequentEven(int[] nums) {
        Map<Integer, Integer> freqMap = new HashMap<>();
        for (int num : nums) {
            if (num % 2 == 0) {
                freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
            }
        }
        
        int maxCount = 0;
        int mostFrequentEven = -1;
        for (Map.Entry<Integer, Integer> entry : freqMap.entrySet()) {
            if (entry.getValue() > maxCount && entry.getKey() % 2 == 0) {
                maxCount = entry.getValue();
                mostFrequentEven = entry.getKey();
            }
        }
        
        return mostFrequentEven;
        
    }
}