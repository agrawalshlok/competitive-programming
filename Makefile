#CXX = /opt/homebrew/opt/llvm/bin/clang++ # Replace 'g++' with the name of your preferred C++ compiler (e.g., clang++)
CXX = g++-13
#CXXFLAGS=-std=c++17 -DLOCAL -g -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-variadic-macros -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -fsanitize-address-use-after-scope
D ?= 0
ifeq ($(D), 1)
	CXXFLAGS=-std=c++17 -DLOCAL -g -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-variadic-macros -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
else ifeq ($(D), 2)
	CXXFLAGS=-std=c++17 -DLOCAL -Wl,-stack_size -Wl,20000000
else
	CXXFLAGS=-std=c++17 -DLOCAL
endif

#clean:
#	find . -maxdepth 1 -type f -executable -delete
clean:
	find . -type f -perm +111 -delete
