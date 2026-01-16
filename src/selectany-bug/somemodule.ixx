module;

#include "header.hpp"

export module somemodule;
import std;

export namespace MyNamespace
{
	using ::MyNamespace::SomeGlobal;

	constexpr auto GetSomeGlobal() -> int
	{
		return ::MyNamespace::SomeGlobal;
	}
}
