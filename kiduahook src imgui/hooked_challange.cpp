#include "hooks.h"
#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui/backends/imgui_impl_dx9.h"
#include "imgui/backends/imgui_impl_win32.h"


long __stdcall hooked_reset(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	if (!menu_impressor->d3d())
		return oEndSceneResetFn(pDevice, pPresentationParameters);

	ImGui_ImplDX9_InvalidateDeviceObjects();

	auto hr = oEndSceneResetFn(pDevice, pPresentationParameters);

	if (SUCCEEDED(hr))
		ImGui_ImplDX9_CreateDeviceObjects();

	return hr;
}


long __stdcall hooked_present(IDirect3DDevice9* device, RECT* src_rect, RECT* dest_rect, HWND dest_wnd_override, RGNDATA* dirty_region)
{
	IDirect3DVertexDeclaration9* vertex_dec;
	device->GetVertexDeclaration(&vertex_dec);

	IDirect3DVertexShader9* vertex_shader;
	device->GetVertexShader(&vertex_shader);

	if (!menu_impressor->d3d())
		menu_impressor->init_styles(device);

	if (menu_impressor->d3d())
	{
		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		if (menu_impressor->open())
			menu_impressor->render_menu();


		ImGui::EndFrame();
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
	}

	device->SetVertexShader(vertex_shader);
	device->SetVertexDeclaration(vertex_dec);

	return oPresentFn(device, src_rect, dest_rect, dest_wnd_override, dirty_region);
}