#include "ScriptingEngine.h"

boost::scoped_ptr<ScriptingEngine> ScriptingEngine::pScriptingEngine(NULL);

ScriptingEngine::ScriptingEngine()
{
	std::cout << "Scripting Constructor" << std::endl;

	lState = lua_open();
	luaL_openlibs(lState);

	luabind::open(lState);
	
	ExposeFunctions();
}


ScriptingEngine::~ScriptingEngine(void)
{
	lua_close(lState);
}

void ScriptingEngine::SetScript(std::string gamefile)
{
	std::cout << "Opening " << gamefile << std::endl;

	if(int error = luaL_dofile(lState, gamefile.c_str()) != 0)
	{
		std::cout << "ERROR " << error << ": Problem opening Lua file " << gamefile << std::endl;
	}
}

void ScriptingEngine::LoadResources()
{
	luabind::call_function<void>(lState, "LoadResources");
}

void ScriptingEngine::Initialise()
{
	luabind::call_function<void>(lState, "Initialise");
}

void ScriptingEngine::Update(float time)
{
	luabind::call_function<void>(lState, "Update", time);
}

boost::scoped_ptr<ScriptingEngine>* ScriptingEngine::GetInstance()
{
	if(pScriptingEngine.get() == NULL)
	{
		pScriptingEngine.reset(new ScriptingEngine);
	}

	return &pScriptingEngine;
}

void ScriptingEngine::ExposeFunctions()
{
	luabind::module(lState)
	[
		luabind::def("SetKey", &ScriptingEngine::DefineKey),
		luabind::def("SetMouse", &ScriptingEngine::DefineMouse),
		luabind::def("GetKey", &ScriptingEngine::GetKey),
		luabind::def("GetMouse", &ScriptingEngine::GetMouse),
		luabind::def("AddAsset", &ScriptingEngine::AddAsset),
		luabind::def("AddGameObject", &ScriptingEngine::AddGameObject),
		luabind::class_<PlayerObject>("PlayerObject")
			.def(luabind::constructor<>())
			.def("Initialise", &PlayerObject::Initialise)
			.def("SetPosition", (void(PlayerObject::*)(float, float, float))&PlayerObject::SetPosition)
			.def("SetPlayerVelocity", &PlayerObject::SetPlayerVelocity)
			.def("SetAsset", &PlayerObject::SetAssetFile),
		luabind::class_<AiObject>("AIObject")
			.def(luabind::constructor<>())
			.def("SetPosition", (void(AiObject::*)(float, float, float))&AiObject::SetPosition)
			.def("ChangePosition", &AiObject::ChangePosition)
			.def("SetAsset", &AiObject::SetAssetFile)
	];
}

void ScriptingEngine::DefineKey(std::string id, int k)
{
	(*Input::GetInstance())->GetKeyboard()->DefineKey(id, k);
}

void ScriptingEngine::DefineMouse(std::string id, int k)
{
	(*Input::GetInstance())->GetMouse()->DefineButton(id, k);
}

bool ScriptingEngine::GetKey(std::string id)
{
	return (*Input::GetInstance())->GetKeyboard()->IsKeyDown(id);
}

bool ScriptingEngine::GetMouse(std::string id)
{
	return (*Input::GetInstance())->GetMouse()->IsButtonDown(id);
}

int ScriptingEngine::GetMouseX()
{
	return (*Input::GetInstance())->GetMouse()->GetMousePosition().x;
}

int ScriptingEngine::GetMouseY()
{
	return (*Input::GetInstance())->GetMouse()->GetMousePosition().y;
}

bool ScriptingEngine::AddAsset(std::string file, std::string type)
{
	return (*AssetManager::GetInstance())->AddAsset(file, type);
}

void ScriptingEngine::AddGameObject(std::string id, GameObject obj)
{
	(*Game::GetInstance())->AddGameObject(id, &obj);
}