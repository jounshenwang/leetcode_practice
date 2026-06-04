/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//------------哈希表法----------------
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen;//哈希表也是可以储存链表的
        while(head!=nullptr){//环形链表没有结束，也就是没有空指针，而一旦有空指针了，那肯定不是环形链表
            if(seen.count(head)){//哈希表里记录过这个节点说明是环形
                return true;
            }
            seen.insert(head);//哈希表里没有这个节点就加进去
            head = head->next;//更新条件
        }
        return false;//遇到空指针跳出循环
    }
};

//------------快慢指针（龟兔赛跑）--------------
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //边界情况，空链表或者只有一个节点
        if(head == nullptr || head->next ==nullptr){
            return false;
        } 
        //创建快慢指针
        ListNode* slow=head;
        ListNode* fast=head->next;
        //循环条件为两指针不相等，即乌龟追上兔子，因为如果没有环，乌龟永远追不上兔子
        while(slow!=fast){
            //进了循环还要判断一次满指针没追上快指针是不是因为快指针已经到空了
            if(fast == nullptr || fast->next ==nullptr){
                return false;
            }
            slow=slow->next;
            fast=fast->next->next;//为什么快指针要走两步？因为如果是环形链表，快指针每次走两步，慢指针每次走一步，那么快指针就会在某个时刻追上慢指针，如果不是环形链表，快指针会先到达空指针，跳出循环。
        }
        //到这里说明追上了，那就是环
        return true;
    }
};