#include "test.h"

#include <stdlib.h>
#include "linked_list.h"
#include "student.h"

// Sample data for multi-node tests.
static struct student s_students[] = {
    { .name = "First Student", .gpa = 3.75 },
    { .name = "Second Student", .gpa = 3.00 },
    { .name = "Third Student", .gpa = 3.50 },
    { .name = "Fourth Student", .gpa = 2.25 },
    { .name = "Fifth Student", .gpa = 2.75 },
    { .name = "Sixth Student", .gpa = 2.50 },
    { .name = "Seventh Student", .gpa = 3.25 },
    { .name = "Eighth Student", .gpa = 3.00 },
    { .name = "Ninth Student", .gpa = 4.00 },
    { .name = "Tenth Student", .gpa = 2.00 },
};
static const int NUM_STUDENTS = 10;

#pragma FIXTURE_START

FIXTURE(LL_tests) {
    struct student list;
    struct ll_node *initial;
};

FIXTURE_SETUP(LL_tests) {
    T_ list = (struct student) {
        .name = "List Head",
        .gpa = 2.0,
    };
    T_ initial = &T_ list.node;
    ll_init(T_ initial);
}

#pragma FIXTURE_END

#pragma TEST_START

TEST(Single_item_traversal, LL_tests) {
    // We should not be able to navigate anywhere from the head node.
    ASSERT_FALSE(ll_has_next(T_ initial));
    ASSERT_FALSE(ll_has_prev(T_ initial));
    ASSERT_NULL(ll_next(T_ initial));
    ASSERT_NULL(ll_prev(T_ initial));

    // The student data should be unchanged.
    struct student *student_head = LL_ENTRY(T_ initial, struct student, node);
    ASSERT_STREQ("List Head", student_head->name);
    ASSERT_EQ(2.0, student_head->gpa, "%f");
}

TEST(Single_item_size, LL_tests) {
    ASSERT_EQ((size_t) 1, ll_size(T_ initial), "%zu");
}

TEST(Single_item_get, LL_tests) {
    ASSERT_EQ(T_ initial, ll_get(T_ initial, 0), "%p");
    ASSERT_NULL(ll_get(T_ initial, 1));
    ASSERT_NULL(ll_get(T_ initial, -1));
}

TEST(Single_item_head_tail, LL_tests) {
    ASSERT_EQ(T_ initial, ll_head(T_ initial), "%p");
    ASSERT_EQ(T_ initial, ll_tail(T_ initial), "%p");
}

TEST(Insert_item_before, LL_tests) {
    struct student previous = {
        .name = "Preceding Student",
        .gpa = 3.75,
    };
    ll_insert_before(&previous.node, T_ initial);

    // Validate the linkage of the new node.
    ASSERT_TRUE(ll_has_next(&previous.node));
    ASSERT_FALSE(ll_has_prev(&previous.node));
    ASSERT_FALSE(ll_has_next(T_ initial));
    ASSERT_TRUE(ll_has_prev(T_ initial));
    ASSERT_EQ(&previous.node, ll_prev(T_ initial), "%p");
    ASSERT_EQ(T_ initial, ll_next(&previous.node), "%p");

    // Ensure that the size computation is still working properly.
    ASSERT_EQ((size_t) 2, ll_size(&previous.node), "%zu");
    ASSERT_EQ((size_t) 1, ll_size(T_ initial), "%zu");
}

TEST(Insert_item_after, LL_tests) {
    struct student next = {
        .name = "Following Student",
        .gpa = 3.625,
    };
    ll_insert_after(&next.node, T_ initial);

    // Validate the linkage of the new node.
    ASSERT_TRUE(ll_has_next(T_ initial));
    ASSERT_FALSE(ll_has_prev(T_ initial));
    ASSERT_FALSE(ll_has_next(&next.node));
    ASSERT_TRUE(ll_has_prev(&next.node));
    ASSERT_EQ(&next.node, ll_next(T_ initial), "%p");
    ASSERT_EQ(T_ initial, ll_prev(&next.node), "%p");

    // Ensure that the size computation is still working properly.
    ASSERT_EQ((size_t) 2, ll_size(T_ initial), "%zu");
    ASSERT_EQ((size_t) 1, ll_size(&next.node), "%zu");
}

