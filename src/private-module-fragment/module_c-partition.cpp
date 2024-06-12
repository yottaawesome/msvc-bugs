module module_c:partition;
import module_a; // changes in module_a recompiles this partition, but does not cause downstream recompilation

int c_export()
{
	return x;
}