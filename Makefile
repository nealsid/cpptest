range-test-copycons: range-test-copycons.cc
#	/usr/local/opt/llvm/bin/clang++ -o range-test-copycons range-test-copycons.cc -std=c++23 -L/usr/local/Cellar/llvm/19.1.0/lib/c++  -v
	g++-14 -O3 -o range-test-copycons range-test-copycons.cc -std=c++23 -ltbb -L/usr/local/lib
