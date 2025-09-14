/**https://leetcode.com/problems/palindrome-pairs/ */
//You are given a 0-indexed array of unique strings words.
//A palindrome pair is a pair of integers (i, j) such that:
//	0 <= i, j < words.length,
//	i != j, and
//	words[i] + words[j] (the concatenation of the two strings) is a palindrome.
//Return an array of all the palindrome pairs of words.
//You must write an algorithm with O(sum of words[i].length) runtime complexity.
// 
//Example 1:
//Input: words = ["abcd","dcba","lls","s","sssll"]
//Output: [[0,1],[1,0],[3,2],[2,4]]
//Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]
//Example 2:
//Input: words = ["bat","tab","cat"]
//Output: [[0,1],[1,0]]
//Explanation: The palindromes are ["battab","tabbat"]
//Example 3:
//Input: words = ["a",""]
//Output: [[0,1],[1,0]]
//Explanation: The palindromes are ["a","a"]
// 
//Constraints:
//	1 <= words.length <= 5000
//	0 <= words[i].length <= 300
//	words[i] consists of lowercase English letters. 
class Solution {
    public:
        vector<vector<int>> palindromePairs(vector<string>& words) {
            vector<vector<int>> result;
            unordered_map<string, int> wordMap;
            
            // Build a map of words to their indices
            for (int i = 0; i < words.size(); i++) {
                wordMap[words[i]] = i;
            }
            
            // Check each word
            for (int i = 0; i < words.size(); i++) {
                string word = words[i];
                int len = word.length();
                
                // Handle empty string case
                if (len == 0) {
                    for (int j = 0; j < words.size(); j++) {
                        if (j != i && isPalindrome(words[j], 0, words[j].size() - 1)) {
                            result.push_back({i, j});
                        }
                    }
                    continue;
                }
                
                // Reverse the current word for easier checking
                string reversed = word;
                reverse(reversed.begin(), reversed.end());
                
                // Case 1: Check if the reverse of the entire word exists
                if (wordMap.count(reversed) && wordMap[reversed] != i) {
                    result.push_back({i, wordMap[reversed]});
                }
                
                // Case 2: Check all prefixes
                for (int j = 1; j < len; j++) {
                    // If prefix is a palindrome, check if the reverse of suffix exists
                    if (isPalindrome(word, 0, j - 1)) {
                        string reversedSuffix = word.substr(j);
                        reverse(reversedSuffix.begin(), reversedSuffix.end());
                        if (wordMap.count(reversedSuffix) && wordMap[reversedSuffix] != i) {
                            result.push_back({wordMap[reversedSuffix], i});
                        }
                    }
                    
                    // If suffix is a palindrome, check if the reverse of prefix exists
                    if (isPalindrome(word, j, len - 1)) {
                        string reversedPrefix = word.substr(0, j);
                        reverse(reversedPrefix.begin(), reversedPrefix.end());
                        if (wordMap.count(reversedPrefix) && wordMap[reversedPrefix] != i) {
                            result.push_back({i, wordMap[reversedPrefix]});
                        }
                    }
                }
            }
            
            return result;
        }
        
    private:
        // Check if a substring is a palindrome
        bool isPalindrome(const string& s, int start, int end) {
            while (start < end) {
                if (s[start++] != s[end--]) {
                    return false;
                }
            }
            return true;
        }
    };
    