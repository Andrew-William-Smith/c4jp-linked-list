#ifndef C4JP_LINKED_LIST_H_INCLUDED
#define C4JP_LINKED_LIST_H_INCLUDED

#include <stdbool.h>
#include <stddef.h>

/**
 * Fetch the container of the specified @c TYPE containing an @c ll_node with
 * the name @c LIST_FIELD that is pointed to by @c PTR.  Inspired heavily by the
 * macro @c container_of from the Linux kernel's generic data structure
 * interface, although somewhat simplified for our purposes.
 */
#define LL_ENTRY(PTR, TYPE, LIST_FIELD) \
    ((TYPE *) (((char *) PTR) - offsetof(TYPE, LIST_FIELD)))

/**
 * An intrusive structure that contains the crucial elements of a linked list:
 * namely, links to the previous and next nodes in the list.  This structure
 * should be included in any structs that you intend to place inside of a linked
 * list.  Failure to do so will result in compilation failures.
 *
 * @note Implementors may choose to make their linked lists either circular
 *       (the head node point to the tail and vice versa) or linear; no explicit
 *       preference is made in this interface, so you may choose whichever
 *       design makes more sense to you.
 */
struct ll_node {
    struct ll_node *prev;    /**< The previous node in this linked list. */
    struct ll_node *next;    /**< The next node in this linked list. */
};

/**
 * A simple function to compare two linked list nodes.  The interface of this
 * function is similar to Java's Comparable#compareTo(): if the first node is
 * less than the second, return a negative number; if it is greater, return a
 * positive number; and if the nodes are equal, return 0.
 */
typedef int (*ll_comparator_t)(struct ll_node *, struct ll_node *);

/** A boolean predicate defined on a linked list node. */
typedef bool (*ll_predicate_t)(struct ll_node *);

/**
 * Initialise a linked list beginning with the specified node.  This node is
 * assumed to be the only node in the list, and this function must be called
 * before attempting to modify the list any further.
 *
 * @param node The node that will serve as the head of the new linked list.
 *             Must be non-null.
 */
void ll_init(struct ll_node *node);

/**
 * Determine whether there are any nodes in the linked list following the
 * specified node.
 *
 * @param node The node from which to check for following nodes.  Must be
 *             non-null.
 * @return @c true if there are nodes following @c node; @c false otherwise.
 */
bool ll_has_next(struct ll_node *node);

/**
 * Determine whether there are any nodes in the linked list prior to the
 * specified node.
 *
 * @param node The node from which to check for preceding nodes.  Must be
 *             non-null.
 * @return @c true if there are nodes before @c node; @c false otherwise.
 */
bool ll_has_prev(struct ll_node *node);

/**
 * Fetch a pointer to the next node in the linked list after the specified node.
 *
 * @param node The node whose following node to retrieve.  Must be non-null.
 * @return A pointer to the following node if there is one; @c NULL otherwise.
 */
struct ll_node *ll_next(struct ll_node *node);

/**
 * Fetch a pointer to the node in the linked list prior to the specified node.
 *
 * @param node The node whose preceding node to retrieve.  Must be non-null.
 * @return A pointer to the preceding node if there is one; @c NULL otherwise.
 */
struct ll_node *ll_prev(struct ll_node *node);

/**
 * Determine the size of the linked list that begins with the specified head
 * node.  Note that the node does not necessarily have to be the head of the
 * overall list; thus, this function can also be considered to return the number
 * of nodes following the current node, inclusive of the node.
 *
 * @param head The head of the list whose size to compute.  Must be non-null.
 * @return The number of nodes following the @c head node, including that node
 *         itself.
 */
size_t ll_size(struct ll_node *head);

/**
 * Fetch the first node in the list that contains the specified node.
 *
 * @param list A node in the list whose head to determine.  Must be non-null.
 * @return A pointer to the head of the list containing @c list.
 */
struct ll_node *ll_head(struct ll_node *list);

/**
 * Fetch the last node in the list that contains the specified node.
 *
 * @param list A node in the list whose tail to determine.  Must be non-null.
 * @return A pointer to the tail of the list containing @c list.
 */
struct ll_node *ll_tail(struct ll_node *list);

/**
 * Get the node at the specified (zero-based) index following the specified
 * node, provided that such a node exists.
 *
 * @param node The node after which to fetch a node.  Must be non-null.
 * @param index The number of nodes after @c node to traverse.  Should be less
 *              than the size of the list.
 * @return A pointer to the node @c index nodes after @c node if one exists;
 *         @c NULL otherwise.
 */
struct ll_node *ll_get(struct ll_node *node, size_t index);

/**
 * Insert the specified node before the specified node that already exists in
 * the linked list.  Surrounding nodes will be relinked as appropriate.
 *
 * @param new The new node to insert into the list.  Must be non-null.
 * @param existing The node before which the new node should be inserted.  Must
 *                 be non-null.
 */
void ll_insert_before(struct ll_node *new, struct ll_node *existing);

/**
 * Insert the specified node after the specified node that already exists in the
 * linked list.  Surrounding nodes will be relinked as appropriate.
 *
 * @param new The new node to insert into the list.  Must be non-null.
 * @param existing The node after which the new node should be inserted.  Must
 *                 be non-null.
 */
void ll_insert_after(struct ll_node *new, struct ll_node *existing);

/**
 * Insert the specified new node in the head (first) position of the list
 * containing the specified node.  Note that the @c list node may be at any
 * point in the list, not just the actual head.
 *
 * @param new The new node to add to the list.  Must be non-null.
 * @param list A node in the list into which to insert the new node.  Must be
 *             non-null.
 */
void ll_insert_first(struct ll_node *new, struct ll_node *list);

/**
 * Insert the specified new node in the tail (last) position of the list
 * containing the specified node.  Note that the @c list node may be at any
 * point in the list, not just the actual head.
 *
 * @param new The new node to add to the list.  Must be non-null.
 * @param list A node in the list into which to insert the new node.  Must be
 *             non-null.
 */
void ll_insert_last(struct ll_node *new, struct ll_node *list);

/**
 * Remove the specified node from the linked list of which it is a member.
 *
 * @param node The node to remove from the list.  Must be non-null.
 */
void ll_remove(struct ll_node *node);

/**
 * Determine the minimum value in the specified list, where all comparisons are
 * performed by the specified comparator function.
 *
 * @param list The head of the list in which to determine the minimum value.
 *             Must be non-null.
 * @param comparator The function used to compare list nodes.  Must be non-null.
 * @return A pointer to the node that has been determined to be the minimum in
 *         the list according to the specified @c comparator.
 */
struct ll_node *ll_min(struct ll_node *list, ll_comparator_t comparator);

/**
 * Determine the maximum value in the specified list, where all comparisons are
 * performed by the specified comparator function.
 *
 * @param list The head of the list in which to determine the maximum value.
 *             Must be non-null.
 * @param comparator The function used to compare list nodes.  Must be non-null.
 * @return A pointer to the node that has been determined to be the maximum in
 *         the list according to the specified @c comparator.
 */
struct ll_node *ll_max(struct ll_node *list, ll_comparator_t comparator);

/**
 * Remove all elements from the specified list that do not satisfy the specified
 * predicate function.
 *
 * @param list The head of the list to search.  Must be non-null.
 * @param predicate The function used to determine whether to retain nodes.
 *                  Must be non-null.
 * @return The head of the new, filtered list; if there are no nodes in the list
 *         that satisfy the predicate, return NULL.
 */
struct ll_node *ll_filter(struct ll_node *list, ll_predicate_t predicate);

#endif // C4JP_LINKED_LIST_H_INCLUDED
