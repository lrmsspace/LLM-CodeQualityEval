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
        vector<string> result;
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word)
        {
            words.push_back(word);
        }

        int maxLength = 0;
        for (auto word : words)
        {
            maxLength = max(maxLength, (int)word.size());
        }

        for (int i = 0; i < maxLength; i++)
        {
            string temp;
            for (auto word : words)
            {
                if (i < word.size())
                {
                    temp += word[i];
                }
            }
        }
        while (temp.back() == ' ')
        {
            temp.pop_back();
        }
        result.push_back(temp);
        for (int i = 1; i < maxLength; i++)
        {
            temp = "";
            for (auto word : words)
            {
                if (i < word.size())
                {
                    temp += word[i];
                }
                else
                {
                    temp += " ";
                }
            }
            while (temp.back() == ' ')
            {
                temp.pop_back();
            }
            result.push_back(temp);
        }
        return result;
    }
};