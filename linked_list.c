#include <assert.h>
#include "linked_list.h"

//instance variables


void ll_init(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    node->next = NULL;
    node->prev = NULL;
}

bool ll_has_next(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    return node->next != NULL;
}

bool ll_has_prev(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    return node->prev != NULL;
}

struct ll_node *ll_next(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    return node->next;
    
}

struct ll_node *ll_prev(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    return node->prev;
    
}

size_t ll_size(struct ll_node *head) {
    assert(head != NULL);
    // TODO: Implement your solution here.
    size_t size = 0;
    struct ll_node *ptr = head;
    while(ll_has_next(ptr)) {
        size++;
        ptr = ll_next(ptr);
    }
    return size;
}

struct ll_node *ll_head(struct ll_node *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.
    struct ll_node *ptr = list;
    while(ll_has_prev(ptr)) {
        ptr = ll_prev(ptr);
    }
    return ptr;
}

struct ll_node *ll_tail(struct ll_node *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.
    struct ll_node *ptr = list;
    while(ll_has_next(ptr)) {
        ptr = ll_next(ptr);
    }
    return ptr;
}

struct ll_node *ll_get(struct ll_node *node, size_t index) {
    assert(node != NULL);
    // TODO: Implement your solution here.

    // is this assertion needed?
    // assert(index < size);

    //can we start from the node pointer from the start, w/o while loop?

    // old code
    // struct ll_node *ptr = header.next;
    // bool node_found = false;
    // while(ptr != &header && !node_found) { 
    //     if(ptr != node) {
    //         ptr = ptr->next;
    //     }
    //     else {
    //         node_found = true;
    //     }
    // }
    // if(node_found) {
    //     for(int i = 0; i < index; i++) {
    //         ptr = ptr -> next;
    //     }
    //     return ptr;
    // }
    // return NULL;

    // //what i think should work
    // for(int i = 0; i < index; i++) {
    //     node = ll_next(node);
    //     if(node == header) { //how do I compare 2 linked list nodes? seg fault
    //          return NULL;
    //     }
    // }
    // return node;
    return NULL;
}

void ll_insert_before(struct ll_node *new, struct ll_node *existing) {
    assert(new != NULL);
    assert(existing != NULL);
    // TODO: Implement your solution here.
}

void ll_insert_after(struct ll_node *new, struct ll_node *existing) {
    assert(new != NULL);
    assert(existing != NULL);
    // TODO: Implement your solution here.
}

void ll_insert_first(struct ll_node *new, struct ll_node *list) {
    assert(new != NULL);
    assert(list != NULL);
    // TODO: Implement your solution here.
}

void ll_insert_last(struct ll_node *new, struct ll_node *list) {
    assert(new != NULL);
    assert(list != NULL);
    // TODO: Implement your solution here.
}

void ll_remove(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
}

struct ll_node *ll_min(struct ll_node *list, ll_comparator_t comparator) {
    assert(list != NULL);
    assert(comparator != NULL);
    // TODO: Implement your solution here.
    return NULL;
}

struct ll_node *ll_max(struct ll_node *list, ll_comparator_t comparator) {
    assert(list != NULL);
    assert(comparator != NULL);
    // TODO: Implement your solution here.
    return NULL;
}

struct ll_node *ll_filter(struct ll_node *list, ll_predicate_t predicate) {
    assert(list != NULL);
    assert(predicate != NULL);
    // TODO: Implement your solution here.
    return NULL;
}
