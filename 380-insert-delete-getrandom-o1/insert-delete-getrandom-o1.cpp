class RandomizedSet {
public:
    unordered_map<int, int> mpp;
    vector<int> nums;
    int index;
    RandomizedSet() { index = 0; }

    bool insert(int val) {
        if (mpp.find(val) == mpp.end()) {
            mpp[val] = index;
            nums.push_back(val);
            index++;
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (mpp.find(val) != mpp.end()) {
            int pos = mpp[val];
            int ele = nums.back();
            nums[pos] = ele;
            nums.back() = val;
            nums.pop_back();
            mpp[ele] = pos;
            mpp.erase(val);
            index--;
            return true;
        }
        return false;
    }

    int getRandom() {
        int idx = rand() % index;
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */