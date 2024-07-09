export module somemodule;
import std;

export 
{
    template<auto VInvoke>
    struct CachedSetting
    {
        using TReturn = std::invoke_result_t<decltype(VInvoke)>;
        std::optional<TReturn> Cached; // Comment out to remove ICE.
    };

    constexpr CachedSetting<[]() { return 1; }> Blah;
}