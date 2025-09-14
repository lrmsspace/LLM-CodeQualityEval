/**https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/ */
//You are given an array of strings words and a string chars.
//A string is good if it can be formed by characters from chars (each character can only be used once).
//Return the sum of lengths of all good strings in words.
// 
//Example 1:
//Input: words = ["cat","bt","hat","tree"], chars = "atach"
//Output: 6
//Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
//Example 2:
//Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
//Output: 10
//Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
// 
//Constraints:
//	1 <= words.length <= 1000
//	1 <= words[i].length, chars.length <= 100
//	words[i] and chars consist of lowercase English letters.
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        vector<int> chars_count(26, 0);
        for (char c : chars) {
            chars_count[c - 'a']++;
        }
        for (string word : words) {
            vector<int> word_count(26, 0);
            bool is_good = true;
            for (char c : word) {
                word_count[c - 'a']++;
                if (word_count[c - 'a'] > chars_count[c - 'a']) {
                    is_good = false;
                    break;
                }
            }
            if (is_good) {
                res += word.size();
            }
        }
        return res;        
    }
};