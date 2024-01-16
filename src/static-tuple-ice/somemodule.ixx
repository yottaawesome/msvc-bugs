export module somemodule;
import std;

export namespace test_namespace
{
	struct some_struct
	{
		static auto make_tuple()
		{
			// return std::tuple{ 1, "a" }; // this is OK
			return std::tuple{ [] { } }; // this appears to generate an ICE
		}
	};
}