import std;

template<typename...T>
struct A
{
	operator auto() { return T{}; };
};

int main()
{
	A<int> a;
	int x = a;
	return 0;
}
