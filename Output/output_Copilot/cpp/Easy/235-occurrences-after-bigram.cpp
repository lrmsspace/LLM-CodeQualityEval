/**https://leetcode.com/problems/occurrences-after-bigram/ */
//Given two strings first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.
//Return an array of all the words third for each occurrence of "first second third".
// 
//Example 1:
//Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
//Output: ["girl","student"]
//Example 2:
//Input: text = "we will we will rock you", first = "we", second = "will"
//Output: ["we","rock"]
// 
//Constraints:
//	1 <= text.length <= 1000
//	text consists of lowercase English letters and spaces.
//	All the words in text are separated by a single space.
//	1 <= first.length, second.length <= 10
//	first and second consist of lowercase English letters.
//	text will not have any leading or trailing spaces.
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        string f = first + " " + second + " ";
        for (int i = 0; i < text.size(); i++) {
            if (text.substr(i, f.size()) == f) {
                int j = i + f.size();
                while (j < text.size() && text[j] != ' ') j++;
                res.push_back(text.substr(i + f.size(), j - i - f.size()));
                i = j;
            }
        } 
        return res;       
    }
};