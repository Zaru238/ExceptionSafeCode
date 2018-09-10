gcc_dir = build_gcc
clang_dir = build_clang

clang:
	mkdir -p $(clang_dir)
	cmake -B$(clang_dir) -H.
	make -C $(clang_dir)

gcc:
	mkdir -p $(gcc_dir)
	cmake -B$(gcc_dir) -H. -DCMAKE_CXX_COMPILER=g++
	make -C $(gcc_dir)

.PHONY: clean

clean:
	rm -rf $(gcc_dir) $(clang_dir)
