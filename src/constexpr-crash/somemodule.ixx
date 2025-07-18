export module somemodule;

import std;

export namespace SomeNamespace
{
	struct Properties
	{
		// Changing this to a different data type like int makes the crash go away.
		std::wstring Class;
	};

	// Removing constexpr from the constructors makes the crash go away.
	struct SomeClass
	{
		constexpr SomeClass(Properties properties) {}
	};

	struct SomeSubclass : SomeClass
	{
		constexpr SomeSubclass() : SomeClass(Properties{ .Class = L"something" }) {}
	};
}
