/**https://leetcode.com/problems/finding-3-digit-even-numbers/ */
//You are given an integer array digits, where each element is a digit. The array may contain duplicates.
//You need to find all the unique integers that follow the given requirements:
//	The integer consists of the concatenation of three elements from digits in any arbitrary order.
//	The integer does not have leading zeros.
//	The integer is even.
//For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.
//Return a sorted array of the unique integers.
// 
//Example 1:
//Input: digits = [2,1,3,0]
//Output: [102,120,130,132,210,230,302,310,312,320]
//Explanation: All the possible integers that follow the requirements are in the output array. 
//Notice that there are no odd integers or integers with leading zeros.
//Example 2:
//Input: digits = [2,2,8,8,2]
//Output: [222,228,282,288,822,828,882]
//Explanation: The same digit can be used as many times as it appears in digits. 
//In this example, the digit 8 is used twice each time in 288, 828, and 882. 
//Example 3:
//Input: digits = [3,7,5]
//Output: []
//Explanation: No even integers can be formed using the given digits.
// 
//Constraints:
//	3 <= digits.length <= 100
//	0 <= digits[i] <= 9
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findEvenNumbers(int* digits, int digitsSize, int* returnSize){
 int count[10] = {0};
    for (int i = 0; i < digitsSize; i++) {
        count[digits[i]]++;
    }

    int *result = (int *)malloc(1000 * sizeof(int));
    *returnSize = 0;

    for (int hundreds = 1; hundreds <= 9; hundreds++) {
        for (int tens = 0; tens <= 9; tens++) {
            for (int units = 0; units <= 9; units += 2) {
                if (count[hundreds] > 0 && count[tens] > (hundreds == tens) && count[units] > (hundreds == units) + (tens == units)) {
                    result[*returnSize] = hundreds * 100 + tens * 10 + units;
                    (*returnSize)++;
                }
            }
        }
    }

    qsort(result, *returnSize, sizeof(int), compare);
    return result;
}
