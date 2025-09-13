/**https://leetcode.com/problems/word-pattern/ */
//Given a pattern and a string s, find if s follows the same pattern.
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:
//	Each letter in pattern maps to exactly one unique word in s.
//	Each unique word in s maps to exactly one letter in pattern.
//	No two letters map to the same word, and no two words map to the same letter.
// 
//Example 1:
//Input: pattern = "abba", s = "dog cat cat dog"
//Output: true
//Explanation:
//The bijection can be established as:
//	'a' maps to "dog".
//	'b' maps to "cat".
//Example 2:
//Input: pattern = "abba", s = "dog cat cat fish"
//Output: false
//Example 3:
//Input: pattern = "aaaa", s = "dog cat cat dog"
//Output: false
// 
//Constraints:
//	1 <= pattern.length <= 300
//	pattern contains only lower-case English letters.
//	1 <= s.length <= 3000
//	s contains only lowercase English letters and spaces ' '.
//	s does not contain any leading or trailing spaces.
//	All the words in s are separated by a single space.
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> char2str;
        unordered_map<string, char> str2char;
        vector<string> words;
        string word;
        istringstream iss(s);
        while (iss >> word) {
            words.push_back(word);
        }
        if (pattern.size() != words.size()) {
            return false;
        }
        for (int i = 0; i < pattern.size(); i++) {
            if (char2str.find(pattern[i]) == char2str.end() && str2char.find(words[i]) == str2char.end()) {
                char2str[pattern[i]] = words[i];
                str2char[words[i]] = pattern[i];
            } else if (char2str[pattern[i]] != words[i] || str2char[words[i]] != pattern[i]) {
                return false;
            }
        }
        return true;        
    }
};