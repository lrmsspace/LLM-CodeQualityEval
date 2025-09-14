/**https://leetcode.com/problems/reconstruct-original-digits-from-english/ */
//Given a string s containing an out-of-order English representation of digits 0-9, return the digits in ascending order.
// 
//Example 1:
//Input: s = "owoztneoer"
//Output: "012"
//Example 2:
//Input: s = "fviefuro"
//Output: "45"
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is one of the characters ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
//	s is guaranteed to be valid.
class Solution {
    public String originalDigits(String s) {
        Map<Character, Integer> count = new HashMap<>();
        for (char c : s.toCharArray()) {
            count.put(c, count.getOrDefault(c, 0) + 1);
        }
        int[] nums = new int[10];
        nums[0] = count.getOrDefault('z', 0);
        nums[2] = count.getOrDefault('w', 0);
        nums[4] = count.getOrDefault('u', 0);
        nums[6] = count.getOrDefault('x', 0);
        nums[8] = count.getOrDefault('g', 0);
        nums[1] = count.getOrDefault('o', 0) - nums[0] - nums[2] - nums[4];
        nums[3] = count.getOrDefault('h', 0) - nums[8];
        nums[5] = count.getOrDefault('f', 0) - nums[4];
        nums[7] = count.getOrDefault('s', 0) - nums[6];
        nums[9] = count.getOrDefault('i', 0) - nums[5] - nums[6] - nums[8];
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 10; i++) {
            while (nums[i]-- > 0) {
                sb.append(i);
            }
        }
        return sb.toString();
    }
}