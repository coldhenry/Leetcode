





// Approach 1: Simple Check 
// B 如果是 rotate string，那他會存在於 A+A裡面
// 記得一個 corner case: A = a, B = aa，所以他們長度要一樣
bool rotateString(string A, string B) {                
    return A.size() == B.size() && (A + A).find(B) != string::npos;
}   