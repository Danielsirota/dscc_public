#ifndef EVENT_H
#define EVENT_H
#include <string>

enum class EventType
{
	window_size,
	window_close,
	window_resize,
	key_button_pressed,
	mouse_button_pressed,
	mouse_scrolled,
	mouse_moved,
	scene_changed
};

class Event
{
public:
	virtual ~Event(){};

	virtual EventType GetEventType() const = 0;
	virtual const char *GetName() const = 0;
};

#endif
