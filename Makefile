FILE=use_aa

all: ${FILE}.cpp

	clang -shared ${FILE}.cpp -o ${FILE}.so `llvm-config --cppflags` -std=gnu++11 -fno-rtti -fPIC
