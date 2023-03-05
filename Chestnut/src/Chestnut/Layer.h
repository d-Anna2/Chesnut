// ReSharper disable CppInconsistentNaming
#pragma once

#include "Chestnut/Core.h"
#include "Chestnut/Events/Event.h"

namespace chestnut {
    class CHESTNUT_API Layer {
    public:
        Layer (const std::string& name = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event& event) {}

        inline const std::string GetName() const {return m_debugName; }
    protected:
        std::string m_debugName;
    };
}