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
    public String longestDupSubstring(String s)
    {
        int left = 1, right = s.length();
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            String dup = search(mid, s);
            if (dup != null)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return search(right, s);
    
    }
}