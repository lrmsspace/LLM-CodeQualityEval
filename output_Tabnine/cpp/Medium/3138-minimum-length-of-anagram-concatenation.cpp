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
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int count = 0;
        for (int f : freq) {
            count += f / 2;
        }
        
        int minLen = s.length();
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']--;
            if (freq[s[i] - 'a'] % 2 == 1) {
                count++;
            }
            while (count <= s.length() / 2) {
                minLen = min(minLen, i + 1);
                freq[s[i - minLen] - 'a']++;
                if (freq[s[i - minLen] - 'a'] % 2 == 0) {
                    count--;
                }
            }

            freq[s[i] - 'a']++;
            if (freq[s[i] - 'a'] % 2 == 1) {
                count--;
            }
        }
        return minLen;
        
    }
};