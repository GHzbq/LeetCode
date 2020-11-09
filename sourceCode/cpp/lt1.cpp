#if 1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> ret;
        int size = static_cast<int>(nums.size());
        if (size < 2) {
            return ret;
        }
        
        std::unordered_map<int, int> unorderedMap(nums.size());
        int temp = 0;
        auto pos = unorderedMap.begin();
        for (int i = 0; i < size; ++i) {
            temp = target - nums[i];
            pos = unorderedMap.find(temp);
            if (pos != unorderedMap.end()) {
                ret.push_back(unorderedMap[temp]);
                ret.push_back(i);
                return ret;
            } else {
                unorderedMap.insert(std::make_pair(nums[i], i));
            }
        }
        return ret;
    }
};

#else

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> ret;
        if(nums.size() < 2)
            return ret;
        for(size_t i = 0; i < nums.size(); ++i)
        {
            for(size_t j = i + 1; j < nums.size(); ++j )
            {
                if(nums[i] + nums[j] == target)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                    break;
                }
            }
        }

        return ret;
    }
};

#endif