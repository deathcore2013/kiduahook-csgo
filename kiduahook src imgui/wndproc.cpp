#include "wndproc.h"
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_win32.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


LRESULT __stdcall HOOKED_WindowProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	if (uMsg == WM_KEYDOWN)
		if (wParam == VK_INSERT)
			menu_impressor->set_open(!menu_impressor->open());

	if (menu_impressor->open())
	{
		ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);

		if (wParam != 'W' && wParam != 'A' && wParam != 'S' && wParam != 'D' && wParam != VK_SHIFT &&
			wParam != VK_CONTROL && wParam != VK_TAB && wParam != VK_SPACE || ImGui::GetIO().WantTextInput)
			return true;
	}
	return CallWindowProc( OldWindowProc, hWnd, uMsg, wParam, lParam );
}
