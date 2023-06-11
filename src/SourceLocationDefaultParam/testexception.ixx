export module testexception;
import <exception>;
import <source_location>;
//import std;

export namespace TestExceptions
{
	struct Exception : public std::exception
	{
		Exception(
			const char* msg,
			const std::source_location& location = std::source_location::current()
		) {}
	};
}