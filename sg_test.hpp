#include <iostream>
#include <string>
#include <stdexcept>

namespace sg { namespace test {

struct Test {
	Test(int num_tests)
	: testnum(1)
	, block_end(0)
	{
		std::cout << "1.." << num_tests << std::endl;
	}

	void pass(std::string text) {
		std::cout << "ok " << testnum++ << " " << text << std::endl;
	}

	void fail(std::string text) {
		std::cout << "not ok " << testnum++ << " " << text << std::endl;
	}

	void diag(std::string text) {
		std::cout << "# " << text << std::endl;
	}

	void diag(const std::exception &e) {
		diag(e.what());
	}

	void test(bool condition, std::string text) {
		if(condition) {
			pass(text);
		} else {
			fail(text);
		}
	}

	void start_block(int num_tests) {
		block_end = testnum + num_tests;
	}

	void end_block() {
		if(block_end == 0) {
			diag("Test is broken: test_finish_try called without test_start_try");
			return;
		}
		if(testnum > block_end) {
			diag("Test is broken: more tests already run than promised in test_start_try");
		}
		while(testnum < block_end) {
			fail("try {} block failed");
		}
		block_end = 0;
	}

private:
	//! Next test to run
	int testnum;
	//! If block_end == testnum, the end of the block was reached
	int block_end;
};

}}
