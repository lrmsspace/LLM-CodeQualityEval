/*
 You are given a string word and a non-negative integer k.
 Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.
 Example 1:
 Input: word = "aeioqq", k = 1
 Output: 0
 Explanation:
 There is no substring with every vowel.
 Example 2:
 Input: word = "aeiou", k = 0
 Output: 1
 Explanation:
 The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".
 Example 3:
 Input: word = "ieaouqqieaouqq", k = 1
 Output: 3
 Explanation:
 The substrings with every vowel and one consonant are:
 word[0..5], which is "ieaouq".
 word[6..11], which is "qieaou".
 word[7..12], which is "ieaouq".
 Constraints:
 5 <= word.length <= 2 * 105
 word consists only of lowercase English letters.
 0 <= k <= word.length - 5
*/

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        int v = 0, c = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < k; i++) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                v++;
            } else {
                c++;
            }
            mp[word[i]]++;
        }
        long long ans = 0;
        if (v > 0 && c >= k) {
            ans++;
        }
        for (int i = k; i < n; i++) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                v++;
            } else {
                c++;
            }
            mp[word[i]]++;
            if (mp[word[i - k]] == 1) {
                if (word[i - k] == 'a' || word[i - k] == 'e' || word[i - k] == 'i' || word[i - k] == 'o' || word[i - k] == 'u') {
                    v--;
                } else {
                    c--;
                }
                mp[word[i - k]]--;
            } else {
                mp[word[i - k]]--;
            }
            if (v > 0 && c >= k) {
                ans++;
            }
        }
        return ans;

            
    }
};