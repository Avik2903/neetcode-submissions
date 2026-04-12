class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int head = 0;
        int tail = numbers.size() - 1;
        while(head < tail)
        {
            int sum = numbers[head] + numbers[tail];
            if (sum == target)
            {
                result.push_back(head+1);
                result.push_back(tail + 1);
                return result;
            }
            if (sum < target) head++;
            if (sum > target) tail--;

        }
        return result;
    }
};
