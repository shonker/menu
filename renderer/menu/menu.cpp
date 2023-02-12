#include "menu.hpp"

#include <array>
#include <functional>

#include "image/image.hpp"
#include "elements/elements.hpp"

#include "../renderer.hpp"
#include "../../dependencies/xorstring/xorstring.hpp"

#include "config/config.hpp"

static auto current_tab = 0;

int lol = 0;

float color[4] = { 1.f, 1.f, 1.f, 1.f };

void Draw_Main( )
{
    ImGui::PushStyleVar( ImGuiStyleVar_ItemSpacing, { 0,0 } );

    auto DrawList = ImGui::GetWindowDrawList( );
    auto Position = ImGui::GetWindowPos( );
    
    ImGui::SetCursorPos( { 20, 10 } );

    ImGui::BeginChild( xs( "Main" ), { 760, 500 }, false, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove );
    {
        switch ( current_tab )
        {
        case 0:
            ImGui::SetCursorPos( { 0, 25 } );

            if ( menu::elements::functions::begin_child( xs( "GENERAL" ), { 205, 430 } ) )
            {
                menu::elements::functions::checkbox(xs("ENABLE AIMBOT"), xs("enables aimbot"), std::get< bool >(menu::config::config_map[features::enable_no_recoil]));
                menu::elements::functions::checkbox(xs("ENABLE SMOOTHING"), xs("enables smoothing"), std::get< bool >(menu::config::config_map[features::enable_no_recoil]));
                menu::elements::functions::checkbox(xs("ENABLE NIGGA BALLS"), xs("enables aimbot"), std::get< bool >(menu::config::config_map[features::enable_no_recoil]));
                menu::elements::functions::checkbox(xs("ENABLE RAT"), xs("enables aimbot"), std::get< bool >(menu::config::config_map[features::enable_no_recoil]));

                menu::elements::functions::slider_int(xs("SLIDER"), &lol, 0, 100, "%i");

                menu::elements::functions::combo("BONE", &std::get< int >(menu::config::config_map[features::assist_bone]), "head\0\rneck\0\rchest\0\0", 4);

                ImGui::Spacing(5);

                menu::elements::functions::checkbox(xs("FOV"), xs("enables aimbot"), std::get< bool >(menu::config::config_map[features::enable_no_recoil]));

                ImGui::ColorEdit4("CUSTOM COLOR", color, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoSidePreview);

                menu::elements::functions::button("BUTTON", ImVec2(185, 22), 0);
            } menu::elements::functions::end_child( );

            ImGui::SetCursorPos( { 220, 25 } );

            if ( menu::elements::functions::begin_child( xs( "CONFIG" ), { 205, 430 } ) )
            {
                menu::elements::functions::checkbox(xs("ENABLE AIMBOT"), xs("enables aimbot"), std::get< bool >(menu::config::config_map[features::enable_no_recoil]));
                menu::elements::functions::checkbox(xs("ENABLE SMOOTHING"), xs("enables smoothing"), std::get< bool >(menu::config::config_map[features::enable_no_recoil]));
                menu::elements::functions::checkbox(xs("ENABLE NIGGA BALLS"), xs("enables aimbot"), std::get< bool >(menu::config::config_map[features::enable_no_recoil]));
                menu::elements::functions::checkbox(xs("ENABLE RAT"), xs("enables aimbot"), std::get< bool >(menu::config::config_map[features::enable_no_recoil]));

                menu::elements::functions::slider_int(xs("SLIDER"), &lol, 0, 100, "%i");

                menu::elements::functions::combo("BONE", &std::get< int >(menu::config::config_map[features::assist_bone]), "head\0\rneck\0\rchest\0\0", 4);

                ImGui::Spacing(5);

                menu::elements::functions::checkbox(xs("FOV"), xs("enables aimbot"), std::get< bool >(menu::config::config_map[features::enable_no_recoil]));

                ImGui::ColorEdit4("CUSTOM COLOR", color, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoSidePreview);

                menu::elements::functions::button("BUTTON", ImVec2(185, 22), 0);
            } menu::elements::functions::end_child( );

            
            break;
        case 1:
            
            ImGui::SetCursorPos( { 500, 25 } );

            if ( menu::elements::functions::begin_child( xs( "PREVIEW" ), { 205, 430 } ) )
            {
                ImGui::GetCurrentWindow( )->DrawList->AddImageRounded( image::d3dx::player_image, Position + ImVec2(475, 60), Position + ImVec2(765, 465), ImVec2(0, 0), ImVec2(1, 1), ImColor(255, 255, 255), 17, 15 );
            } menu::elements::functions::end_child( );

            
            break;
        case 3:
           
            break;
        case 4:
            
            break;
        default:
            break;
        }
    }
    ImGui::EndChild( );

    ImGui::PopStyleVar( );
}

void menu::draw( )
{
    if ( renderer::values::renderer->is_menu_open )
    {
        ImGui::SetNextWindowSize( { 60.5, 500 }, ImGuiCond_Once );

        ImVec2 DashPosition = { 0, 0 };

        ImGui::Begin( xs( "Dashboard" ), nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar );
        {
            auto DrawList = ImGui::GetWindowDrawList( );
            DashPosition = ImGui::GetWindowPos( );
            
            DrawList->AddImageRounded( image::d3dx::intellisense_icon, 
                DashPosition + ImVec2 { 15, 10 },
                DashPosition + ImVec2{ 40, 35 }, ImVec2{ 0, 0 }, ImVec2{ 1, 1 },
                ImColor { 255, 255, 255 }, 0, 15);

            ImGui::SetCursorPos( { 5, 100 } );

            ImGui::BeginGroup( );
            {
                menu::elements::functions::tab( xs( "AIMBOT" ), (const char*)ICON_FA_BULLSEYE_ARROW, current_tab, 0 );

                ImGui::Spacing( );

                menu::elements::functions::tab(xs( "VISUALS" ), (const char*)ICON_FA_EYE, current_tab, 1 );

                ImGui::Spacing( );

                menu::elements::functions::tab( xs( "MISC" ), (const char*)ICON_FA_ARCHIVE, current_tab, 2 );

                ImGui::Spacing( );

                menu::elements::functions::tab( xs( "WEAPON" ), (const char*)ICON_FA_BOW_ARROW, current_tab, 3 );

                ImGui::Spacing( );

                menu::elements::functions::tab( xs( "CFG" ), (const char*)ICON_FA_COGS, current_tab, 4 );

                ImGui::Spacing( 55 );

                menu::elements::functions::tab( xs( "EXIT" ), (const char*)ICON_FA_SIGN_OUT, current_tab, 5 );

                ImGui::Spacing( );
            }
            ImGui::EndGroup( );
        } ImGui::End( );

        ImGui::SetNextWindowSize( { 760, 500 }, ImGuiCond_Once );

        ImGui::Begin( xs( "EscapeFromTarkov" ), nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove );
        {
            ImGui::SetWindowPos( DashPosition + ImVec2 { 65, 0 }, ImGuiCond_Always );
            {
                Draw_Main( );
            }
        }
        ImGui::End( );
    }
    else
    {
        ImGui::Begin( xs( "UnityWndClass" ), nullptr, ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_NoMove );
        { 
            auto DrawList = ImGui::GetWindowDrawList( );

            ImGui::SetWindowSize( { 220, 40 } );

            ImGui::SetWindowPos( { 0, 0 } );

            DrawList->AddText( renderer::values::fonts::druk_wide_bold, 25, { 15, 5 }, ImColor{ 255, 255, 255, 70 }, xs( "loaded" ) );
        }
        ImGui::End( );
    }
}