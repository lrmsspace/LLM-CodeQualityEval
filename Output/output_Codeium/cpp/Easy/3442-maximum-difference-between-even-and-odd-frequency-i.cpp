/*
 You are given a string s consisting of lowercase English letters.
 Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:
 a1 has an odd frequency in the string.
 a2 has an even frequency in the string.
 Return this maximum difference.
 Example 1:
 Input: s = "aaaaabbc"
 Output: 3
 Explanation:
 The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
 The maximum difference is 5 - 2 = 3.
 Example 2:
 Input: s = "abcabcab"
 Output: 1
 Explanation:
 The character 'a' has an odd frequency of 3, and 'c' has an even frequency of 2.
 The maximum difference is 3 - 2 = 1.
 Constraints:
 3 <= s.length <= 100
 s consists only of lowercase English letters.
 s contains at least one character with an odd frequency and one with an even frequency.
*/

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            ++freq[c];
        }
        int maxDiff = 0;
        for (auto it1 = freq.begin(); it1 != freq.end(); ++it1) {
            for (auto it2 = next(it1); it2 != freq.end(); ++it2) {
                if (it1->second % 2 != it2->second % 2) {
                    maxDiff = max(maxDiff, abs(it1->second - it2->second));
                }
            }
        }
        return maxDiff;
    }
};