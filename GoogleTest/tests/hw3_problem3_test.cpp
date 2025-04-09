#include <gtest/gtest.h>
#include "../hw3_problem3.h"

TEST(InsertInOrder, EmptyListLinkedList) {
    Node* head = NULL;
    head = insertInOrder(head, 10);

    EXPECT_EQ(10, head->value);
    EXPECT_EQ(NULL, head->next);
}

TEST(InsertInOrder, SingleValueInsertAfter) {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->value = 5;
    head->next = NULL;

    head = insertInOrder(head, 10);

    EXPECT_EQ(5, head->value);
    EXPECT_EQ(10, head->next->value);
    EXPECT_EQ(NULL, head->next->next);

    free(head);
}

TEST(InsertInOrder, SingleValueInsertBefore) {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->value = 10;
    head->next = NULL;

    head = insertInOrder(head, 5);

    EXPECT_EQ(5, head->value);
    EXPECT_EQ(10, head->next->value);
    EXPECT_EQ(NULL, head->next->next);

    free(head);
}

TEST(InsertInOrder, MultiValueInsertMiddle) {
    struct Node* head = insertInOrder(NULL, 3);
    head = insertInOrder(head, 7);
    head = insertInOrder(head, 7);
    head = insertInOrder(head, 12);

    EXPECT_EQ(3, head->value);
    EXPECT_EQ(7, head->next->value);
    EXPECT_EQ(7, head->next->next->value);
    EXPECT_EQ(12, head->next->next->next->value);
    EXPECT_EQ(NULL, head->next->next->next->next);

    head = insertInOrder(head, 9);

    EXPECT_EQ(3, head->value);
    EXPECT_EQ(7, head->next->value);
    EXPECT_EQ(7, head->next->next->value);
    EXPECT_EQ(9, head->next->next->next->value);
    EXPECT_EQ(12, head->next->next->next->next->value);
    EXPECT_EQ(NULL, head->next->next->next->next->next);

    free(head);
}

TEST(InsertInOrder, MultiValueInsertFirst) {
    struct Node* head = insertInOrder(NULL, 3);
    head = insertInOrder(head, 7);
    head = insertInOrder(head, 7);
    head = insertInOrder(head, 12);

    EXPECT_EQ(3, head->value);
    EXPECT_EQ(7, head->next->value);
    EXPECT_EQ(7, head->next->next->value);
    EXPECT_EQ(12, head->next->next->next->value);
    EXPECT_EQ(NULL, head->next->next->next->next);

    head = insertInOrder(head, 1);

    EXPECT_EQ(1, head->value);
    EXPECT_EQ(3, head->next->value);
    EXPECT_EQ(7, head->next->next->value);
    EXPECT_EQ(7, head->next->next->next->value);
    EXPECT_EQ(12, head->next->next->next->next->value);
    EXPECT_EQ(NULL, head->next->next->next->next->next);

    free(head);
}

TEST(InsertInOrder, MultiValueInsertEnd) {
    struct Node* head = insertInOrder(NULL, 3);
    head = insertInOrder(head, 7);
    head = insertInOrder(head, 7);
    head = insertInOrder(head, 12);

    EXPECT_EQ(3, head->value);
    EXPECT_EQ(7, head->next->value);
    EXPECT_EQ(7, head->next->next->value);
    EXPECT_EQ(12, head->next->next->next->value);
    EXPECT_EQ(NULL, head->next->next->next->next);

    head = insertInOrder(head, 15);

    EXPECT_EQ(3, head->value);
    EXPECT_EQ(7, head->next->value);
    EXPECT_EQ(7, head->next->next->value);
    EXPECT_EQ(12, head->next->next->next->value);
    EXPECT_EQ(15, head->next->next->next->next->value);
    EXPECT_EQ(NULL, head->next->next->next->next->next);

    free(head);
}
