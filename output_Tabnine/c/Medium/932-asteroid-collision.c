/**https://leetcode.com/problems/asteroid-collision/ */
//We are given an array asteroids of integers representing asteroids in a row.
//For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
//Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
// 
//Example 1:
//Input: asteroids = [5,10,-5]
//Output: [5,10]
//Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
//Example 2:
//Input: asteroids = [8,-8]
//Output: []
//Explanation: The 8 and -8 collide exploding each other.
//Example 3:
//Input: asteroids = [10,2,-5]
//Output: [10]
//Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
// 
//Constraints:
//	2 <= asteroids.length <= 104
//	-1000 <= asteroids[i] <= 1000
//	asteroids[i] != 0
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* stack = malloc(asteroidsSize * sizeof(int));
    int top = -1;
    
    for (int i = 0; i < asteroidsSize; i++) {
        while (top >= 0 && stack[top] > 0 && asteroids[i] < 0 && stack[top] * asteroids[i] < 0) {
            if (stack[top] == -asteroids[i]) {
                top--;
                break;
            }
            top--;
        }
        stack[++top] = asteroids[i];
    }
    
    *returnSize = top + 1;
    int* result = malloc(top + 1 * sizeof(int));
    for (int i = 0; i <= top; i++) {
        result[i] = stack[i];
    }
    
    free(stack);
    
    return result;
    
}