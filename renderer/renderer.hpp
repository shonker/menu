#pragma once

#define IMGUI_DEFINE_MATH_OPERATORS

#include <wrl.h>
#include <wrl/client.h>

#include <d3d11.h>
#include <d3dcompiler.h>

#include <dcomp.h>

#include <dxgi.h>
#include <dxgi1_2.h>
#include <dxgi1_3.h>

#include <windows.h>

#include <memory>
#include <atomic>

#include <string_view>

#include <functional>

#include <dwmapi.h>
#pragma comment ( lib, "dwmapi" )

#include "../dependencies/imgui/imgui.h"
#include "../dependencies/imgui/imgui_impl_dx11.h"
#include "../dependencies/imgui/imgui_impl_win32.h"
#include "../dependencies/imgui/imgui_internal.h"

#include "../dependencies/font/hashes.h"
#include "../dependencies/font/sffont.hpp"
#include "../dependencies/font/poppins.hpp"
#include "../dependencies/font/faprolight.hpp"
#include "../dependencies/font/drukwidebold.hpp"

#include "../dependencies/font/cynthe.hpp"

#include "../dependencies/xorstring/xorstring.hpp"

#pragma comment(  lib, "dxgi"  )
#pragma comment(  lib, "dcomp"  )

#pragma comment( lib, "d3d11.lib" )

#pragma comment( lib, "comctl32.lib" )

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );

namespace renderer::structures
{
	struct renderer_t
	{
		HWND overlay_window, game_window;

		RECT overlay_rect{ 0 }; RECT game_rect{ 0 };

		const float alpha_channel[4] = { 0.f, 0.f, 0.f, 0.f };

		bool is_menu_open = false; bool is_watermark_shown = true;

		void release_render_target( );

		void create_render_target( );

		void initialize_imgui( );

		void initialize_device( );

		void render( );

		renderer_t( HWND game_window );
	};
}

namespace renderer::values
{
	extern std::unique_ptr< renderer::structures::renderer_t > renderer;

	extern std::atomic< bool > insert_hit;

	namespace fonts
	{
		inline ImFont* pro_font_windows;
		inline ImFont* druk_wide_bold;
		inline ImFont* px18;
		inline ImFont* px24;
	}

	extern void set_styles( void* );
}

namespace renderer
{
	void start( std::string_view window_name );

	LRESULT __stdcall wndproc( HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam );
}