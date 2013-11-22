#include <stdio.h>
#include <stdlib.h>

#include <lua.h>
#include <lauxlib.h>

static int has_entity(lua_State *L) {
	int arg_count = lua_gettop(L);
	if(arg_count != 1) {
		lua_pushstring(L, "`has_entity` expects a single argument");
		lua_error(L);
	}
	// read the first argument from the stack
	int id = luaL_checkint(L, 1);
	// return a single boolean value
	lua_pushboolean(L, id > 0 && id < 10); return 1;
}

static int factorial(lua_State *L) {
	int arg_count = lua_gettop(L);
	if(arg_count != 1) {
		lua_pushstring(L, "`has_entity` expects a single argument");
		lua_error(L);
	}
	int n = luaL_checkint(L, 1);
	double result = 1.0;
	int i = 0;
	for(i = 1; i <= n; i++) {
		result *= i;
	}
	lua_pushnumber(L, result); return 1;
}

void run_lua_script(char* script_name) {
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	// Define a C function in Lua
	lua_pushcfunction(L, &has_entity); lua_setglobal(L, "has_entity");
	lua_pushcfunction(L, &factorial); lua_setglobal(L, "factorial");

	int status = luaL_loadfile(L, "main.lua");
	if(status) {
		fprintf(stderr, "Couldn't load file: %s\n", lua_tostring(L, -1));
		exit(1);
	}
	int result = lua_pcall(L, 0, LUA_MULTRET, 0);
	if(result) {
		fprintf(stderr, "Failed to run script: %s\n", lua_tostring(L, -1));
		exit(1);
	}
	lua_getglobal(L, "main");
	lua_call(L, 0, 0);
	lua_close(L);
}

int main(int argc, char **argv) {
	if(argc == 2) {
		run_lua_script(argv[1]);
	} else {
		printf("You must enter the path to the script.");
		return 1;
	}
	return 0;
}
