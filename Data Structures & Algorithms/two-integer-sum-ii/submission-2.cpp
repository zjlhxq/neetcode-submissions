class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0; i<numbers.size(); i++) {
            int complement = target - numbers[i];
            int l = i +1, r = numbers.size() - 1;
            while (l<=r) {
                int mid = l + (r - l) / 2;
                if (numbers[mid] == complement) {
                    return {i+1, mid + 1};
                } else if(numbers[mid] < complement) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

    }
};
