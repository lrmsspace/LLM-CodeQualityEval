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
char** printVertically(char * s, int* returnSize) {
    int len = strlen(s);
    char** res = (char**)malloc(len * sizeof(char*));
    int cnt = 0;
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            j = 0;
            continue;
        }
        if (!res[j]) {
            res[j] = (char*)malloc(20 * sizeof(char));
            cnt++;
        }
        if (strlen(res[j]) == 0) {
            res[j][0] = s[i];
            res[j][1] = '\0';
        } else {
            strcat(res[j], (char[2]){s[i], '\0'});
        }
        j++;
    }
    *returnSize = cnt;
    return res;
}   