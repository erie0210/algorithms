class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=1;
        int le=0; int ri = 0;
        while(true){
            ri++;
            if(ri==nums.size()){
                break;
            }
            if(nums[le]<nums[ri]){
                cnt++;
                nums[cnt-1]=nums[ri];
                le = ri;
            }
        }
        return cnt;
    }
};