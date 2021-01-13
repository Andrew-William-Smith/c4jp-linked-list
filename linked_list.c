#include <assert.h>
#include "linked_list.h"

//instance variables
struct ll_node header; 


void ll_init(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    header.next = node;
    header.prev = node;
}

bool ll_has_next(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.

    printf("\nnode -> next == %p, header = %p", node->next, header);
    if(node->next == &header || node->next == NULL) {
        return false;
    }
    return true;
}

bool ll_has_prev(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    
    printf("\nnode -> prev == %p, header = %p\n", node->next, header);
    if(node->prev == &header || node->prev == NULL) {
        return false;
    }
    return true;
}

struct ll_node *ll_next(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.

    if(ll_has_next(node)) {
        return node->next;
    }
    return NULL;
}

struct ll_node *ll_prev(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.

    if(ll_has_prev(node)) {
        return node->prev;
    }
    return NULL;
}

size_t ll_size(struct ll_node *head) {
    assert(head != NULL);
    // TODO: Implement your solution here.

    size_t size = 1;
    
    while(ll_has_next(head)) {
        size++;
        head = ll_next(head);
    }
    return size;
}

struct ll_node *ll_head(struct ll_node *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.

    return ll_next(&header);
}

struct ll_node *ll_tail(struct ll_node *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.

    return ll_prev(&header);
}

struct ll_node *ll_get(struct ll_node *node, size_t index) {
    assert(node != NULL);
    // TODO: Implement your solution here.

    // is this assertion needed?
    // assert(index < size);

    for(int i = 0; i < index; i++) {
        node = ll_next(node);
        if(node == NULL) { //how do I compare 2 linked list nodes? seg fault
             return NULL;
        }
    }
    return node;
}

void ll_insert_before(struct ll_node *new, struct ll_node *existing) {
    assert(new != NULL);
    assert(existing != NULL);
    // TODO: Implement your solution here.
    struct ll_node *oldPrev = existing->prev;


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
