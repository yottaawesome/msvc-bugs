#include <string>
import somemodule;

int main()
{
    SomeNamespace::SomeObject obj;
    std::string s = obj.DoSomething();

    return 0; // place breakpoint here
}
