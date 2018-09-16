conan_dir = tools/conan

release_dir = build_release
debug_dir = build_debug

release:
	mkdir -p $(release_dir)
	conan install -if $(release_dir) $(conan_dir) --profile $(conan_dir)/profile_clang_release --build gtest
	cmake -B$(release_dir) -H. -DCMAKE_CXX_COMPILER=clang++-6.0 -DCMAKE_BUILD_TYPE=Release
	make -C $(release_dir)
	cd $(release_dir) && ctest -T memcheck --verbose || exit 1

debug:
	mkdir -p $(debug_dir)
	conan install -if $(debug_dir) $(conan_dir) --profile $(conan_dir)/profile_clang_debug --build gtest
	cmake -B$(debug_dir) -H. -DCMAKE_CXX_COMPILER=clang++-6.0 -DCMAKE_BUILD_TYPE=Debug
	make -C $(debug_dir)
	cd $(debug_dir) && ctest -T memcheck --verbose || exit 1


.PHONY: clean apply_format

apply_format:
	scripts/apply_clang_format.sh

clean:
	rm -rf $(debug_dir) $(release_dir)
