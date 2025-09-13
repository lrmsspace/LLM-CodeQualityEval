/*
 Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
 You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.
 Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.
 Since the answer may be very large, return it modulo 109 + 7.
 Example 1:
 Input: word = "aabbccdd", k = 7
 Output: 5
 Explanation:
 The possible strings are: "aabbccdd", "aabbccd", "aabbcdd", "aabccdd", and "abbccdd".
 Example 2:
 Input: word = "aabbccdd", k = 8
 Output: 1
 Explanation:
 The only possible string is "aabbccdd".
 Example 3:
 Input: word = "aaabbb", k = 3
 Output: 8
 Constraints:
 1 <= word.length <= 5 * 105
 word consists only of lowercase English letters.
 1 <= k <= 2000
*/

class Solution {
public:
    int possibleStringCount(string word, int k) {
        const int MOD = 1e9 + 7;
        int n = word.length();
        if (n < k) return 0;

        // Count the frequency of each character
        unordered_map<char, int> freq;
        for (char c : word) {
            freq[c]++;
        }

        // Calculate the number of distinct characters
        int distinctCount = freq.size();

        // Calculate the number of possible original strings
        long long result = 1;
        for (const auto& [c, count] : freq) {
            result = (result * (count + 1)) % MOD; // Each character can be included or not
        }

        // Subtract the cases where the length is less than k
        if (distinctCount < k) {
            result = (result - 1 + MOD) % MOD; // Exclude the empty string case
        }

        return static_cast<int>(result);
        
    }
};