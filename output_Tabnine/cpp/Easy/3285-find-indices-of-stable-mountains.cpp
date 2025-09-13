/*
 There are n mountains in a row, and each mountain has a height. You are given an integer array height where height[i] represents the height of mountain i, and an integer threshold.
 A mountain is called stable if the mountain just before it (if it exists) has a height strictly greater than threshold. Note that mountain 0 is not stable.
 Return an array containing the indices of all stable mountains in any order.
 Example 1:
 Input: height = [1,2,3,4,5], threshold = 2
 Output: [3,4]
 Explanation:
 Mountain 3 is stable because height[2] == 3 is greater than threshold == 2.
 Mountain 4 is stable because height[3] == 4 is greater than threshold == 2.
 Example 2:
 Input: height = [10,1,10,1,10], threshold = 3
 Output: [1,3]
 Example 3:
 Input: height = [10,1,10,1,10], threshold = 10
 Output: []
 Constraints:
 2 <= n == height.length <= 100
 1 <= height[i] <= 100
 1 <= threshold <= 100
*/

class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> result;
        int n = height.size();
        
        // Find the peak of the mountain
        int peak = 0;
        for (int i = 1; i < n - 1; i++) {
            if (height[i] > height[peak] && height[i] > height[i + 1]) {
                peak = i;
            }
        }
        
        // Check if the peak is stable
        if (peak > 0 && height[peak] > threshold && height[peak] > height[peak - 1]) {
            result.push_back(peak);
        }
        
        // Find the tallest mountain to the left of the peak
        int left = peak;
        while (left > 0 && height[left] >= height[left - 1]) {
            left--;
        }
        
        // Find the tallest mountain to the right of the peak
        int right = peak;
        while (right < n - 1 && height[right] >= height[right + 1]) {
            right++;
        }
        // Check if the tallest mountain to the left and right of the peak are stable
        if (left > 0 && height[left] > threshold && height[left] > height[left - 1] &&
            right < n - 1 && height[right] > threshold && height[right] > height[right + 1]) {
            result.push_back(left);
            result.push_back(right);
        }
        
        return result;  
        
        
    }
};