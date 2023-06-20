module;

#include <string>

export module somemodule;

export namespace SomeNamespace
{
	struct SomeObject
	{
		std::string DoSomething()
		{
			return "blahblahblah";
		}
	};

	std::string DoSomething2()
	{
		return "blahblahblah";
	}
}
