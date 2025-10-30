#ifndef __HYPERION_DIAG_H
#define __HYPERION_DIAG_H

#define __DIAG_HALT(where, what, data, size)                                   \
    printf("HALT AT %s: %s\n", where, what);                                   \
    for (int i = 0; i < size; i++) {                                           \
        if (i % 8 == 0)                                                        \
            puts("");                                                          \
        printf(" %.5e ", *(data + i));                                         \
    }                                                                          \
    puts("");                                                                  \
    getchar();

// This redifines the macro, which is _probably_ bad practice. I _definitely_
// don't care :)
#ifndef __DIAG_ON
#define __DIAG_HALT(where, what, data, size)
#endif

#endif
