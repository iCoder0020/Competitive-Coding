/*
ID: ishan-sang
PROG: LRU Cache
LANG: C++                  
*/

#include<bits/stdc++.h>
unordered_map<int,pair<int, list<int>:: iterator>>M;
list<int> dll;
int cap;
LRUCache::LRUCache(int capacity) 
{
    cap = capacity;
    dll.clear();
    M.clear();
}

int LRUCache::get(int key) 
{
    if(M.find(key) == M.end())
        return -1;
    else
    {
        list<int>:: iterator it = M[key].second;
        dll.erase(it);
        dll.push_front(key);
        M[key].second = dll.begin();           
        return M[key].first;
    }
}

void LRUCache::set(int key, int value) 
{
    if(M.find(key) == M.end())
    {
        if(dll.size() == cap)
        {
            int k = dll.back();
            dll.pop_back();
            M.erase(k);
        }
    }
    else
    {
        list<int>:: iterator it = M[key].second;
        dll.erase(it);
    }
    dll.push_front(key);
    M[key] = {value, dll.begin()};
}
