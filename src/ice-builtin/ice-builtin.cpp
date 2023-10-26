template<auto T = __builtin_FILE()>
struct Something { };

int main()
{
    Something s;
    return 0;
}
