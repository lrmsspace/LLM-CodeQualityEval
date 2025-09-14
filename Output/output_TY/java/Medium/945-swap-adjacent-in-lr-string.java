/**https://leetcode.com/problems/swap-adjacent-in-lr-string/ */
//In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string result, return True if and only if there exists a sequence of moves to transform start to result.
// 
//Example 1:
//Input: start = "RXXLRXRXL", result = "XRLXXRRLX"
//Output: true
//Explanation: We can transform start to result following these steps:
//RXXLRXRXL ->
//XRXLRXRXL ->
//XRLXRXRXL ->
//XRLXXRRXL ->
//XRLXXRRLX
//Example 2:
//Input: start = "X", result = "L"
//Output: false
// 
//Constraints:
//	1 <= start.length <= 104
//	start.length == result.length
//	Both start and result will only consist of characters in 'L', 'R', and 'X'.
class Solution {
    public boolean canTransform(String start, String result) {
        int n = start.length();
        int lCount = 0, rCount = 0;
        for (int i = 0; i < n; i++) {
            if (start.charAt(i) == 'L') lCount++;
            else if (start.charAt(i) == 'R') rCount++;
        }
        if (lCount != rCount) return false;
        int i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && start.charAt(i) == 'X') i++;
            while (j < n && result.charAt(j) == 'X') j++;
            if (i < n && j < n) {
                char s = start.charAt(i);
                char t = result.charAt(j);
                if (s == t) {
                    if (s == 'L' && i < j) return false;
                    if (s == 'R' && i > j) return false;
                    i++;
                    j++;
                } else {
                    return false;
                }
            }
        }
        return i == n && j == n;
    }
}