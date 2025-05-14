// Uncomment this include to fix the error,
// you can also use <memory> instead of
// <string>.
// Other alternatives don't appear to work,
// including importing <string>, exporting it
// from testmodule, or testmodule using and 
// exporting memcpy_s.
//#include <string>
// Issue goes away with /dxifcInlineFunctions- 
// See https://developercommunity.visualstudio.com/t/MSVC-says-cannot-write-function-definiti/10290176
// https://developercommunity.visualstudio.com/t/Modules-exporting-CWinRT-objects-enco/10527223
import std;
import testmodule;

int main()
{
	JSON::JsonObject root;
	auto array = JSON::JsonArray::Parse(L"[1,2,3]");
	std::ranges::for_each(array, [](auto s) { std::println("{}", s.GetNumber()); });

	return 0;
}