/**https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/ */
//You are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.
//Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.
// 
//Example 1:
//Input: cards = [3,4,2,3,4,7]
//Output: 4
//Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.
//Example 2:
//Input: cards = [1,0,5,3]
//Output: -1
//Explanation: There is no way to pick up a set of consecutive cards that contain a pair of matching cards.
// 
//Constraints:
//	1 <= cards.length <= 105
//	0 <= cards[i] <= 106
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        if (n < 2) return -1;
        
        vector<int> left(n, -1), right(n, -1);
        for (int i = 0; i < n; ++i) {
            if (left[cards[i]] == -1) left[cards[i]] = i;
            else right[cards[i]] = i;
        }
        
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (left[cards[i]] == -1 || right[cards[i]] == -1) continue;
            ans = min(ans, max(right[cards[i]] - left[cards[i]], left[cards[i]] + n - right[cards[i]]));
        }
        
        return ans == INT_MAX? -1 : ans;
        
    }
};