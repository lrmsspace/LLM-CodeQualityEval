/**https://leetcode.com/problems/zigzag-conversion/ */
//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows:
//string convert(string s, int numRows);
// 
//Example 1:
//Input: s = "PAYPALISHIRING", numRows = 3
//Output: "PAHNAPLSIIGYIR"
//Example 2:
//Input: s = "PAYPALISHIRING", numRows = 4
//Output: "PINALSIGYAHRPI"
//Explanation:
//P     I    N
//A   L S  I G
//Y A   H R
//P     I
//Example 3:
//Input: s = "A", numRows = 1
//Output: "A"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of English letters (lower-case and upper-case), ',' and '.'.
//	1 <= numRows <= 1000
char* convert(char* s, int numRows) {
    if (numRows == 1) {
        return s;
    }
    
    int len = strlen(s);
    char* res = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;
    int step = 1;
    for (int i = 0; i < numRows; i++) {
        index = i;
        step = (i == 0 || i == numRows - 1) ? (numRows - 1) * 2 : (numRows - i - 1) * 2;
        while (index < len) {
            res[index] = s[index];
            index += step;
        }
    }
    res[len] = '\0';
    return res;
}