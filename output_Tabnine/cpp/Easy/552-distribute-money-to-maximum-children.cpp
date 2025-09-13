/**https://leetcode.com/problems/distribute-money-to-maximum-children/ */
//You are given an integer money denoting the amount of money (in dollars) that you have and another integer children denoting the number of children that you must distribute the money to.
//You have to distribute the money according to the following rules:
//	All money must be distributed.
//	Everyone must receive at least 1 dollar.
//	Nobody receives 4 dollars.
//Return the maximum number of children who may receive exactly 8 dollars if you distribute the money according to the aforementioned rules. If there is no way to distribute the money, return -1.
// 
//Example 1:
//Input: money = 20, children = 3
//Output: 1
//Explanation: 
//The maximum number of children with 8 dollars will be 1. One of the ways to distribute the money is:
//- 8 dollars to the first child.
//- 9 dollars to the second child. 
//- 3 dollars to the third child.
//It can be proven that no distribution exists such that number of children getting 8 dollars is greater than 1.
//Example 2:
//Input: money = 16, children = 2
//Output: 2
//Explanation: Each child can be given 8 dollars.
// 
//Constraints:
//	1 <= money <= 200
//	2 <= children <= 30
class Solution {
public:
    int distMoney(int money, int children) {
        int sum = money + children * 4;
        if (sum % 4!= 0) return -1;
        int target = sum / 4;
        if (target < 4) return -1;
        for (int i = 1; i <= children; ++i) {
            if ((target - 4) / i >= 1 && (target - 4) % i == 0) {
                return i;
            }
        }
        return -1;      
    }
};