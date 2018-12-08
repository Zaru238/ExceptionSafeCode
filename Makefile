conan_dir = tools/conan

release_dir = build_release
debug_dir = build_debug

release:
	mkdir -p $(release_dir)
	cmake -B$(release_dir) -H. -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Release
	make -C $(release_dir)
	cd $(release_dir) && valgrind --leak-check=yes --error-exitcode=1 bin/testrunner || exit 1

debug:
	mkdir -p $(debug_dir)
	cmake -B$(debug_dir) -H. -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Debug
	make -C $(debug_dir)
	cd $(debug_dir) && valgrind --leak-check=yes --error-exitcode=1 bin/testrunner || exit 1


.PHONY: clean apply_format

format:
	scripts/apply_clang_format.sh

clean:
	rm -rf $(debug_dir) $(release_dir)
