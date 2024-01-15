export module somemodule;
import std;

export namespace test_namespace
{
	auto make_safe(auto&& callable, auto&&...args)
	{
		return [callable, ...args = std::forward<decltype(args)>(args)]
		{
			// Commenting out the try-catch (leaving the invoke and returns) resolves the ICE.
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

	auto F1()
	{
		// ICEs here -- doesn't happen if we don't return anything from this function.
		return make_safe(some_func, some_struct{});
	}
}