#include <stdio.h>

#define offsetof(type,member) ((size_t) &(((type *)0)->member))
#define container_of(ptr, type, member)({\
    const typeof(((type *)123)->member) *_mptr = (ptr);\
    (type *)((char *)ptr - offsetof(type, member));\
})

struct test_t{
    char c;
    int a;
    double b; 
};

int main(int argc, char *argv[])
{
    struct test_t st = {'a', 10, 123.123};
    struct test_t *p = NULL;

    p = container_of(&st.a, struct test_t, a);
        

    printf("p->c:%c\n", p->c);
    printf("p->a:%d\n", p->a);
    printf("p->b:%lf\n", p->b);

    return 0;
}
