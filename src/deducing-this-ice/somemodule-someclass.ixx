export module somemodule:someclass;
import std;
import :concepts;

export namespace SomeModule::Stuff
{
	template<typename T>
	struct SomeClass
	{
		auto ToVector(this auto&& self) -> std::vector<T>
		{
			std::vector<int> something;
			return {};
		}
	};
}
