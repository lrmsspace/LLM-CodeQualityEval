/*
 Given a string word, compress it using the following algorithm:
 Begin with an empty string comp. While word is not empty, use the following operation:
 Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
 Append the length of the prefix followed by c to comp.
 Return the string comp.
 Example 1:
 Input: word = "abcde"
 Output: "1a1b1c1d1e"
 Explanation:
 Initially, comp = "". Apply the operation 5 times, choosing "a", "b", "c", "d", and "e" as the prefix in each operation.
 For each prefix, append "1" followed by the character to comp.
 Example 2:
 Input: word = "aaaaaaaaaaaaaabb"
 Output: "9a5a2b"
 Explanation:
 Initially, comp = "". Apply the operation 3 times, choosing "aaaaaaaaa", "aaaaa", and "bb" as the prefix in each operation.
 For prefix "aaaaaaaaa", append "9" followed by "a" to comp.
 For prefix "aaaaa", append "5" followed by "a" to comp.
 For prefix "bb", append "2" followed by "b" to comp.
 Constraints:
 1 <= word.length <= 2 * 105
 word consists only of lowercase English letters.
*/

class Solution {
public:
    string compressedString(string word) {
        string res = "";
        int cnt = 1;
        char prev = word[0];
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == prev) {
                cnt++;
            } else {
                while (cnt > 0) {
                    if (cnt >= 9) {
                        res += "9";
                        res += prev;
                        cnt -= 9;
                    } else {
                        res += to_string(cnt);
                        res += prev;
                        cnt = 0;
                    }
                }
                prev = word[i];
                cnt = 1;
            }
        }
        while (cnt > 0) {
            if (cnt >= 9) {
                res += "9";
                res += prev;
                cnt -= 9;
            } else {
                res += to_string(cnt);
                res += prev;
                cnt = 0;
            }
        }
        return res;
     
    }
};