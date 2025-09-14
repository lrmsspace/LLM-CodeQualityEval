/**https://leetcode.com/problems/find-unique-binary-string/ */
//Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.
// 
//Example 1:
//Input: nums = ["01","10"]
//Output: "11"
//Explanation: "11" does not appear in nums. "00" would also be correct.
//Example 2:
//Input: nums = ["00","01"]
//Output: "11"
//Explanation: "11" does not appear in nums. "10" would also be correct.
//Example 3:
//Input: nums = ["111","011","001"]
//Output: "101"
//Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 16
//	nums[i].length == n
//	nums[i] is either '0' or '1'.
//	All the strings of nums are unique.
class Solution {
    public String findDifferentBinaryString(String[] nums) {
        int n = nums[0].length();
        int[] count = new int[2 << n];
        
        for (String num : nums) {
            int val = 0;
            for (int i = 0; i < n; i++) {
                val |= (num.charAt(i) - '0') << i;
            }
            count[val]++;
        }
        
        for (int i = 0; i < (1 << n); i++) {
            if (count[i] == 0) {
                return Integer.toBinaryString(i).substring(n - 1, n);
            }
        }
        
        return "";  // should never reach here, but added for completeness
        
    }
}