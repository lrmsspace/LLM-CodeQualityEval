/**https://leetcode.com/problems/excel-sheet-column-title/ */
//Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
//For example:
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28 
//...
// 
//Example 1:
//Input: columnNumber = 1
//Output: "A"
//Example 2:
//Input: columnNumber = 28
//Output: "AB"
//Example 3:
//Input: columnNumber = 701
//Output: "ZY"
// 
//Constraints:
//	1 <= columnNumber <= 231 - 1
class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder sb = new StringBuilder();
        while (columnNumber > 0) {
            columnNumber--; // Decrement columnNumber to make it 0-indexed
            int remainder = columnNumber % 26;
            sb.append((char) ('A' + remainder)); // Append the corresponding character
            columnNumber /= 26; // Move to the next "digit"
        }
        return sb.reverse().toString(); // Reverse the string to get the correct order        
    }
}