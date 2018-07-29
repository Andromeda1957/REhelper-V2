#!/bin/bash

echo "Must be ran as root"

g++ -I headers/ -fPIC -shared src/defaults.cpp -o libdefaults.so
mv libdefaults.so /lib
g++ -I headers/ -fPIC -shared src/pickone.cpp -o libpick1.so
mv libpick1.so /lib
g++ -I headers/ -fPIC -shared src/picktwo.cpp -o libpick2.so
mv libpick2.so /lib
g++ -I headers/ -fPIC -shared src/pickthree.cpp -o libpick3.so
mv libpick3.so /lib
g++ -I headers/ -fPIC -shared src/options.cpp -o liboptions.so
mv liboptions.so /lib
g++ -I headers/ -L. -ldefaults -lpick1 -lpick2 -lpick3 -loptions -lcrypto REhelper.cpp -o REhelper
mv REhelper /usr/local/bin