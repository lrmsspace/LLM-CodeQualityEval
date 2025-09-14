/**https://leetcode.com/problems/minimum-money-required-before-transactions/ */
//You are given a 0-indexed 2D integer array transactions, where transactions[i] = [costi, cashbacki].
//The array describes transactions, where each transaction must be completed exactly once in some order. At any given moment, you have a certain amount of money. In order to complete transaction i, money >= costi must hold true. After performing a transaction, money becomes money - costi + cashbacki.
//Return the minimum amount of money required before any transaction so that all of the transactions can be completed regardless of the order of the transactions.
// 
//Example 1:
//Input: transactions = [[2,1],[5,0],[4,2]]
//Output: 10
//Explanation:
//Starting with money = 10, the transactions can be performed in any order.
//It can be shown that starting with money < 10 will fail to complete all transactions in some order.
//Example 2:
//Input: transactions = [[3,0],[0,3]]
//Output: 3
//Explanation:
//- If transactions are in the order [[3,0],[0,3]], the minimum money required to complete the transactions is 3.
//- If transactions are in the order [[0,3],[3,0]], the minimum money required to complete the transactions is 0.
//Thus, starting with money = 3, the transactions can be performed in any order.
// 
//Constraints:
//	1 <= transactions.length <= 105
//	transactions[i].length == 2
//	0 <= costi, cashbacki <= 109
long long minimumMoney(int** transactions, int transactionsSize, int* transactionsColSize) {
    int n = transactionsSize;
    int* dp = (int*)calloc(n, sizeof(int));
    int* prefixSum = (int*)calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + transactions[i][1];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        int maxMoney = 0;
        for (int j = i + 1; j < n; j++) {
            maxMoney = max(maxMoney, prefixSum[j] - prefixSum[i]);
            dp[i] = max(dp[i], transactions[i][0] + maxMoney);
        }
    }
    
    long long minMoney = prefixSum[n - 1];
    free(dp);
    free(prefixSum);
    return minMoney;
    
}