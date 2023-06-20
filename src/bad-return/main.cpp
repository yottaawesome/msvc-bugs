#include <string>
import somemodule;

int main()
{
    SomeNamespace::SomeObject obj;
    // This doesn't work. We expect to get back "blahblahblahblah", 
    // but instead we get garbage back, and the program crashes 
    // when the scope ends in Debug builds.
    std::string s = obj.DoSomething();
    
    // On the other hand, this works fine.
    //std::string s = obj.DoAnotherThing();

    return 0;
}
