#pragma once

#include "stdafx.h"

struct Telegram
{
	int sender;

	int receiver;

	int message;

	double dispatchTime;

	luabind::object ExtraInfo;

	Telegram(void): dispatchTime(-1), sender(-1), receiver(-1), message(-1)
	{
		ExtraInfo = luabind::object();
	}
	
	Telegram(double time, int sender, int receiver, int msg, luabind::object extra)
	{
		dispatchTime = time;
		this->sender = sender;
		this->receiver = receiver;
		this->message = msg;
		this->ExtraInfo = extra;
	}
};

const double minDelay = 0.25;

inline bool operator==(const Telegram& t1, const Telegram& t2)
{
	return (fabs(t1.dispatchTime - t2.dispatchTime) < minDelay) &&
		(t1.sender == t2.sender) &&
		(t1.receiver == t2.receiver) &&
		(t1.message == t2.message);
}

inline bool operator<(const Telegram& t1, const Telegram& t2)
{
	if(t1 == t2)
	{
		return false;
	}
	else
	{
		return (t1.dispatchTime < t2.dispatchTime);
	}
}

inline std::ostream& operator<<(std::ostream& os, const Telegram& t)
{
	os << "time: " << t.dispatchTime << " Sender: " << t.sender <<
		" Receiver: " << t.receiver << " Msg: " << t.message;
	return os;
}

