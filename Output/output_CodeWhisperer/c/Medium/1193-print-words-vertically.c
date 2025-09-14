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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** printVertically(char * s, int* returnSize)
{
    int len = strlen(s);
    int max = 0;
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            if (count > max) {
                max = count;
            }
            count = 0;
        } else {
            count++;
        }
    }
    if (count > max) {
        max = count;
    }
    char** result = (char**)malloc(sizeof(char*) * max);
    for (int i = 0; i < max; i++) {
        result[i] = (char*)malloc(sizeof(char) * (len + 1));
        memset(result[i], ' ', sizeof(char) * (len + 1));
    }
    int* index = (int*)malloc(sizeof(int) * max);
    memset(index, 0, sizeof(int) * max);
    count = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            count++;
        } else {
            result[i - count][index[i - count]++] = s[i];
        }
    }
    *returnSize = max;
    return result;
}