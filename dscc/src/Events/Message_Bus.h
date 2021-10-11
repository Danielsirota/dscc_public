#ifndef MESSAGEBUS_H
#define MESSAGEBUS_H
#include "Event.h"
#include <vector>
#include <functional>
#include <map>

class Message_Bus
{
public:
	Message_Bus(Event &event) : e(event){};
	Event &e;

	/* T is child event to cast to and F is function to send to*/
	template <typename T, typename F>
	void notify(const F &func)
	{
		if (e.GetEventType() == T::GetStaticType())
		{
			func(static_cast<T &>(e));
		}
	}
};
#endif
