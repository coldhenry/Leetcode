/*

LRU: least recently used 
-> Discards the least recently used items first.

這題的邏輯
1. 需要一個 list 裝 key-value pair
2. 需要另一個 hashmap 拿來做 constant time find
3. 但其實真正的操作都在 list 上
4. 一個重點就是不管 get 或 put，有被用到過的東西都會被移到 list 的最前面

補充
C++ container: list: 具有可以pop/push 前後、erase in constant time 的功能
裡面的一些重點功能：pop_back, pop_front, push_front, push_back, erase
有一個下面有用到的
splice(要換到的位置，那個 list，從list裡面哪個位置(iterator)): 白話文就是把一個list特定位置換到另一個位置，不用erase再push

NOTE1: 一個iterator，就把他想成一個有順便紀錄是第幾個的實體內容，是可以直接：
auto iterator = map.find()一個被找到的iterator
iterator->second->second 可以是直接當做一個 map 的 element 的 second second

*/

class LRUCache{
    size_t m_capacity;
    MAP m_map;   //m_map_iter->first: key, m_map_iter->second: list iterator;
    LII m_list;  //m_list_iter->first: key, m_list_iter->second: value;
public:
    LRUCache(size_t capacity):m_capacity(capacity) {}

    int get(int key) {
        auto found_iter = m_map.find(key);
        if (found_iter == m_map.end()) //key doesn't exist
            return -1;
        m_list.splice(m_list.begin(), m_list, found_iter->second); //move the node corresponding to key to front
        return found_iter->second->second;                         //return value of the node
    }

    void set(int key, int value) {
        auto found_iter = m_map.find(key);
        if (found_iter != m_map.end()) //key exists
        {
            m_list.splice(m_list.begin(), m_list, found_iter->second); //move the node corresponding to key to front
            found_iter->second->second = value;                        //update value of the node
            return;
        }
        if (m_map.size() == m_capacity) //reached capacity
        {
           int key_to_del = m_list.back().first; 
           m_list.pop_back();            //remove node in list;
           m_map.erase(key_to_del);      //remove key in map
        }
        m_list.emplace_front(key, value);  //把新的放到 list 最前面
        m_map[key] = m_list.begin();       //map 的 value 是給 iterator
    }
private:
	typedef list<pair<int,int>> LII;
	typedef unordered_map<int, LII::iterator> MAP;

};