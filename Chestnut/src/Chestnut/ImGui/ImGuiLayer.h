#pragma once
#include "Chestnut/Layer.h"

namespace chestnut {
    class CHESTNUT_API ImGuiLayer: public Layer{
public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnUpdate() override;
        void OnEvent(Event& event);
        void OnAttach() override;
        void OnDetach() override;
    private:
        float m_time = 0.0f;
};
}
