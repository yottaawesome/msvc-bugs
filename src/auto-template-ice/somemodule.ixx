export module somemodule;
import std;

export
{
    struct SettableDefaults
    {
        // ICE does not occur if template is moved to the struct level.
        template<auto VGet>
        static std::expected<std::invoke_result_t<decltype(VGet)>, std::string> VNoExceptGet()
        {
            return std::invoke(VGet);
        };
    };

    template<auto VGet, auto VSet, auto VNoExceptGet = SettableDefaults::VNoExceptGet<VGet>>
    struct Settable
    {
        const auto& operator=(auto&&...set) const
        {
            return *this;
        }
    };

    constexpr Settable <
        []() -> std::string { return "a"; },
        [](std::string_view i) { }
    > TestSettable;
}