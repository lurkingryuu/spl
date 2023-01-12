# Systems Programming Laboratory

## GCC
---
#### Preprocessing
- `ds.c > ds.i`

#### Compiling
- ```gcc -S ds.i``` -> gives ds.s as an output

#### Assembling
- ```as ds.s -o ds.o```
- To check the contents of file -> ```nm ds.o```

#### Linking
- ```gcc -o ds.out ds.o```
- ```nm ds.out``` -> To check the contents of the binary ds.out 
#### Runtime Loading
- ```gcc -static -o ds.out ds.o```
- ```ldd ds.out``` -> This command lists the dynamically linked dependencies

#### One Shot
- ```gcc -Wall -o app ds.c defs.c queue.c stack.c hash.c```
#### Individual object files
- ```gcc -Wall -c defs.c```
- ```gcc -Wall -c stack.c```
- ```gcc -wall -c queue.c```
- ```gcc -Wall -c heap.c```
- ```gcc -Wall -o app ds.c defs.o queue.o stack.o hash.o```

## Libraries
---
#### Basic categories
- Static Libraries
	- format: `libm.a` is a static library of math library, in which `lib` is a prefix, `.a` is the suffix
	- The functions are inserted in the executable during the linking, increasing the size of the executable significantly
- Dynamic/Shared Libraries
	- format: `libm.so` is a dynamic/shared library of math library, in which `lib` is a prefix, `.so` is the suffix
	- The functions are read from the .so objects during runtime. `ldd a.out` will list out the dynamically linked dependencies

#### Static Library
	
- `ar rcs libstaqueheap.a defs.o stack.o queue.o heap.o`
- compiling by `gcc -Wall ds.c` will give an error. 
- Instead, use `gcc -Wall -o ds.out -L. ds.c -lstaqueheap`. 
- `-L.` where the `-L` flag advises the linker to add `.` to the library path.
- We can avoid `-L` flag by adding `libstaqueheap.a` in `/usr/lib or /usr/local/lib or /usr/lib/x86_64-linux-gnu/`
	


