all: 1a.llvm 1b.llvm 2a.llvm 2b.llvm 3.llvm 4.llvm

%.llvm: %.c
	clang -O0 -S -emit-llvm $< -o $@;

clean:
	rm -f *.llvm
