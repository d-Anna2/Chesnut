#include "cnpch.h"

#include "WindowsWindow.h"

#include "Chestnut/Log.h"

namespace chestnut {
    static bool s_GLFWInitialized = false;

    Window* Window::Create(const WindowProps& props) {
        return new WindowsWindow(props);
    }

    WindowsWindow::WindowsWindow(const WindowProps& props) {
        Init(props);
    }

    WindowsWindow::~WindowsWindow() {
        Shutdown();
    }

    void WindowsWindow::Init(const WindowProps& props) {
        m_data.Title = props.Title;
        m_data.width = props.Width;
        m_data.height = props.Height;

        CN_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (!s_GLFWInitialized) {
            // TODO: glfwTerminate on sys shutdown
            int success = glfwInit();
            CN_CORE_ASSERT(success, "could not initialze GLFW");

            s_GLFWInitialized = true;
        }

        m_window = glfwCreateWindow((int) props.Width, (int) props.Height, m_data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, &m_data);
        SetVSync(true);
    }

    void WindowsWindow::Shutdown() {
        glfwDestroyWindow(m_window);
    }

    void WindowsWindow::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }

    void WindowsWindow::SetVSync(bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }
        m_data.vSync = enabled;
    }

    bool WindowsWindow::IsVSync() const {
        return m_data.vSync;
    }



}
