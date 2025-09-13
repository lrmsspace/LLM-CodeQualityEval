/**https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/ */
//Given two integers num and k, consider a set of positive integers with the following properties:
//	The units digit of each integer is k.
//	The sum of the integers is num.
//Return the minimum possible size of such a set, or -1 if no such set exists.
//Note:
//	The set can contain multiple instances of the same integer, and the sum of an empty set is considered 0.
//	The units digit of a number is the rightmost digit of the number.
// 
//Example 1:
//Input: num = 58, k = 9
//Output: 2
//Explanation:
//One valid set is [9,49], as the sum is 58 and each integer has a units digit of 9.
//Another valid set is [19,39].
//It can be shown that 2 is the minimum possible size of a valid set.
//Example 2:
//Input: num = 37, k = 2
//Output: -1
//Explanation: It is not possible to obtain a sum of 37 using only integers that have a units digit of 2.
//Example 3:
//Input: num = 0, k = 7
//Output: 0
//Explanation: The sum of an empty set is considered 0.
// 
//Constraints:
//	0 <= num <= 3000
//	0 <= k <= 9
class Solution {
public:
    int minimumNumbers(int num, int k) {
        // The sum of a set of integers is equal to num when the units digit of each integer is k.
        // Therefore, we need to find the smallest number with a units digit of k that is greater than or equal to the units digit of num.
        // If such a number does not exist, it means it is not possible to obtain a sum of num using only integers that have a units digit of k.
        int unitsDigit = num % 10;
        if (unitsDigit < k) {
            return -1;
        }
        
        // If the units digit of num is k, we can start by adding the units digit itself to the set.
        int minSize = 1;
        int currentSum = unitsDigit;
        
        // If the units digit of num is not k, we need to find the smallest number with a units digit of k that is greater than or equal to the units digit of num.
        // We can do this by adding the smallest possible units digit of k to the current sum.
        int nextUnitsDigit = (unitsDigit + 1) % 10;
        while (currentSum + nextUnitsDigit <= num) {
            currentSum += nextUnitsDigit;
            minSize++;
            nextUnitsDigit = (nextUnitsDigit + 1) % 10;
        }
        
        return minSize;
        
    }
};