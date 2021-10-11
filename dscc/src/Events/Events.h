#ifndef EVENTS_H
#define EVENTS_H
#include "Event.h"
#include "Message_Bus.h"

class windowResizeEvent : public Event
{
public:
	windowResizeEvent(int width, int height)
	{
		x = width;
		y = height;
	};
	int x;
	int y;

	static EventType GetStaticType() { return EventType::window_size; };
	EventType GetEventType() const { return EventType::window_size; };
	const char *GetName() const { return "window_size"; };
};

class windowCloseEvent : public Event
{
public:
	windowCloseEvent() = default;

	static EventType GetStaticType() { return EventType::window_close; };
	EventType GetEventType() const { return EventType::window_close; };
	const char *GetName() const { return "window_close"; };
};

class mouseButtonPressedEvent : public Event
{
public:
	mouseButtonPressedEvent(int button) : button(button) {}

	static EventType GetStaticType() { return EventType::mouse_button_pressed; };
	EventType GetEventType() const { return EventType::mouse_button_pressed; };
	const char *GetName() const { return "mouse_button_pressed"; };
	int button;
};

class mouseScrolledEvent : public Event
{
public:
	mouseScrolledEvent() = default;

	static EventType GetStaticType() { return EventType::mouse_scrolled; };
	EventType GetEventType() const { return EventType::mouse_scrolled; };
	const char *GetName() const { return "mouse_scrolled"; };
};

class mouseMovedEvent : public Event
{
public:
	mouseMovedEvent(int xpos, int ypos) : xpos(xpos), ypos(ypos) {}

	static EventType GetStaticType() { return EventType::mouse_moved; };
	EventType GetEventType() const { return EventType::mouse_moved; };
	const char *GetName() const { return "mouse_moved"; };
	int xpos;
	int ypos;
};

class keyButtonPressedEvent : public Event
{
public:
	keyButtonPressedEvent(int key) : key(key) {}

	static EventType GetStaticType() { return EventType::key_button_pressed; };
	EventType GetEventType() const { return EventType::key_button_pressed; };
	const char *GetName() const { return "key_button_pressed"; };
	int key;
};

class sceneChangedEvent : public Event
{
public:
	sceneChangedEvent() = default;

	static EventType GetStaticType() { return EventType::scene_changed; };
	EventType GetEventType() const { return EventType::scene_changed; };
	const char *GetName() const { return "scene_changed"; };
};
#endif