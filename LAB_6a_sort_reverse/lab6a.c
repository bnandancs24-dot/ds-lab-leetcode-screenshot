#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

/* Create a linked list */
struct node* create(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;

    for (int i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

/* Display a list */
void display(struct node *head) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Sort a list */
void sort(struct node *head) {
    struct node *i, *j;
    int temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted\n");
}

/* Reverse a list */
struct node* reverse(struct node *head) {
    struct node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    printf("List reversed\n");
    return prev;
}

/* Concatenate two lists */
struct node* concatenate(struct node *h1, struct node *h2) {
    struct node *temp;

    if (h1 == NULL)
        return h2;

    temp = h1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = h2;
    printf("Lists concatenated\n");
    return h1;
}

int main() {
    int choice, n;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Create List 1\n");
        printf("2. Create List 2\n");
        printf("3. Sort List 1\n");
        printf("4. Reverse List 1\n");
        printf("5. Concatenate List 1 and List 2\n");
        printf("6. Display List 1\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes in List 1: ");
                scanf("%d", &n);
                head1 = create(n);
                break;

            case 2:
                printf("Enter number of nodes in List 2: ");
                scanf("%d", &n);
                head2 = create(n);
                break;

            case 3:
                sort(head1);
                break;

            case 4:
                head1 = reverse(head1);
                break;

            case 5:
                head1 = concatenate(head1, head2);
                break;

            case 6:
                display(head1);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
