#!/bin/bash

echo "Must be ran as root"

g++ -I headers/ -fPIC -shared src/defaults.cpp -o libdefaults.so
cp libdefaults.so /lib
g++ -I headers/ -fPIC -shared src/pickone.cpp -o libpick1.so
cp libpick1.so /lib
g++ -I headers/ -fPIC -shared src/picktwo.cpp -o libpick2.so
cp libpick2.so /lib
g++ -I headers/ -fPIC -shared src/pickthree.cpp -o libpick3.so
cp libpick3.so /lib
g++ -I headers/ -fPIC -shared src/options.cpp -o liboptions.so
cp liboptions.so /lib
g++ -I headers/ -L. -ldefaults -lpick1 -lpick2 -lpick3 -loptions -lcrypto REhelper.cpp -o REhelper