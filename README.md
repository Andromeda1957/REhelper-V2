# REhelperp-V2
REhelper rewritten in C++

Either compile manually or use the install script. <br .>

## Compile
export LD_LIBRARY_PATH=\<dir of REhelper.cpp\> <br />
g++ -I headers/ -fPIC -shared src/defaults.cpp -o libdefaults.so <br />
g++ -I headers/ -fPIC -shared src/pickone.cpp -o libpick1.so <br />
g++ -I headers/ -fPIC -shared src/picktwo.cpp -o libpick2.so <br />
g++ -I headers/ -fPIC -shared src/pickthree.cpp -o libpick3.so <br />
g++ -I headers/ -fPIC -shared src/options.cpp -o liboptions.so <br />
g++ -I headers/ -L. -ldefaults -lpick1 -lpick2 -lpick3 -loptions -lcrypto REhelper.cpp -o REhelper

## Install
bash install.sh
