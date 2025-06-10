// Compile with std=c++latest and C++23 standard library modules.
import std;

enum Blah
{
	X [[deprecated]]
};

// OK
namespace [[deprecated]] AnotherNamespace { }

// Fails to compile on MSVC, but accepted by GCC and Clang
namespace SomeNamespace [[deprecated]] { }

int main()
{
	return 0;
}
