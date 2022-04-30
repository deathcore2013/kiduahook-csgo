#include "../hooks.h"
#include "../imgui/imgui.h"



#include "../trashconstr/rage.h"
#include "../trashconstr/aa.h"
#include "../trashconstr/legit.h"
#include "../trashconstr/players.h"
#include "../trashconstr/weapons.h"
#include "../trashconstr/grenades.h"
#include "../trashconstr/world.h"
#include "../trashconstr/view.h"
#include "../trashconstr/main.h"
#include "../trashconstr/inventory.h"
#include "../trashconstr/scripts.h"
#include "../trashconstr/configs.h"
#include "../trashconstr/soufiw.h"
#include "../imgui/backends/imgui_impl_win32.h"
#include "../imgui/backends/imgui_impl_dx9.h"




ImFont* tolstiy = nullptr;
ImFont* ne_takoi_tolstiy = nullptr;
ImFont* ne_takoi_tolstiy2 = nullptr;
IDirect3DTexture9* r = nullptr;
IDirect3DTexture9* a = nullptr;
IDirect3DTexture9* l = nullptr;
IDirect3DTexture9* p = nullptr;
IDirect3DTexture9* w = nullptr;
IDirect3DTexture9* g = nullptr;
IDirect3DTexture9* wo = nullptr;
IDirect3DTexture9* v = nullptr;
IDirect3DTexture9* m = nullptr;
IDirect3DTexture9* i = nullptr;
IDirect3DTexture9* s = nullptr;
IDirect3DTexture9* c = nullptr;
IDirect3DTexture9* soufiww = nullptr;

float animspeed;
bool customize;


static int tabs = 0;

void shonax_menu::Tabss()
{
    if (r == nullptr)
        D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, &rage, sizeof(rage), 15, 15, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &r);
    if (a == nullptr)
        D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, &antiaim, sizeof(antiaim), 15, 15, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &a);
    if (l == nullptr)
        D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, &legit, sizeof(legit), 13, 15, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &l);
    if (p == nullptr)
        D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, &players, sizeof(players), 15, 15, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &p);
    if (w == nullptr)
        D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, &weapons, sizeof(weapons), 15, 13, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &w);
    if (g == nullptr)
        D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, &grenades, sizeof(grenades), 15, 13, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &g);
    if (wo == nullptr)
        D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, &world, sizeof(world), 15, 15, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &wo);
    if (r == nullptr)
        D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, &rage, sizeof(rage), 15, 15, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &r);
    if (v == nullptr)
        D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, &view, sizeof(view), 15, 15, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &v);
    if (m == nullptr)
        D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, &mmain, sizeof(mmain), 15, 15, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &m);
    if (i == nullptr)
        D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, &inventory, sizeof(inventory), 15, 15, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &i);
    if (s == nullptr)
        D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, &scripts, sizeof(scripts), 15, 15, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &s);
    if (c == nullptr)
        D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, &configs, sizeof(configs), 15, 15, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &c);

    ImVec2 pos;
    ImDrawList* draw;

    pos = ImGui::GetWindowPos();
    draw = ImGui::GetWindowDrawList();

    ImVec4* colors = ImGui::GetStyle().Colors;
    colors[ImGuiCol_Button] = ImColor(35, 35, 45, 0);
    colors[ImGuiCol_ButtonActive] = ImColor(63, 63, 60, 255);
    colors[ImGuiCol_ButtonHovered] = ImColor(63, 63, 60, 255);
    ImGui::PushFont(ne_takoi_tolstiy);
    ImGui::SetCursorPos(ImVec2(12, 94));
    if (ImGui::Button("##rage", ImVec2(172, 31)))
        tabs = 0;
    ImGui::SetCursorPos(ImVec2(12, 130));
    if (ImGui::Button("##aa", ImVec2(172, 31)))
        tabs = 1;
    ImGui::SetCursorPos(ImVec2(12, 166));
    if (ImGui::Button("##legit", ImVec2(172, 31)))
        tabs = 2;
    ImGui::SetCursorPos(ImVec2(12, 234));
    if (ImGui::Button("##players", ImVec2(172, 31)))
        tabs = 3;
    ImGui::SetCursorPos(ImVec2(12, 270));
    if (ImGui::Button("##weapon", ImVec2(172, 31)))
        tabs = 4;
    ImGui::SetCursorPos(ImVec2(12, 306));
    if (ImGui::Button("##grenades", ImVec2(172, 31)))
        tabs = 5;
    ImGui::SetCursorPos(ImVec2(12, 342));
    if (ImGui::Button("##world", ImVec2(172, 31)))
        tabs = 6;
    ImGui::SetCursorPos(ImVec2(12, 378));
    if (ImGui::Button("##view", ImVec2(172, 31)))
        tabs = 7;
    ImGui::SetCursorPos(ImVec2(12, 433));
    if (ImGui::Button("##main", ImVec2(172, 31)))
        tabs = 8;
    ImGui::SetCursorPos(ImVec2(12, 469));
    if (ImGui::Button("##inventory", ImVec2(172, 31)))
        tabs = 9;
    ImGui::SetCursorPos(ImVec2(12, 505));
    if (ImGui::Button("##scripts", ImVec2(172, 31)))
        tabs = 10;
    ImGui::SetCursorPos(ImVec2(12, 541));
    if (ImGui::Button("##config", ImVec2(172, 31)))
        tabs = 11;

    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 101), ImColor(255, 255, 255), "Ragebot");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 137), ImColor(255, 255, 255), "Anti Aim");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 173), ImColor(255, 255, 255), "Legitbot");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 241), ImColor(255, 255, 255), "Players");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 277), ImColor(255, 255, 255), "Weapon");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 313), ImColor(255, 255, 255), "Grenades");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 349), ImColor(255, 255, 255), "World");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 385), ImColor(255, 255, 255), "View");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 440), ImColor(255, 255, 255), "Main");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 476), ImColor(255, 255, 255), "Inventory");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 512), ImColor(255, 255, 255), "Scripts");
    draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 51, pos.y + 548), ImColor(255, 255, 255), "Configs");

    ImGui::SetCursorPos(ImVec2(25, 102));
    ImGui::Image(r, ImVec2(15, 15));

    ImGui::SetCursorPos(ImVec2(25, 138));
    ImGui::Image(a, ImVec2(15, 15));

    ImGui::SetCursorPos(ImVec2(25, 174));
    ImGui::Image(l, ImVec2(13, 15));

    ImGui::SetCursorPos(ImVec2(25, 242));
    ImGui::Image(p, ImVec2(15, 15));

    ImGui::SetCursorPos(ImVec2(25, 278));
    ImGui::Image(w, ImVec2(15, 13));

    ImGui::SetCursorPos(ImVec2(25, 314));
    ImGui::Image(g, ImVec2(15, 13));

    ImGui::SetCursorPos(ImVec2(25, 350));
    ImGui::Image(wo, ImVec2(15, 15));

    ImGui::SetCursorPos(ImVec2(25, 386));
    ImGui::Image(v, ImVec2(15, 15));

    ImGui::SetCursorPos(ImVec2(25, 441));
    ImGui::Image(m, ImVec2(15, 15));

    ImGui::SetCursorPos(ImVec2(25, 477));
    ImGui::Image(i, ImVec2(15, 15));

    ImGui::SetCursorPos(ImVec2(25, 513));
    ImGui::Image(s, ImVec2(15, 15));

    ImGui::SetCursorPos(ImVec2(25, 549));
    ImGui::Image(c, ImVec2(15, 15));

    ImGui::PopFont();
}

