/*
 You are given two strings word1 and word2.
 A string x is called valid if x can be rearranged to have word2 as a prefix.
 Return the total number of valid substrings of word1.
 Example 1:
 Input: word1 = "bcca", word2 = "abc"
 Output: 1
 Explanation:
 The only valid substring is "bcca" which can be rearranged to "abcc" having "abc" as a prefix.
 Example 2:
 Input: word1 = "abcabc", word2 = "abc"
 Output: 10
 Explanation:
 All the substrings except substrings of size 1 and size 2 are valid.
 Example 3:
 Input: word1 = "abcabc", word2 = "aaabc"
 Output: 0
 Constraints:
 1 <= word1.length <= 105
 1 <= word2.length <= 104
 word1 and word2 consist only of lowercase English letters.
*/

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> word2_count(26, 0), window_count(26, 0);
        for (char c : word2) {
            word2_count[c - 'a']++;
        }
        
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            window_count[word1[i] - 'a']++;
            if (i >= m) {
                window_count[word1[i - m] - 'a']--;
            }
            bool is_valid = true;
            for (int j = 0; j < 26; ++j) {
                if (window_count[j] < word2_count[j]) {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid) {
                result++;
            }
        }
        return result;

    }
};