class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v= nums1;
        for (auto it : nums2) v.push_back(it);
        sort(v.begin(), v.end());
        int n = v.size();
        return n%2==0? (v[(n/2)-1] + v[n/2])/2.0 : v[(n-1)/2];
    }
};
