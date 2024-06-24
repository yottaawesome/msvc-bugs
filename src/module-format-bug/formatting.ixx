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

    template<size_t N>
    struct std::formatter<wchar_t[N]> : std::formatter<std::string>
    {
        auto format(const wchar_t(id)[N], std::format_context& ctx) const
        {
            return std::format_to(ctx.out(), "{}", "a");
        }
    };
}
