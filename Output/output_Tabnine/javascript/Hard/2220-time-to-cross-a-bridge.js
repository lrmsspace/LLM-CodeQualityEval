/**https://leetcode.com/problems/time-to-cross-a-bridge/ */
//There are k workers who want to move n boxes from the right (old) warehouse to the left (new) warehouse. You are given the two integers n and k, and a 2D integer array time of size k x 4 where time[i] = [righti, picki, lefti, puti].
//The warehouses are separated by a river and connected by a bridge. Initially, all k workers are waiting on the left side of the bridge. To move the boxes, the ith worker can do the following:
//	Cross the bridge to the right side in righti minutes.
//	Pick a box from the right warehouse in picki minutes.
//	Cross the bridge to the left side in lefti minutes.
//	Put the box into the left warehouse in puti minutes.
//The ith worker is less efficient than the jth worker if either condition is met:
//	lefti + righti > leftj + rightj
//	lefti + righti == leftj + rightj and i > j
//The following rules regulate the movement of the workers through the bridge:
//	Only one worker can use the bridge at a time.
//	When the bridge is unused prioritize the least efficient worker (who have picked up the box) on the right side to cross. If not, prioritize the least efficient worker on the left side to cross.
//	If enough workers have already been dispatched from the left side to pick up all the remaining boxes, no more workers will be sent from the left side.
//Return the elapsed minutes at which the last box reaches the left side of the bridge.
// 
//Example 1:
//Input: n = 1, k = 3, time = [[1,1,2,1],[1,1,3,1],[1,1,4,1]]
//Output: 6
//Explanation:
//From 0 to 1 minutes: worker 2 crosses the bridge to the right.
//From 1 to 2 minutes: worker 2 picks up a box from the right warehouse.
//From 2 to 6 minutes: worker 2 crosses the bridge to the left.
//From 6 to 7 minutes: worker 2 puts a box at the left warehouse.
//The whole process ends after 7 minutes. We return 6 because the problem asks for the instance of time at which the last worker reaches the left side of the bridge.
//Example 2:
//Input: n = 3, k = 2, time = [[1,5,1,8],[10,10,10,10]]
//Output: 37
//Explanation:
//The last box reaches the left side at 37 seconds. Notice, how we do not put the last boxes down, as that would take more time, and they are already on the left with the workers.
// 
//Constraints:
//	1 <= n, k <= 104
//	time.length == k
//	time[i].length == 4
//	1 <= lefti, picki, righti, puti <= 1000
/**
 * @param {number} n
 * @param {number} k
 * @param {number[][]} time
 * @return {number}
 */
var findCrossingTime = function(n, k, time) {
    const leftSide = Array(k).fill(0);
    const rightSide = Array(k).fill(0);
    const bridge = 0;
    
    let minTime = 0;
    let lastBoxTime = 0;
    let workerIndex = 0;
    let workersOnLeft = 0;
    
    while (lastBoxTime < n) {
        // Update left side workers
        for (let i = 0; i < k; i++) {
            if (leftSide[i] > 0) {
                leftSide[i]--;
            }
            if (leftSide[i] === 0 && rightSide[i] === 0) {
                workersOnLeft--;
            }
        }
        
        // Update right side workers
        if (rightSide[workerIndex] > 0) {
            rightSide[workerIndex]--;
        }
        
        // Send workers from left side to pick up boxes
        while (workersOnLeft < n && time[workerIndex][1] > 0) {
            leftSide[workerIndex]++;
            time[workerIndex][1]--;
            workersOnLeft++;
        }
        
        // Choose least efficient worker
        let minLeftWorker = workerIndex;
        let minLeftTime = time[workerIndex][0] + time[workerIndex][2];
        let minRightWorker = workerIndex;
        let minRightTime = time[workerIndex][0] + time[workerIndex][3];
        
        for (let i = 1; i < k; i++) {
            if (leftSide[i] > 0 && (time[i][0] + time[i][2] < minLeftTime || (time[i][0] + time[i][2] === minLeftTime && i < minLeftWorker))) {
                minLeftWorker = i;
                minLeftTime = time[i][0] + time[i][2];
            }
            if (rightSide[i] > 0 && (time[i][0] + time[i][3] < minRightTime || (time[i][0] + time[i][3] === minRightTime && i < minRightWorker))) {
                minRightWorker = i;
                minRightTime = time[i][0] + time[i][3];
            }
        }
    
        // Cross bridge
        minTime = Math.max(minLeftTime, minRightTime);
        if (bridge > 0) {
            bridge--;
        } else {
            bridge = Math.min(time[minLeftWorker][2], time[minRightWorker][3]);
            minTime += bridge;
        }
        
        // Update last box time
        if (rightSide[workerIndex] === 0) {
            lastBoxTime++;
        }
        
        // Update worker index
        workerIndex = (workerIndex + 1) % k;
    }
    
    return minTime;
    
};