/**https://leetcode.com/problems/closest-divisors/ */
//Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.
//Return the two integers in any order.
// 
//Example 1:
//Input: num = 8
//Output: [3,3]
//Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.
//Example 2:
//Input: num = 123
//Output: [5,25]
//Example 3:
//Input: num = 999
//Output: [40,25]
// 
//Constraints:
//	1 <= num <= 10^9
class Solution {
public:
    vector<int> closestDivisors(int num) {
        int n1 = num + 1;
        int n2 = num + 2;
        int d1 = sqrt(n1);
        int d2 = sqrt(n2);
        if (d1 * d1 == n1)
            return {d1, d1};
        if (d2 * d2 == n2)
            return {d2, d2};
        if (abs(d1 - (n1 / d1)) < abs(d2 - (n2 / d2)))
            return {d1, n1 / d1};
        return {d2, n2 / d2};
    }
};