class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        for (auto i : nums1)
            if (!binary_search(result.begin(), result.end(), i) and
                binary_search(nums2.begin(), nums2.end(), i))
                result.push_back(i);
        return result;
    }
};