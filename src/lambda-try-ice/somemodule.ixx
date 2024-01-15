export module somemodule;
import std;

// ICE seems to only occur in module code. If this code is in main.cpp, the ICE doesn't happen.
export namespace test_namespace
{
	auto make_safe(auto&& callable, auto&&...args)
	{
		return [callable, ...args = std::forward<decltype(args)>(args)]
		{
			// Commenting out the try-catch (leaving the invoke and returns) also resolves the ICE.
			try
			{
				std::invoke(callable, args...);
				return true;
			}
			catch (...)
			{
				return false;
			}
		};
	}

	struct some_struct { };

	void some_func(const some_struct& a) { }

	auto return_safe_lambda()
	{
		// No ICE occurs iff we don't return anything from this function,
		// i.e. we just call make_safe().
		return make_safe(some_func, some_struct{});
	}
}