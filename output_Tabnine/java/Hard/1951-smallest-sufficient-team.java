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
class Solution {
    public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
        // Step 1: Create a map to store the frequency of each skill
        Map<String, Integer> skillFrequency = new HashMap<>();
        for (String skill : req_skills) {
            skillFrequency.put(skill, 1);
        }
        
        // Step 2: Create a priority queue to store the people with their skills and their total skills required
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(people -> -skillFrequency.get(people[0])));
        for (int i = 0; i < people.size(); i++) {
            pq.offer(new int[]{i, people.get(i).size()});
            for (String skill : people.get(i)) {
                skillFrequency.put(skill, skillFrequency.getOrDefault(skill, 0) + 1);
            }
        }
        
        // Step 3: Create a set to store the current team
        Set<Integer> team = new HashSet<>();
        
        // Step 4: Create a variable to store the minimum team size
        int minTeamSize = Integer.MAX_VALUE;
        
        // Step 5: Iterate through the priority queue and add people to the team until the minimum team size is reached
        while (!pq.isEmpty() && team.size() < minTeamSize) {
            int[] person = pq.poll();
            int personIndex = person[0];
            int personSkillsRequired = person[1];
            
            // Step 6: Add the person to the team if they have all the required skills
            if (hasAllSkills(personIndex, people, skillFrequency)) {
                team.add(personIndex);
                minTeamSize = team.size();
            }
        }
        
        // Step 7: Convert the set to an array and return it
        int[] result = new int[team.size()];
        int index = 0;
        for (int personIndex : team) {
            result[index++] = personIndex;
        }
        return result;

        
    }
}