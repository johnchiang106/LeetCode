class Solution {
#define pair_N_i pair<ListNode*,int>
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())   return NULL;
        auto my_comp = [](const pair_N_i& a, const pair_N_i& b) {
            return a.first->val > b.first->val;
        };
        priority_queue<pair_N_i, vector<pair_N_i>, decltype(my_comp)> pq{my_comp};
        int n = lists.size();
        for(int i = 0; i < n; ++i){
            if(lists[i]){
                pq.push({lists[i],i});
            }
        }
        if(pq.empty())   return NULL;

        ListNode* ans = new ListNode(), *last = ans;
        do{
            ListNode* curr = pq.top().first;
            int i = pq.top().second;
            pq.pop();
            if(curr->next)  pq.push({curr->next,i});
            last->next = curr, last = curr;
        }while(!pq.empty());

        last = ans->next;
        delete ans;
        return last;
    }
#undef pair_N_i
};