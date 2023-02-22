module;

#include <exception>
#include <string>
#include <source_location>

module testexception;

namespace TestExceptions
{
	Exception::Exception(
		const std::string& msg,
		const std::source_location& location
	)
	{ }
}