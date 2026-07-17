/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        // Bruetforce solution using Hashmap+DummyNode
        Node*temp=head;
        unordered_map<Node*,Node*>mp;

        //step 1: makedummyNode and store copy in map 
        while(temp!=NULL){
            //1st we have to createnew node #dummyNode
            Node*newNode= new Node(temp->val);
            //Store original temp val and newNode temp value in map
            mp[temp]=newNode; //copy
            temp=temp->next;
        
        }
        //step 2: connecting ptrs random and next

        temp=head;
        while(temp!=NULL){
            Node*copyNode=mp[temp];
            copyNode->next= mp[temp->next];
            copyNode->random=mp[temp->random];
            temp=temp->next;

        }
        return mp[head];
    }
};
