#include <assert.h>
#include "linked_list.h"

void ll_init(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
}

bool ll_has_next(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    return false;
}

bool ll_has_prev(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    return false;
}

struct ll_node *ll_next(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    return NULL;
}

struct ll_node *ll_prev(struct ll_node *node) {
    assert(node != NULL);
    // TODO: Implement your solution here.
    return NULL;
}

size_t ll_size(struct ll_node *head) {
    assert(head != NULL);
    // TODO: Implement your solution here.
    return 0;
}

struct ll_node *ll_head(struct ll_node *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.
    return NULL;
}

struct ll_node *ll_tail(struct ll_node *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.
    return NULL;
}

struct ll_node *ll_get(struct ll_node *node, size_t index) {
    assert(node != NULL);
    // TODO: Implement your solution here.
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
