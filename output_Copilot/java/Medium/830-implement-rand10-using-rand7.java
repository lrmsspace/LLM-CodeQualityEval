/**https://leetcode.com/problems/implement-rand10-using-rand7/ */
//Given the API rand7() that generates a uniform random integer in the range [1, 7], write a function rand10() that generates a uniform random integer in the range [1, 10]. You can only call the API rand7(), and you shouldn't call any other API. Please do not use a language's built-in random API.
//Each test case will have one internal argument n, the number of times that your implemented function rand10() will be called while testing. Note that this is not an argument passed to rand10().
// 
//Example 1:
//Input: n = 1
//Output: [2]
//Example 2:
//Input: n = 2
//Output: [2,8]
//Example 3:
//Input: n = 3
//Output: [3,8,10]
// 
//Constraints:
//	1 <= n <= 105
// 
//Follow up:
//	What is the expected value for the number of calls to rand7() function?
//	Could you minimize the number of calls to rand7()?
/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {
    public int rand10() {
        // We can use the rejection sampling method to generate a random number between 1 and 10 using rand7.
        // We will generate two random numbers between 1 and 7, and use them to create a number between 1 and 49.
        // If the number is less than or equal to 40, we can map it to a number between 1 and 10.
        // If the number is greater than 40, we will discard it and try again.

        int num = 0;
        do {
            int row = rand7() - 1; // Get a number between 0 and 6
            int col = rand7() - 1; // Get a number between 0 and 6
            num = row * 7 + col; // Get a number between 0 and 48
        } while (num >= 40); // Discard numbers greater than or equal to 40

        return num % 10 + 1; // Map the number to a range of [1,10]        
    }
}