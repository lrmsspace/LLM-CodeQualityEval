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

class Solution {
    public int minGroupsForValidAssignment(int[] balls) {
        int[] count = new int[1000001];
        for(int i = 0; i < balls.length; i++) {
            count[balls[i]]++;
        }
        
        int ans = 0;
        for(int i = 1; i < count.length; i++) {
            if(count[i] == 0) continue;
            int temp = count[i];
            int temp2 = temp;
            int temp3 = temp;
            int temp4 = temp;
            int temp5 = temp;
            int temp6 = temp;
            int temp7 = temp;
            int temp8 = temp;
            int temp9 = temp;
            int temp10 = temp;
        }
        return Math.min(temp2, Math.min(temp3, Math.min(temp4, Math.min(temp5, Math.min(temp6, Math.min(temp7, Math.min(temp8, Math.min(temp9, temp10))))))));
        
    }
}