TEST(Insert_before_and_after, LL_tests) {
    struct student previous = {
        .name = "Preceding Student",
        .gpa = 3.75,
    }, next = {
        .name = "Following Student",
        .gpa = 3.625,
    };
    struct ll_node *head = &previous.node;
    ll_insert_before(head, T_ initial);
    ll_insert_after(&next.node, T_ initial);

    // Validate the linkage of both nodes.
    ASSERT_NULL(ll_prev(head));
    ASSERT_EQ(T_ initial, ll_next(head), "%p");
    ASSERT_EQ(head, ll_prev(T_ initial), "%p");
    ASSERT_EQ(&next.node, ll_next(T_ initial), "%p");
    ASSERT_EQ(T_ initial, ll_prev(&next.node), "%p");
    ASSERT_NULL(ll_next(&next.node));
    ASSERT_EQ((size_t) 3, ll_size(head), "%zu");

    // Ensure data integrity within the list.  Also, further get() tests.
    struct student *first = LL_ENTRY(ll_get(head, 0), struct student, node);
    ASSERT_STREQ("Preceding Student", first->name);
    ASSERT_EQ(3.75, first->gpa, "%f");
    struct student *second = LL_ENTRY(ll_get(head, 1), struct student, node);
    ASSERT_STREQ("List Head", second->name);
    ASSERT_EQ(2.00, second->gpa, "%f");
    struct student *third = LL_ENTRY(ll_get(head, 2), struct student, node);
    ASSERT_STREQ("Following Student", third->name);
    ASSERT_EQ(3.625, third->gpa, "%f");
    // get() failures.
    ASSERT_NULL(ll_get(head, 3));
    ASSERT_NULL(ll_get(head, -1));

    // While we're at it, let's also test the head and tail getters.
    ASSERT_EQ(&previous.node, ll_head(head), "%p");
    ASSERT_EQ(&next.node, ll_tail(head), "%p");
}

TEST(Insert_first_once, LL_tests) {
    struct student new_head = {
        .name = "Actual First Student",
        .gpa = 4.25,    // I wish...
    };
    struct ll_node *head = &new_head.node;
    ll_insert_first(head, T_ initial);

    // Validate list structure.  I trust that the linkage is correct by now.
    ASSERT_EQ(head, ll_get(head, 0), "%p");
    ASSERT_EQ(T_ initial, ll_get(head, 1), "%p");
    ASSERT_NULL(ll_get(head, 2));
}

TEST(Insert_first_multiple, LL_tests) {
    struct ll_node *head = &s_students[NUM_STUDENTS - 1].node;

    // Add all students to the list.
    for (int i = 0; i < NUM_STUDENTS; i++) {
        ll_insert_first(&s_students[i].node, T_ initial);
    }

    // Ensure that all students were added in the correct order.
    for (int i = 0; i < NUM_STUDENTS; i++) {
        ASSERT_EQ(&s_students[i].node, ll_get(head, NUM_STUDENTS - 1 - i), "%p");
    }
    ASSERT_EQ(T_ initial, ll_get(head, NUM_STUDENTS), "%p");
    ASSERT_NULL(ll_get(head, NUM_STUDENTS + 1));
}

TEST(Insert_last_once, LL_tests) {
    struct student new_tail = {
        .name = "Actual Last Student",
        .gpa = 0.00,
    };
    ll_insert_last(&new_tail.node, T_ initial);

    // Validate list structure.  I trust that the linkage is correct by now.
    ASSERT_EQ(T_ initial, ll_get(T_ initial, 0), "%p");
    ASSERT_EQ(&new_tail.node, ll_get(T_ initial, 1), "%p");
    ASSERT_NULL(ll_get(T_ initial, 2));
}

TEST(Insert_last_multiple, LL_tests) {
    // Add all students to the list.
    for (int i = 0; i < NUM_STUDENTS; i++) {
        ll_insert_last(&s_students[i].node, T_ initial);
    }

    // Ensure that all students were added in the correct order.
    ASSERT_EQ(T_ initial, ll_get(T_ initial, 0), "%p");
    for (int i = 1; i <= NUM_STUDENTS; i++) {
        ASSERT_EQ(&s_students[i - 1].node, ll_get(T_ initial, i), "%p");
    }
    ASSERT_NULL(ll_get(T_ initial, NUM_STUDENTS + 1));
}

