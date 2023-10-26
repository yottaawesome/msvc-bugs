import std;

namespace Test
{
    template <size_t N>
    struct FixedString
    {
        char buf[N]{};
        consteval FixedString(const char(&arg)[N]) noexcept
        {
            std::copy_n(arg, N, buf);
        }

        consteval const char* ConstEvalData() const noexcept
        {
            return buf;
        }

        constexpr const char* ConstExprData() const noexcept
        {
            return buf;
        }

        consteval std::string_view View() const noexcept
        {
            return { buf, N };
        }
    };
    template<size_t N>
    FixedString(char const (&)[N]) -> FixedString<N>;

    template<FixedString FSComment = "">
    struct FuncScope
    {
        void operator()(auto&&...args)
        {
            std::cout << std::format("{}, using FSComment.ConstEvalData()\n", FSComment.ConstEvalData());       // this either crashes or just prints garbage
            std::cout << std::format("{}, using FSComment.ConstExprData()\n", FSComment.ConstExprData());       // this works fine, prints expected result
            std::cout << std::format("{}, using FSComment.View()\n", FSComment.View());                         // this works fine, prints expected result
        }
    };

    void Run()
    {
        FuncScope<"This is a string"> ts;
        ts();
    }
}

int main()
{
    Test::Run();
    return 0;
}
