#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

/* Notice: sometimes, Cppcheck would find the potential NULL pointer bugs,
 * but some of them cannot occur. You can suppress them by adding the
 * following line.
 *   cppcheck-suppress nullPointer
 */


/**
 * q_new - Create an empty queue
 */
struct list_head *q_new()
{
    struct list_head *q = malloc(sizeof(*q));

    if (!q)  // If allocate failed
        return NULL;

    INIT_LIST_HEAD(q);
    return q;
}

/**
 * q_free - Free all storage used by queue
 * @head: list_head struct of the queue to be freed
 */
void q_free(struct list_head *head)
{
    if (!head)  // If the queue is empty
        return;

    element_t *entry, *safe;

    list_for_each_entry_safe (entry, safe, head, list)
        q_release_element(entry);

    free(head);
}

/**
 * q_insert_head - Insert an element at head of queue
 * @head: list_head struct to be insterted
 * @s: the string to be inserted
 */
bool q_insert_head(struct list_head *head, char *s)
{
    element_t *new_node;
    size_t str_len;

    if (!s || !*s)
        return false;

    if (!head)  // If head is a null pointer
        return false;

    // allocate memory of new node
    new_node = malloc(sizeof(element_t));

    if (!new_node)  // If allocation failed
        return false;

    INIT_LIST_HEAD(&new_node->list);

    // +1 for null-terminator '\0'
    str_len = strlen(s) + 1;

    new_node->value = malloc(str_len * sizeof(char));

    // If allocation failed
    if (!new_node->value) {
        free(new_node);
        return false;
    }

    memcpy(new_node->value, s, str_len);

    list_add(&new_node->list, head);

    return true;
}

/**
 * q_insert_head - Insert an element at tail of queue
 * @head: list_head struct to be insterted
 * @s: the string to be inserted
 */
bool q_insert_tail(struct list_head *head, char *s)
{
    element_t *new_node;
    size_t str_len;

    if (!s || !*s)
        return false;

    if (!head)  // If head is a null pointer
        return false;

    // allocate memory of new node
    new_node = malloc(sizeof(element_t));

    if (!new_node)  // If allocation failed
        return false;

    INIT_LIST_HEAD(&new_node->list);

    // +1 for null-terminator '\0'
    str_len = strlen(s) + 1;

    new_node->value = malloc(str_len * sizeof(char));

    // If allocation failed
    if (!new_node->value) {
        free(new_node);
        return false;
    }

    memcpy(new_node->value, s, str_len);

    list_add_tail(&new_node->list, head);
    return true;
}

/* Remove an element from head of queue */
element_t *q_remove_head(struct list_head *head, char *sp, size_t bufsize)
{
    return NULL;
}

/* Remove an element from tail of queue */
element_t *q_remove_tail(struct list_head *head, char *sp, size_t bufsize)
{
    return NULL;
}

/**
 * q_size - Return number of elements in queue
 * @head: head of the queue to return number of elements
 */
int q_size(struct list_head *head)
{
    if (!head) {
        return 0;
    }

    int len = 0;
    struct list_head *li;

    list_for_each (li, head)
        len++;

    return len;
}

/* Delete the middle node in queue */
bool q_delete_mid(struct list_head *head)
{
    // https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

    if (!head)
        return false;

    struct list_head *fast = head->next, *slow = head->next;

    while (fast != head && fast->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    list_del(slow);
    q_release_element(list_entry(slow, element_t, list));

    return true;
}

/* Delete all nodes that have duplicate string */
bool q_delete_dup(struct list_head *head)
{
    // https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
    return true;
}

/* Swap every two adjacent nodes */
void q_swap(struct list_head *head)
{
    // https://leetcode.com/problems/swap-nodes-in-pairs/
    if (!head)
        return;

    struct list_head *current;

    for (current = head->next; current != head && current->next != head;
         current = current->next)
        list_move_tail(current->next, current);
}

/* Reverse elements in queue */
void q_reverse(struct list_head *head) {}

/* Reverse the nodes of the list k at a time */
void q_reverseK(struct list_head *head, int k)
{
    // https://leetcode.com/problems/reverse-nodes-in-k-group/
}

/* Sort elements of queue in ascending/descending order */
void q_sort(struct list_head *head, bool descend) {}

/* Remove every node which has a node with a strictly less value anywhere to
 * the right side of it */
int q_ascend(struct list_head *head)
{
    // https://leetcode.com/problems/remove-nodes-from-linked-list/
    return 0;
}

/* Remove every node which has a node with a strictly greater value anywhere to
 * the right side of it */
int q_descend(struct list_head *head)
{
    // https://leetcode.com/problems/remove-nodes-from-linked-list/
    return 0;
}

/* Merge all the queues into one sorted queue, which is in ascending/descending
 * order */
int q_merge(struct list_head *head, bool descend)
{
    // https://leetcode.com/problems/merge-k-sorted-lists/
    return 0;
}
