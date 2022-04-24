class UndergroundSystem {
    struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};
    unordered_map<int, pair<string,int>> checkInMap;
    unordered_map<pair<string,string>, pair<int,int>, hash_pair> totalDurationmap;
public:
    UndergroundSystem() {
        checkInMap.clear();
        totalDurationmap.clear();
    }
    
    void checkIn(int id, string startStation, int t) {
        checkInMap[id] = make_pair(startStation, t);
    }
    
    void checkOut(int id, string endStation, int t) {
        auto it = checkInMap.find(id);
        if (it != checkInMap.end()) {
            string startStation = it->second.first;
            int startTime = it->second.second;
            pair<string,string> stations = make_pair(startStation, endStation);
            auto it1 = totalDurationmap.find(stations);
            if (it1 != totalDurationmap.end()) {
                int duration = it1->second.first;
                int numberOfTrips = it1->second.second;
                totalDurationmap[stations] = make_pair(duration + t - startTime, numberOfTrips + 1);
            } else {
                totalDurationmap[stations] = make_pair(t - startTime, 1);
            }
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<string,string> key = make_pair(startStation,endStation);
        pair<int,int> value = totalDurationmap[key];
        int totalDuration = value.first;
        int numberOfTrips = value.second;
        return (double)totalDuration / numberOfTrips;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */