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
        vector<string> res;
        unordered_set<char> row1({'q','w','e','r','t','y','u','i','o','p'});
        unordered_set<char> row2({'a','s','d','f','g','h','j','k','l'});
        unordered_set<char> row3({'z','x','c','v','b','n','m'});
        for (auto& word : words) {
            unordered_set<char> s;
            for (auto& c : word) s.insert(tolower(c));
            if ((s.size() == row1.size() && s == row1) || (s.size() == row2.size() && s == row2) || (s.size() == row3.size() && s == row3)) res.push_back(word);
        }
        return res;
        
    }
};