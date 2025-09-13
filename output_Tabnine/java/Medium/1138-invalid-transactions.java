/**https://leetcode.com/problems/invalid-transactions/ */
//A transaction is possibly invalid if:
//	the amount exceeds $1000, or;
//	if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
//You are given an array of strings transaction where transactions[i] consists of comma-separated values representing the name, time (in minutes), amount, and city of the transaction.
//Return a list of transactions that are possibly invalid. You may return the answer in any order.
// 
//Example 1:
//Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
//Output: ["alice,20,800,mtv","alice,50,100,beijing"]
//Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.
//Example 2:
//Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
//Output: ["alice,50,1200,mtv"]
//Example 3:
//Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
//Output: ["bob,50,1200,mtv"]
// 
//Constraints:
//	transactions.length <= 1000
//	Each transactions[i] takes the form "{name},{time},{amount},{city}"
//	Each {name} and {city} consist of lowercase English letters, and have lengths between 1 and 10.
//	Each {time} consist of digits, and represent an integer between 0 and 1000.
//	Each {amount} consist of digits, and represent an integer between 0 and 2000.
class Solution {
    public List<String> invalidTransactions(String[] transactions) {
        Map<String, List<String[]>> map = new HashMap<>();
        for (String transaction : transactions) {
            String[] parts = transaction.split(",");
            String name = parts[0];
            int time = Integer.parseInt(parts[1]);
            int amount = Integer.parseInt(parts[2]);
            String city = parts[3];
            List<String[]> list = map.computeIfAbsent(name, k -> new ArrayList<>());
            list.add(new String[]{city, String.valueOf(time), String.valueOf(amount)});
            if (amount > 1000) {
                list.add(new String[]{city, String.valueOf(time), String.valueOf(amount)});
            }
            for (int i = 0; i < list.size() - 1; i++) {
                String[] current = list.get(i);
                String[] next = list.get(i + 1);
                if (current[0].equals(next[0]) && Math.abs(Integer.parseInt(current[1]) - Integer.parseInt(next[1])) <= 60) {
                    list.remove(i + 1);
                    break;
                }
            }
            while (list.size() > 10) {
                list.remove(list.size() - 1);
            }
            
            // Remove duplicates
            for (int i = 0; i < list.size() - 1; i++) {
                for (int j = i + 1; j < list.size(); j++) {
                    if (list.get(i)[0].equals(list.get(j)[0]) && list.get(i)[1].equals(list.get(j)[1]) && list.get(i)[2].equals(list.get(j)[2])) {
                        list.remove(j);
                        break;
                    }
                }
            }
        }
        return new ArrayList<>(map.values()).stream().flatMap(List::stream).collect(Collectors.toList());
    }
}