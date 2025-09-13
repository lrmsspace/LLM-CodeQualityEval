/**https://leetcode.com/problems/maximum-number-of-robots-within-budget/ */
//You have n robots. You are given two 0-indexed integer arrays, chargeTimes and runningCosts, both of length n. The ith robot costs chargeTimes[i] units to charge and costs runningCosts[i] units to run. You are also given an integer budget.
//The total cost of running k chosen robots is equal to max(chargeTimes) + k * sum(runningCosts), where max(chargeTimes) is the largest charge cost among the k robots and sum(runningCosts) is the sum of running costs among the k robots.
//Return the maximum number of consecutive robots you can run such that the total cost does not exceed budget.
// 
//Example 1:
//Input: chargeTimes = [3,6,1,3,4], runningCosts = [2,1,3,4,5], budget = 25
//Output: 3
//Explanation: 
//It is possible to run all individual and consecutive pairs of robots within budget.
//To obtain answer 3, consider the first 3 robots. The total cost will be max(3,6,1) + 3 * sum(2,1,3) = 6 + 3 * 6 = 24 which is less than 25.
//It can be shown that it is not possible to run more than 3 consecutive robots within budget, so we return 3.
//Example 2:
//Input: chargeTimes = [11,12,19], runningCosts = [10,8,7], budget = 19
//Output: 0
//Explanation: No robot can be run that does not exceed the budget, so we return 0.
// 
//Constraints:
//	chargeTimes.length == runningCosts.length == n
//	1 <= n <= 5 * 104
//	1 <= chargeTimes[i], runningCosts[i] <= 105
//	1 <= budget <= 1015 
int maximumRobots(int* chargeTimes, int chargeTimesSize, int* runningCosts, int runningCostsSize, long long budget) {
    int maxRobots = 0;
    int left = 0;
    int maxChargeTime = 0;
    long long runningCostSum = 0;
    
    for (int right = 0; right < chargeTimesSize; ++right) {
        runningCostSum += runningCosts[right];
        if (chargeTimes[right] > maxChargeTime) {
            maxChargeTime = chargeTimes[right];
        }
        
        while (maxChargeTime + (right - left + 1) * runningCostSum > budget) {
            runningCostSum -= runningCosts[left];
            left++;
            maxChargeTime = 0;
            for (int k = left; k <= right; ++k) {
                if (chargeTimes[k] > maxChargeTime) {
                    maxChargeTime = chargeTimes[k];
                }
            }
        }
        
        if (right - left + 1 > maxRobots) {
            maxRobots = right - left + 1;
        }
    }
    
    return maxRobots;
}

