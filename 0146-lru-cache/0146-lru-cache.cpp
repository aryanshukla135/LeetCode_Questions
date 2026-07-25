class LRUCache {
public:
   // {key,val}
    list<pair<int,int>> l ;
    unordered_map<int,list<pair<int,int>> ::iterator> mp ;
    int limit = 0 ;

    LRUCache(int capacity) {
        limit = capacity ;
    }
    
    int get(int key) {
      int val = -1 ;
      if(mp.count(key)){
        auto it = mp[key];
        val = it->second ;
        l.erase(it);
        l.push_back({key,val});
        auto itr = l.end();
        itr--;
        mp[key]= itr ;
      }
      return val ;
    }
    
    void put(int key, int value) {
         if(!mp.count(key) && l.size() != limit){
            l.push_back({key,value});
            auto it = l.end();
            it--;
            mp[key] = it ;
         }else if(!mp.count(key) && l.size() == limit){
               int oldKey = l.front().first;
                mp.erase(oldKey);
                l.pop_front();

                l.push_back({key, value});

                auto it = l.end();
                it--;

                mp[key] = it;
         }else if(mp.count(key) ){

            auto it = mp[key];
            mp.erase(key);
            l.erase(it);
            l.push_back({key,value});
            auto itr = l.end();
            itr--;
            mp[key] = itr ;
         }

    }
};

// here we can not we can use queue because of if we want any want value which is in 

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */