#include <Chestnut.h>

class Sandbox: public chestnut::Application {
public:
    Sandbox() = default;
};

chestnut::Application* chestnut::createApplication() {
    return new Sandbox();
}
