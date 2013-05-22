#pragma once

#include <set>
#include <string>
#include <boost/scoped_ptr.hpp>
#include "Telegram.h"
#include "stdafx.h"

const double SEND_MSG_IMMEDIATELY = 0.0;
const int NO_ADDITIONAL_INFO = 0;
const int SENDER_ID_IRRELEVENT = -1;

class AIObject;

class MessageDispatcher
{
public:
	void DispatchMessage(double delay, int sender, int receiver, int msg, luabind::object extraInfo);

	void DispatchDelayedMessages();

	static boost::scoped_ptr<MessageDispatcher>* GetInstance();
private:
	std::set<Telegram> PriorityQueue;

	static boost::scoped_ptr<MessageDispatcher> singleton;

	void Discharge(AIObject* pReceiver, const Telegram& msg);
};

