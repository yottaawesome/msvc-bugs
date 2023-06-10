export module testexception;
import <exception>;
import <source_location>;
//import std;

export namespace TestExceptions
{
	class Exception : public std::exception
	{
		public:
			virtual ~Exception() = default;
			Exception(
				const char* msg,
				const std::source_location& location = std::source_location::current()
			) {}
	};
}