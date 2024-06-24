import std;
import formatting;

// This compiles fine when uncommented.
//template<size_t N>
//struct std::formatter<wchar_t[N]> : std::formatter<std::string>
//{
//    auto format(const wchar_t(id)[N], std::format_context& ctx) const
//    {
//        return std::format_to(ctx.out(), "{}", "a");
//    }
//};

int main()
{
    M m{ 2 };
    std::println("{}", m); // works
    std::println("{}", L"a"); // Does not compile unless the above template is uncommented.
    return 0;
}
