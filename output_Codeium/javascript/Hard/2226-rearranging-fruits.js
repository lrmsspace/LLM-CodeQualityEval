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
var minCost = function(basket1, basket2) {
    const freq1 = {};
    const freq2 = {};

    for (const fruit of basket1) {
        freq1[fruit] = (freq1[fruit] || 0) + 1;
    }

    for (const fruit of basket2) {
        freq2[fruit] = (freq2[fruit] || 0) + 1;
    }

    const allFruits = new Set([...basket1, ...basket2]);
    const excess = [];
    const deficit = [];
    
    for (const fruit of allFruits) {
        const count1 = freq1[fruit] || 0;
        const count2 = freq2[fruit] || 0;
        const diff = count1 - count2;
        
        if (diff % 2 !== 0) return -1;

        if (diff > 0) {
            excess.push(...Array(diff / 2).fill(fruit));
        } else if (diff < 0) {
            deficit.push(...Array(-diff / 2).fill(fruit));
        }
    }

    excess.sort((a, b) => a - b);
    deficit.sort((a, b) => a - b);
    
    let totalCost = 0;
    for (let i = 0; i < excess.length; i++) {
        totalCost += Math.min(excess[i], deficit[i]);
    }

    return totalCost;
};
};