/**https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/ */
//You are given an integer array jobs, where jobs[i] is the amount of time it takes to complete the ith job.
//There are k workers that you can assign jobs to. Each job should be assigned to exactly one worker. The working time of a worker is the sum of the time it takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment such that the maximum working time of any worker is minimized.
//Return the minimum possible maximum working time of any assignment. 
// 
//Example 1:
//Input: jobs = [3,2,3], k = 3
//Output: 3
//Explanation: By assigning each person one job, the maximum time is 3.
//Example 2:
//Input: jobs = [1,2,4,7,8], k = 2
//Output: 11
//Explanation: Assign the jobs the following way:
//Worker 1: 1, 2, 8 (working time = 1 + 2 + 8 = 11)
//Worker 2: 4, 7 (working time = 4 + 7 = 11)
//The maximum working time is 11.
// 
//Constraints:
//	1 <= k <= jobs.length <= 12
//	1 <= jobs[i] <= 107
/**
 * @param {number[]} jobs
 * @param {number} k
 * @return {number}
 */
var minimumTimeRequired = function(jobs, k) {
    jobs.sort((a, b) => b - a); // sort jobs in descending order
    let sum = 0; // sum of all jobs
    let maxTime = 0; // maximum time among workers
    
    for (let i = 0; i < jobs.length; i++) {
        sum += jobs[i]; // add current job to sum
        maxTime = Math.max(maxTime, sum * (i + 1)); // update maximum time if necessary
    }
    
    let left = 1; // left bound for binary search
    let right = sum; // right bound for binary search
    
    while (left <= right) {
        let mid = Math.floor((left + right) / 2); // midpoint for binary search
        let workers = 0; // number of workers needed
        let time = 0; // total time needed
        
        for (let job of jobs) {
            time += Math.ceil(job / mid); // calculate time needed for current job
            workers++; // increment number of workers if necessary
            if (workers >= k) break; // if enough workers are found, break the loop
        }
        
        if (workers >= k) {
            right = mid - 1; // update right bound if enough workers are found
        } else {
            left = mid + 1; // update left bound if not enough workers are found
        }
    }
    
    return left; // return the minimum possible maximum working time of any assignment
    
};