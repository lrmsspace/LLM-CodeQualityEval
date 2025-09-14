/**https://leetcode.com/problems/longest-duplicate-substring/ */
//Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.
//Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".
// 
//Example 1:
//Input: s = "banana"
//Output: "ana"
//Example 2:
//Input: s = "abcd"
//Output: ""
// 
//Constraints:
//	2 <= s.length <= 3 * 104
//	s consists of lowercase English letters.
class Solution {
    public String longestDupSubstring(String s) {
        int n = s.length(), l = 1, r = n - 1, start = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (search(s, mid) != -1) {
                start = search(s, mid);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return start == -1 ? "" : s.substring(start, start + l - 1);        
    }
}