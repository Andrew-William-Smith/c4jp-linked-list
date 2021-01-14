#include <assert.h>
#include "linked_list.h"


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

    while(ll_has_prev(list)) {
        list = ll_prev(list);
    }
    return list;
}

struct ll_node *ll_tail(struct ll_node *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.

    while(ll_has_next(list)) {
        list = ll_next(list);
    }
    return list;
}

struct ll_node *ll_get(struct ll_node *node, size_t index) {
    assert(node != NULL);
    // TODO: Implement your solution here.

    // is this assertion needed?
    // assert(index < size);

    for(long unsigned int i = 0; i < index; i++) {
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
     
    if(ll_has_prev(existing)) {
        existing->prev->next = new;
    }
    new->next = existing;
    new->prev = existing->prev;
    existing->prev = new;

}

void ll_insert_after(struct ll_node *new, struct ll_node *existing) {
    assert(new != NULL);
    assert(existing != NULL);
    // TODO: Implement your solution here

    if(ll_has_next(existing)) {
        existing->next->prev = new;
    }
    new->prev = existing;
    new->next = existing->next;
    existing->next = new;
    

}

void ll_insert_first(struct ll_node *new, struct ll_node *list) {
    assert(new != NULL);
    assert(list != NULL);
    // TODO: Implement your solution here.

    ll_insert_before(new, ll_head(list));

}

void ll_insert_last(struct ll_node *new, struct ll_node *list) {
    assert(new != NULL);
    assert(list != NULL);
    // TODO: Implement your solution here.

    ll_insert_after(new, ll_tail(list));
}

void ll_remove(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    if(ll_has_prev(node)) {
        node->prev->next = node->next;
    }
    if(ll_has_next(node)) {
        node->next->prev = node->prev;
    }
}

struct ll_node *ll_min(struct ll_node *list, ll_comparator_t comparator) {
    assert(list != NULL);
    assert(comparator != NULL);
    // TODO: Implement your solution here.
    struct ll_node *result = list;
    while(list != NULL) {
        if(comparator(list, result) < 0) {
            result = list;
        }
        list = ll_next(list);
    }
    return result;
}

struct ll_node *ll_max(struct ll_node *list, ll_comparator_t comparator) {
    assert(list != NULL);
    assert(comparator != NULL);
    // TODO: Implement your solution here.
    struct ll_node *result = list;
    while(list != NULL) {
        if(comparator(list, result) > 0) {
            result = list;
        }
        list = ll_next(list);
    }
    return result;
}

struct ll_node *ll_filter(struct ll_node *list, ll_predicate_t predicate) {
    assert(list != NULL);
    assert(predicate != NULL);
    // TODO: Implement your solution here.
    struct ll_node *result = NULL;
    while(list != NULL) {
        if(!predicate(list)) {
            ll_remove(list);
        }
        else if(result == NULL) {
            result = list;
        }
        list = ll_next(list);
    }
    return result;
    
}
