#include <iostream>

extern "C"{
#include "../../LuaDll/lua.h"
#include "../../LuaDll/lauxlib.h"
#include "../../LuaDll/lualib.h"
}

int c_supply_lua_foo(lua_State * L)
{
	//���մ�lua���ݹ����Ĳ���
	const char * arg1_from_lua = lua_tostring(L, 1);
	const char * arg2_from_lua = lua_tostring(L, 2);

	printf("arg1 is [%s]\n", arg1_from_lua);
	printf("arg2 is [%s]\n", arg2_from_lua);

	//Ҫ���ݸ�lua�ķ���ֵ
	lua_pushstring(L, "����");
	lua_pushnumber(L, 26);
	lua_pushstring(L, "washing");

	return 3;//����ֵ����
}

int main(int argc, char* argv[])
{
	lua_State * L = luaL_newstate();
	
	luaL_openlibs(L);
		
	/* 1>> ִ���ַ���
		const char *buf = "print('hello, world!')";
		luaL_dostring(L, buf);
	*/
	
	/* 2>> ִ���ļ�����ȡȫ�ֱ���
		luaL_dofile(L, ".\\Resources\\my.lua");
		lua_getglobal(L, "name");
		lua_getglobal(L, "age");
		lua_getglobal(L, "job");
		const char * name = lua_tostring(L, 1);
		int age = (int)lua_tointeger(L, 2);
		const char * job = lua_tostring(L, 3);
		printf("name = [%s]\n", name);
		printf("age =  [%d]\n", age);
		printf("job =  [%s]\n", job);

		lua_pop(L, 2);

		const char * last = lua_tostring(L, 1);
		printf("last = [%s]\n", last);
	*/

	/* 3>> c����lua����
		luaL_dofile(L, ".\\Resources\\my.lua");
		lua_getglobal(L, "addAge");
		lua_pushnumber(L, 10);
		lua_pcall(L, 1, 2, 0);

		int count = lua_gettop(L);
		int ret = lua_tonumber(L, -1);
		const char * ret2 = lua_tostring(L, -2);
		printf("ret = [%s is %d.]\n", ret2, ret);
	*/

	/* 4>> lua����c����
		lua_register(L, "c_supply_foo", c_supply_lua_foo);
		luaL_dofile(L, ".\\Resources\\my.lua");

		printf("last = [%d]\n", lua_gettop(L));
	*/
	
	lua_close(L);
	system("PAUSE");

	return 1;
}
