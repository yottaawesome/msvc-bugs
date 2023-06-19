#include <string>
import somemodule;

int main()
{
    // We expect to get back "blahblahblahblah", but instead we get garbage back, 
    // and the program crashes crashes when the scope ends
    SomeNamespace::SomeObject obj;
    std::string s = obj.DoSomething("blah");

    return 0;
}
