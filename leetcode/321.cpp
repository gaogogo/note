#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        //int end1 = 0, endl2 = 0;
        vector<int> res;
        vector<int>::iterator it_1 = nums1.begin();
        vector<int>::iterator it_2 = nums2.begin();
        vector<int>::iterator it_max_1 = max_element(nums1.begin(),nums1.end());
        vector<int>::iterator it_max_2 = max_element(nums2.begin(),nums2.end());
        if(*it_max_1 >= *it_max_2) {
            res.push_back(*it_max_1);
            it_1 = it_max_1;
        }
        else {
            res.push_back(*it_max_2);
            it_2 = it_max_2;
        }
        for(int i=2; i <= k; i++) {
            if (it_1 != nums1.end() - 1 || it_2 != nums2.end() - 1) {
                it_max_1 = max_element(it_1, nums1.end());
                it_max_2 = max_element(it_2, nums2.end());
                if(*it_max_1 >= *it_max_2) {
                    res.push_back(*it_max_1);
                    it_1 = it_max_1;
                }
                else {
                    res.push_back(*it_max_2);
                    it_2 = it_max_2;
                }
            }
            else {
                
            }
        }
        return res;
    }
}
