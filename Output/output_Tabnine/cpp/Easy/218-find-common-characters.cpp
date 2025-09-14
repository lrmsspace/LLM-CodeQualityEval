/**https://leetcode.com/problems/find-common-characters/ */
//Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
// 
//Example 1:
//Input: words = ["bella","label","roller"]
//Output: ["e","l","l"]
//Example 2:
//Input: words = ["cool","lock","cook"]
//Output: ["c","o"]
// 
//Constraints:
//	1 <= words.length <= 100
//	1 <= words[i].length <= 100
//	words[i] consists of lowercase English letters.
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq(26, 0);
        vector<string> result;
        
        for (const auto& word : words) {
            vector<int> temp(26, 0);
            for (const auto& c : word) {
                temp[c - 'a']++;
            }
            
            for (int i = 0; i < 26; i++) {
                freq[i] = min(freq[i], temp[i]);
            }
        }
        
        for (int i = 0; i < 26; i++) {
            while (freq[i]--) {
                result.push_back(string(1, i + 'a'));
            }
        }
        
        return result;
        
    }
};