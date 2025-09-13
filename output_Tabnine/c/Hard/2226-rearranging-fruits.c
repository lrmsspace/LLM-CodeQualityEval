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
long long minCost(int* basket1, int basket1Size, int* basket2, int basket2Size) {
    // Count the frequency of each fruit in basket1 and basket2
    int freq1[100001] = {0};
    int freq2[100001] = {0};
    for (int i = 0; i < basket1Size; i++) {
        freq1[basket1[i]]++;
        freq2[basket2[i]]++;
    }
    
    // Find the fruits that have different frequencies
    int diff = 0;
    for (int i = 1; i <= 100000; i++) {
        diff += abs(freq1[i] - freq2[i]);
    }
    
    // If the baskets are already equal, return 0
    if (diff == 0) {
        return 0;
    }
    
    // If it's impossible to make both baskets equal, return -1
    if (diff % 2!= 0) {
        return -1;
    }
    
    // Sort the baskets based on the frequency of each fruit
    qsort(basket1, basket1Size, sizeof(int), cmp);
    qsort(basket2, basket2Size, sizeof(int), cmp);
    
    // Calculate the minimum cost to make both baskets equal
    long long minCost = 0;
    for (int i = 0; i < basket1Size; i++) {
        minCost += min(basket1[i], basket2[i]);
    }
    
    return minCost;
    
}