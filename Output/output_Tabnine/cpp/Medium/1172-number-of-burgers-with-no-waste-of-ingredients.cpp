/**https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/ */
//Given two integers tomatoSlices and cheeseSlices. The ingredients of different burgers are as follows:
//	Jumbo Burger: 4 tomato slices and 1 cheese slice.
//	Small Burger: 2 Tomato slices and 1 cheese slice.
//Return [total_jumbo, total_small] so that the number of remaining tomatoSlices equal to 0 and the number of remaining cheeseSlices equal to 0. If it is not possible to make the remaining tomatoSlices and cheeseSlices equal to 0 return [].
// 
//Example 1:
//Input: tomatoSlices = 16, cheeseSlices = 7
//Output: [1,6]
//Explantion: To make one jumbo burger and 6 small burgers we need 4*1 + 2*6 = 16 tomato and 1 + 6 = 7 cheese.
//There will be no remaining ingredients.
//Example 2:
//Input: tomatoSlices = 17, cheeseSlices = 4
//Output: []
//Explantion: There will be no way to use all ingredients to make small and jumbo burgers.
//Example 3:
//Input: tomatoSlices = 4, cheeseSlices = 17
//Output: []
//Explantion: Making 1 jumbo burger there will be 16 cheese remaining and making 2 small burgers there will be 15 cheese remaining.
// 
//Constraints:
//	0 <= tomatoSlices, cheeseSlices <= 107
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int diff = tomatoSlices - 2 * cheeseSlices;
        if (diff < 0 || diff % 2!= 0) return {};
        
        int jumbo = (diff + 2) / 2;
        int small = diff / 2;
        return {jumbo, small};  // return the total number of jumbo and small burgers respectively.  // The return value is a vector of two integers.  // The first integer represents the total number of jumbo burgers, and the second integer represents the total number of small burgers.  // The function should return an empty vector if it is not possible to make the remaining tomatoSlices and cheeseSlices equal to 0.  // The function should
        
    }
};