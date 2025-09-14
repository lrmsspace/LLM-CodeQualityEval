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
/**
 * @param {number[]} skill
 * @return {number}
 */
var dividePlayers = function(skill) {
    const n = skill.length;
    const sum = skill.reduce((a, b) => a + b, 0);
    if (sum % 2!== 0) return -1;
    const target = sum / 2;
    const count = new Map();
    
    for (let i = 0; i < n; i++) {
        const diff = target - skill[i];
        if (count.has(diff)) {
            return count.get(diff) * skill[i];
        }
        count.set(skill[i], (count.get(skill[i]) || 0) + 1);
    }
    
    return -1;
    
};