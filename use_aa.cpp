#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Analysis/AliasSetTracker.h"
using namespace llvm;

//#define DEBUG_TYPE "hello"

namespace {
  struct Hello : public FunctionPass{ 
    static char ID;
    Hello() : FunctionPass(ID) {
    }
    AliasSetTracker *AST;

    virtual bool runOnFunction(Function &F) override{
      AliasAnalysis &AA = getAnalysis<AAResultsWrapperPass>().getAAResults();
      AliasSetTracker tr(AA);
      errs() << " Hello: ";
      errs().write_escaped(F.getName()) << '\n';
      for(auto& BB : F){
        for(auto& I : BB){
          if(AllocaInst *alloc = dyn_cast<AllocaInst>(&I)){
	    tr.add(&I);

//            errs()<< *alloc << '\n';
	  }
	  
	  else if(StoreInst *SI = dyn_cast<StoreInst>(&I)){
	    tr.add(SI);
//            errs()<< *SI << '\n';

	  }
	  
	  else{
            
	  }
        }
      }

      for (const AliasSet &AS : tr){
        for (auto I = AS.begin(); I != AS.end(); I++)
          errs()<<"Found Alias To " << *I.getPointer() << '\n';
      }

      return false;
    }
    virtual void getAnalysisUsage(AnalysisUsage &AU) const override {
      AU.addRequired<AAResultsWrapperPass>();
    }
  };
}

char Hello::ID = 0;
static RegisterPass<Hello> X("hello", "Hello World Pass");
