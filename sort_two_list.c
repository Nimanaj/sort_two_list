#include <stdlib.h>
#include <stdio.h>

struct ListNode {
      int val;
      struct ListNode *next;
};

struct ListNode* new_node(int value, struct ListNode* next) {
    struct ListNode* node = calloc(1, sizeof(struct ListNode));
    node->val = value; 
    node->next = next;
    return node;
} 

void printList(struct ListNode* node){
	while(node != NULL){
		printf("%d \n", node->val);
		node = node->next;
	}
}
 
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    
    struct ListNode* result = calloc(1,sizeof(struct ListNode));
    struct ListNode* result3 = result;

    while((list1 != NULL) || (list2 != NULL) ) {
        struct ListNode* result2 = calloc(1,sizeof(struct ListNode));
        if(list1->val <= list2->val){
            result->val = list1->val;
            result->next = result2;
			printf("Result: %d\n", result->val);
			result = result->next;
			if(list1->next == NULL){
				break;
			}
			list1 = list1->next;
        }else{
            result->val = list2->val;
            result->next = result2;
			printf("Result: %d\n", result->val);
            result = result->next;
			if(list2->next == NULL){
				break;
			}
			list2 = list2->next;
        }
    }
	
	printList(result);
	if(list1->next != NULL){
		while(list1 != NULL){
			struct ListNode* result2 = calloc(1,sizeof(struct ListNode));
			
			result->val = list1->val;
			if(list1->next != NULL){
				result->next = result2;
			}
			list1 = list1->next;
            result = result->next;
		}
	}
	else {
		while(list2 != NULL){
			printf("Liste2: %d\n", list2->val);
			struct ListNode* result2 = calloc(1,sizeof(struct ListNode));
			
			result->val = list2->val;
			printf("Result, Schlrifr 2: %d\n", result->val);
			if(list2->next != NULL){
				result->next = result2;
			}
			list2 = list2->next;
            result = result->next;
		}
	}
   return result3;
}

int main() {
	struct ListNode* list1 = NULL;
	struct ListNode* list2 = NULL;
    list1 = new_node(1, new_node(3, NULL));
    list2 = new_node(2, new_node(4, NULL));
	printList(mergeTwoLists(list1, list2));
    return 0;
}