module;

#include <string>
#include <vector>
#include <windows.h>

export module somemodule;
// Set to true to return a constructed string, which fixes the issue.
#define RETURN_STR false

namespace SomeNamespace
{
	// Making this a member function fixes the issue
	// Removing the parameter also appears to fix the issue
	std::string BytesToString(const std::vector<std::byte>& bytes)
	{
		std::string returnVal2 = "blahblahblahblah";
		return returnVal2;
	}

	export class SomeObject final
	{
		public:
			std::string DoSomething(const std::string& plaintext)
			{
				std::vector<std::byte> randomBytes{
					std::byte(0x97), std::byte(0x38), std::byte(0xf8), std::byte(0x5d), std::byte(0x39)
				};

#if RETURN_STR
				std::string returnVal = BytesToString(randomBytes);
				return returnVal;
#else
				return BytesToString(randomBytes);
#endif
			}

			/*static std::string DoSomething(const std::string& plaintext, const std::string& seed)
			{
				SomeObject obj;
				return obj.DoSomething(plaintext);
			}*/
	};
}
