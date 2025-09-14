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
public:
    int countSpecialNumbers(int n) {
        int res = 0;
        int num = n;
        int digits = 0;
        while (num > 0) {
            num /= 10;
            digits++;
        }
        for (int i = 1; i <= digits; i++) {
            int temp = 1;
            for (int j = 1; j <= i - 1; j++) {
                temp *= 9;
            }
            for (int j = 1; j <= i - 2; j++) {
                temp *= (10 - j);
            }
            res += temp;
        }
        vector<int> nums;
        num = n;
        while (num > 0) {
            nums.push_back(num % 10);
            num /= 10;
        }
        for (int i = 0; i < digits - 1; i++) {
            int temp = 1;
            for (int j = 1; j <= digits - i - 1; j++) {
                temp *= (10 - j);
            }
            res -= temp;
        }
        for (int i = 0; i < digits; i++) {
            for (int j = i + 1; j < digits; j++) {
                if (nums[i] == nums[j]) {
                    int temp = 1;
                    for (int k = i + 1; k < j; k++) {
                        temp *= (10 - k);
                    }
                    res -= temp;
                }
            }
        }
        return res;     
    }
};