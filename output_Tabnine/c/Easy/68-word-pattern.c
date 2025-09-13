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
bool wordPattern(char* pattern, char* s) {
    int n = strlen(pattern);
    char* words[n];
    int wordCount = 0;
    char* start = s;
    while (*start) {
        if (*start =='') {
            *start = '\0';
            words[wordCount++] = start + 1;
            start++;
        } else {
            start++;
        }
    }
    if (wordCount!= n) {
        return false;
    }
    unordered_map<char, string> map1;
    unordered_map<string, char> map2;
    for (int i = 0; i < n; i++) {
        if (map1.find(pattern[i]) == map1.end() && map2.find(words[i]) == map2.end()) {
            map1[pattern[i]] = words[i];
            map2[words[i]] = pattern[i];
        } else if (map1[pattern[i]]!= words[i] || map2[words[i]]!= pattern[i]) {
            return false;
        }
    }
    return true;
}