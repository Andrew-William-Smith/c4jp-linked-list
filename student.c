#include "student.h"

#include <assert.h>

static ll_comparator_t compare_gpa(struct ll_node *first,
                                   struct ll_node *second) {
    struct student *first_student = LL_ENTRY(first, struct student, node);
    struct student *second_student = LL_ENTRY(second, struct student, node);
    if (first_student->gpa < second_student->gpa) {
        return -1;
    } else if (first_student->gpa > second_student->gpa) {
        return 1;
    } else {
        return 0;
    }
}

static ll_predicate_t is_honour_roll(struct ll_node *cur_node) {
    struct student *student = LL_ENTRY(cur_node, struct student, node);
    return student->gpa >= 3.5;
}

struct student *student_worst_performer(struct student *list) {
    assert(list != NULL);
    struct ll_node *min = ll_min(&list->node, compare_gpa);
    return LL_ENTRY(min, struct student, node);
}

struct student *student_valedictorian(struct student *list) {
    assert(list != NULL);
    struct ll_node *max = ll_max(&list->node, compare_gpa);
    return LL_ENTRY(max, struct student, node);
}

struct student *student_honour_roll(struct student *list) {
    assert(list != NULL);
    struct ll_node *head = ll_filter(&list->node, is_honour_roll);
    if (head == NULL) {
        return NULL;
    }
    return LL_ENTRY(head, struct student, node);
}