void shonax_menu::init_styles(IDirect3DDevice9* device)
{
	ImGui::CreateContext();
	//ImGui::GetStyle()

    ImGui_ImplWin32_Init(hwndWindow);
    ImGui_ImplDX9_Init(device);




    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGuiStyle* style = &ImGui::GetStyle();
    ImGui::StyleColorsDark();

    style->Alpha = 1.f;
    style->WindowRounding = 1.f;
    style->FramePadding = ImVec2(4, 3);
    style->WindowPadding = ImVec2(8, 8);
    style->ItemInnerSpacing = ImVec2(4, 4);
    style->ItemSpacing = ImVec2(8, 4);
    style->FrameRounding = 5.f;
    style->ScrollbarSize = 2.f;
    style->ScrollbarRounding = 12.f;


    ImVec4* colors = ImGui::GetStyle().Colors;
    colors[ImGuiCol_ChildBg] = ImColor(24, 29, 59, 0);
    colors[ImGuiCol_Border] = ImVec4(0.07f, 0.07f, 0.11f, 0.50f);
    colors[ImGuiCol_FrameBg] = ImColor(25, 25, 33, 255);
    colors[ImGuiCol_FrameBgActive] = ImColor(25, 25, 33, 255);
    colors[ImGuiCol_FrameBgHovered] = ImColor(25, 25, 33, 255);
    colors[ImGuiCol_Header] = ImColor(25, 25, 33, 255);
    colors[ImGuiCol_HeaderActive] = ImColor(28, 28, 36, 255);
    colors[ImGuiCol_HeaderHovered] = ImColor(30, 30, 38, 255);
    colors[ImGuiCol_PopupBg] = ImColor(35, 35, 45, 255);
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    //ImGui::StyleColorsClassic();
    tolstiy = io.Fonts->AddFontFromFileTTF("C:/windows/fonts/ariblk.ttf", 40.0f);
    ne_takoi_tolstiy = io.Fonts->AddFontFromFileTTF("C:/windows/fonts/arialbd.ttf", 13.0f);
    ne_takoi_tolstiy2 = io.Fonts->AddFontFromFileTTF("C:/windows/fonts/arialbd.ttf", 15.0f);

    g_pd3dDevice = device;
    set_d3d(true);
}

