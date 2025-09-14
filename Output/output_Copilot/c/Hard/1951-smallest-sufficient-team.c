/**https://leetcode.com/problems/smallest-sufficient-team/ */
//In a project, you have a list of required skills req_skills, and a list of people. The ith person people[i] contains a list of skills that the person has.
//Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.
//	For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].
//Return any sufficient team of the smallest possible size, represented by the index of each person. You may return the answer in any order.
//It is guaranteed an answer exists.
// 
//Example 1:
//Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
//Output: [0,2]
//Example 2:
//Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
//Output: [1,2]
// 
//Constraints:
//	1 <= req_skills.length <= 16
//	1 <= req_skills[i].length <= 16
//	req_skills[i] consists of lowercase English letters.
//	All the strings of req_skills are unique.
//	1 <= people.length <= 60
//	0 <= people[i].length <= 16
//	1 <= people[i][j].length <= 16
//	people[i][j] consists of lowercase English letters.
//	All the strings of people[i] are unique.
//	Every skill in people[i] is a skill in req_skills.
//	It is guaranteed a sufficient team exists.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallestSufficientTeam(char** req_skills, int req_skillsSize, char*** people, int peopleSize, int* peopleColSize, int* returnSize) {
       int n = req_skillsSize;
        int m = 1 << n;
        int* dp = (int*)malloc(m * sizeof(int));
        int* parent = (int*)malloc(m * sizeof(int));
        for (int i = 0; i < m; i++) {
            dp[i] = INT_MAX;
            parent[i] = -1;
        }
        dp[0] = 0;
        for (int i = 0; i < peopleSize; i++) {
            int skills = 0;
            for (int j = 0; j < peopleColSize[i]; j++) {
                for (int k = 0; k < n; k++) {
                    if (strcmp(people[i][j], req_skills[k]) == 0) {
                        skills |= 1 << k;
                        break;
                    }
                }
            }
            for (int j = m - 1; j >= 0; j--) {
                if (dp[j] == INT_MAX) continue;
                int next = j | skills;
                if (dp[next] > dp[j] + 1) {
                    dp[next] = dp[j] + 1;
                    parent[next] = j;
                }
            }
        }
        int* result = (int*)malloc(dp[m - 1] * sizeof(int));
        int index = m - 1, count = 0;
        while (index > 0) {
            int prev = parent[index];
            for (int i = 0; i < n; i++) {
                if ((prev & (1 << i)) && !(index & (1 << i))) {
                    result[count++] = i;
                }
            }
            index = prev;
        }
        *returnSize = count;
        return result;     
}