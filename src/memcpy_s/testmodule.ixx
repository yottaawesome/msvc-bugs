module;
#include <strsafe.h>
#include <memory.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/windows.data.json.h>

export module testmodule;

export namespace JSON
{
	using winrt::Windows::Data::Json::JsonObject;
}
