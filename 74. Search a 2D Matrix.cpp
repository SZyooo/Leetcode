class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = -1, right = matrix.size();
        int mid;
        while(left + 1 < right)
        {
            mid = left + (right - left)/2;
            if(matrix[mid][0] >= target)
            {
                right = mid;
            }
            else{
                left = mid;
            }
        }
        if(right < matrix.size() && matrix[right][0] == target)
            return true;
        else{
            if(left < 0)
            {
                return false;
            }
            int inline_left = left;
            left = -1, right = matrix[0].size();
            while(left + 1 < right)
            {
                mid = (left + right) /2;
                if(matrix[inline_left][mid] >= target)
                {
                    right = mid;
                }
                else
                    left = mid;
            }
            if(right >= matrix[0].size())
                return false;
            return matrix[inline_left][right] == target;
        }
    }
};