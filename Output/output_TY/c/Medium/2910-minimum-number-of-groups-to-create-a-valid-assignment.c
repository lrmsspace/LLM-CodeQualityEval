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
    int *cnt = calloc(1000001, sizeof(int));
    int i, j, k, n, m, ans = 0;
    for (i = 0; i < ballsSize; i++) {
        cnt[balls[i]]++;
    }
    for (i = 0; i < 1000001; i++) {
        if (cnt[i] == 0) continue;
        n = cnt[i];
        m = n / i;
        if (n % i == 0) {
            ans += m;
        } else {
            ans += m + 1;
        }
    }
    return ans; 
    
}