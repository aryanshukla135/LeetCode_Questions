/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

         if(head->next->next == nullptr){
            return {-1,-1};
         }
         ListNode*curr = head->next;
         ListNode*prev= head ;
         ListNode*currnext = nullptr;

         int mini = INT_MAX ;
         int maxi = -1 ;
         int first = -1 ;
         int prevval = -1;
         int last = -1 ;
         int cnt =1 ;

         while(curr->next != nullptr){
            currnext = curr->next ;
            if(curr->val > prev->val && curr->val > currnext->val){
                if(first == -1) first = cnt ;
                last = cnt ;
                if(prevval != -1)
                mini = min(mini,last-prevval);
                prevval = last;
            }
            if(curr->val < prev->val && curr->val < currnext->val){
                if(first == -1) first = cnt ;
                last = cnt ;
                if(prevval != -1)
                mini = min(mini,last-prevval);
                prevval = last;
            }
            cnt++;
            prev = curr ;
            curr  = currnext;
         }
         if(first == last){
            return {-1,-1};
         }
         cout<<last<<" "<<first;
         maxi = last - first ;
         return {mini,maxi};

    }
};