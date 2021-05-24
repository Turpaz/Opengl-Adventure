#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace engine
{
	class Input
	{
	private:
		GLFWwindow* m_window;
		bool lastKeys[348] = { false };
		unsigned int mouseMode = GLFW_CURSOR_NORMAL;
	public:
		Input() {}
		Input(GLFWwindow* window)
			: m_window(window)
		{

		}

		bool pressed(int key)
		{
			return glfwGetKey(m_window, key) == GLFW_PRESS;
		}

		bool released(int key)
		{
			return glfwGetKey(m_window, key) == GLFW_RELEASE;
		}

		bool mouseDown(int button)
		{
			return glfwGetMouseButton(m_window, button) == GLFW_PRESS;
		}

		glm::vec2 mousePosition()
		{
			double xpos, ypos;
			glfwGetCursorPos(m_window, &xpos, &ypos);
			return glm::vec2(xpos, ypos);
		}
		template <typename T> void mousePosition(T& x, T& y)
		{
			glfwGetCursorPos(m_window, &x, &y);
		}

		void setMouseMode(int mode)
		{
			glfwSetInputMode(m_window, GLFW_CURSOR, mode);
			mouseMode = mode;
		}
		unsigned int getMouseMode()
		{
			return mouseMode;
		}

		// TODO: add press (and not hold) callback

		// TODO: add scroll input

		// TODO: add controller input
	};
}

class MouseModes
{
public:
	static const int disabled = GLFW_CURSOR_DISABLED;
	static const int hidden = GLFW_CURSOR_HIDDEN;
	static const int normal = GLFW_CURSOR_NORMAL;
};

class MouseKeys
{
public:
	static const int lmb = GLFW_MOUSE_BUTTON_LEFT;
	static const int leftMouseButton = GLFW_MOUSE_BUTTON_LEFT;
	static const int rmb = GLFW_MOUSE_BUTTON_RIGHT;
	static const int rightMouseButton = GLFW_MOUSE_BUTTON_RIGHT;
	static const int mmb = GLFW_MOUSE_BUTTON_MIDDLE;
	static const int middleMouseButton = GLFW_MOUSE_BUTTON_MIDDLE;

	//static const int lastMouseButton = GLFW_MOUSE_BUTTON_LAST;

	static const int mb1 = GLFW_MOUSE_BUTTON_1;
	static const int mb2 = GLFW_MOUSE_BUTTON_2;
	static const int mb3 = GLFW_MOUSE_BUTTON_3;
	static const int mb4 = GLFW_MOUSE_BUTTON_4;
	static const int mb5 = GLFW_MOUSE_BUTTON_5;
	static const int mb6 = GLFW_MOUSE_BUTTON_6;
	static const int mb7 = GLFW_MOUSE_BUTTON_7;
	static const int mb8 = GLFW_MOUSE_BUTTON_8;
};

class Keys
{
public: // Currently 83 keys
	static const int Tab = GLFW_KEY_TAB;
	static const int Esc = GLFW_KEY_ESCAPE;
	static const int Space = GLFW_KEY_SPACE;
	static const int End = GLFW_KEY_END;
	static const int Home = GLFW_KEY_HOME;
	static const int Enter = GLFW_KEY_ENTER;
	static const int Backspace = GLFW_KEY_BACKSPACE;
	static const int Comma = GLFW_KEY_COMMA;
	static const int Apostrophe = GLFW_KEY_APOSTROPHE;
	static const int Backslah = GLFW_KEY_BACKSLASH;
	static const int CapsLock = GLFW_KEY_CAPS_LOCK;
	static const int Delete = GLFW_KEY_DELETE;
	static const int Equal = GLFW_KEY_EQUAL;
	static const int Insert = GLFW_KEY_INSERT;
	static const int LeftAlt = GLFW_KEY_LEFT_ALT;
	static const int LeftCtrl = GLFW_KEY_LEFT_CONTROL;
	static const int LeftShift = GLFW_KEY_LEFT_SHIFT;
	static const int LeftBracket = GLFW_KEY_LEFT_BRACKET;
	static const int Minus = GLFW_KEY_MINUS;
	static const int Menu = GLFW_KEY_MENU;
	static const int NumLock = GLFW_KEY_NUM_LOCK;
	static const int PageDown = GLFW_KEY_PAGE_DOWN;
	static const int PageUp = GLFW_KEY_PAGE_UP;
	static const int Pause = GLFW_KEY_PAUSE;
	static const int Period = GLFW_KEY_PERIOD;
	static const int PrtSc = GLFW_KEY_PRINT_SCREEN;
	static const int RightAlt = GLFW_KEY_RIGHT_ALT;
	static const int RightCtrl = GLFW_KEY_RIGHT_CONTROL;
	static const int RightShift = GLFW_KEY_RIGHT_SHIFT;
	static const int RightBracket = GLFW_KEY_RIGHT_BRACKET;
	static const int Semicolon = GLFW_KEY_SEMICOLON;
	static const int Slash = GLFW_KEY_SLASH;

	static const int NUM_0 = GLFW_KEY_0;
	static const int NUM_1 = GLFW_KEY_1;
	static const int NUM_2 = GLFW_KEY_2;
	static const int NUM_3 = GLFW_KEY_3;
	static const int NUM_4 = GLFW_KEY_4;
	static const int NUM_5 = GLFW_KEY_5;
	static const int NUM_6 = GLFW_KEY_6;
	static const int NUM_7 = GLFW_KEY_7;
	static const int NUM_8 = GLFW_KEY_8;
	static const int NUM_9 = GLFW_KEY_9;

	static const int A = GLFW_KEY_A;
	static const int B = GLFW_KEY_B;
	static const int C = GLFW_KEY_C;
	static const int D = GLFW_KEY_D;
	static const int E = GLFW_KEY_E;
	static const int F = GLFW_KEY_F;
	static const int G = GLFW_KEY_G;
	static const int H = GLFW_KEY_H;
	static const int I = GLFW_KEY_I;
	static const int J = GLFW_KEY_J;
	static const int K = GLFW_KEY_K;
	static const int L = GLFW_KEY_L;
	static const int M = GLFW_KEY_M;
	static const int N = GLFW_KEY_N;
	static const int O = GLFW_KEY_O;
	static const int P = GLFW_KEY_P;
	static const int Q = GLFW_KEY_Q;
	static const int R = GLFW_KEY_R;
	static const int S = GLFW_KEY_S;
	static const int T = GLFW_KEY_T;
	static const int U = GLFW_KEY_U;
	static const int V = GLFW_KEY_V;
	static const int W = GLFW_KEY_W;
	static const int X = GLFW_KEY_X;
	static const int Y = GLFW_KEY_Y;
	static const int Z = GLFW_KEY_Z;

	static const int Down = GLFW_KEY_DOWN;
	static const int Left = GLFW_KEY_LEFT;
	static const int Up = GLFW_KEY_UP;
	static const int Right = GLFW_KEY_RIGHT;

	static const int F1 = GLFW_KEY_F1;
	static const int F2 = GLFW_KEY_F2;
	static const int F3 = GLFW_KEY_F3;
	static const int F4 = GLFW_KEY_F4;
	static const int F5 = GLFW_KEY_F5;
	static const int F6 = GLFW_KEY_F6;
	static const int F7 = GLFW_KEY_F7;
	static const int F8 = GLFW_KEY_F8;
	static const int F9 = GLFW_KEY_F9;
	static const int F10 = GLFW_KEY_F10;
	static const int F11 = GLFW_KEY_F11;
	static const int F12 = GLFW_KEY_F12;

	// TODO: Numpad keys (KP)
};