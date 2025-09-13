/**https://leetcode.com/problems/three-equal-parts/ */
//You are given an array arr which consists of only zeros and ones, divide the array into three non-empty parts such that all of these parts represent the same binary value.
//If it is possible, return any [i, j] with i + 1 < j, such that:
//	arr[0], arr[1], ..., arr[i] is the first part,
//	arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
//	arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
//	All three parts have equal binary values.
//If it is not possible, return [-1, -1].
//Note that the entire part is used when considering what binary value it represents. For example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.
// 
//Example 1:
//Input: arr = [1,0,1,0,1]
//Output: [0,3]
//Example 2:
//Input: arr = [1,1,0,1,1]
//Output: [-1,-1]
//Example 3:
//Input: arr = [1,1,0,0,1]
//Output: [0,2]
// 
//Constraints:
//	3 <= arr.length <= 3 * 104
//	arr[i] is 0 or 1
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
int n = arr.size();
vector<int> result{-1, -1};

int totalOnes = count(arr.begin(), arr.end(), 1);
if (totalOnes % 3 != 0) return result;
if (totalOnes == 0) return {0, n - 1};

int k = totalOnes / 3;
int first = -1, second = -1, third = -1, count = 0;

for (int i = 0; i < n; ++i) {
    if (arr[i] == 1) {
        if (count == 0) first = i;
        if (count == k) second = i;
        if (count == 2 * k) third = i;
        count++;
    }
}

while (third < n && arr[first] == arr[second] && arr[second] == arr[third]) {
    first++; second++; third++;
}

if (third == n) result = {first - 1, second};
return result;
    }
};