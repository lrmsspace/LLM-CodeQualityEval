/**https://leetcode.com/problems/task-scheduler/ */
//You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.
//Return the minimum number of CPU intervals required to complete all tasks.
// 
//Example 1:
//Input: tasks = ["A","A","A","B","B","B"], n = 2
//Output: 8
//Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
//After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.
//Example 2:
//Input: tasks = ["A","C","A","B","D","B"], n = 1
//Output: 6
//Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
//With a cooling interval of 1, you can repeat a task after just one other task.
//Example 3:
//Input: tasks = ["A","A","A", "B","B","B"], n = 3
//Output: 10
//Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.
//There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.
// 
//Constraints:
//	1 <= tasks.length <= 104
//	tasks[i] is an uppercase English letter.
//	0 <= n <= 100
/**
 * @param {character[]} tasks
 * @param {number} n
 * @return {number}
 */
var leastInterval = function(tasks, n) {
    
    let map = new Map();
    for(let i=0;i<tasks.length;i++){
        map.set(tasks[i], map.has(tasks[i]) ? map.get(tasks[i])+1 : 1);
    }
    
    let max = 0;
    for(let [key, value] of map){
        max = Math.max(max, value);
    }
    
    let maxCount = 0;
    for(let [key, value] of map){
        if(value === max){
            maxCount++;
        }
    }
    
    return Math.max(tasks.length, (n+1)*(max-1)+maxCount);
};