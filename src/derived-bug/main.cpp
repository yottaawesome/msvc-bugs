#include <string>

// Independently ran into this bug, already reported: https://developercommunity.visualstudio.com/t/Static-constexpr-member-of-CRTP-base-cla/10503957
template <typename TDerived>
struct Superclass
{
    static constexpr std::wstring_view Value = TDerived::ClassName;
};
struct Subclass : public Superclass<Subclass>
{
    static constexpr std::wstring_view ClassName = L"blahblah";
};

int main()
{
	return 0;
}
