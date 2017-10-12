set -e

cd build
cmake ..
cd ..

cp SFML-2.4.2/bin/* build/bin/Debug

echo "*** Now go open the VS solution..."