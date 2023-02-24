module;

#define IMPORTHEADERS true // Set to false to fix ICE

#include <include/rapidjson/rapidjson.h>
#include <include/rapidjson/document.h>
#if !IMPORTHEADERS
#include <format>
#endif

export module testmodule;

#if IMPORTHEADERS
import <format>;
#endif

export namespace TestNamespace
{
	// ICE doesn't occur if the return type is something else
	// ICE doesn't occur if this function is in some other file, like main.cpp
	rapidjson::Value* SomeFunction()
	{
		// Comment this line to fix ICE, regardless of how headers 
		// are included or what the return type is
		std::format("/{}", "path");
		
		return nullptr;
	}
}
