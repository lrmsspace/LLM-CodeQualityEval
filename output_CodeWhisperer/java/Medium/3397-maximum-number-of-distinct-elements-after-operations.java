/*
import java.util.HashMap;
 You are given an integer array nums and an integer k.
 You are allowed to perform the following operation on each element of the array at most once:
 Add an integer in the range [-k, k] to the element.
 Return the maximum possible number of distinct elements in nums after performing the operations.
 Example 1:
 Input: nums = [1,2,2,3,3,4], k = 2
 Output: 6
 Explanation:
 nums changes to [-1, 0, 1, 2, 3, 4] after performing operations on the first four elements.
 Example 2:
 Input: nums = [4,4,4,4], k = 1
 Output: 3
 Explanation:
 By adding -1 to nums[0] and 1 to nums[1], nums changes to [3, 5, 4, 4].
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 109
 0 <= k <= 109
*/

class Solution {
    public int maxDistinctElements(int[] nums, int k) {
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        for (int num : nums) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }
        
        int distinctElements = freqMap.size();
        int maxDistinctElements = distinctElements;
        
        for (int freq : freqMap.values()) {
            if (freq > 1) {
                int operationsNeeded = freq - 1;
                if (operationsNeeded <= k) {
                    k -= operationsNeeded;
                    distinctElements--;
                } else {
                    break;
                }
            }
        }
        
        return distinctElements + k;
            
    }
}