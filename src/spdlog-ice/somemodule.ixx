module;

#include <string>
#include "spdlog/spdlog.h"

export module somemodule;

export namespace SomeModule
{
	void Info(const std::string_view fmt, auto&&...args)
	{
		spdlog::info(fmt.data(), std::forward<decltype(args)>(args)...);
	}
}