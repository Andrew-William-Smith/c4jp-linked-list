#include "linked_list.h"

#include <assert.h>

void ll_init(struct ll_node *node) {
    assert(node != NULL);
    node->prev = node->next = NULL;
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
    return node->next;
}

struct ll_node *ll_prev(struct ll_node *node) {
    assert(node != NULL);
    return node->prev;
}

size_t ll_size(struct ll_node *head) {
    assert(head != NULL);
    size_t size = 0;
    struct ll_node *temp = head;
    while (temp != NULL) {
        temp = temp->next;
        size++;
    }
    return size;
}

struct ll_node *ll_head(struct ll_node *list) {
    assert(list != NULL);
    struct ll_node *temp = list;
    while (ll_has_prev(temp)) {
        temp = temp->prev;
    }
    return temp;
}

struct ll_node *ll_tail(struct ll_node *list) {
    assert(list != NULL);
    struct ll_node *temp = list;
    while (ll_has_next(temp)) {
        temp = temp->next;
    }
    return temp;
}

struct ll_node *ll_get(struct ll_node *node, size_t index) {
    assert(node != NULL);
    struct ll_node *temp = node;
    size_t cur_index = 0;
    while (cur_index < index && temp != NULL) {
        temp = temp->next;
        cur_index++;
    }
    if (cur_index != index) {
        return NULL;
    }
    return temp;
}

void ll_insert_before(struct ll_node *new, struct ll_node *existing) {
    assert(new != NULL);
    assert(existing != NULL);
    struct ll_node *temp = existing->prev;
    if (temp != NULL) {
        temp->next = new;
        new->prev = temp;
    } else {
        new->prev = NULL;
    }
    new->next = existing;
    existing->prev = new;
}

void ll_insert_after(struct ll_node *new, struct ll_node *existing) {
    assert(new != NULL);
    assert(existing != NULL);
    struct ll_node *temp = existing->next;
    if (temp != NULL) {
        temp->prev = new;
        new->next = temp;
    } else {
        new->next = NULL;
    }
    new->prev = existing;
    existing->next = new;
}

void ll_insert_first(struct ll_node *new, struct ll_node *list) {
    assert(new != NULL);
    assert(list != NULL);
    struct ll_node *head = ll_head(list);
    ll_insert_before(new, head);
}

void ll_insert_last(struct ll_node *new, struct ll_node *list) {
    assert(new != NULL);
    assert(list != NULL);
    struct ll_node *tail = ll_tail(list);
    ll_insert_after(new, tail);
}

void ll_remove(struct ll_node *node) {
    assert(node != NULL);
    struct ll_node *first = node->prev;
    struct ll_node *second = node->next;
    if (first != NULL) {
        first->next = second;
    }
    if (second != NULL) {
        second->prev = first;
    }
}

struct ll_node *ll_min(struct ll_node *list, ll_comparator_t comparator) {
    assert(list != NULL);
    assert(comparator != NULL);
    struct ll_node *min = list;
    struct ll_node *temp = list->next;
    while (temp != NULL) {
        if (comparator(temp, min) < 0) {
            min = temp;
        }
        temp = temp->next;
    }
    return min;
}

struct ll_node *ll_max(struct ll_node *list, ll_comparator_t comparator) {
    assert(list != NULL);
    assert(comparator != NULL);
    struct ll_node *max = list;
    struct ll_node *temp = list->next;
    while (temp != NULL) {
        if (comparator(temp, max) > 0) {
            max = temp;
        }
        temp = temp->next;
    }
    return max;
}

struct ll_node *ll_filter(struct ll_node *list, ll_predicate_t predicate) {
    assert(list != NULL);
    assert(predicate != NULL);
    struct ll_node *head = NULL;
    struct ll_node *temp = list;
    while (temp != NULL) {
        if (!predicate(temp)) {
            ll_remove(temp);
        } else if (head == NULL) {
            head = temp;
        }
        temp = temp->next;
    }
    return head;
}
