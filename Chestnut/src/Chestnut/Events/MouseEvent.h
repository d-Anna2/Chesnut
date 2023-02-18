#pragma once

#include "Event.h"

namespace chestnut {
    class CHESTNUT_API MouseMovedEvent: public Event {
    public:
        MouseMovedEvent(float x, float y): m_mouseX(x), m_mouseY(y) {}

        inline float GetX() const { return m_mouseX; }
        inline float GetY() const { return m_mouseY; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseMoveEvent: " << m_mouseX << ", " << m_mouseY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_mouseX, m_mouseY;
    };

    class CHESTNUT_API MouseScrolledEvent: public Event {
    public:
        MouseScrolledEvent(float xOffset, float yOffset): m_xOffset(xOffset), m_yOffset(yOffset) {}

        inline float GetXOffset() const { return m_xOffset; }
        inline float GetYOffset() const { return m_yOffset; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_xOffset, m_yOffset;
    };

    class CHESTNUT_API MouseButtonEvent: public Event {
    public:
        inline int GetMouseButton() const { return m_button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    protected:
        MouseButtonEvent(button): m_button(button) {}
        
        int m_button;
    };

    class CHESTNUT_API MouseButtonPressecEvent: public MouseButtonEvent {
    public:
        MouseButtonPressedEvent(int button): MouseButtonEvent(button) {}
        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class CHESTNUT_API MouseButtonReleasedEvent: public MouseButtonEvent {
    public:
        MouseButtonReleasedEvent(int button): MouseButtonEvent(button) {}
        std::string ToString() const override {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
    
}
