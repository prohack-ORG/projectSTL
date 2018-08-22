#ifndef LOGGING_H
#define LOGGING_H


#ifdef DEBUG_PRINT
#define PRINTF(X) printf("%s\t%s\n", __func__, X);
#else
#define PRINTF(X)
#endif
#define TO_STR(X) std::to_string(X)

#endif //endof LOGGING_H
