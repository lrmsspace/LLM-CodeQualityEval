/**https://leetcode.com/problems/adding-two-negabinary-numbers/ */
//Given two numbers arr1 and arr2 in base -2, return the result of adding them together.
//Each number is given in array format:  as an array of 0s and 1s, from most significant bit to least significant bit.  For example, arr = [1,1,0,1] represents the number (-2)^3 + (-2)^2 + (-2)^0 = -3.  A number arr in array, format is also guaranteed to have no leading zeros: either arr == [0] or arr[0] == 1.
//Return the result of adding arr1 and arr2 in the same format: as an array of 0s and 1s with no leading zeros.
// 
//Example 1:
//Input: arr1 = [1,1,1,1,1], arr2 = [1,0,1]
//Output: [1,0,0,0,0]
//Explanation: arr1 represents 11, arr2 represents 5, the output represents 16.
//Example 2:
//Input: arr1 = [0], arr2 = [0]
//Output: [0]
//Example 3:
//Input: arr1 = [0], arr2 = [1]
//Output: [1]
// 
//Constraints:
//	1 <= arr1.length, arr2.length <= 1000
//	arr1[i] and arr2[i] are 0 or 1
//	arr1 and arr2 have no leading zeros
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int n = max(arr1.size(), arr2.size());
        vector<int> result(n + 1, 0);
        int carry = 0;
        
        for (int i = 0; i < n; i++) {
            int sum = carry;
            if (i < arr1.size()) sum += arr1[arr1.size() - 1 - i];
            if (i < arr2.size()) sum += arr2[arr2.size() - 1 - i];
            result[n - 1 - i] = sum % 2;
            carry = sum / 2;
        }
        
        if (carry == 1) result.insert(result.begin(), 1);
        
        while (result.size() > 1 && result[0] == 0) result.erase(result.begin());
        
        return result;
        
    }
};