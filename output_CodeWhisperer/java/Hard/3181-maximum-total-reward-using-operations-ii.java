/*
import java.util.HashSet;
import java.util.Arrays;
import java.util.Set;
 You are given an integer array rewardValues of length n, representing the values of rewards.
 Initially, your total reward x is 0, and all indices are unmarked. You are allowed to perform the following operation any number of times:
 Choose an unmarked index i from the range [0, n - 1].
 If rewardValues[i] is greater than your current total reward x, then add rewardValues[i] to x (i.e., x = x + rewardValues[i]), and mark the index i.
 Return an integer denoting the maximum total reward you can collect by performing the operations optimally.
 Example 1:
 Input: rewardValues = [1,1,3,3]
 Output: 4
 Explanation:
 During the operations, we can choose to mark the indices 0 and 2 in order, and the total reward will be 4, which is the maximum.
 Example 2:
 Input: rewardValues = [1,6,4,3,2]
 Output: 11
 Explanation:
 Mark the indices 0, 2, and 1 in order. The total reward will then be 11, which is the maximum.
 Constraints:
 1 <= rewardValues.length <= 5 * 104
 1 <= rewardValues[i] <= 5 * 104
*/

class Solution {
    public int maxTotalReward(int[] rewardValues) {
        Arrays.sort(rewardValues);
        Set<Integer> set = new HashSet<>();
        set.add(0);
        for (int reward : rewardValues) {
            Set<Integer> newSet = new HashSet<>();
            for (int num : set) {
                if (reward > num) {
                    newSet.add(num + reward);
                }
            }
            set.addAll(newSet);
            set.add(rewardValues[0] + reward);
        }
        return set.stream().max(Integer::compareTo).get();        
    }
}