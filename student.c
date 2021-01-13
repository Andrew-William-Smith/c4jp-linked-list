#include <assert.h>
#include "student.h"

static int gpa_comparator(struct ll_node *first, struct ll_node *second) {
    double one = LL_ENTRY(first, struct student, gpa)->gpa;
    double two = LL_ENTRY(second, struct student, gpa)->gpa;

    if(one < two) {
        return -1;
    }
    else if(one > two) {
        return 1;
    }
    else {
        return 0;
    }
}

struct student *student_worst_performer(struct student *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.
    return LL_ENTRY(ll_min(&list->node, gpa_comparator), struct student, node);
}

struct student *student_valedictorian(struct student *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.
    return LL_ENTRY(ll_max(&list->node, gpa_comparator), struct student, node);
}

static bool honour_roll_check(struct ll_node *check) {
    double check_gpa = LL_ENTRY(check, struct student, gpa)->gpa;
    if(check_gpa < 3.50) {
        return false;
    }
    return true;
}

struct student *student_honour_roll(struct student *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.
    struct ll_node *result = ll_filter(&list->node, honour_roll_check);
    if(result != NULL) {
        return LL_ENTRY(result, struct student, node);
    }
    return NULL;
}
