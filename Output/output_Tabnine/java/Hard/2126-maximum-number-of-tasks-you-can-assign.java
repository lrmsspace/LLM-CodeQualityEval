/**https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/ */
//You have n tasks and m workers. Each task has a strength requirement stored in a 0-indexed integer array tasks, with the ith task requiring tasks[i] strength to complete. The strength of each worker is stored in a 0-indexed integer array workers, with the jth worker having workers[j] strength. Each worker can only be assigned to a single task and must have a strength greater than or equal to the task's strength requirement (i.e., workers[j] >= tasks[i]).
//Additionally, you have pills magical pills that will increase a worker's strength by strength. You can decide which workers receive the magical pills, however, you may only give each worker at most one magical pill.
//Given the 0-indexed integer arrays tasks and workers and the integers pills and strength, return the maximum number of tasks that can be completed.
// 
//Example 1:
//Input: tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
//Output: 3
//Explanation:
//We can assign the magical pill and tasks as follows:
//- Give the magical pill to worker 0.
//- Assign worker 0 to task 2 (0 + 1 >= 1)
//- Assign worker 1 to task 1 (3 >= 2)
//- Assign worker 2 to task 0 (3 >= 3)
//Example 2:
//Input: tasks = [5,4], workers = [0,0,0], pills = 1, strength = 5
//Output: 1
//Explanation:
//We can assign the magical pill and tasks as follows:
//- Give the magical pill to worker 0.
//- Assign worker 0 to task 0 (0 + 5 >= 5)
//Example 3:
//Input: tasks = [10,15,30], workers = [0,10,10,10,10], pills = 3, strength = 10
//Output: 2
//Explanation:
//We can assign the magical pills and tasks as follows:
//- Give the magical pill to worker 0 and worker 1.
//- Assign worker 0 to task 0 (0 + 10 >= 10)
//- Assign worker 1 to task 1 (10 + 10 >= 15)
//The last pill is not given because it will not make any worker strong enough for the last task.
// 
//Constraints:
//	n == tasks.length
//	m == workers.length
//	1 <= n, m <= 5 * 104
//	0 <= pills <= m
//	0 <= tasks[i], workers[j], strength <= 109
class Solution {
    public int maxTaskAssign(int[] tasks, int[] workers, int pills, int strength) {
        // Sort the tasks and workers based on strength requirement
        Arrays.sort(tasks);
        Arrays.sort(workers);
        
        // Initialize variables
        int maxTasks = 0;
        int taskIndex = 0;
        int workerIndex = 0;
        
        // Iterate through the tasks and workers
        while (taskIndex < tasks.length && workerIndex < workers.length) {
            // If the current worker is strong enough, assign the task and increment the worker index
            if (workers[workerIndex] >= tasks[taskIndex]) {
                maxTasks++;
                workerIndex++;
            }
            // If the current worker is not strong enough, give a pill and increment the pill count
            else {
                pills--;
                if (pills == 0) {
                    break;
                }
            }
            // Increment the task index
            taskIndex++;
        }
        
        // Return the maximum number of tasks that can be completed
        return maxTasks;
        
    }
}