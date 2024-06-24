export module formatting;
import std;

export
{
    // Dummy type to test custom formatting.
    struct M
    {
        int x = 1;
    };

    // Custom formatter for M, compiles fine.
    template<>
    struct std::formatter<M> : std::formatter<std::string>
    {
        auto format(const M& m, std::format_context& ctx) const
        {
            return std::format_to(ctx.out(), "{}", m.x);
        }
    };

    // This doesn't work.
    /*template<size_t N>
    struct std::formatter<wchar_t[N]> : std::formatter<std::string>
    {
        auto format(const wchar_t(id)[N], std::format_context& ctx) const
        {
            return std::format_to(ctx.out(), "{}", "a");
        }
    };*/
}


// This works. Note the lack of the std qualifier before formatter. 
// Including it causes compilation to fail.
export namespace std
{
    template<size_t N>
    struct formatter<wchar_t[N]> : formatter<std::string>
    {
        auto format(auto&& id, format_context ctx) const
        {
            return format_to(ctx.out(), "{}", 10);
        }
    };
}