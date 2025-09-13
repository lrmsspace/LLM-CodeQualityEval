/**https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/ */
//You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
//Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
//Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// 
//Example 1:
//Input: k = 2, prices = [2,4,1]
//Output: 2
//Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
//Example 2:
//Input: k = 2, prices = [3,2,6,5,0,3]
//Output: 7
//Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// 
//Constraints:
//	1 <= k <= 100
//	1 <= prices.length <= 1000
//	0 <= prices[i] <= 1000
/**
 * @param {number} k
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(k, prices) {
    let n = prices.length;
    if(n<=1) return 0;
    if(k>=n/2){
        let profit = 0;
        for(let i=1;i<n;i++){
            if(prices[i]>prices[i-1]) profit += prices[i]-prices[i-1];
        }
        return profit;
    }
    let dp = Array(n).fill(0).map(()=>Array(2).fill(0).map(()=>Array(k+1).fill(-1)));
    let dfs = (i,buy,k)=>{
        if(i>=n) return 0;
        if(k<=0) return 0;
    }
    if(dp[i][buy][k]!=-1) return dp[i][buy][k];
    if(buy){
        return dp[i][buy][k] = Math.max(-prices[i]+dfs(i+1,0,k),dfs(i+1,1,k));
    }else{
        return dp[i][buy][k] = Math.max(prices[i]+dfs(i+1,1,k-1),dfs(i+1,0,k));
    }
    return dfs(0,1,k);
};