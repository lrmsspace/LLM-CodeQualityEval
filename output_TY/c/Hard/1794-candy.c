/**https://leetcode.com/problems/candy/ */
//There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
//You are giving candies to these children subjected to the following requirements:
//	Each child must have at least one candy.
//	Children with a higher rating get more candies than their neighbors.
//Return the minimum number of candies you need to have to distribute the candies to the children.
// 
//Example 1:
//Input: ratings = [1,0,2]
//Output: 5
//Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
//Example 2:
//Input: ratings = [1,2,2]
//Output: 4
//Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
//The third child gets 1 candy because it satisfies the above two conditions.
// 
//Constraints:
//	n == ratings.length
//	1 <= n <= 2 * 104
//	0 <= ratings[i] <= 2 * 104
int candy(int* ratings, int ratingsSize){
    int *candy = malloc(sizeof(int) * ratingsSize);
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    for (i = 0; i < ratingsSize; i++) {
        candy[i] = 1;
    }
    for (i = 1; i < ratingsSize; i++) {
       if (ratings[i] > ratings[i - 1]) {
           candy[i] = candy[i - 1] + 1;
       }
    }
    for (i = ratingsSize - 2; i >= 0; i--) {
       if (ratings[i] > ratings[i + 1]) {
           candy[i] = max(candy[i], candy[i + 1] + 1);
       }
    }
    return sum(candy, ratingsSize);
}