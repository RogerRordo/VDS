cp VDS/start.png temp.png
eog temp.png &
g++ VDS/VDS.h VDS/VDS.cpp $1 -std=c++14 -o vds -g
gdb -ex "source VDS/vdsgdb.gdb" vds
rm temp.png
rm temp.dot
