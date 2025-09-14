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
        int[] count = new int[10];
        while (n > 0) {
            count[n % 10]++;
            n /= 10;
        }
        int ans = 0;
        for (int i = 1; i < 10; i++) {
            ans += count[i] * i;
        }
        for (int i = 1; i < 10; i++) {
            if (count[i] > 1) {
                ans += (count[i] - 1) * i;
            }
        }
        for (int i = 0; i < 10; i++) {
            if (count[i] == 0) {
                continue;
            }
            for (int j = 1; j < 10; j++) {
                if (i % j == 0) {
                    ans += count[i] * count[j];
                }
            }
        }  
        return ans;
    }
}