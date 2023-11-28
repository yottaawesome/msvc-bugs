template<typename T>
concept Something = requires(T t)
{
	t();
};

template<typename V, template<typename T>>
void Func() {}

int main()
{
	Func<int, Something>();
	return 0;
}
