/*

KET CONCEPTS
1. 兩種走向：無限循環，跟最後到1 -> 想想為何不會無限放大?
2. 只要不循環，就會走向1 -> 我們只需要檢查有沒有循環 -> 不能有 visited 過的
3. 知道怎麼把 digit 分出來
4. (進階) 如果可以想到環 + 題目問能否找到環 -> 想到 Floyd's Cycle

*/


// get the next number
int next(int n){
    int sum = 0;
    while(n != 0)
    {
    	int digit = n % 10;
        sum += (digit * digit);
        n = n / 10;
    }
    return sum;
}


//Approach 1: Visited array using Hashset
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        
        while(n != 1)
        {
            if(visited.find(n) == visited.end()) visited.insert(n);
            else return false; // 有 visited 就是無限循環了
            
            n = next(n);
        }
        
        return true;
    }
};

//Approach 2: Floyd's Cycle
public:
    bool isHappy(int n) {
        int slow = next(n);
        int fast = next(next(n));
        
        while(slow != fast)
        {
            slow = next(slow);
            fast = next(next(fast));
        }
		
		// they will eventaully meet, 就看是不是答案1        
        return fast == 1 ;
    }

