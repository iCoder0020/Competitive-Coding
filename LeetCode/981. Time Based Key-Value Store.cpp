/*
ID: iCoder0020
PROG: Time Based Key-Value Store
LANG: C++                  
*/

class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, map<int,string>>M;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
       M[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) 
    {
        auto it1 = M.find(key);
        if(it1 == M.end())
            return "";
        auto it = M[key].upper_bound(timestamp);
        if(it == M[key].begin())
            return "";
        it--;
        return (*it).second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */