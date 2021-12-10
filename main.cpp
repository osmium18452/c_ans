#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    node *next;
};

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    node *head1 = NULL, *head2 = NULL;
    while (n--) {
        node *p = (node *) malloc(sizeof(node));
        scanf("%d", &(p->val));
        p->next = head1;
        head1 = p;
    }
    while (m--) {
        node *p = (node *) malloc(sizeof(node));
        scanf("%d", &(p->val));
        p->next = head2;
        head2 = p;
    }
    node *q = head2;
    while (q != NULL) {
        node *p = head1, *prev = NULL;
        while (p != NULL) {
            if (p->val == q->val) {
                if (p == head1) {
                    head1 = p->next;
                    free(p);
                    p=head1;
                } else if (p->next == NULL) {
                    prev->next = NULL;
                    free(p);
                    break;
                } else {
                    prev->next = p->next;
                    free(p);
                    p = prev->next;
                }
            } else {
                prev = p;
                p = p->next;
            }
        }
        q = q->next;
    }
    node *p = head1;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    return 0;
}