void shonax_menu::render_menu()
{
    ImVec2 pos;
    ImDrawList* draw;
    if (soufiww == nullptr)
        D3DXCreateTextureFromFileInMemoryEx(g_pd3dDevice, &soufiw, sizeof(soufiw), 100, 100, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &soufiww);

    {
        ImGui::Begin("JUUUUU", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoTitleBar);
        {
            pos = ImGui::GetWindowPos();
            draw = ImGui::GetWindowDrawList();

            ImGui::SetWindowSize(ImVec2(810, 675));

            //1
            draw->AddRectFilled(ImVec2(pos.x + 190, pos.y + 0), ImVec2(pos.x + 807, pos.y + 657), ImColor(8, 8, 8), 8.f, 10);
            //

            //2
            draw->AddRectFilled(ImVec2(pos.x + 0, pos.y + 0), ImVec2(pos.x + 197, pos.y + 657), ImColor(8, 8, 8, 230), 10.f, 5);
            //

            //�������
            draw->AddText(tolstiy, 35.f, ImVec2(pos.x + 16, pos.y + 26), ImColor(65, 186, 217), "NEVERPIVO");
            draw->AddText(tolstiy, 35.f, ImVec2(pos.x + 17, pos.y + 26), ImColor(255, 255, 255), "NEVERPIVO");
            //

            //����� �� ��������
            draw->AddLine(ImVec2(pos.x + 0, pos.y + 593), ImVec2(pos.x + 190, pos.y + 594), ImColor(32, 32, 30));
            draw->AddLine(ImVec2(pos.x + 190, pos.y + 70), ImVec2(pos.x + 807, pos.y + 71), ImColor(32, 32, 30));
            //

            //������
            draw->AddText(ne_takoi_tolstiy, 13.f, ImVec2(pos.x + 21, pos.y + 74), ImColor(55, 55, 55), "Aimbot");
            draw->AddText(ne_takoi_tolstiy, 13.f, ImVec2(pos.x + 21, pos.y + 214), ImColor(55, 55, 55), "Visuals");
            draw->AddText(ne_takoi_tolstiy, 13.f, ImVec2(pos.x + 21, pos.y + 412), ImColor(55, 55, 55), "Miscellaneous");
            //

            //����
            Tabss();
            //

            //���������
            ImGui::SetCursorPos(ImVec2(100, 100));
            draw->AddCircleImageFilled(soufiww, ImVec2(pos.x + 39, pos.y + 626), 23.f, ImColor(255, 255, 255), 360);
            draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 70, pos.y + 606), ImColor(255, 255, 255), "Putin");
            draw->AddText(ne_takoi_tolstiy, 13.f, ImVec2(pos.x + 70, pos.y + 630), ImColor(55, 55, 55), "Till:");
            draw->AddText(ne_takoi_tolstiy, 13.f, ImVec2(pos.x + 95, pos.y + 630), ImColor(22, 162, 240), "01.01.2100");
            //

            //��
            ImGui::PushFont(ne_takoi_tolstiy);
            static bool te, te1;
            static int shonax_int;
            static float shonax_slider;
            if (tabs == 0)
            {
            }

            if (tabs == 1)
            {
            }

            if (tabs == 2)
            {
            }

            if (tabs == 3)
            {
                //ESP
                ImGui::BeginGroup();
                draw->AddRectFilled(ImVec2(pos.x + 210, pos.y + 90), ImVec2(pos.x + 490, pos.y + 450), ImColor(13, 11, 16));
                draw->AddLine(ImVec2(pos.x + 210, pos.y + 120), ImVec2(pos.x + 490, pos.y + 121), ImColor(32, 32, 30));
                draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 218, pos.y + 98), ImColor(255, 255, 255), "ESP");

                ImGui::SetCursorPos(ImVec2(230, 130 + 20 * 0));
                ImGui::Checkbox("test", &te);
                ImGui::SetCursorPos(ImVec2(230, 130 + 20 * 1));
                ImGui::SliderFloat("fuck me", &shonax_slider, 0, 100, "0.2f");
                ImGui::SetCursorPos(ImVec2(230, 130 + 20 * 2));
                ImGui::Combo("test again", &shonax_int, "Russian\0\English\0\0", 2);

                ImGui::EndGroup();
                //

                //CHAMS
                ImGui::BeginGroup();
                draw->AddRectFilled(ImVec2(pos.x + 506, pos.y + 90), ImVec2(pos.x + 786, pos.y + 450), ImColor(13, 11, 16));
                draw->AddLine(ImVec2(pos.x + 506, pos.y + 120), ImVec2(pos.x + 786, pos.y + 121), ImColor(32, 32, 30));
                draw->AddText(ne_takoi_tolstiy, 15.f, ImVec2(pos.x + 516, pos.y + 98), ImColor(255, 255, 255), "Chams");

                ImGui::SetCursorPos(ImVec2(527, 130));
                ImGui::Checkbox("test1", &te1);


                ImGui::EndGroup();
                //
            }

            if (tabs == 4)
            {
            }

            if (tabs == 5)
            {
            }

            if (tabs == 6)
            {
            }

            if (tabs == 7)
            {
            }

            if (tabs == 8)
            {
            }

            if (tabs == 9)
            {
            }

            if (tabs == 10)
            {
            }

            if (tabs == 11)
            {
            }
            ImGui::PopFont();
            //
            ImGui::End();
        }
    }
}
