## Dependencies ##

### Guile 2.x development files ###

Fedora: `yum install guile-devel`

Ubuntu: `apt-get install guile-2.0-dev`


### Lua 5.2 development files ###

Fedora: `yum install lua-devel`

Ubuntu: `apt-get install liblua5.2-dev`

### Squirrel development files ###

Since Fedora ships Squirrel 2 and Ubuntu doesn't have it at all and it compiles
in a few seconds with no dependencies, we just bundle Squirrel 3.0.4 in
`lib/squirrel`.

Running `make lib/squirrel/lib/libsquirrel.a` will compile the language. The
target for the C program that includes Squirrel has it as a dependency so `make
squirrel` should just work.


### Script ###

The steps each script should do:

* Define a parameterless `main` function
* Call a C computation function (takes an int, returns a float)
* Call a printf-like C function
* Modify a C struct?
  - guile: http://www.gnu.org/software/guile/manual/html_node/Foreign-Structs.html
* Use a script-native object provided by the C code?


### Moar langs ###

Would be nice if we added more languages (and possibly different runtimes for
the languages already present). Such as:

* JavaScript (V8 and SpiderMonkey)
* Racket
  - http://docs.racket-lang.org/inside/overview.html#%28part._embedding%29
* Python
  - http://docs.python.org/2/extending/embedding.html
* LuaJIT
* Nasal?
  - http://www.plausible.org/nasal/


## License ##

Licensed under WTFPL v2. See `LICENSE.txt`.
