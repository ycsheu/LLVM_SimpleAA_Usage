# LLVM_SimpleAA_Usage
## Introduction
A simple example composed only of necessary codes.

An example to the usage of AliasSetTracker

## Usage
aa1.c is the target to be analyzed.

aa1.ll is the llvm ir of aa1.c

use_aa.cpp is the pass we concerned about

install llvm then
``` bash
sh make.sh && sh test.sh
```
## Reference
https://stackoverflow.com/questions/44092428/llvm-4-0-0-initialize-an-aliassettracker-class
