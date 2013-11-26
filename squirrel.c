#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <squirrel.h>


#define SQUIRREL_STACK_SIZE 1024  // Number of Squirrel objects


void print_func(HSQUIRRELVM v, const SQChar *s, ...) {
	va_list argp;
	va_start(argp, s);
	vprintf(s, argp);
	va_end(argp);
}

void run_squirrel_script(char* script_name) {
	HSQUIRRELVM v = sq_open(SQUIRREL_STACK_SIZE);
	sq_setprintfunc(v, &print_func, 0);
	sqstd_seterrorhandlers(v);
	sq_pushroottable(v);
	if(SQ_FAILED(sqstd_dofile(v, script_name, SQFalse, SQTrue))) {
		exit(1);
	}
	sq_pushroottable(v);
	sq_pushstring(v, "main", -1);
	sq_get(v, -2);

	sq_pushroottable(v);
	sq_call(v, 1, SQFalse, SQTrue);
	sq_pop(v, 2);
	sq_close(v);
}

int main(int argc, char **argv) {
	if(argc == 2) {
		run_squirrel_script(argv[1]);
	} else {
		printf("You must enter the path to the script.");
		return 1;
	}
	return 0;
}