TEST(Remove_only_node, LL_tests) {
    /* If this operation doesn't crash, we'll consider it to be working.  Your
     * solution should always pass this test if the tester prints an exit
     * status, although it may crash to indicate failure. */
    ll_remove(T_ initial);
}

TEST(Remove_head, LL_tests) {
    struct student new_head = {
        .name = "First Student",
        .gpa = 3.14,
    };
    struct ll_node *tail = &new_head.node;
    ll_insert_last(tail, T_ initial);
    ll_remove(T_ initial);

    // The added node should be the only node remaining in the list.
    ASSERT_FALSE(ll_has_prev(tail));
    ASSERT_FALSE(ll_has_next(tail));
    ASSERT_EQ((size_t) 1, ll_size(tail), "%zu");
}

TEST(Remove_tail, LL_tests) {
    struct student new_tail = {
        .name = "Last Student",
        .gpa = 2.72,
    };
    ll_insert_last(&new_tail.node, T_ initial);
    ll_remove(&new_tail.node);

    // The original node should be the only node remaining in the list.
    ASSERT_FALSE(ll_has_prev(T_ initial));
    ASSERT_FALSE(ll_has_next(T_ initial));
    ASSERT_EQ((size_t) 1, ll_size(T_ initial), "%zu");
}

TEST(Remove_middle, LL_tests) {
    struct student new_head = {
        .name = "First Student",
        .gpa = 1.62,
    }, new_tail = {
        .name = "Last Student",
        .gpa = 2.30
    };
    ll_insert_first(&new_head.node, T_ initial);
    ll_insert_last(&new_tail.node, T_ initial);
    ll_remove(T_ initial);

    // The surrounding nodes should still be in the list.
    ASSERT_EQ(&new_head.node, ll_get(&new_head.node, 0), "%p");
    ASSERT_EQ(&new_head.node, ll_head(&new_head.node), "%p");
    ASSERT_EQ(&new_tail.node, ll_get(&new_head.node, 1), "%p");
    ASSERT_EQ(&new_tail.node, ll_tail(&new_head.node), "%p");
    ASSERT_EQ((size_t) 2, ll_size(T_ initial), "%zu");
}

TEST(Worst_student_only, LL_tests) {
    ASSERT_EQ(&T_ list, student_worst_performer(&T_ list), "%p");
}

TEST(Worst_student_many, LL_tests) {
    // Add all of the sample students to the list.
    for (int i = 0; i < NUM_STUDENTS; i++) {
        ll_insert_last(&s_students[i].node, T_ initial);
    }

    struct student *worst = student_worst_performer(&T_ list);
    ASSERT_NON_NULL(worst);
    ASSERT_EQ(2.00, worst->gpa, "%f");
}

TEST(Valedictorian_homeschooled, LL_tests) {
    ASSERT_EQ(&T_ list, student_valedictorian(&T_ list), "%p");
}

TEST(Valedictorian_classmates, LL_tests) {
    // Add all of the sample students to the list.
    for (int i = 0; i < NUM_STUDENTS; i++) {
        ll_insert_last(&s_students[i].node, T_ initial);
    }


    struct student *valedictorian = student_valedictorian(&T_ list);
    ASSERT_NON_NULL(valedictorian);
    ASSERT_EQ(4.00, valedictorian->gpa, "%f");
}

TEST(Honour_roll_no_qualifiers, LL_tests) {
    // The default student does not qualify for the honour roll.  How sad!
    ASSERT_NULL(student_honour_roll(&T_ list));
}

TEST(Honour_roll_some_qualify, LL_tests) {
    for (int i = 0; i < NUM_STUDENTS; i++) {
        ll_insert_last(&s_students[i].node, T_ initial);
    }

    // Some of the sample students do qualify.  Good for them!
    struct student *honour_roll = student_honour_roll(&T_ list);
    ASSERT_NON_NULL(honour_roll);
    struct ll_node *honour_node = &honour_roll->node;
    ASSERT_EQ((size_t) 3, ll_size(honour_node), "%zu");
    for (; ll_has_next(honour_node); honour_node = ll_next(honour_node)) {
        ASSERT_GE(LL_ENTRY(honour_node, struct student, node)->gpa, 3.50, "%f");
    }
}

#pragma TEST_END

int main() {
    return (int) test_failed_tests;
}
