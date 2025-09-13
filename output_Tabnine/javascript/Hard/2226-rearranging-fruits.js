/**https://leetcode.com/problems/rearranging-fruits/ */
//You have two fruit baskets containing n fruits each. You are given two 0-indexed integer arrays basket1 and basket2 representing the cost of fruit in each basket. You want to make both baskets equal. To do so, you can use the following operation as many times as you want:
//	Chose two indices i and j, and swap the ith fruit of basket1 with the jth fruit of basket2.
//	The cost of the swap is min(basket1[i],basket2[j]).
//Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.
//Return the minimum cost to make both the baskets equal or -1 if impossible.
// 
//Example 1:
//Input: basket1 = [4,2,2,2], basket2 = [1,4,1,2]
//Output: 1
//Explanation: Swap index 1 of basket1 with index 0 of basket2, which has cost 1. Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. Rearranging both the arrays makes them equal.
//Example 2:
//Input: basket1 = [2,3,4,1], basket2 = [3,2,5,1]
//Output: -1
//Explanation: It can be shown that it is impossible to make both the baskets equal.
// 
//Constraints:
//	basket1.length == basket2.length
//	1 <= basket1.length <= 105
//	1 <= basket1[i],basket2[i] <= 109
/**
 * @param {number[]} basket1
 * @param {number[]} basket2
 * @return {number}
 */
var minCost = function(basket1, basket2) {
    // Create a frequency count for each basket
    let count1 = Array(100001).fill(0);
    let count2 = Array(100001).fill(0);
    for (let i = 0; i < basket1.length; i++) {
        count1[basket1[i]]++;
        count2[basket2[i]]++;
    }
    
    // Calculate the difference in fruit counts
    let diff = 0;
    for (let i = 1; i <= 100000; i++) {
        diff += Math.abs(count1[i] - count2[i]);
    }
    
    // If the difference is odd, it's impossible to make both baskets equal
    if (diff % 2 === 1) {
        return -1;
    }
    
    // Calculate the minimum cost to make both baskets equal
    let cost = 0;
    for (let i = 1; i <= 100000; i++) {
        cost += Math.min(count1[i], count2[i]) * Math.min(basket1[i], basket2[i]);
    }
    return cost / 2;
    
};