/**https://leetcode.com/problems/number-of-common-factors/ */
//Given two positive integers a and b, return the number of common factors of a and b.
//An integer x is a common factor of a and b if x divides both a and b.
// 
//Example 1:
//Input: a = 12, b = 6
//Output: 4
//Explanation: The common factors of 12 and 6 are 1, 2, 3, 6.
//Example 2:
//Input: a = 25, b = 30
//Output: 2
//Explanation: The common factors of 25 and 30 are 1, 5.
// 
//Constraints:
//	1 <= a, b <= 1000
int commonFactors(int a, int b){
    int i, j, count = 0;
    for(i = 1; i <= a; i++){
        if(a % i == 0){
            for(j = 1; j <= b; j++){
                if(b % j == 0){
                    if(i == j){
                        count++;
                    }
                }
            }
        }
    }
    return count;
}