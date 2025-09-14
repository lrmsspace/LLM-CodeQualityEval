/*
 You are given two integers, n and k.
 An array of distinct positive integers is called a k-avoiding array if there does not exist any pair of distinct elements that sum to k.
 Return the minimum possible sum of a k-avoiding array of length n.
 Example 1:
 Input: n = 5, k = 4
 Output: 18
 Explanation: Consider the k-avoiding array [1,2,4,5,6], which has a sum of 18.
 It can be proven that there is no k-avoiding array with a sum less than 18.
 Example 2:
 Input: n = 2, k = 6
 Output: 3
 Explanation: We can construct the array [1,2], which has a sum of 3.
 It can be proven that there is no k-avoiding array with a sum less than 3.
 Constraints:
 1 <= n, k <= 50
*/

class Solution {
public:
    int minimumSum(int n, int k) {

        // Initialize a vector to store the k-avoiding array
        vector<int> arr(n);
        
        // Start from the smallest number and fill the array
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
        
        // While the sum of the array is less than k, try to find a pair of distinct elements that sum to k
        while (accumulate(arr.begin(), arr.end(), 0) < k) {
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (arr[i] + arr[j] == k) {
                        // Swap the elements to avoid the pair summing to k
                        swap(arr[i], arr[j]);
                        break;
                    }
                }
            }
        }
        // Return the minimum possible sum of the k-avoiding array
        return accumulate(arr.begin(), arr.end(), 0);
        
    }
};