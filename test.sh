clang aa1.c -S -emit-llvm
opt -load ./use_aa.so -hello aa1.ll
