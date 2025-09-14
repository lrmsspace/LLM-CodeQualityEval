/**https://leetcode.com/problems/keyboard-row/ */
//Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
//Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.
//In the American keyboard:
//	the first row consists of the characters "qwertyuiop",
//	the second row consists of the characters "asdfghjkl", and
//	the third row consists of the characters "zxcvbnm".
// 
//Example 1:
//Input: words = ["Hello","Alaska","Dad","Peace"]
//Output: ["Alaska","Dad"]
//Explanation:
//Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.
//Example 2:
//Input: words = ["omk"]
//Output: []
//Example 3:
//Input: words = ["adsdf","sfd"]
//Output: ["adsdf","sfd"]
// 
//Constraints:
//	1 <= words.length <= 20
//	1 <= words[i].length <= 100
//	words[i] consists of English letters (both lowercase and uppercase). 
class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        vector<string> result;
        for (auto word : words) {
            bool isOneRow = true;
            char row = 0;
            for (auto c : word) {
                char r = 0;
                if (c >= 'a' && c <= 'z') {
                    r = 1;
                } else if (c >= 'A' && c <= 'Z') {
                    r = 2;
                }
                if (row == 0) {
                    row = r;
                } else if (row != r) {
                    isOneRow = false;
                    break;
                }
            }
            if (isOneRow) {
                result.push_back(word);
            }
        }
        return result;
    }
};