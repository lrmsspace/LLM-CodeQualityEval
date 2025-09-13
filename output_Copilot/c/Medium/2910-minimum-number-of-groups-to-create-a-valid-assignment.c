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

int minGroupsForValidAssignment(int* balls, int ballsSize) {
    // Create a frequency map to count occurrences of each ball number
    int freq[1000001] = {0}; // Assuming ball numbers are in the range 1 to 10^6
    for (int i = 0; i < ballsSize; i++) {
        freq[balls[i]]++;
    }

    // Find the maximum frequency
    int maxFreq = 0;
    for (int i = 0; i < 1000001; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }

    // The minimum number of groups needed is equal to the maximum frequency
    return maxFreq;    
}