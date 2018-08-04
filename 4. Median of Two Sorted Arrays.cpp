class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        vector<int> nums;
        vector<int>::iterator iter1 = nums1.begin();
        vector<int>::iterator iter2 = nums2.begin();
        while (iter1 != nums1.end() && iter2 != nums2.end()) {
            if (*iter1 < *iter2)
                nums.push_back(*(iter1++));
            else
                nums.push_back(*(iter2++));
        }
        while (iter1 != nums1.end())
            nums.push_back(*(iter1++));
        while (iter2 != nums2.end())
            nums.push_back(*(iter2++));

        int mid = nums.size() / 2;
        return (mid * 2 != nums.size()) ? nums[mid] / 1.0 : (nums[mid - 1] + nums[mid]) / 2.0;
    }
};