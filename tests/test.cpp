#include "sg_test.hpp"

int someOperationThatMightThrow() {
	return 1;
}

int main() {
	sg::test::Test tester(4);
	tester.pass("First test succeeds");
	tester.test(true, "Second test succeeds");
	tester.diag("Some diagnostics output");
	tester.start_block(2);
	try {
		int result = someOperationThatMightThrow();
		tester.pass("Operation didn't throw");
		tester.test(result == 1, "Result is one");
	} catch(...) {}
	tester.end_block();
}
