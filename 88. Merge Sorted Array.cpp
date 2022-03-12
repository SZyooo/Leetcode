class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> arr1(nums1.begin(),nums1.begin()+m);
        int sentinel1 = 0, sentinel2 = 0;
        int inputIdx = 0;
        while(sentinel1!=m || sentinel2!=n)
        {
            if(sentinel1 == m)
            {
                nums1[inputIdx++] = nums2[sentinel2++];
            }
            else if(sentinel2 == n)
            {
                nums1[inputIdx++] = arr1[sentinel1++];
            }
            else
            {
                if(arr1[sentinel1] <= nums2[sentinel2])
                {
                    nums1[inputIdx++] = arr1[sentinel1++];
                }
                else{
                    nums1[inputIdx++] = nums2[sentinel2++];
                }
            }
        }
    }
};
