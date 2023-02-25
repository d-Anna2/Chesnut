#pragma once

#include "Event.h"

namespace chestnut {
    class CHESTNUT_API WindowResizeEvent: public Event {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height): m_width(width), m_height(height) {}

        inline unsigned int GetWidth() const { return m_width; }
        inline unsigned int GetHeight() const { return m_height; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_width << ", " << m_height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    private:
        unsigned int m_width, m_height;
    };

    class CHESTNUT_API WindowCloseEvent: public Event {
    public:
        WindowCloseEvent() {}

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class CHESTNUT_API AppTickEvent: public Event {
        AppTickEvent() {}

        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class CHESTNUT_API AppUpdateEent: public Event {
        AppUpdateEent() {}

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class CHESTNUT_API AppRenderEvent: public Event {
        AppRenderEvent() {}

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}