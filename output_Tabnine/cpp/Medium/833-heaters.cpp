/**https://leetcode.com/problems/heaters/ */
//Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.
//Every house can be warmed, as long as the house is within the heater's warm radius range. 
//Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.
//Notice that all the heaters follow your radius standard, and the warm radius will the same.
// 
//Example 1:
//Input: houses = [1,2,3], heaters = [2]
//Output: 1
//Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
//Example 2:
//Input: houses = [1,2,3,4], heaters = [1,4]
//Output: 1
//Explanation: The two heaters were placed at positions 1 and 4. We need to use a radius 1 standard, then all the houses can be warmed.
//Example 3:
//Input: houses = [1,5], heaters = [2]
//Output: 3
// 
//Constraints:
//	1 <= houses.length, heaters.length <= 3 * 104
//	1 <= houses[i], heaters[i] <= 109
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size(), m = heaters.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int ans = 0, i = 0, j = 0;
        while (i < n && j < m) {
            if (houses[i] <= heaters[j]) {
                ans = max(ans, heaters[j] - houses[i]);
                i++;
            } else {
                j++;
            }
        }
        
        while (i < n) {
            ans = max(ans, houses[i] - heaters.back());
            i++;
        }
        
        while (j < m) {
            ans = max(ans, heaters[j] - houses.front());
            j++;
        }
        
        return ans;
        
    }
};