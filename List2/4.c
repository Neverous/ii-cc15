#include <stdlib.h>
#include <stdio.h>

struct tree
{
    double x;
    double y;
    struct tree *left;
    struct tree *right;
}; // struct tree

const double *find(double x, const struct tree *t)
{
    while(t)
    {
        if(t->x < x)
            t = t->right;

        else if(t->x > x)
            t = t->left;

        else
            break;
    }

    if(t)
        return &t->y;

    return 0;
}

struct tree *test;

int main(void)
{
    test = (struct tree*) malloc(sizeof(struct tree));
    test->x = 1.0;
    test->y = 1.0;
    test->left = (struct tree*) malloc(sizeof(struct tree));
    test->right = (struct tree*) malloc(sizeof(struct tree));
    test->left->x = 0.0;
    test->left->y = 0.0;
    test->left->left = NULL;
    test->left->right = NULL;
    test->right->x = 2.0;
    test->right->y = 2.0;
    test->right->left = NULL;
    test->right->right = NULL;

    printf("%.2lf\n", *find(0.0, test));
    printf("%.2lf\n", *find(1.0, test));
    printf("%.2lf\n", *find(2.0, test));
    printf("%ld\n", (long) find(7.0, test));

    return 0;
}
