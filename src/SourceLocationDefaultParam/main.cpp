// #include <source_location> // uncomment to fix ICE
//import <source_location>; // does not fix ICE
//import std; // does not fix ICE
import testexception;

int main()
{
    // ICE only occurs when constructed and thrown in one statement. 
    // ICE doesn't occur when separately constructing and then
    // throwing the exception.
    // ICE doesn't occur when invoking functions or function members.
    throw TestExceptions::Exception("Some test message");

    return 0;
}
