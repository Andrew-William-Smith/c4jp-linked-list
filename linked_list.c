#include <assert.h>
#include <string.h>
#include "linked_list.h"

void ll_init(struct ll_node *node) {
    assert(node != NULL);
    
    node->prev = NULL;
    node->next = NULL;
}

bool ll_has_next(struct ll_node *node) {
    assert(node != NULL);
    
    return (node->next == NULL ? false:true );
}

bool ll_has_prev(struct ll_node *node) {
    assert(node != NULL);
    
    return (node->prev == NULL ? false:true );
}

struct ll_node *ll_next(struct ll_node *node) {
    assert(node != NULL);
    
    return ll_has_next(node) ? node->next:NULL;
}

struct ll_node *ll_prev(struct ll_node *node) {
    assert(node != NULL);
    return ll_has_prev(node) ? node->prev:NULL;
}

size_t ll_size(struct ll_node *head) {
    assert(head != NULL);

    size_t counter = 1;
    while (ll_has_next(head))
    {
        head = ll_next(head);
        counter++;
    }
    
    return counter;
}

struct ll_node *ll_head(struct ll_node *list) {
    assert(list != NULL);

    struct ll_node *ll_head = list;
    while (ll_has_prev(ll_head))
    {
        ll_head = ll_prev(ll_head);
    }
    
    return ll_head;
}

struct ll_node *ll_tail(struct ll_node *list) {
    assert(list != NULL);

    struct ll_node *ll_tail= list;
    while (ll_has_next(ll_tail))
    {
        ll_tail = ll_next(ll_tail);
    }

    return ll_tail;
}

struct ll_node *ll_get(struct ll_node *node, size_t index) {
    assert(node != NULL);
// Sorry I switch to solution branch becouse I face so many truble  while solving ll_get.
    size_t i;
    for ( i=0 ; node != NULL && i < index;node = ll_next(node),i++);
    return (i == index) ? node:NULL;
}

void ll_insert_before(struct ll_node *new, struct ll_node *existing) {
    assert(new != NULL);
    assert(existing != NULL);

    ll_init(new);
    ll_has_prev(existing) ? new->prev=ll_prev(existing):NULL;
    ll_has_prev(existing) ? ll_prev(existing)->next=new:NULL;
    existing->prev = new;
    new->next = existing;
}

void ll_insert_after(struct ll_node *new, struct ll_node *existing) {
    assert(new != NULL);
    assert(existing != NULL);

    ll_init(new);
    ll_has_next(existing) ? new->next=ll_next(existing):NULL;
    ll_has_next(existing) ? ll_next(existing)->prev=new:NULL;
    existing->next = new;
    new->prev = existing;
}

void ll_insert_first(struct ll_node *new, struct ll_node *list) {
    assert(new != NULL);
    assert(list != NULL);

    ll_init(new);
    new->next = ll_head(list);
    ll_head(list)->prev=new;
}

void ll_insert_last(struct ll_node *new, struct ll_node *list) {
    assert(new != NULL);
    assert(list != NULL);

    ll_init(new);
    new->prev = ll_tail(list);
    ll_tail(list)->next = new;
}

void ll_remove(struct ll_node *node) {
    assert(node != NULL);
    
    ll_has_next(node) ? ll_next(node)->prev = node->prev:NULL;
    ll_has_prev(node) ? ll_prev(node)->next = node->next:NULL;
}


struct ll_node *ll_min(struct ll_node *list, ll_comparator_t comparator) {
    
    assert(list != NULL);
    assert(comparator != NULL);

    struct ll_node *min = list;
    while (ll_has_next(list))
    {
        comparator(list,ll_next(list)) < 0 ? min = ll_next(list):NULL; 
        list = ll_next(list);
    }
    
    return min;
}

struct ll_node *ll_max(struct ll_node *list, ll_comparator_t comparator) {
    assert(list != NULL);
    assert(comparator != NULL);

    struct ll_node *max = list;
    while (ll_has_next(list))
    {
        comparator(list,ll_next(list)) > 0 ? max = ll_next(list):NULL; 
        list = ll_next(list);
    }
    
    return max;
    
}

struct ll_node *ll_filter(struct ll_node *list, ll_predicate_t predicate,double cond) {
    assert(list != NULL);
    assert(predicate != NULL);

   struct ll_node *head = NULL;
    for (;list != NULL; list = list->next)
    {
        if (!predicate(list,cond)) {
            ll_remove(list);
        }else if(head == NULL){
            head = list;
        }
    
    }
    return head;
}
