export module somemodule;

export namespace TestNamespace
{
	constexpr auto Do() -> int*
	{
		return new int(0);
	}
	constexpr auto MakeInt() noexcept -> int*
	{
		if consteval
		{
			auto x = Do();
			delete x;
			//[] { return new int(0); };
		}
		return nullptr;
	}
}
