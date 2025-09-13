/*
 You are given a string s, which is known to be a concatenation of anagrams of some string t.
 Return the minimum possible length of the string t.
 An anagram is formed by rearranging the letters of a string. For example, "aab", "aba", and, "baa" are anagrams of "aab".
 Example 1:
 Input: s = "abba"
 Output: 2
 Explanation:
 One possible string t could be "ba".
 Example 2:
 Input: s = "cdef"
 Output: 4
 Explanation:
 One possible string t could be "cdef", notice that t can be equal to s.
 Example 2:
 Input: s = "abcbcacabbaccba"
 Output: 3
 Constraints:
 1 <= s.length <= 105
 s consist only of lowercase English letters.
*/

class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        int ans = n;
        vector<int> freq(26, 0);
        for (char ch: s) {
            freq[ch - 'a']++;
        }
        int left = 0, right = 0;
        int count = n;
        while (right < n) {
            char ch = s[right];
            freq[ch - 'a']--;
            if (freq[ch - 'a'] == 0) {
                count--;
            }
            right++;
            while (count == 0) {
                ans = min(ans, right - left);
                char ch = s[left];
                freq[ch - 'a']++;
            }
        }
        return ans;
        
    }
};