//https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    struct ListNode *cur1 = l1, *cur2 = l2, *sum = NULL, *curSum = NULL; 
    int carry = 0, acc = 0;
    
    // Writing loops and their conditions is a good first approach
    while(cur1 || cur2 || carry){
        
        
        if(curSum == NULL){ // create inital node
            curSum = (struct ListNode*) malloc(sizeof(struct ListNode));
            curSum->next = NULL;
            sum = curSum; // save list head
            
            
        }
        else{ //create new node and advance to it
            curSum->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            curSum->next->next = NULL;
            curSum = curSum->next;
        }


        /*
        In every iteration of this loop, these two actions must take place. They were the second thing I wrote down. I think of them as "universal truths." 
        Finding these and writing them down is a good stragety, its borrowed from mathematical proof writing. 
        */
        if(cur1){
            acc += cur1->val;
            cur1 = cur1->next;
            
        }
        if(cur2){
            acc += cur2->val;
            cur2 = cur2->next;
        }
      
        
        acc += carry;
        
        curSum->val = acc % 10;
        
        carry = 0;
        if(acc >= 10){
            carry = 1;
        }
        
        acc = 0;
    }
    

    return  sum;
    
}

/* 
  bonus: This was my first attempt at the problem. It mostly works and I think its pretty clever, but I didnt account for integer overflow. One of the problems constraints is that the numbers can have
  up to 100 digits, making values far greater than the 32 bits of an integer.
*/

/*
int listToInt(struct ListNode* l){
    int weight = 1, base = 10, sum = 0;
    struct ListNode *cur = l;
    while(cur != NULL){
        
        
        
        sum += cur->val * weight;
        

        cur = cur->next;

        
        weight *= base;
    }
    return sum;
}
struct ListNode* intToList(int i){
    
    struct ListNode* head = (struct ListNode *) malloc(sizeof(struct ListNode)); head->next = NULL;
    struct ListNode* cur = head;
    
    while(1){
        
        cur->val = i % 10; //isolate current 1's place
        i = i / 10; //shift out 1's place
        
        if(i == 0){
            break;
        }
        else{
            cur->next = (struct ListNode *) malloc(sizeof(struct ListNode));
            cur->next->next = NULL;
            cur = cur->next;
        }
        
    }
    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    return  intToList(listToInt(l1) + listToInt(l2));
    
}
*/
