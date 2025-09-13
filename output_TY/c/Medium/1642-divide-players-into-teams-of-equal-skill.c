/**https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/ */
//You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.
//The chemistry of a team is equal to the product of the skills of the players on that team.
//Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.
// 
//Example 1:
//Input: skill = [3,2,5,1,3,4]
//Output: 22
//Explanation: 
//Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6.
//The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.
//Example 2:
//Input: skill = [3,4]
//Output: 12
//Explanation: 
//The two players form a team with a total skill of 7.
//The chemistry of the team is 3 * 4 = 12.
//Example 3:
//Input: skill = [1,1,2,3]
//Output: -1
//Explanation: 
//There is no way to divide the players into teams such that the total skill of each team is equal.
// 
//Constraints:
//	2 <= skill.length <= 105
//	skill.length is even.
//	1 <= skill[i] <= 1000
long long dividePlayers(int* skill, int skillSize){
    int i, j, sum, count, max, min, temp;
    long long result;
    sum = 0;
    count = 0;
    max = 0;
    min = 1000;
    for (i = 0; i < skillSize; i++) {
        sum += skill[i];
        if (skill[i] > max) {
            max = skill[i];
        }
        if (skill[i] < min) {
            min = skill[i];
        }
    }
    if (sum % 2 != 0) {
        return -1;
    }
    sum = sum / 2;
    for (i = 0; i < skillSize; i++) {
        for (j = i + 1; j < skillSize; j++) {
            if (skill[i] + skill[j] == sum) {
                count++;
                result += (long long)skill[i] * skill[j];
            }
        }
    }
    if (count != skillSize / 2) {
        return -1;
    }
    return result;
}
