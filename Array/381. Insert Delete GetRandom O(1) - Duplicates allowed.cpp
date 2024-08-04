class RandomizedCollection {

private:
    vector<pair<int,int>>nums;
    unordered_map<int,vector<int>>mp;

public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        int ind = nums.size();
        int m_ind = mp[val].size();
        mp[val].push_back(ind);
        nums.push_back({val,m_ind});
        return m_ind == 0;
    }
    
    bool remove(int val) {

        if(mp[val].size() == 0) return false;

        // delete the last index in map.
        int ind = mp[val].back();
        mp[val].pop_back();

        // delete the index ind in nums.
        int n_size = nums.size();
        swap(nums[ind], nums[n_size - 1]);
        nums.pop_back();

        // update the swapped index in map.
        int m_val = nums[ind].first;
        int m_ind = nums[ind].second;
        mp[m_val][m_ind] = ind;

        return true;
    }
    
    int getRandom() {
        int n_size = nums.size();
        int ind = rand() % n_size;
        return nums[ind].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */