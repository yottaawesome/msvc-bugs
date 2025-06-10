module;

#include <corecrt_memcpy_s.h>
#include <strsafe.h>
#include <memory.h>
#include "macrotest.hpp" // <----------------- HACK, BUT WORKS!
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/windows.data.json.h>

export module testmodule;

export namespace JSON
{
    using 
        ::winrt::Windows::Data::Json::JsonObject,
        ::winrt::Windows::Data::Json::JsonArray;
}
