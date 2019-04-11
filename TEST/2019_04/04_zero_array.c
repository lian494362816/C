#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct test_t {
    int a;
    int b;
    char buf[0];
};

int main(int argc, char *argv[])
{
    struct test_t zero_array;
    struct test_t *pst = NULL;
    char *p = NULL;

    memset(&zero_array, 0, sizeof(struct test_t));
    printf("sizeof:%ld \n", sizeof(struct test_t));

    pst = malloc(sizeof(struct test_t) + 30);
    if(NULL == pst)
    {
        printf("malloc1 fail \n");
        return -1;
    }

    p = malloc(30);
    if (NULL == p)
    {
        printf("malloc2 fail \n");
        free(pst);
        return -1;
    }

    memcpy(p, "hello word1", strlen("hello word1"));
    memcpy(pst->buf, "hello word2", strlen("hello word2"));

    printf("p:%s \n", p);
    printf("pst:%s \n", pst->buf);

    free(pst);
    free(p);
    
    return 0;
}
