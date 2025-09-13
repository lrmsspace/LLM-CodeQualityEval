/**https://leetcode.com/problems/most-profit-assigning-work/ */
//You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:
//	difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
//	worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
//Every worker can be assigned at most one job, but one job can be completed multiple times.
//	For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
//Return the maximum profit we can achieve after assigning the workers to the jobs.
// 
//Example 1:
//Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
//Output: 100
//Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
//Example 2:
//Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
//Output: 0
// 
//Constraints:
//	n == difficulty.length
//	n == profit.length
//	m == worker.length
//	1 <= n, m <= 104
//	1 <= difficulty[i], profit[i], worker[i] <= 105
/**
 * @param {number[]} difficulty
 * @param {number[]} profit
 * @param {number[]} worker
 * @return {number}
 */
var maxProfitAssignment = function(difficulty, profit, worker) {
    // Sort the difficulty array in ascending order
    difficulty.sort((a, b) => a - b);
    
    // Sort the profit array in descending order
    profit.sort((a, b) => b - a);
    
    // Sort the worker array in ascending order
    worker.sort((a, b) => a - b);
    
    let maxProfit = 0;
    let i = 0;
    let j = 0;
    
    while (i < difficulty.length && j < worker.length) {
        // If the current difficulty of the job is less than or equal to the ability of the current worker,
        // assign the job to the worker and update the maximum profit
        if (difficulty[i] <= worker[j]) {
            maxProfit = Math.max(maxProfit, profit[i] + worker[j]);
            i++;
        } else {
            // If the current difficulty of the job is greater than the ability of the current worker,
            // move to the next worker
            j++;
        }
    }
    
    return maxProfit;
    
};