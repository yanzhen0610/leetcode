class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        int i, tmp, result[2];
        for (i = 0; i < nums.size(); ++i)
        {
            tmp = nums[i];
            if (m[target - tmp])
            {
                result[0] = m[target - tmp] - 1;
                result[1] = i;
                break;
            }
            m[tmp] = i + 1;
        }
        return vector<int>({result[0], result[1]});
    }
};