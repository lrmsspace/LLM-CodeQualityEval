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
        string temp;
        for (char c : s) {
            if (c == ' ') {
                words.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }
        words.push_back(temp);
        vector<string> result;
        int maxLen = 0;
        for (string word : words) {
            maxLen = max(maxLen, (int)word.length());
        }
        for (int i = 0; i < maxLen; ++i) {
            string temp2;
            for (string word : words) {
                if (i < word.length()) {
                    temp2 += word[i];
                } else {
                    temp2 += ' ';
                }
            }
            temp2.erase(temp2.find_last_not_of(' ') + 1);
            result.push_back(temp2);
        }
        return result;
    }
};