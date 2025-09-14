/*
 You are given an array apple of size n and an array capacity of size m.
 There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.
 Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.
 Note that, apples from the same pack can be distributed into different boxes.
 Example 1:
 Input: apple = [1,3,2], capacity = [4,3,1,5,2]
 Output: 2
 Explanation: We will use boxes with capacities 4 and 5.
 It is possible to distribute the apples as the total capacity is greater than or equal to the total number of apples.
 Example 2:
 Input: apple = [5,5,5], capacity = [2,4,2,7]
 Output: 4
 Explanation: We will need to use all the boxes.
 Constraints:
 1 <= n == apple.length <= 50
 1 <= m == capacity.length <= 50
 1 <= apple[i], capacity[i] <= 50
 The input is generated such that it's possible to redistribute packs of apples into boxes.
*/

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        int n = apple.size(), m = capacity.size();
        
        vector<int> prefix_apple(n), prefix_capacity(m);
        
        prefix_apple[0] = apple[0];
        prefix_capacity[0] = capacity[0];
        
        for(int i = 1; i < n; i++){
            prefix_apple[i] = prefix_apple[i - 1] + apple[i];
        }
        
        for(int i = 1; i < m; i++){
            prefix_capacity[i] = prefix_capacity[i - 1] + capacity[i];
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            int left = 0, right = m;
            while(left < right){
                int mid = (left + right) / 2;
                if(prefix_capacity[mid] >= prefix_apple[i]){
                    right = mid;
                }
                else{
                    left = mid + 1;
                }
            }
            ans = max(ans, right + 1);
        }

        return ans;

    }
};