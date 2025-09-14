/**https://leetcode.com/problems/sum-of-square-numbers/ */
//Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
// 
//Example 1:
//Input: c = 5
//Output: true
//Explanation: 1 * 1 + 2 * 2 = 5
//Example 2:
//Input: c = 3
//Output: false
// 
//Constraints:
//	0 <= c <= 231 - 1
class Solution {
    public boolean judgeSquareSum(int c) {
        for(int i = 0; i * i <= c; i++){
            int j = (int)Math.sqrt(c - i * i);
            if(i * i + j * j == c){
                return true;
            }
        }
        return false;
    }
}