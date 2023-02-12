#pragma once

#include <windows.h>
#include <string_view>
#include <unordered_map>

#include <variant>
#include <fstream>

enum features : int32_t
{
	assist_enable,
	assist_smoothness,
	assist_bone,
	assist_max_distance,
	assist_show_fov,
	assist_fov,
	assist_fov_segments,
	assist_hotkey,

	enable_no_recoil,
	enable_no_sway,
	enable_no_stamina,
	enable_night_vision,
	enable_thermal_vision,
	enable_remove_visor,

	visor_intensity,

	recoil_x,
	recoil_y,

	recoil_depth_x,
	recoil_depth_y,

	recoil_random_x,
	recoil_random_y,

	sway_intensity,

	loot_through_walls,
	no_inertia,

	display_max_distance,
	display_item_max_distance,

	display_item_max_price,
	display_item_min_price,

	display_extractions,
	display_items,

	display_corpses,
	display_grenades,

	display_bounding_box,
	display_filled_box,
	display_players_name,
	display_players_type,
	display_corner_box,
	display_head_hitbox,
	display_skeleton,
	display_distance,
	display_health,

	extraction_color,

	item_color,
	expensive_item_color,

	corpse_color,
	grenade_color,

	bounding_box_color,
	filled_box_color,
	corner_box_color,
	player_names_color,
	player_types_color,
	hitbox_color,
	skeleton_color,
	distance_color,
	operator_color,
	health_color,
	fov_color,
};

namespace menu::config
{
	extern std::variant< bool, int, float > config_map[];
}