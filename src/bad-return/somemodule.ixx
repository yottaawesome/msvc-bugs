module;

#include <string>
#include <vector>
#include <windows.h>

export module somemodule;
// Set to true to return a pre-constructed string, which fixes the issue.
#define RETURN_STR false

namespace SomeNamespace
{
	// Making this a member function of SomeObject fixes the issue.
	// Removing the parameter also appears to fix the issue.
	std::string BytesToString(const std::vector<std::byte>& bytes)
	{
		// Returning returnVal or "blahblahblahblah" directly makes no difference.
		std::string returnVal = "blahblahblahblah";
		return returnVal;
	}

	// Using a struct or class makes no difference.
	export struct SomeObject
	{
		std::string DoSomething(const std::string& plaintext)
		{
			// Dummy argument with random bytes
			std::vector<std::byte> randomBytes{
				std::byte(0x97), std::byte(0x38), std::byte(0xf8), std::byte(0x5d), std::byte(0x39),
				std::byte(0x79), std::byte(0xa0), std::byte(0xde), std::byte(0xa2), std::byte(0xd2)
			};

#if RETURN_STR
			// This works fine.
			std::string returnVal = BytesToString(randomBytes);
			return returnVal;
#else
			// This doesn't.
			return BytesToString(randomBytes);
#endif
		}
	};
}
