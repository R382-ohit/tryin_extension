class RandomizedSet {
public:
    unordered_map<int, int> mpp;
    RandomizedSet() {}

    bool insert(int val) {
        if (mpp.find(val) == mpp.end()) {
            mpp[val] = 1;
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (mpp.find(val) != mpp.end()) {
            mpp.erase(val);
            return true;
        }
        return false;
    }

    int getRandom() {
        // each element must have the same probability of being returned
        int random_index = rand() % mpp.size();
        auto it = mpp.begin();
        advance(it, random_index);
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */