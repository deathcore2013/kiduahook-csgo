#pragma once

class shonax_menu
{
	IDirect3DDevice9* g_pd3dDevice;
	bool menu_open;
	bool d3d_init;
public:
	bool open()
	{
		return menu_open;
	}
	bool d3d()
	{
		return d3d_init;
	}
	void set_open(bool _)
	{
		menu_open = _;
	}
	void set_d3d(bool _)
	{
		d3d_init = _;
	}
	void Tabss();
	void init_styles(IDirect3DDevice9* device);
	void render_menu();
};






inline shonax_menu* menu_impressor = new shonax_menu();
