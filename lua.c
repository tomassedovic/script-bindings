#include <stdio.h>
#include <stdlib.h>

#include <lua.h>
#include <lauxlib.h>

int main(int argc, char **argv) {
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
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
	return 0;
}
