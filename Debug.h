#ifdef DEBUG
#define DEBUG_ERR(X) \
        do { \
                printf("ERR: %s, at line %d in %s\n", X, __LINE__, __FILE__); \
        } while (0)
#define DEBUG_LOG(...) \
        do { \
                printf(__VA_ARGS__); \
        } while (0)
#else
#define DEBUG_ERR(X) \
        do { \
        } while(0)
#define DEBUG_LOG(...) \
        do { \
        } while(0)
#endif
