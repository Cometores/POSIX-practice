#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    unsigned int value;
    struct ListNode *next;
} elem;

elem *head;

static int insertElement(int);
static int removeElement(void);

static int insertElement(int value){
    if(value < 0)
        return -1;

    if(!head){
        head = malloc(sizeof(elem));
        if(!head)
            return -2;
        
        head->value = value;
        head->next = NULL;

        return value;
    }

    elem* current = head;

    for(; current->next; current = current->next){
        if(value == current->value)
            return -1;
    }

    //check last element
    if(value == current->value)
        return -1;

    elem* new = malloc(sizeof(elem));
    if(!new)
        return -2;

    new->value = value;
    new->next = NULL;
    current ->next = new;

    return value;
}

static int removeElement(void) {
    if(!head) 
        return -1;

    unsigned int to_delete;

    if (head->next == NULL){
        // Only one item in the list
        to_delete = head->value;
        free(head);
        head = NULL;
    }else{
        // multiple items in the list
        elem *current = head;
        for(; current->next->next; current = current->next);

        to_delete = current->next->value;
        free(current->next);
        current->next = NULL;
    }

    return to_delete;
}


int main (int argc, char* argv[]) {
    printf("Insert elements into empty list:\n");
    printf("\tinsert 47: %d\n", insertElement(47));
    printf("\tinsert 11: %d\n", insertElement(11));
    printf("\tinsert 23: %d\n", insertElement(23));

    printf("\nTry to insert duplicate\n");
    printf("\tinsert 11: %d\n", insertElement(11));

    printf("\nTry to insert negative number\n");
    printf("\tinsert -15: %d\n", insertElement(-15));

    printf("\nList now looks like this: \n\t{list_head -> 47 -> 11 -> 23}\n\n");

    printf("Delete all elements\n");
    printf("\tremove: %d\n", removeElement());
    printf("\tremove: %d\n", removeElement());
    printf("\tremove: %d\n", removeElement());

    printf("\nTry to call 'removeElement' for empty list\n");
    printf("\tremove: %d\n", removeElement()); 
    
    printf("\nAdding items to a cleaned list\n");
    printf("\tinsert 19: %d\n", insertElement(19));
    printf("\tinsert 20: %d\n", insertElement(20));
    
    printf("\nSecond element in the list: %d\n", head->next->value);
    
    exit(EXIT_SUCCESS);
    return 0;
}
