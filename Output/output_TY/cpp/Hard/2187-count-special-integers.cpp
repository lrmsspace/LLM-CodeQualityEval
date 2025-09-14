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
        int ans = 0;
        vector<int> digits;
        while(n){
            digits.push_back(n%10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());
        int size = digits.size();
        for(int i = 0; i < size; i++){
            int mask = 0;
            for(int j = 0; j < i; j++){
                mask |= (1 << digits[j]);
            }
            for(int j = i + 1; j < size; j++){
                if((mask & (1 << digits[j])) == 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};