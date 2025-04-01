class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
    unordered_map<int, int> sumMap;  
    int prefixSum = 0, count = 0;

    sumMap[0] = 1;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        if (sumMap.find(prefixSum - k) != sumMap.end()) {
            count += sumMap[prefixSum - k]; 
        }

        sumMap[prefixSum]++;
    }

    return count;
    }
};