export module testexception;
import <exception>;
import <string>;
import <source_location>;

export namespace TestExceptions
{
	class Exception : public std::exception
	{
		public:
			virtual ~Exception() = default;
			Exception(
				const std::string& msg,
				const std::source_location& location = std::source_location::current()
			) {}
	};
}