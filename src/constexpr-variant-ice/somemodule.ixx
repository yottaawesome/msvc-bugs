export module somemodule;
import std;

// Moving this namespace to main makes the issue go away.
export namespace SomeNamespace
{
	constexpr void Arrays()
	{
		constexpr std::variant<std::integral_constant<int, 0>> constants;
	}
}
