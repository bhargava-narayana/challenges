#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>

#ifndef INLINE
#if __GNUC__ && !__GNUC_STDC_INLINE__
#       define INLINE exten inline
#else
#       define INLINE inline
#endif
INLINE int max(unsigned long long element1, unsigned long long element2) {
        return element1>element2 ? element1 : element2;
}
