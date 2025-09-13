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
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        int start = 0, end = n - 1, mid, max_len = 0, pos = 0;
        while (start <= end) {
            mid = start + (end - start) / 2;
            string sub = s.substr(0, mid);
            int i = 0;
            bool found = false;
            while (i <= n - mid) {
                if (s.substr(i, mid) == sub) {
                    found = true;
                    break;
                }
                i++;
            }
            if (found) {
                start = mid + 1;
                if (mid > max_len) {
                    max_len = mid;
                    pos = i;
                }
            }
            else end = mid - 1;
        }
        return s.substr(pos, max_len);
    }
};