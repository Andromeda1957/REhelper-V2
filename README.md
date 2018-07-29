# REhelperp-V2
REhelper rewritten in C++

## Compile
export LD_LIBRARY_PATH=\<dir of REhelper.cpp\>
g++ -I headers/ -fPIC -shared src/defaults.cpp -o libdefaults.so
g++ -I headers/ -fPIC -shared src/pickone.cpp -o libpick1.so
g++ -I headers/ -fPIC -shared src/picktwo.cpp -o libpick2.so 
g++ -I headers/ -fPIC -shared src/pickthree.cpp -o libpick3.so
g++ -I headers/ -fPIC -shared src/options.cpp -o liboptions.so
g++ -I headers/ -L. -ldefaults -lpick1 -lpick2 -lpick3 -loptions -lcrypto REhelper.cpp -o REhelper
