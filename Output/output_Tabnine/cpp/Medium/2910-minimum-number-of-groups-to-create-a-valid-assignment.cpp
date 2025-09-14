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
public:
    int minGroupsForValidAssignment(vector<int>& balls) {
        unordered_map<int, int> count;
        for (int ball : balls) {
            count[ball]++;
        }
        
        int minGroups = 0;
        while (!count.empty()) {
            int minCount = INT_MAX;
            int maxCount = INT_MIN;
            for (auto& pair : count) {
                minCount = min(minCount, pair.second);
                maxCount = max(maxCount, pair.second);
            }
            
            minGroups += maxCount - minCount + 1;
            for (auto& pair : count) {
                pair.second -= minCount;
                if (pair.second == 0) {
                    count.erase(pair.first);
                }
            }
        }
        
        return minGroups;
        
    }
};