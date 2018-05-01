#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
  struct Hello : public FunctionPass{ //, public AliasAnalysis{
    static char ID;
    Hello() : FunctionPass(ID) {}

    virtual bool runOnFunction(Function &F){
      errs() << " Hello: ";
      errs().write_escaped(F.getName()) << '\n';
      return false;
    }
  };
}

char Hello::ID = 0;

static RegisterPass<Hello> X("hello", "Hello World Pass");
