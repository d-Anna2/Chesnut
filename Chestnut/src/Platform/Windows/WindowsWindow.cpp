#include "cnpch.h"

#include "WindowsWindow.h"

#include "Chestnut/Log.h"
#include "Chestnut/Events/ApplicationEvent.h"
#include "Chestnut/Events/KeyEvent.h"
#include "Chestnut/Events/MouseEvent.h"

namespace chestnut {
    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int errorCode, const char* description) {
        CN_CORE_ERROR("GLFW_ERROR ({0}): {1}", errorCode, description);
    }

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
            glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWInitialized = true;
        }

        m_window = glfwCreateWindow((int) props.Width, (int) props.Height, m_data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, &m_data);
        SetVSync(true);

        // set GLFW callbacks
        glfwSetWindowSizeCallback(m_window,[](GLFWwindow* window, int width, int height) {
            WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
            data.width = width;
            data.height = height;
            WindowResizeEvent event (width, height);
            data.eventCallback(event);
        });
        glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
            WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.eventCallback(event);
        });
        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
            switch (action) {
                case GLFW_PRESS: {
                    KeyPressedEvent event(key, 0);
                    data.eventCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    KeyReleasedEvent event(key);
                    data.eventCallback(event);
                    break;
                }
                case GLFW_REPEAT: {
                    KeyPressedEvent event(key, 1); // adopt to real value
                    data.eventCallback(event);
                    break;
                }
            }
        });
        glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) {
            WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
            switch (action) {
                case GLFW_PRESS: {
                    MouseButtonPressedEvent event(button);
                    data.eventCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    MouseButtonReleasedEvent event(button);
                    data.eventCallback(event);
                    break;
                }
            }
        });
        glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xoffset, double yoffset) {
            WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
            MouseScrolledEvent event((float) xoffset, (float) yoffset);
            data.eventCallback(event);
        });
        glfwSetCursorPosCallback(m_window, [] (GLFWwindow* window, double xpos, double ypos) {
            WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
            MouseMovedEvent event((float) xpos, (float) ypos);
            data.eventCallback(event);
        });
    }

   
    void WindowsWindow::Shutdown() {
            glfwTerminate();
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
