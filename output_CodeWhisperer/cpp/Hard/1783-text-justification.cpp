/**https://leetcode.com/problems/text-justification/ */
//Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
//You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
//Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
//For the last line of text, it should be left-justified, and no extra space is inserted between words.
//Note:
//	A word is defined as a character sequence consisting of non-space characters only.
//	Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
//	The input array words contains at least one word.
// 
//Example 1:
//Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
//Output:
//[
//   "This    is    an",
//   "example  of text",
//   "justification.  "
//]
//Example 2:
//Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
//Output:
//[
//  "What   must   be",
//  "acknowledgment  ",
//  "shall be        "
//]
//Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
//Note that the second line is also left-justified because it contains only one word.
//Example 3:
//Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
//Output:
//[
//  "Science  is  what we",
//  "understand      well",
//  "enough to explain to",
//  "a  computer.  Art is",
//  "everything  else  we",
//  "do                  "
//]
// 
//Constraints:
//	1 <= words.length <= 300
//	1 <= words[i].length <= 20
//	words[i] consists of only English letters and symbols.
//	1 <= maxWidth <= 100
//	words[i].length <= maxWidth
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0;
        while (i < n) {
            int j = i + 1;
            int len = words[i].length();
            while (j < n && len + words[j].length() + (j - i) <= maxWidth) {
                len += words[j].length();
                j++;
            }
            int numWords = j - i;
            int numSpaces = maxWidth - len;
            string s = words[i];
            if (numWords == 1 || j == n) {
                for (int k = i + 1; k < j; k++) {
                    s += " " + words[k];
                }
                s += string(numSpaces, ' ');
            } else {
                int spaces = numSpaces / (numWords - 1);
                int extra = numSpaces % (numWords - 1);
                for (int k = i + 1; k < j; k++) {
                    s += string(spaces + (k - i <= extra ? 1 : 0), ' ') + words[k];
                }
            }
            res.push_back(s);
            i = j;
        }
        return res;    
    }
};