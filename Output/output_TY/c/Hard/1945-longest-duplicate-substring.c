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
char * longestDupSubstring(char * s){   

    int n = strlen(s);
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        char *p = strstr(s, s + mid);
        if (p) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return s + l;
}