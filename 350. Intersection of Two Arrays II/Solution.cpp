class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        auto it1 = nums1.begin(), it2 = nums2.begin();
        sort(it1, nums1.end());
        sort(it2, nums2.end());
        while (it1 < nums1.end() and it2 < nums2.end())
        {
            if (*it1 == *it2)
            {
                result.push_back(*it1);
                ++it1;
                ++it2;
            }
            else if (*it1 < *it2) ++it1;
            else ++it2;
        }
        return result;
    }
};