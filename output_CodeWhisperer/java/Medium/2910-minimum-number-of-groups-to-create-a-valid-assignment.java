/*
import java.util.HashMap;
import java.util.Map;
import java.util.Collections;
import java.util.List;
import java.util.ArrayList;
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
        Map<Integer, Integer> freq = new HashMap<>();
        for (int ball : balls) {
            freq.put(ball, freq.getOrDefault(ball, 0) + 1);
        }
        
        List<Integer> counts = new ArrayList<>(freq.values());
        int minFreq = Collections.min(counts);
        
        for (int i = minFreq; i >= 1; i--) {
            int groups = 0;
            for (int count : counts) {
                if (count / i * i == count) {
                    groups += count / i;
                } else if ((count - i) / i * i + i == count) {
                    groups += (count - i + 1) / (i + 1);
                } else {
                    groups = 0;
                    break;
                }
            }
            if (groups != 0) {
                return groups;
            }
        }
        
        return -1;        
    }
}