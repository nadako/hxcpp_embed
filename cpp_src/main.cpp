#include <Calculator.h>

extern "C" void __hxcpp_lib_main();

int main() {
	__hxcpp_lib_main();

	auto result = Calculator_obj::add(2, 3);
	printf("Result: %d\n", result);

	return 0;
}
