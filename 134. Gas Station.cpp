class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> difference(gas.size(),0);
        int start = -1;
        int sum = 0;
        for(int i=0;i<gas.size();i++){
            difference[i] = gas[i] - cost[i];
            if(difference[i] >= 0 && start == -1){
                start = i;
            }
            sum += difference[i];
        }
        if(sum < 0){
            return -1;
        }
        else{
            int cur_sum = difference[start];
            int has_started = true;
            for(int i = start + 1;i < difference.size();i++){
                if(has_started){
                    cur_sum += difference[i];
                    if(cur_sum < 0){
                        has_started = false;
                        cur_sum = 0;
                    }
                }
                else{
                    if(difference[i] > 0){
                        start = i;
                        cur_sum = difference[i];
                        has_started = true;
                    }
                }
            }
            return start;
        }
    }
};