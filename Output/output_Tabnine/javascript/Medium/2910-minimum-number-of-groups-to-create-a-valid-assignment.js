/*
 You are given a collection of numbered balls and instructed to sort them into boxes for a nearly balanced distribution. There are two rules you must follow:
 Balls with the same box must have the same value. But, if you have more than one ball with the same number, you can put them in different boxes.
 The biggest box can only have one more ball than the smallest box.
 ​Return the fewest number of boxes to sort these balls following these rules.
 Example 1: 
 Input:   balls = [3,2,3,2,3] 
 Output:   2 
 Explanation:
 We can sort balls into boxes as follows:
 [3,3,3]
 [2,2]
 The size difference between the two boxes doesn't exceed one.
 Example 2: 
 Input:   balls = [10,10,10,3,1,1] 
 Output:   4 
 Explanation:
 We can sort balls into boxes as follows:
 [10]
 [10,10]
 [3]
 [1,1]
 You can't use fewer than four boxes while still following the rules. For example, putting all three balls numbered 10 in one box would break the rule about the maximum size difference between boxes.
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 109
*/

/**
 * @param {number[]} balls
 * @return {number}
 */
var minGroupsForValidAssignment = function(balls) {
    // Create a frequency map
    const freqMap = new Map();
    for (let ball of balls) {
        freqMap.set(ball, (freqMap.get(ball) || 0) + 1);
    }
    
    // Sort the frequency map by value
    const sortedFreqMap = Array.from(freqMap.entries()).sort((a, b) => b[1] - a[1]);
    
    // Initialize the count of groups
    let count = 0;
    let currentGroupSize = 1;
    // Iterate through the sorted frequency map
    for (let [ball, freq] of sortedFreqMap) {
        // If the current group size is greater than or equal to the frequency of the ball,
        // add the ball to the current group and decrement the frequency
        if (currentGroupSize >= freq) {
            currentGroupSize--;
        } else {
            // If the current group size is less than the frequency,
            // create a new group with the remaining frequency
            count++;
            currentGroupSize = freq - 1;
        }
    }
    
    return count;
    
};