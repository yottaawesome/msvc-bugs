#define memcpy_s memcpy_proxy

int memcpy_proxy(
    void* const,
    unsigned long long const,
    void const* const,
    unsigned long long const
);