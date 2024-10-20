import std;

namespace InvalidConstexpr
{
	struct A
	{
		~A()
		{
			std::filesystem::remove("AAAAAA");
		}
	};

	struct B
	{
		constexpr ~B()
		{
			if (H)
				delete H;
		}

		auto Get() const
		{
			if (not H) H = new A();
			return H;
		}

		mutable A* H = nullptr;
	};

	constexpr B X; // this should not compile, gcc and clang reject it
}

int main()
{
	return 0;
}

