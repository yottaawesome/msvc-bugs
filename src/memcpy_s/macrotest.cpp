#include <string>

int memcpy_proxy(
    void* const destination,
    unsigned long long const destinationSize,
    void const* const source,
    unsigned long long const sourceSize
)
{
    return memcpy_s(destination, destinationSize, source, sourceSize);
}