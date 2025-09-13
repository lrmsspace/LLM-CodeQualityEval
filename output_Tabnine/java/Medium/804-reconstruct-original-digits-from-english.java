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
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }
        StringBuilder sb = new StringBuilder();
        int[] nums = {0, 2, 4, 6, 8, 3, 5, 7, 9};
        for (int num : nums) {
            while (count[num - 'a'] > 0) {
                sb.append(num);
                for (char c : s.toCharArray()) {
                    if (c - 'a' == num - 'a') {
                        count[c - 'a']--;
                    }
                }
            }
        }
        return sb.toString();   
    }
}