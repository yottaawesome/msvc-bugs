export module somemodule;

export namespace TestNamespace
{
	constexpr int* MakeInt() noexcept
	{
		if consteval
		{
			return new int{};
		}
		return {};
	}
}
