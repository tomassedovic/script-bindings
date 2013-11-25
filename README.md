## Dependencies ##

### Guile 2.x development files ###

Fedora: `yum install guile-devel`

Ubuntu: `apt-get install guile-2.0-dev`


### Lua 5.2 development files ###

Ubuntu: `apt-get install liblua5.2-dev`


Script:
* Define a parameterless `main` function
* Call a C computation function (takes an int, returns a float)
* Call a printf-like C function
* Modify a C struct?
  - guile: http://www.gnu.org/software/guile/manual/html_node/Foreign-Structs.html



### Moar langs ###

Would be nice if we added more languages (and possibly different runtimes for
the languages already present). Such as:

* JavaScript (V8 and SpiderMonkey)
* Racket
  - http://docs.racket-lang.org/inside/overview.html#%28part._embedding%29
* Python
  - http://docs.python.org/2/extending/embedding.html
* Nasal?
  - http://www.plausible.org/nasal/


## License ##

Licensed under WTFPL v2. See `LICENSE.txt`.
