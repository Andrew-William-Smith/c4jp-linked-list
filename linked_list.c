#include <assert.h>
#include "linked_list.h"

void ll_init(struct ll_node *node) {
    assert(node != NULL);
    node->prev = NULL;
    node->next = NULL;
}

bool ll_has_next(struct ll_node *node) {
    assert(node != NULL);
    return node->next != NULL;
}

bool ll_has_prev(struct ll_node *node) {
    assert(node != NULL);
    return node->prev != NULL;
}

struct ll_node *ll_next(struct ll_node *node) {
    assert(node != NULL);
    return ll_has_next(node) ? node->next : NULL;
}

struct ll_node *ll_prev(struct ll_node *node) {
    assert(node != NULL);
    return ll_has_prev(node) ? node->prev : NULL;
}

size_t ll_size(struct ll_node *head) {
    assert(head != NULL);
    size_t length;
    for (length = 0; head != NULL; head = ll_next(head), length++);
    return length;
}

struct ll_node *ll_head(struct ll_node *list) {
    assert(list != NULL);
    while (ll_has_prev(list)) {
        list = ll_prev(list);
    }
    return list;
}

struct ll_node *ll_tail(struct ll_node *list) {
    assert(list != NULL);
    while (ll_has_next(list)) {
        list = ll_next(list);
    }
    return list;
}

struct ll_node *ll_get(struct ll_node *node, size_t index) {
    assert(node != NULL);
    size_t i;
    for (i = 0; node != NULL && i < index; node = ll_next(node), i++);
    return (i == index) ? node : NULL;
}

void ll_insert_before(struct ll_node *new, struct ll_node *existing) {
    assert(new != NULL);
    assert(existing != NULL);

    if (ll_has_prev(existing)) {
        existing->prev->next = new;
    }
    new->next = existing;
    new->prev = existing->prev;
    existing->prev = new;
}

void ll_insert_after(struct ll_node *new, struct ll_node *existing) {
    assert(new != NULL);
    assert(existing != NULL);

    if (ll_has_next(existing)) {
        existing->next->prev = new;
    }
    new->prev = existing;
    new->next = existing->next;
    existing->next = new;
}

void ll_insert_first(struct ll_node *new, struct ll_node *list) {
    assert(new != NULL);
    assert(list != NULL);
    ll_insert_before(new, ll_head(list));
}

void ll_insert_last(struct ll_node *new, struct ll_node *list) {
    assert(new != NULL);
    assert(list != NULL);
    ll_insert_after(new, ll_tail(list));
}

void ll_remove(struct ll_node *node) {
    assert(node != NULL);
    if (ll_has_prev(node)) {
        node->prev->next = node->next;
    }
    if (ll_has_next(node)) {
        node->next->prev = node->prev;
    }
}

struct ll_node *ll_min(struct ll_node *list, ll_comparator_t comparator) {
    assert(list != NULL);
    assert(comparator != NULL);

    struct ll_node *min = list;
    for (; list != NULL; list = list->next) {
        if (comparator(list, min) < 0) {
            min = list;
        }
    }
    return min;
}

struct ll_node *ll_max(struct ll_node *list, ll_comparator_t comparator) {
    assert(list != NULL);
    assert(comparator != NULL);

    struct ll_node *max = list;
    for (; list != NULL; list = list->next) {
        if (comparator(list, max) > 0) {
            max = list;
        }
    }
    return max;
}

struct ll_node *ll_filter(struct ll_node *list, ll_predicate_t predicate) {
    assert(list != NULL);
    assert(predicate != NULL);

    struct ll_node *head = NULL;
    for (; list != NULL; list = list->next) {
        if (!predicate(list)) {
            ll_remove(list);
        } else if (head == NULL) {
            head = list;
        }
    }

    return head;
}
