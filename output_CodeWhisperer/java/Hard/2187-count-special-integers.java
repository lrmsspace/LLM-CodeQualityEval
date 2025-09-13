/**https://leetcode.com/problems/count-special-integers/ */
//We call a positive integer special if all of its digits are distinct.
//Given a positive integer n, return the number of special integers that belong to the interval [1, n].
// 
//Example 1:
//Input: n = 20
//Output: 19
//Explanation: All the integers from 1 to 20, except 11, are special. Thus, there are 19 special integers.
//Example 2:
//Input: n = 5
//Output: 5
//Explanation: All the integers from 1 to 5 are special.
//Example 3:
//Input: n = 135
//Output: 110
//Explanation: There are 110 integers from 1 to 135 that are special.
//Some of the integers that are not special are: 22, 114, and 131.
// 
//Constraints:
//	1 <= n <= 2 * 109
class Solution {
    public int countSpecialNumbers(int n) {
        String s = Integer.toString(n);
        int len = s.length();
        int ans = 0;
        for(int i = 1; i < len; i++){
            int prod = 1;
            for(int j = 9; j > 9 - i; j--){
                prod *= j;
            }
            ans += prod;
        }
        boolean[] seen = new boolean[10];
        for(int i = 0; i < len; i++){
            int digit = s.charAt(i) - '0';
            int prod = 1;
            for(int j = i == 0 ? 1 : 0; j < digit; j++){
                if(i == 0 && j == 0) continue;
                if(!seen[j]){
                    prod *= 10 - i;
                }
            }
            if(i > 0 && seen[digit]) break;
            seen[digit] = true;
            ans += prod;
        }
        return ans;     
    }
}