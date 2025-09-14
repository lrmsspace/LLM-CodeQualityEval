/**https://leetcode.com/problems/friends-of-appropriate-ages/ */
//There are n persons on a social media website. You are given an integer array ages where ages[i] is the age of the ith person.
//A Person x will not send a friend request to a person y (x != y) if any of the following conditions is true:
//	age[y] <= 0.5 * age[x] + 7
//	age[y] > age[x]
//	age[y] > 100 && age[x] < 100
//Otherwise, x will send a friend request to y.
//Note that if x sends a request to y, y will not necessarily send a request to x. Also, a person will not send a friend request to themself.
//Return the total number of friend requests made.
// 
//Example 1:
//Input: ages = [16,16]
//Output: 2
//Explanation: 2 people friend request each other.
//Example 2:
//Input: ages = [16,17,18]
//Output: 2
//Explanation: Friend requests are made 17 -> 16, 18 -> 17.
//Example 3:
//Input: ages = [20,30,100,110,120]
//Output: 3
//Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.
// 
//Constraints:
//	n == ages.length
//	1 <= n <= 2 * 104
//	1 <= ages[i] <= 120
class Solution {
    public int numFriendRequests(int[] ages) {
    int[] count = new int[121];
    for (int age : ages) {
        count[age]++;   
    }

    int totalRequests = 0;
    for (int ageA = 0; ageA <= 120; ageA++) {
        if (count[ageA] == 0) continue;
        for (int ageB = 0; ageB <= 120; ageB++) {
            if (count[ageB] == 0) continue;
            if (ageB <= 0.5 * ageA + 7) continue;
            if (ageB > ageA) continue;
            if (ageB > 100 && ageA < 100) continue;
            totalRequests += count[ageA] * (count[ageB] - (ageA == ageB ? 1 : 0));
        }
    }

    return totalRequests;
    }
}