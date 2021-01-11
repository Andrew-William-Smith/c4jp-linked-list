#include <assert.h>
#include "student.h"

/** Callback function to compare students by GPA. */
static int student_gpa_comparator(struct ll_node *first, struct ll_node *second) {
    double first_gpa = LL_ENTRY(first, struct student, node)->gpa;
    double second_gpa = LL_ENTRY(second, struct student, node)->gpa;
    // Since these are doubles, we cannot simply subtract and cast to int!
    if (first_gpa < second_gpa) {
        return -1;
    } else if (first_gpa > second_gpa) {
        return 1;
    } else {
        return 0;
    }
}

struct student *student_worst_performer(struct student *list) {
    assert(list != NULL);
    return LL_ENTRY(ll_min(&list->node, student_gpa_comparator),
                    struct student, node);
}

struct student *student_valedictorian(struct student *list) {
    assert(list != NULL);
    return LL_ENTRY(ll_max(&list->node, student_gpa_comparator),
                    struct student, node);
}

/** Predicate to determine whether a student qualifies for the honour roll. */
static bool student_on_honour_roll(struct ll_node *s) {
    return LL_ENTRY(s, struct student, node)->gpa >= 3.50;
}

struct student *student_honour_roll(struct student *list) {
    assert(list != NULL);
    struct ll_node *filtered = ll_filter(&list->node, student_on_honour_roll);
    return filtered != NULL ? LL_ENTRY(filtered, struct student, node) : NULL;
}
