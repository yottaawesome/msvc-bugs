export module somemodule:concepts;
import std;

export namespace SomeModule::Concepts
{
	template<typename T>
	struct IsVector : std::false_type {};

	template<typename T>
	struct IsVector<std::vector<T>> : std::true_type {};
}
