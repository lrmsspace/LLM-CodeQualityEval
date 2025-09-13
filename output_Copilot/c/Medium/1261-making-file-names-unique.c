/**https://leetcode.com/problems/making-file-names-unique/ */
//Given an array of strings names of size n. You will create n folders in your file system such that, at the ith minute, you will create a folder with the name names[i].
//Since two files cannot have the same name, if you enter a folder name that was previously used, the system will have a suffix addition to its name in the form of (k), where, k is the smallest positive integer such that the obtained name remains unique.
//Return an array of strings of length n where ans[i] is the actual name the system will assign to the ith folder when you create it.
// 
//Example 1:
//Input: names = ["pes","fifa","gta","pes(2019)"]
//Output: ["pes","fifa","gta","pes(2019)"]
//Explanation: Let's see how the file system creates folder names:
//"pes" --> not assigned before, remains "pes"
//"fifa" --> not assigned before, remains "fifa"
//"gta" --> not assigned before, remains "gta"
//"pes(2019)" --> not assigned before, remains "pes(2019)"
//Example 2:
//Input: names = ["gta","gta(1)","gta","avalon"]
//Output: ["gta","gta(1)","gta(2)","avalon"]
//Explanation: Let's see how the file system creates folder names:
//"gta" --> not assigned before, remains "gta"
//"gta(1)" --> not assigned before, remains "gta(1)"
//"gta" --> the name is reserved, system adds (k), since "gta(1)" is also reserved, systems put k = 2. it becomes "gta(2)"
//"avalon" --> not assigned before, remains "avalon"
//Example 3:
//Input: names = ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece"]
//Output: ["onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece(4)"]
//Explanation: When the last folder is created, the smallest positive valid k is 4, and it becomes "onepiece(4)".
// 
//Constraints:
//	1 <= names.length <= 5 * 104
//	1 <= names[i].length <= 20
//	names[i] consists of lowercase English letters, digits, and/or round brackets.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** getFolderNames(char** names, int namesSize, int* returnSize) {

        *returnSize = namesSize;
        char** result = (char**)malloc(namesSize * sizeof(char*));
        if (!result) return NULL;

        // Hash map to store the count of each base name
        typedef struct {
            char* key;
            int value;
        } HashMapEntry;

        HashMapEntry* hashMap = (HashMapEntry*)calloc(namesSize * 2, sizeof(HashMapEntry));
        if (!hashMap) {
            free(result);
            return NULL;
        }

        int hashMapSize = namesSize * 2;

        // Helper function to calculate hash
        int hashFunction(const char* str, int size) {
            unsigned long hash = 5381;
            while (*str) {
                hash = ((hash << 5) + hash) + *str++;
            }
            return hash % size;
        }

        // Helper function to insert into hash map
        void insertIntoHashMap(const char* key, int value) {
            int index = hashFunction(key, hashMapSize);
            while (hashMap[index].key != NULL) {
                if (strcmp(hashMap[index].key, key) == 0) {
                    hashMap[index].value = value;
                    return;
                }
                index = (index + 1) % hashMapSize;
            }
            hashMap[index].key = strdup(key);
            hashMap[index].value = value;
        }

        // Helper function to get value from hash map
        int getFromHashMap(const char* key) {
            int index = hashFunction(key, hashMapSize);
            while (hashMap[index].key != NULL) {
                if (strcmp(hashMap[index].key, key) == 0) {
                    return hashMap[index].value;
                }
                index = (index + 1) % hashMapSize;
            }
            return -1;
        }

        for (int i = 0; i < namesSize; i++) {
            char* name = names[i];
            int count = getFromHashMap(name);

            if (count == -1) {
                // Name is unique
                result[i] = strdup(name);
                insertIntoHashMap(name, 1);
            } else {
                // Name is not unique, find the next available name
                char newName[256];
                while (1) {
                    snprintf(newName, sizeof(newName), "%s(%d)", name, count);
                    if (getFromHashMap(newName) == -1) {
                        result[i] = strdup(newName);
                        insertIntoHashMap(newName, 1);
                        insertIntoHashMap(name, count + 1);
                        break;
                    }
                    count++;
                }
            }
        }

        // Free hash map keys
        for (int i = 0; i < hashMapSize; i++) {
            if (hashMap[i].key) {
                free(hashMap[i].key);
            }
        }
        free(hashMap);

        return result;
}