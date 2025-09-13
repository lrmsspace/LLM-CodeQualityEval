/**https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/ */
//LeetCode company workers use key-cards to unlock office doors. Each time a worker uses their key-card, the security system saves the worker's name and the time when it was used. The system emits an alert if any worker uses the key-card three or more times in a one-hour period.
//You are given a list of strings keyName and keyTime where [keyName[i], keyTime[i]] corresponds to a person's name and the time when their key-card was used in a single day.
//Access times are given in the 24-hour time format "HH:MM", such as "23:51" and "09:49".
//Return a list of unique worker names who received an alert for frequent keycard use. Sort the names in ascending order alphabetically.
//Notice that "10:00" - "11:00" is considered to be within a one-hour period, while "22:51" - "23:52" is not considered to be within a one-hour period.
// 
//Example 1:
//Input: keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"], keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
//Output: ["daniel"]
//Explanation: "daniel" used the keycard 3 times in a one-hour period ("10:00","10:40", "11:00").
//Example 2:
//Input: keyName = ["alice","alice","alice","bob","bob","bob","bob"], keyTime = ["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
//Output: ["bob"]
//Explanation: "bob" used the keycard 3 times in a one-hour period ("21:00","21:20", "21:30").
// 
//Constraints:
//	1 <= keyName.length, keyTime.length <= 105
//	keyName.length == keyTime.length
//	keyTime[i] is in the format "HH:MM".
//	[keyName[i], keyTime[i]] is unique.
//	1 <= keyName[i].length <= 10
//	keyName[i] contains only lowercase English letters.
class Solution {
    public List<String> alertNames(String[] keyName, String[] keyTime) {
        Map<String, PriorityQueue<String>> map = new HashMap<>();
        for (int i = 0; i < keyName.length; i++) {
            String name = keyName[i];
            String time = keyTime[i];
            int hour = Integer.parseInt(time.substring(0, 2));
            int minute = Integer.parseInt(time.substring(3));
            String key = hour + ":" + minute;
            if (!map.containsKey(name)) {
                map.put(name, new PriorityQueue<>());
            }
            map.get(name).add(key);
        }
        
        List<String> result = new ArrayList<>();
        for (String name : map.keySet()) {
            PriorityQueue<String> queue = map.get(name);
            int count = 0;
            while (!queue.isEmpty()) {
                String time1 = queue.poll();
                while (!queue.isEmpty() && queue.peek().equals(time1)) {
                    queue.poll();
                }
                count++;
                if (count >= 3) {
                    result.add(name);
                    break;
                }
            }
        }
        
        Collections.sort(result);
        return result;
        
    }
}