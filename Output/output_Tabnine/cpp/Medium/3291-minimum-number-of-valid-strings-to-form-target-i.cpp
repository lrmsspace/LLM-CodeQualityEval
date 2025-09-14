/*
 You are given an array of strings words and a string target.
 A string x is called valid if x is a prefix of any string in words.
 Return the minimum number of valid strings that can be concatenated to form target. If it is not possible to form target, return -1.
 Example 1:
 Input: words = ["abc","aaaaa","bcdef"], target = "aabcdabc"
 Output: 3
 Explanation:
 The target string can be formed by concatenating:
 Prefix of length 2 of words[1], i.e. "aa".
 Prefix of length 3 of words[2], i.e. "bcd".
 Prefix of length 3 of words[0], i.e. "abc".
 Example 2:
 Input: words = ["abababab","ab"], target = "ababaababa"
 Output: 2
 Explanation:
 The target string can be formed by concatenating:
 Prefix of length 5 of words[0], i.e. "ababa".
 Prefix of length 5 of words[0], i.e. "ababa".
 Example 3:
 Input: words = ["abcdef"], target = "xyz"
 Output: -1
 Constraints:
 1 <= words.length <= 100
 1 <= words[i].length <= 5 * 103
 The input is generated such that sum(words[i].length) <= 105.
 words[i] consists only of lowercase English letters.
 1 <= target.length <= 5 * 103
 target consists only of lowercase English letters.
*/

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {

        // Create a map to store the prefix of each word
        unordered_map<string, int> prefixMap;
        for (const auto& word : words) {
            for (int i = 1; i <= word.size(); ++i) {
                prefixMap[word.substr(0, i)]++;
            }
        }
        int targetLength = target.size();   
        int minCount = INT_MAX;
        for (int i = 0; i <= targetLength - words[0].size(); ++i) {     
            string prefix = target.substr(i, words[0].size());
            if (prefixMap.find(prefix)!= prefixMap.end()) {
                minCount = min(minCount, prefixMap[prefix]);
            }
        }
        return minCount == INT_MAX? -1 : minCount;
        
    }
};