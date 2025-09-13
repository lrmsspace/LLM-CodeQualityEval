/**https://leetcode.com/problems/string-matching-in-an-array/ */
//Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.
//A substring is a contiguous sequence of characters within a string
// 
//Example 1:
//Input: words = ["mass","as","hero","superhero"]
//Output: ["as","hero"]
//Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
//["hero","as"] is also a valid answer.
//Example 2:
//Input: words = ["leetcode","et","code"]
//Output: ["et","code"]
//Explanation: "et", "code" are substring of "leetcode".
//Example 3:
//Input: words = ["blue","green","bu"]
//Output: []
//Explanation: No string of words is substring of another string.
// 
//Constraints:
//	1 <= words.length <= 100
//	1 <= words[i].length <= 30
//	words[i] contains only lowercase English letters.
//	All the strings of words are unique.
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        unordered_set<string> set(words.begin(), words.end());
        
        for(int i = 0; i < words.size(); i++) {
            for(int j = i + 1; j < words.size(); j++) {
                if(set.find(words[j].substr(0, words[i].size()))!= set.end()) {
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        
        return result;
        
    }
};