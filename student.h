#ifndef C4JP_STUDENTS_H_INCLUDED
#define C4JP_STUDENTS_H_INCLUDED

#include "linked_list.h"

/**
 * A simple list of data on the students enrolled in a university.  This struct
 * is used to test your linked list implementation for correctness, but users
 * may choose to make a linked list out of any struct they wish, so do not
 * specialise your implementation for this specific struct!
 */
struct student {
    char *name;
    double gpa;
    struct ll_node node;
};

/**
 * Determine the student who is the worst performer in the list, defined to be
 * the student with the worst (lowest) GPA.
 *
 * @param list The list of students to search.  Must be non-null.
 * @return A pointer to the student in the list with the lowest GPA.
 * @note You must implement this function using @c ll_min().  Failure to do so
 *       will result in your submission not being reviewed.
 */
struct student *student_worst_performer(struct student *list);

/**
 * Determine the student in the list who is the valedictorian of their class, or
 * the person who has the best (highest) GPA.
 *
 * @param list The list of students to search.  Must be non-null.
 * @return A pointer to the student in the list with the highest GPA.
 * @note You must implement this function using @c ll_max().  Failure to do so
 *       will result in your submission not being reviewed.
 */
struct student *student_valedictorian(struct student *list);

/**
 * Determine the honour roll for the class specified in the list of students.
 * All students with a GPA of 3.50 and above qualify for the honour roll.
 *
 * @param list The list of students to search.  Must be non-null.
 * @return A list of students whose GPAs are 3.50 or above.  If there are no
 *         such students in the class, return @c NULL and contact the school's
 *         administrators for a performance review of the teacher.
 */
struct student *student_honour_roll(struct student *list);

#endif // C4JP_STUDENTS_H_INCLUDED
