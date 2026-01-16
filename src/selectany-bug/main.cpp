import std;
import somemodule;

int main()
{
	// prints 42 as expected
	std::println("{}", MyNamespace::GetSomeGlobal()); 
	// prints 0, which is unexpected
	std::println("{}", MyNamespace::SomeGlobal);
}
