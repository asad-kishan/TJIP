// 380. Insert Delete GetRandom O(1)
// https://leetcode.com/problems/insert-delete-getrandom-o1/description/

class RandomizedSet {
public:
    vector<int> list;
    unordered_map<int, int> val_to_idx;

    RandomizedSet() {
        list.clear();
        val_to_idx.clear();
    }
    
    bool insert(int val) {
        if(val_to_idx.find(val) != val_to_idx.end()) return false;
        
        val_to_idx[val] = list.size();
        list.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(val_to_idx.find(val) == val_to_idx.end()) return false;

        int tar_idx = val_to_idx[val];
        int last_idx = list.size() - 1;
        swap(list[tar_idx], list[last_idx]);
        val_to_idx[list[tar_idx]] = tar_idx;
        list.pop_back();
        val_to_idx.erase(val);
        return true;
    }
    
    int getRandom() {
        int rand_idx = rand() % list.size();
        return list[rand_idx];
    }
}; 
