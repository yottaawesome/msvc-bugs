import std;

namespace Util
{
	template<typename T>
	concept ValidCharType = std::same_as<T, char> or std::same_as<T, wchar_t>;

	template<typename T>
	concept ValidViewType = std::same_as<T, std::string_view> or std::same_as<T, std::wstring_view>;

	template<typename T>
	concept ValidStringType = std::same_as<T, std::string> or std::same_as<T, std::wstring>;

	template <ValidCharType TChar, ValidViewType TView, ValidStringType TString, size_t N>
	struct FixedString
	{
		using CharType = TChar;
		using ViewType = TView;
		using StringType = TString;

		TChar buf[N]{};

		consteval FixedString(const TChar(&arg)[N]) noexcept
		{
			std::copy_n(arg, N, buf);
		}

		constexpr operator const TChar* () const noexcept
		{
			return buf;
		}

		consteval TView ToView() const noexcept
		{
			return { buf };
		}

		consteval operator TView() const noexcept
		{
			return { buf };
		}

		constexpr operator TString() const noexcept
		{
			return { buf };
		}

		constexpr TString ToString() const noexcept
		{
			return { buf };
		}
	};
	// Comment out the below to make ICE go away
	template<size_t N>
	FixedString(char const (&)[N]) -> FixedString<char, std::string_view, std::string, N>;
	template<size_t N>
	FixedString(wchar_t const (&)[N]) -> FixedString<wchar_t, std::wstring_view, std::wstring, N>;
	// Comment out the above to make the ICE go away

	template<size_t N>
	using WideFixedString = FixedString<wchar_t, std::wstring_view, std::wstring, N>;
	template<size_t N>
	using NarrowFixedString = FixedString<char, std::string_view, std::string, N>;
}

namespace Test
{
    template<Util::WideFixedString VClassName>
    struct ControlTraits
    {
        virtual ~ControlTraits() = default;
        static constexpr std::wstring_view Class = VClassName;
    };

    template<Util::WideFixedString VText, unsigned long VId, unsigned long VX>
    struct TestButtonTraits : public ControlTraits<L"Button"> { };
}

int main()
{
	return 0;
}
