#include <assert.h>
#include "student.h"
#include <stdbool.h>

int comparator(struct ll_node * first,struct ll_node * second){

    double first_gpa = LL_ENTRY(first , struct student , node)->gpa;
    double second_gpa = LL_ENTRY(second , struct student , node)->gpa;

    if(second_gpa >= first_gpa){
        return 1;
    }
    else if(second_gpa <= first_gpa){
        return -1;
    }
    else{
        return 0;
    }
}

bool predicate(struct ll_node * list,double cond){
    double gpa = LL_ENTRY(list,struct student,node)->gpa;
    return gpa >= cond;
}

struct student *student_worst_performer(struct student *list) {
    assert(list != NULL);
    
    return  LL_ENTRY(ll_min(&list->node,comparator),struct student,node);
}

struct student *student_valedictorian(struct student *list) {
    assert(list != NULL);

    return LL_ENTRY(ll_max(&list->node, comparator),struct student, node);
}

struct student *student_honour_roll(struct student *list) {
    assert(list != NULL);
    
     struct ll_node *filtered = ll_filter(&list->node, predicate,3.50);
    return filtered != NULL ? LL_ENTRY(filtered, struct student, node) : NULL;
}

