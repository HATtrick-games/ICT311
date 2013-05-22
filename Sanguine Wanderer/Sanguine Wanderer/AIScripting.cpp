#include "StdAfx.h"
#include "AIScripting.h"

AIScripting::AIScripting(void)
{
	lState = lua_open();

	LoadLuaLibraries();
	RegisterClasses();
}


AIScripting::~AIScripting(void)
{
	lua_close(lState);
	lState = NULL;
}

bool AIScripting::LoadScript(std::string filename)
{
	try 
	{
		luaL_dofile(lState, filename.c_str());
	} 
	catch(luabind::error)
	{
		std::cout << "Error trying to call Lua function." << std::endl;
	}
	catch(const std::exception& theError)
	{
		std::cerr << theError.what() << std::endl;
	}

	return true;
}

void AIScripting::LoadLuaLibraries()
{
	luaL_openlibs(lState);
	luabind::open(lState);
}

void AIScripting::RegisterClasses()
{
	RegisterStateMachine(lState);
	RegisterGameObject(lState);
	RegisterVector2D(lState);
	RegisterMessage(lState);
	RegisterTelegram(lState);
}

void AIScripting::RegisterStateMachine(lua_State* state)
{
	luabind::module(state)
	[
		luabind::class_<StateMachine<AIObject> >("StateMachine")
			.def("ChangeState", &StateMachine<AIObject>::ChangeState)
			.def("SetCurrentState", &StateMachine<AIObject>::SetCurrentState)
			.def("SetPreviousState", &StateMachine<AIObject>::SetPreviousState)
			.def("SetGlobalState", &StateMachine<AIObject>::SetGlobalState)
			.def("GetCurrentState", &StateMachine<AIObject>::GetCurrentState)
			.def("GetPreviousState", &StateMachine<AIObject>::GetPreviousState)
			.def("GetGlobalState", &StateMachine<AIObject>::GetGlobalState)
			.def("RevertToPreviousState", &StateMachine<AIObject>::RevertToPreviousState)
	];
}

void AIScripting::RegisterGameObject(lua_State* state)
{
	luabind::module(state)
	[
		luabind::class_<AIObject>("AIObject")
			.def("GetPlayerID", &AIObject::GetID)
			.def("GetFSM", &AIObject::GetFSM)
			.def("SetPlayerID", &AIObject::SetID)
			.def("SetPosition", &AIObject::SetPosition)
			.def("SetVelocity", &AIObject::SetVelocity)
			.def("SendMessage", &AIObject::SendMessage)
			.def("PursueTarget", &AIObject::PursueTarget)
			.def("FleeTarget", &AIObject::FleeTarget)
			.def("EvadeTarget", &AIObject::EvadeTarget)
			.def("Wander", &AIObject::Wander)
			.def("CanViewTarget", &AIObject::CanViewTarget)
			.def("DistanceToTarget", &AIObject::DistanceFromTarget)
	];
}

void AIScripting::RegisterVector2D(lua_State* state)
{
	luabind::module(state)
	[
		luabind::class_<Vector2D>("Vector2D")
			.def(luabind::constructor<>())
			.def("Set", &Vector2D::Set)
			.def("GetX", &Vector2D::GetX)
			.def("GetY", &Vector2D::GetY)
	];
}

void AIScripting::RegisterMessage(lua_State* state)
{
	luabind::module(state)
	[
		luabind::class_<MessageDispatcher>("MessageDispatcher")
			.def("DispatchMessage", &MessageDispatcher::DispatchMessage)		
	];
}

void AIScripting::RegisterTelegram(lua_State* state)
{
	luabind::module(state)
	[
		luabind::class_<Telegram>("Telegram")
			.def_readwrite("sender", &Telegram::sender)
			.def_readwrite("receiver", &Telegram::receiver)
			.def_readwrite("message", &Telegram::message)
			.def_readwrite("dispatchTime", &Telegram::dispatchTime)
			.def_readwrite("extraInfo", &Telegram::ExtraInfo)
	];
}