#include <string>
import somemodule;

int main()
{
    SomeNamespace::SomeObject obj;
    // This doesn't work. We expect to get back "blahblahblahblah", 
    // but instead we get garbage back, and the program crashes 
    // when the scope ends in Debug builds.
    std::string s = obj.DoSomething();
    std::string s2 = SomeNamespace::DoSomething2();

    return 0;
}
