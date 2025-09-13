/**https://leetcode.com/problems/print-words-vertically/ */
//Given a string s. Return all the words vertically in the same order in which they appear in s.
//Words are returned as a list of strings, complete with spaces when is necessary. (Trailing spaces are not allowed).
//Each word would be put on only one column and that in one column there will be only one word.
// 
//Example 1:
//Input: s = "HOW ARE YOU"
//Output: ["HAY","ORO","WEU"]
//Explanation: Each word is printed vertically. 
// "HAY"
// "ORO"
// "WEU"
//Example 2:
//Input: s = "TO BE OR NOT TO BE"
//Output: ["TBONTB","OEROOE","   T"]
//Explanation: Trailing spaces is not allowed. 
//"TBONTB"
//"OEROOE"
//"   T"
//Example 3:
//Input: s = "CONTEST IS COMING"
//Output: ["CIC","OSO","N M","T I","E N","S G","T"]
// 
//Constraints:
//	1 <= s.length <= 200
//	s contains only upper case English letters.
//	It's guaranteed that there is only one space between 2 words.
class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        string word;
        for (char c : s) {
            if (c == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += c;
            }
        }
        words.push_back(word);
        
        int maxLen = 0;
        for (string& w : words) {
            maxLen = max(maxLen, (int)w.length());
        }
        
        vector<string> res;
        for (int i = 0; i < maxLen; i++) {
            string verticalWord;
            for (string& w : words) {
                if (i < w.length()) {
                    verticalWord += w[i];
                } else {
                    verticalWord += ' ';
                }
            }
            while (verticalWord.back() == ' ') {
                verticalWord.pop_back();
            }
            res.push_back(verticalWord);
        }
        
        return res;
        
    }
};