export module somemodule;
import std;

export 
{
    // ICE does not occur if this template is moved to main.
    template<auto VInvoke>
    struct CachedSetting
    {
        using TReturn = std::invoke_result_t<decltype(VInvoke)>;
        std::optional<TReturn> Cached; // Comment out to remove ICE.
    };
    // ICE does not occur if this is moved to main.
    constexpr CachedSetting<[] { return 1; }> Blah;
}