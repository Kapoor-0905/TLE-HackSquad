class Solution {
public:
    
    int len(ListNode *head) {
        int n = 0;
        ListNode *temp = head;
        while(temp != NULL) {
            temp = temp->next;
            n++;
        }
        
        return n;
    }
    
    ListNode *getIntersectionNode(ListNode *headX, ListNode *headY) {
        int n = len(headX), m = len(headY);
        
        int diff = abs(n - m);
        
        for (int i = 0; i < diff; i++) {
            if(n > m) headX = headX->next;
            else headY = headY->next;
        }
        
        while (headX != NULL or headY != NULL) {
            if (headX == headY) return headX;
            
            headX = headX->next;
            headY = headY->next;
        }
        
        return NULL;
    }
};
