export module testexception;
import <source_location>;
//import std;

export namespace TestExceptions
{
	struct Exception
	{
		Exception(
			const char* msg,
			const std::source_location& location = std::source_location::current()
		) {}
	};
}