%.llvm: %.c
	clang -O0 -S -emit-llvm $< -o $@;

%.lli: %.llvm
	lli $<;

clean:
	rm -f *.llvm
