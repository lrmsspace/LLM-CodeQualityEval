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
        vector<string> ans;
        int min_count[26] = {0};
        for (int i = 0; i < words[0].size(); i++) {
            min_count[words[0][i] - 'a']++;
        }
        for (int i = 1; i < words.size(); i++) {
            int count[26] = {0};
            for (int j = 0; j< words[i].size(); j++) {
                count[words[i][j] - 'a']++;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (min_count[i] != 0) {
                for (int j = 0; j < min_count[i]; j++) {
                    ans.push_back(string(1, i + 'a'));
                }
            }
        }
        return ans;
    }
};