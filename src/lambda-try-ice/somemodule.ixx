export module somemodule;
import std;

// ICE seems to only occur in module code. If this code is in main.cpp, the ICE doesn't happen.
export namespace test_namespace
{
	auto make_safe()
	{
		return []
		{
			// Commenting out the try-catch (leaving the invoke and returns) also resolves the ICE.
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

	auto return_safe_lambda()
	{
		// No ICE occurs if we don't return anything from this function,
		// i.e. we just call make_safe().
		return make_safe();
	}
}