all: 1.llvm 1.opt.llvm 1.pass.llvm 2.llvm 2.opt.llvm 2.pass.llvm 3.llvm 3.opt.llvm 3.pass.llvm 4.llvm 4.opt.llvm 4.pass.llvm

%.pass.llvm: %.llvm
	opt -O3 -S -print-after-all $< &> $@;

%.opt.llvm: %.c
	clang -O3 -S -emit-llvm $< -o $@;

%.llvm: %.c
	clang -O0 -S -emit-llvm $< -o $@;

%.opt.lli: %.opt.llvm
	lli $<;

%.lli: %.llvm
	lli $<;

clean:
	rm -f *.llvm
