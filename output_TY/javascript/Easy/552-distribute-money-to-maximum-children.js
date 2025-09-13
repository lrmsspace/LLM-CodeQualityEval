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
/**
 * @param {number} money
 * @param {number} children
 * @return {number}
 */
var distMoney = function(money, children) {
    let count = 0;
    let left = money - children;
    while(left >= 0 && children > 0){
        if(left >= 7){
            left -= 8;
            count++;
            children--;
        }else{
            left--;
            count++;
            children--;
        }
    }
    if(left === 0 && children === 0) return count;
    if(left === 0 && children > 0) return count - 1;
    if(left < 0 && children > 0) return count - 2;
    if(left < 0 && children === 0) return count - 1;
    return -1; 
};