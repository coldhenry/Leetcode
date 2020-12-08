/*

這題可以回溯到以前寫的一些
一個 Unordered lists 要變 ordered list
會想到甚麼? 以前做過的是 merge 兩個 Ordered list 還有 找一個 list 的中間 node

所以如果我們能break down 成小片小片的 ordered list，是不是就可以全部組起來變一個 ordered list
這個解法就是 merge sort / divide conquer




*/


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        // 無中生有必須要先從真實的 ListNode開始 initiate
        ListNode dummyHead(0);
        ListNode* ptr = &dummyHead;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        // 因為 list1 或 list2 有人先變 null 了，直接把剩下段接上去
        ptr->next = list1? list1 : list2;

        return dummyHead.next; // 不是只有ptr可回傳，謹記謹記
    }

    ListNode* getMid(ListNode* head) {
        ListNode* midPrev = nullptr;
        while (head && head->next) {
            midPrev = (midPrev == nullptr) ? head : midPrev->next;
            head = head->next->next;
        }
        // 在 linked list 當中，奇數的中間就是中間，偶數的中間是右邊那個(剛好可以讓奇數的位置是對的)
        ListNode* mid = midPrev->next;
        // 這邊只是在刪 pointer
        midPrev->next = nullptr;
        return mid;
    }
};