module;

#include <winrt/windows.foundation.h>
#include <winrt/windows.foundation.collections.h>
#include <winrt/windows.data.json.h>

export module somemodule;

export namespace SomeNamespace
{
	class SomeClass
	{
		public:
			SomeClass() {} // Comment this out to fix the issue
			//SomeClass(); // Uncomment this to fix the issue

		private:
			winrt::Windows::Data::Json::JsonObject m_root;
	};
	//SomeClass::SomeClass() {} // Uncomment this to fix the issue
}
