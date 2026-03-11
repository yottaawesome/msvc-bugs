import std;

// Bug ticket https://developercommunity.visualstudio.com/t/C2666-false-ambiguity-with-explicit-obje/11058201
namespace strings
{
	template<typename T>
	struct always_false : std::false_type {};

	template<std::size_t N, typename TChar = char>
	struct fixed_string
	{
		TChar Buffer[N]{};
		constexpr fixed_string(const TChar(&str)[N])
		{
			std::copy_n(str, N, Buffer);
		}
		constexpr auto begin(this auto&& self) noexcept { return self.Buffer; }
		constexpr auto end(this auto&& self) noexcept { return self.Buffer + N - 1; }

		template<std::size_t M>
		constexpr auto operator==(this auto&& self, const TChar(&str)[M]) noexcept -> bool
		{
			if constexpr (N != M)
				return false;
			else
				return std::equal(self.begin(), self.end(), str, str + N - 1);
		}

		template<std::size_t M>
		constexpr auto operator==(this auto&& self, const fixed_string<M, TChar>& other) noexcept -> bool
		{
			if constexpr (N != M)
				return false;
			else
				return std::equal(self.begin(), self.end(), other.begin(), other.end());
		}
	};
	template<std::size_t N>
	fixed_string(const char(&str)[N]) -> fixed_string<N, char>;
	template<std::size_t N>
	fixed_string(const wchar_t(&str)[N]) -> fixed_string<N, wchar_t>;
	// GCC and Clang in C++26 mode compile this code with a warning, but MSVC fails
	// with "C2666: 'operator==': overloaded operator have similar conversions".
	static_assert(fixed_string("Hello") == fixed_string("Hello"));
}

int main()
{
	return 0;
}

