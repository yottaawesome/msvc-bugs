#include <string>
import somemodule;

int main()
{
    // We expect to get back "blahblahblahblah", but instead we get garbage back, 
    // and the program crashes when the scope ends in Debug builds.
    SomeNamespace::SomeObject obj;
    std::string s = obj.DoSomething("blah");

    return 0;
}
