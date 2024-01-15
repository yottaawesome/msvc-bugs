export module somemodule;
import std;

// ICE seems to only occur in module code. If this code is in main.cpp, the ICE doesn't happen.
export namespace test_namespace
{
	auto make_safe()
	{
		return []
		{
			// Commenting out the try-catch (leaving returns) also resolves the ICE.
			try
			{
				return true;
			}
			catch (...)
			{
				return false;
			}
		};
	}
}