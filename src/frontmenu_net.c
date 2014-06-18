/******************************************************************************/
// Free implementation of Bullfrog's Dungeon Keeper strategy game.
/******************************************************************************/
/** @file frontmenu_net.c
 *     GUI menus for network support.
 * @par Purpose:
 *     Functions to show and maintain network screens.
 * @par Comment:
 *     None.
 * @author   KeeperFX Team
 * @date     05 Jan 2009 - 09 Oct 2010
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/
#include "frontmenu_net.h"
#include "globals.h"
#include "bflib_basics.h"

#include "bflib_datetm.h"
#include "bflib_guibtns.h"
#include "bflib_netsp.hpp"
#include "bflib_video.h"
#include "bflib_vidraw.h"
#include "bflib_sprite.h"
#include "bflib_sprfnt.h"

#include "front_network.h"
#include "gui_frontbtns.h"
#include "frontend.h"
#include "front_landview.h"
#include "net_game.h"
#include "kjm_input.h"
#include "game_merge.h"
#include "game_legacy.h"
#include "keeperfx.hpp"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************/
DLLIMPORT void _DK_frontnet_start_input(void);
DLLIMPORT void _DK_frontnet_serial_reset(void);
DLLIMPORT void _DK_frontnet_modem_reset(void);
DLLIMPORT void _DK_frontnet_draw_services_scroll_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_service_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_service_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_service_up_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_service_down_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_service_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_service_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_service_select(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_session_set_player_name(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_text_bar(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_session_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_session_up_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_session_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_session_down_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_session_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_sessions_scroll_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_session_selected(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_session_select(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_session_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_players_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_players_up_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_players_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_players_down_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_players_scroll_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_net_session_players(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_session_join(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_session_create(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_return_to_main_menu(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_join_game_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_alliance_box_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_net_start_players(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_select_alliance(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_alliance_grid(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_alliance_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_maintain_alliance(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_messages_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_messages_up_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_messages_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_messages_down_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_bottom_scroll_box_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_messages_scroll_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_current_message(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_messages(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_start_game_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_return_to_session_menu(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_small_scroll_box_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_small_scroll_box(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_comport_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_comport_up_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_comport_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_comport_down_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_comport_scroll_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_comport_selected(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_comport_select(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_comport_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_comport_select_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_speed_up(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_speed_up_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_speed_down(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_speed_down_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_speed_scroll_tab(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_speed_selected(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_speed_select(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_speed_button(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_speed_select_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_draw_text_cont_bar(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_net_set_modem_init(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_net_set_modem_hangup(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_net_set_modem_dial(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_net_set_phone_number(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_net_modem_start(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_net_modem_start_maintain(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_net_set_modem_answer(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_net_serial_start(struct GuiButton *gbtn);
DLLIMPORT void _DK_frontnet_net_serial_start_maintain(struct GuiButton *gbtn);
/******************************************************************************/
struct GuiButtonInit frontend_net_service_buttons[] = {
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0, 999,  30, 999,  30,371, 46, frontend_draw_large_menu_button,   0, 201,  0,      {10},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  82, 124,  82, 124,220, 26, frontnet_draw_scroll_box_tab,      0, 201,  0,      {12},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  82, 150,  82, 150,450,180, frontnet_draw_scroll_box,          0, 201,  0,      {26},            0, 0, NULL },
  { 1,  0, 0, 0, frontnet_service_up,NULL,frontend_over_button,       0, 532, 149, 532, 149, 26, 14, frontnet_draw_slider_button,       0, 201,  0,      {17},            0, 0, frontnet_service_up_maintain },
  { 1,  0, 0, 0, frontnet_service_down,NULL,frontend_over_button,     0, 532, 317, 532, 317, 26, 14, frontnet_draw_slider_button,       0, 201,  0,      {18},            0, 0, frontnet_service_down_maintain },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0, 536, 163, 536, 163, 10,154, frontnet_draw_services_scroll_tab, 0, 201,  0,      {40},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0, 102, 125, 102, 125,220, 26, frontend_draw_text,                0, 201,  0,      {33},            0, 0, NULL },
  { 0,  0, 0, 0, frontnet_service_select,NULL,frontend_over_button,   0,  95, 158,  95, 158,424, 26, frontnet_draw_service_button,      0, 201,  0,      {45},            0, 0, frontnet_service_maintain },
  { 0,  0, 0, 0, frontnet_service_select,NULL,frontend_over_button,   0,  95, 184,  95, 184,424, 26, frontnet_draw_service_button,      0, 201,  0,      {46},            0, 0, frontnet_service_maintain },
  { 0,  0, 0, 0, frontnet_service_select,NULL,frontend_over_button,   0,  95, 210,  95, 210,424, 26, frontnet_draw_service_button,      0, 201,  0,      {47},            0, 0, frontnet_service_maintain },
  { 0,  0, 0, 0, frontnet_service_select,NULL,frontend_over_button,   0,  95, 236,  95, 236,424, 26, frontnet_draw_service_button,      0, 201,  0,      {48},            0, 0, frontnet_service_maintain },
  { 0,  0, 0, 0, frontnet_service_select,NULL,frontend_over_button,   0,  95, 262,  95, 262,424, 26, frontnet_draw_service_button,      0, 201,  0,      {49},            0, 0, frontnet_service_maintain },
  { 0,  0, 0, 0, frontnet_service_select,NULL,frontend_over_button,   0,  95, 288,  95, 288,424, 26, frontnet_draw_service_button,      0, 201,  0,      {50},            0, 0, frontnet_service_maintain },
  { 0,  0, 0, 0, frontend_change_state,NULL,frontend_over_button,     1, 999, 404, 999, 404,371, 46, frontend_draw_large_menu_button,   0, 201,  0,       {6},            0, 0, NULL },
  {-1,  0, 0, 0, NULL,               NULL,        NULL,               0,   0,   0,   0,   0,  0,  0, NULL,                              0,   0,  0,       {0},            0, 0, NULL },
};

struct GuiButtonInit frontend_net_session_buttons[] = {
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0, 999,  12, 999,  12,371, 46, frontend_draw_large_menu_button,   0, 201,  0,      {12},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  82,  61,  82,  61,165, 29, frontnet_draw_text_bar,            0, 201,  0,      {27},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  95,  63,  91,  63,165, 25, frontend_draw_text,                0, 201,  0,      {19},            0, 0, NULL },
  { 5, -1,-1, 0, frontnet_session_set_player_name,NULL,frontend_over_button,19,200,63,95,63,432, 25, frontend_draw_enter_text,          0, 201,  0,{(long)tmp_net_player_name}, 20, 0, NULL },
  { 0,  0, 0, 0, frontnet_session_add,NULL,      frontend_over_button,0, 321,  93, 321,  93,247, 46, frontend_draw_small_menu_button,   0, 201,  0,     {110},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  82, 112,  82, 112,220, 26, frontnet_draw_scroll_box_tab,      0, 201,  0,      {28},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  82, 138,  82, 138,450,180, frontnet_draw_scroll_box,          0, 201,  0,      {25},            0, 0, NULL },
  { 1,  0, 0, 0, frontnet_session_up,NULL,       frontend_over_button,0, 532, 137, 532, 137, 26, 14, frontnet_draw_slider_button,       0, 201,  0,      {17},            0, 0, frontnet_session_up_maintain },
  { 1,  0, 0, 0, frontnet_session_down,NULL,     frontend_over_button,0, 532, 217, 532, 217, 26, 14, frontnet_draw_slider_button,       0, 201,  0,      {18},            0, 0, frontnet_session_down_maintain },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0, 536, 151, 536, 151, 10, 66, frontnet_draw_sessions_scroll_tab, 0, 201,  0,      {40},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0, 102, 113, 102, 113,220, 26, frontend_draw_text,                0, 201,  0,      {29},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  82, 230,  82, 230,450, 23, frontnet_draw_session_selected,    0, 201,  0,      {35},            0, 0, NULL },
  { 0,  0, 0, 0, frontnet_session_select,NULL,   frontend_over_button,0,  95, 141,  95, 141,424, 26, frontnet_draw_session_button,      0, 201,  0,      {45},            0, 0, frontnet_session_maintain },
  { 0,  0, 0, 0, frontnet_session_select,NULL,   frontend_over_button,0,  95, 167,  95, 167,424, 26, frontnet_draw_session_button,      0, 201,  0,      {46},            0, 0, frontnet_session_maintain },
  { 0,  0, 0, 0, frontnet_session_select,NULL,   frontend_over_button,0,  95, 193,  95, 193,424, 26, frontnet_draw_session_button,      0, 201,  0,      {47},            0, 0, frontnet_session_maintain },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  82, 261,  82, 261,220, 26, frontnet_draw_scroll_box_tab,      0, 201,  0,      {28},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  82, 287,  82, 287,450, 74, frontnet_draw_scroll_box,          0, 201,  0,      {24},            0, 0, NULL },
  { 1,  0, 0, 0, frontnet_players_up,NULL,       frontend_over_button,0, 532, 286, 532, 286, 26, 14, frontnet_draw_slider_button,       0, 201,  0,      {36},            0, 0, frontnet_players_up_maintain },
  { 1,  0, 0, 0, frontnet_players_down,NULL,     frontend_over_button,0, 532, 344, 532, 344, 26, 14, frontnet_draw_slider_button,       0, 201,  0,      {37},            0, 0, frontnet_players_down_maintain },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0, 536, 300, 536, 300, 10, 44, frontnet_draw_players_scroll_tab,  0, 201,  0,      {40},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  95, 262,  95, 262,220, 22, frontend_draw_text,                0, 201,  0,      {31},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  95, 291,  82, 291,450, 52, frontnet_draw_net_session_players, 0, 201,  0,      {21},            0, 0, NULL },
  { 0,  0, 0, 0, frontnet_session_join,NULL,     frontend_over_button,0,  72, 360,  72, 360,247, 46, frontend_draw_small_menu_button,   0, 201,  0,      {13},            0, 0, frontnet_join_game_maintain },
  { 0,  0, 0, 0, frontnet_session_create,NULL,   frontend_over_button,0, 321, 360, 321, 360,247, 46, frontend_draw_small_menu_button,   0, 201,  0,      {14},            0, 0, NULL },
  { 0,  0, 0, 0, frontnet_return_to_main_menu,NULL,frontend_over_button,0,999,404, 999, 404,371, 46, frontend_draw_large_menu_button,   0, 201,  0,       {6},            0, 0, NULL },
  {-1,  0, 0, 0, NULL,               NULL,        NULL,               0,   0,   0,   0,   0,  0,  0, NULL,                              0,   0,  0,       {0},            0, 0, NULL },
};

/*struct GuiButtonInit frontend_net_session_buttons[] = {
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0, 999,  30, 999,  30,371, 46, frontend_draw_large_menu_button,   0, 201,  0,      {12},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  82,  79,  82,  79,165, 29, frontnet_draw_text_bar,            0, 201,  0,      {27},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  95,  81,  91,  81,165, 25, frontend_draw_text,                0, 201,  0,      {19},            0, 0, NULL },
  { 5, -1,-1, 0, frontnet_session_set_player_name,NULL,frontend_over_button,19,200,81,95,81,432, 25, frontend_draw_enter_text,          0, 201,  0,{(long)tmp_net_player_name}, 20, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  82, 112,  82, 112,220, 26, frontnet_draw_scroll_box_tab,      0, 201,  0,      {28},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  82, 138,  82, 138,450,180, frontnet_draw_scroll_box,          0, 201,  0,      {25},            0, 0, NULL },
  { 1,  0, 0, 0, frontnet_session_up,NULL,       frontend_over_button,0, 532, 137, 532, 137, 26, 14, frontnet_draw_slider_button,       0, 201,  0,      {17},            0, 0, frontnet_session_up_maintain },
  { 1,  0, 0, 0, frontnet_session_down,NULL,     frontend_over_button,0, 532, 217, 532, 217, 26, 14, frontnet_draw_slider_button,       0, 201,  0,      {18},            0, 0, frontnet_session_down_maintain },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0, 536, 151, 536, 151, 10, 66, frontnet_draw_sessions_scroll_tab, 0, 201,  0,      {40},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0, 102, 113, 102, 113,220, 26, frontend_draw_text,                0, 201,  0,      {29},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  82, 230,  82, 230,450, 23, frontnet_draw_session_selected,    0, 201,  0,      {35},            0, 0, NULL },
  { 0,  0, 0, 0, frontnet_session_select,NULL,   frontend_over_button,0,  95, 141,  95, 141,424, 26, frontnet_draw_session_button,      0, 201,  0,      {45},            0, 0, frontnet_session_maintain },
  { 0,  0, 0, 0, frontnet_session_select,NULL,   frontend_over_button,0,  95, 167,  95, 167,424, 26, frontnet_draw_session_button,      0, 201,  0,      {46},            0, 0, frontnet_session_maintain },
  { 0,  0, 0, 0, frontnet_session_select,NULL,   frontend_over_button,0,  95, 193,  95, 193,424, 26, frontnet_draw_session_button,      0, 201,  0,      {47},            0, 0, frontnet_session_maintain },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  82, 261,  82, 261,220, 26, frontnet_draw_scroll_box_tab,      0, 201,  0,      {28},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  82, 287,  82, 287,450, 74, frontnet_draw_scroll_box,          0, 201,  0,      {24},            0, 0, NULL },
  { 1,  0, 0, 0, frontnet_players_up,NULL,       frontend_over_button,0, 532, 286, 532, 286, 26, 14, frontnet_draw_slider_button,       0, 201,  0,      {36},            0, 0, frontnet_players_up_maintain },
  { 1,  0, 0, 0, frontnet_players_down,NULL,     frontend_over_button,0, 532, 344, 532, 344, 26, 14, frontnet_draw_slider_button,       0, 201,  0,      {37},            0, 0, frontnet_players_down_maintain },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0, 536, 300, 536, 300, 10, 44, frontnet_draw_players_scroll_tab,  0, 201,  0,      {40},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  95, 262,  95, 262,220, 22, frontend_draw_text,                0, 201,  0,      {31},            0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,        NULL,               0,  95, 291,  82, 291,450, 52, frontnet_draw_net_session_players, 0, 201,  0,      {21},            0, 0, NULL },
  { 0,  0, 0, 0, frontnet_session_join,NULL,     frontend_over_button,0,  72, 360,  72, 360,247, 46, frontend_draw_small_menu_button,   0, 201,  0,      {13},            0, 0, frontnet_join_game_maintain },
  { 0,  0, 0, 0, frontnet_session_create,NULL,   frontend_over_button,0, 321, 360, 321, 360,247, 46, frontend_draw_small_menu_button,   0, 201,  0,      {14},            0, 0, NULL },
  { 0,  0, 0, 0, frontnet_session_add,NULL,      frontend_over_button,0,  72, 404,  72, 404,247, 46, frontend_draw_small_menu_button,   0, 201,  0,      {15},            0, 0, NULL },
  { 0,  0, 0, 0, frontnet_return_to_main_menu,NULL,frontend_over_button,0,321,404, 321, 404,247, 46, frontend_draw_small_menu_button,   0, 201,  0,       {6},            0, 0, NULL },
  //{ 0,  0, 0, 0, frontnet_return_to_main_menu,NULL,frontend_over_button,0,999,404, 999, 404,371, 46, frontend_draw_large_menu_button,   0, 201,  0,       {6},            0, 0, NULL },
  {-1,  0, 0, 0, NULL,               NULL,        NULL,               0,   0,   0,   0,   0,  0,  0, NULL,                              0,   0,  0,       {0},            0, 0, NULL },
};*/

struct GuiButtonInit frontend_net_start_buttons[] = {
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 999,  30, 999,  30, 371, 46, frontend_draw_large_menu_button,   0, 201,  0,  {12}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  82,  78,  82,  78, 220, 26, frontnet_draw_scroll_box_tab,      0, 201,  0,  {28}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 421,  81, 421,  81, 100, 27, frontnet_draw_alliance_box_tab,    0, 201,  0,  {28}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  82, 104,  82, 104, 450, 70, frontnet_draw_scroll_box,          0, 201,  0,  {90}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 102,  79, 102,  79, 220, 26, frontend_draw_text,                0, 201,  0,  {31}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  95, 105,  82, 105, 432,104, frontnet_draw_net_start_players,   0, 201,  0,  {21}, 0, 0, NULL },
  { 0,  0, 0, 0, frontnet_select_alliance,NULL,frontend_over_button,  0, 431, 107, 431, 116, 432, 88, frontnet_draw_alliance_grid,       0, 201,  0,  {74}, 0, 0, NULL },
  { 0,  0, 0, 0, frontnet_select_alliance,NULL,frontend_over_button,  0, 431, 108, 431, 108,  22, 26, frontnet_draw_alliance_button,     0, 201,  0,  {74}, 0, 0, frontnet_maintain_alliance },
  { 0,  0, 0, 0, frontnet_select_alliance,NULL,frontend_over_button,  1, 453, 108, 453, 108,  22, 26, frontnet_draw_alliance_button,     0, 201,  0,  {74}, 0, 0, frontnet_maintain_alliance },
  { 0,  0, 0, 0, frontnet_select_alliance,NULL,frontend_over_button,  2, 475, 108, 475, 108,  22, 26, frontnet_draw_alliance_button,     0, 201,  0,  {74}, 0, 0, frontnet_maintain_alliance },
  { 0,  0, 0, 0, frontnet_select_alliance,NULL,frontend_over_button,  3, 497, 108, 497, 108,  22, 26, frontnet_draw_alliance_button,     0, 201,  0,  {74}, 0, 0, frontnet_maintain_alliance },
  { 0,  0, 0, 0, frontnet_select_alliance,NULL,frontend_over_button,  0, 431, 134, 431, 134,  22, 26, frontnet_draw_alliance_button,     0, 201,  0,  {75}, 0, 0, frontnet_maintain_alliance },
  { 0,  0, 0, 0, frontnet_select_alliance,NULL,frontend_over_button,  1, 453, 134, 453, 134,  22, 26, frontnet_draw_alliance_button,     0, 201,  0,  {75}, 0, 0, frontnet_maintain_alliance },
  { 0,  0, 0, 0, frontnet_select_alliance,NULL,frontend_over_button,  2, 475, 134, 475, 134,  22, 26, frontnet_draw_alliance_button,     0, 201,  0,  {75}, 0, 0, frontnet_maintain_alliance },
  { 0,  0, 0, 0, frontnet_select_alliance,NULL,frontend_over_button,  3, 497, 134, 497, 134,  22, 26, frontnet_draw_alliance_button,     0, 201,  0,  {75}, 0, 0, frontnet_maintain_alliance },
  { 0,  0, 0, 0, frontnet_select_alliance,NULL,frontend_over_button,  0, 431, 160, 431, 160,  22, 26, frontnet_draw_alliance_button,     0, 201,  0,  {76}, 0, 0, frontnet_maintain_alliance },
  { 0,  0, 0, 0, frontnet_select_alliance,NULL,frontend_over_button,  1, 453, 160, 453, 160,  22, 26, frontnet_draw_alliance_button,     0, 201,  0,  {76}, 0, 0, frontnet_maintain_alliance },
  { 0,  0, 0, 0, frontnet_select_alliance,NULL,frontend_over_button,  2, 475, 160, 475, 160,  22, 26, frontnet_draw_alliance_button,     0, 201,  0,  {76}, 0, 0, frontnet_maintain_alliance },
  { 0,  0, 0, 0, frontnet_select_alliance,NULL,frontend_over_button,  3, 497, 160, 497, 160,  22, 26, frontnet_draw_alliance_button,     0, 201,  0,  {76}, 0, 0, frontnet_maintain_alliance },
  { 0,  0, 0, 0, frontnet_select_alliance,NULL,frontend_over_button,  0, 431, 186, 431, 183,  22, 26, frontnet_draw_alliance_button,     0, 201,  0,  {77}, 0, 0, frontnet_maintain_alliance },
  { 0,  0, 0, 0, frontnet_select_alliance,NULL,frontend_over_button,  1, 453, 186, 453, 186,  22, 26, frontnet_draw_alliance_button,     0, 201,  0,  {77}, 0, 0, frontnet_maintain_alliance },
  { 0,  0, 0, 0, frontnet_select_alliance,NULL,frontend_over_button,  2, 475, 186, 475, 186,  22, 26, frontnet_draw_alliance_button,     0, 201,  0,  {77}, 0, 0, frontnet_maintain_alliance },
  { 0,  0, 0, 0, frontnet_select_alliance,NULL,frontend_over_button,  3, 497, 186, 497, 186,  22, 26, frontnet_draw_alliance_button,     0, 201,  0,  {77}, 0, 0, frontnet_maintain_alliance },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 284, 217, 284, 217,   0,  0, frontnet_draw_bottom_scroll_box_tab,0,201,  0,  {28}, 0, 0, NULL },
  { 0,  0, 0, 0, frontend_toggle_computer_players,NULL,frontend_over_button,0,297,214,297,214,220,26, frontend_draw_computer_players,    0, 201,  0, {103}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  82, 246,  82, 246, 220, 26, frontnet_draw_scroll_box_tab,      0, 201,  0,  {28}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  82, 272,  82, 272, 450,111, frontnet_draw_scroll_box,          0, 201,  0,  {91}, 0, 0, NULL },
  { 1,  0, 0, 0, frontnet_messages_up,NULL,  frontend_over_button,    0, 532, 271, 532, 271,  26, 14, frontnet_draw_slider_button,       0, 201,  0,  {38}, 0, 0, frontnet_messages_up_maintain },
  { 1,  0, 0, 0, frontnet_messages_down,NULL,frontend_over_button,    0, 532, 373, 532, 373,  26, 14, frontnet_draw_slider_button,       0, 201,  0,  {39}, 0, 0, frontnet_messages_down_maintain },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 102, 247, 102, 247, 220, 26, frontend_draw_text,                0, 201,  0,  {34}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 536, 285, 536, 285,  10, 88, frontnet_draw_messages_scroll_tab, 0, 201,  0,  {40}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  82, 386,  82, 386, 459, 23, frontnet_draw_current_message,     0, 201,  0,  {43}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  89, 273,  89, 273, 438,104, frontnet_draw_messages,            0, 201,  0,  {44}, 0, 0, NULL },
  { 0,  0, 0, 0, set_packet_start,   NULL,   frontend_over_button,    0,  49, 412,  49, 412, 247, 46, frontend_draw_small_menu_button,   0, 201,  0,  {15}, 0, 0, frontnet_start_game_maintain },
  { 0,  0, 0, 0, frontnet_return_to_session_menu,NULL,frontend_over_button,1, 345,412,345,412,247,46, frontend_draw_small_menu_button,   0, 201,  0,  {16}, 0, 0, NULL },
  {-1,  0, 0, 0, NULL,               NULL,   NULL,                    0,   0,   0,   0,   0,   0,  0, NULL,                              0,   0,  0,   {0}, 0, 0, NULL },
};

struct GuiButtonInit frontend_net_modem_buttons[] = {
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 999,  30, 999,  30, 371, 46, frontend_draw_large_menu_button,   0, 201,  0,  {53}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  41, 102,  41, 102, 212, 26, frontnet_draw_small_scroll_box_tab,0, 201,  0,  {28}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  41, 128,  41, 128, 268, 70, frontnet_draw_small_scroll_box,    0, 201,  0,  {24}, 0, 0, NULL },
  { 1,  0, 0, 0, frontnet_comport_up,NULL,   frontend_over_button,    0, 275, 128, 275, 128,  26, 14, frontnet_draw_slider_button,       0, 201,  0,  {17}, 0, 0, frontnet_comport_up_maintain },
  { 1,  0, 0, 0, frontnet_comport_down,NULL, frontend_over_button,    0, 275, 186, 275, 186,  26, 14, frontnet_draw_slider_button,       0, 201,  0,  {18}, 0, 0, frontnet_comport_down_maintain },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 279, 142, 279, 142,  22, 44, frontnet_draw_comport_scroll_tab,  0, 201,  0,  {40}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  61, 103,  61, 103, 172, 25, frontend_draw_text,                0, 201,  0,  {55}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  41, 198,  41, 198, 268, 23, frontnet_draw_comport_selected,    0, 201,  0,  {57}, 0, 0, NULL },
  { 0,  0, 0, 0, frontnet_comport_select,NULL,frontend_over_button,   0,  54, 136,  54, 136, 190, 26, frontnet_draw_comport_button,      0, 201,  0,  {45}, 0, 0, frontnet_comport_select_maintain },
  { 0,  0, 0, 0, frontnet_comport_select,NULL,frontend_over_button,   0,  54, 164,  54, 164, 190, 26, frontnet_draw_comport_button,      0, 201,  0,  {46}, 0, 0, frontnet_comport_select_maintain },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 331, 102, 331, 102, 212, 26, frontnet_draw_small_scroll_box_tab,0, 201,  0,  {28}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 331, 128, 331, 128, 268, 70, frontnet_draw_small_scroll_box,    0, 201,  0,  {24}, 0, 0, NULL },
  { 1,  0, 0, 0, frontnet_speed_up,  NULL,   frontend_over_button,    0, 565, 128, 565, 128,  26, 14, frontnet_draw_slider_button,       0, 201,  0,  {36}, 0, 0, frontnet_speed_up_maintain },
  { 1,  0, 0, 0, frontnet_speed_down,NULL,   frontend_over_button,    0, 565, 186, 565, 186,  26, 14, frontnet_draw_slider_button,       0, 201,  0,  {37}, 0, 0, frontnet_speed_down_maintain },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 569, 142, 569, 142,  22, 44, frontnet_draw_speed_scroll_tab,    0, 201,  0,  {40}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 351, 103, 351, 103, 172, 25, frontend_draw_text,                0, 201,  0,  {56}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 331, 198, 331, 198, 450, 23, frontnet_draw_speed_selected,      0, 201,  0,  {58}, 0, 0, NULL },
  { 0,  0, 0, 0, frontnet_speed_select,NULL, frontend_over_button,    0, 344, 136, 344, 136, 190, 14, frontnet_draw_speed_button,        0, 201,  0,  {47}, 0, 0, frontnet_speed_select_maintain },
  { 0,  0, 0, 0, frontnet_speed_select,NULL, frontend_over_button,    0, 344, 164, 344, 164, 190, 14, frontnet_draw_speed_button,        0, 201,  0,  {48}, 0, 0, frontnet_speed_select_maintain },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  82, 254,  82, 254, 165, 28, frontnet_draw_text_cont_bar,       0, 201,  0,  {27}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  95, 255,  91, 255, 165, 25, frontend_draw_text,                0, 201,  0,  {71}, 0, 0, NULL },
  { 5, -3,-1, 0, frontnet_net_set_phone_number,NULL,frontend_over_button,71,280,255,95, 255, 432, 25, frontend_draw_enter_text,          0, 201,  0, {(long)tmp_net_phone_number}, 20, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  82, 282,  82, 282, 165, 28, frontnet_draw_text_cont_bar,       0, 201,  0,  {27}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  95, 283,  91, 283, 165, 25, frontend_draw_text,                0, 201,  0,  {66}, 0, 0, NULL },
  { 5, -1,-1, 0, frontnet_net_set_modem_init,NULL,frontend_over_button,66,280,283,  95, 283, 432, 25, frontend_draw_enter_text,          0, 201,  0, {(long)tmp_net_modem_init}, -20, -1, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  82, 310,  82, 310, 165, 28, frontnet_draw_text_cont_bar,       0, 201,  0,  {27}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  95, 311,  91, 311, 165, 25, frontend_draw_text,                0, 201,  0,  {67}, 0, 0, NULL },
  { 5, -1,-1, 0, frontnet_net_set_modem_hangup,NULL,frontend_over_button,67,280,311,95, 311, 432, 25, frontend_draw_enter_text,          0, 201,  0, {(long)tmp_net_modem_hangup}, -20, -1, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  82, 338,  82, 338, 165, 28, frontnet_draw_text_cont_bar,       0, 201,  0,  {27}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  95, 339,  91, 339, 165, 25, frontend_draw_text,                0, 201,  0,  {68}, 0, 0, NULL },
  { 5, -1,-1, 0, frontnet_net_set_modem_dial,NULL,frontend_over_button,68,280,339,  95, 339, 432, 25, frontend_draw_enter_text,          0, 201,  0, {(long)tmp_net_modem_dial}, -20, -1, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  82, 366,  82, 366, 165, 28, frontnet_draw_text_cont_bar,       0, 201,  0,  {27}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  95, 367,  91, 367, 165, 25, frontend_draw_text,                0, 201,  0,  {69}, 0, 0, NULL },
  { 5, -1,-1, 0, frontnet_net_set_modem_answer,NULL,frontend_over_button,69,280,367,95, 367, 432, 25, frontend_draw_enter_text,          0, 201,  0, {(long)tmp_net_modem_answer}, -20, -1, NULL },
  { 0,  0, 0, 0, frontnet_net_modem_start,NULL,frontend_over_button,  0,  49, 412,  49, 412, 247, 46, frontend_draw_small_menu_button,   0, 201,  0,  {72}, 0, 0, frontnet_net_modem_start_maintain },
  { 0,  0, 0, 0, frontend_change_state,NULL,frontend_over_button,     1, 345, 412, 345, 412, 247, 46, frontend_draw_small_menu_button,   0, 201,  0,  {16}, 0, 0, NULL },
  {-1,  0, 0, 0, NULL,               NULL,   NULL,                    0,   0,   0,   0,   0,   0,  0, NULL,                              0,   0,  0,   {0}, 0, 0, NULL },
};

struct GuiButtonInit frontend_net_serial_buttons[] = {
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 999,  30, 999,  30, 371, 46, frontend_draw_large_menu_button,   0, 201,  0,  {54}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  41, 178,  41, 178, 212, 26, frontnet_draw_small_scroll_box_tab,0, 201,  0,  {28}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  41, 204,  41, 204, 268, 70, frontnet_draw_small_scroll_box,    0, 201,  0,  {24}, 0, 0, NULL },
  { 1,  0, 0, 0, frontnet_comport_up,NULL,   frontend_over_button,    0, 275, 204, 275, 204,  26, 14, frontnet_draw_slider_button,       0, 201,  0,  {17}, 0, 0, frontnet_comport_up_maintain },
  { 1,  0, 0, 0, frontnet_comport_down,NULL, frontend_over_button,    0, 275, 262, 275, 262,  26, 14, frontnet_draw_slider_button,       0, 201,  0,  {18}, 0, 0, frontnet_comport_down_maintain },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 279, 218, 279, 218,  22, 44, frontnet_draw_comport_scroll_tab,  0, 201,  0,  {40}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  61, 179,  61, 179, 172, 25, frontend_draw_text,                0, 201,  0,  {55}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0,  41, 274,  41, 274, 268, 23, frontnet_draw_comport_selected,    0, 201,  0,  {57}, 0, 0, NULL },
  { 0,  0, 0, 0, frontnet_comport_select,NULL,frontend_over_button,   0,  54, 212,  54, 212, 190, 26, frontnet_draw_comport_button,      0, 201,  0,  {45}, 0, 0, frontnet_comport_select_maintain },
  { 0,  0, 0, 0, frontnet_comport_select,NULL,frontend_over_button,   0,  54, 240,  54, 240, 190, 26, frontnet_draw_comport_button,      0, 201,  0,  {46}, 0, 0, frontnet_comport_select_maintain },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 331, 178, 331, 178, 212, 26, frontnet_draw_small_scroll_box_tab,0, 201,  0,  {28}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 331, 204, 331, 204, 268, 70, frontnet_draw_small_scroll_box,    0, 201,  0,  {24}, 0, 0, NULL },
  { 1,  0, 0, 0, frontnet_speed_up,NULL,     frontend_over_button,    0, 565, 204, 565, 204,  26, 14, frontnet_draw_slider_button,       0, 201,  0,  {36}, 0, 0, frontnet_speed_up_maintain },
  { 1,  0, 0, 0, frontnet_speed_down,NULL,   frontend_over_button,    0, 565, 262, 565, 262,  26, 14, frontnet_draw_slider_button,       0, 201,  0,  {37}, 0, 0, frontnet_speed_down_maintain },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 569, 218, 569, 218,  22, 44, frontnet_draw_speed_scroll_tab,    0, 201,  0,  {40}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 351, 179, 351, 179, 172, 25, frontend_draw_text,                0, 201,  0,  {56}, 0, 0, NULL },
  { 0,  0, 0, 0, NULL,               NULL,   NULL,                    0, 331, 274, 331, 274, 450, 23, frontnet_draw_speed_selected,      0, 201,  0,  {58}, 0, 0, NULL },
  { 0,  0, 0, 0, frontnet_speed_select,NULL, frontend_over_button,    0, 344, 212, 344, 212, 190, 26, frontnet_draw_speed_button,        0, 201,  0,  {47}, 0, 0, frontnet_speed_select_maintain },
  { 0,  0, 0, 0, frontnet_speed_select,NULL, frontend_over_button,    0, 344, 240, 344, 240, 190, 26, frontnet_draw_speed_button,        0, 201,  0,  {48}, 0, 0, frontnet_speed_select_maintain },
  { 0,  0, 0, 0, frontnet_net_serial_start,NULL,frontend_over_button, 0,  49, 412,  49, 412, 247, 46, frontend_draw_small_menu_button,   0, 201,  0,  {73}, 0, 0, frontnet_net_serial_start_maintain },
  { 0,  0, 0, 0, frontend_change_state,NULL, frontend_over_button,    1, 345, 412, 345, 412, 247, 46, frontend_draw_small_menu_button,   0, 201,  0,  {16}, 0, 0, NULL },
  {-1,  0, 0, 0, NULL,               NULL,   NULL,                    0,   0,   0,   0,   0,   0,  0, NULL,                              0,   0,  0,   {0}, 0, 0, NULL },
};

struct GuiMenu frontend_net_service_menu =
 { 20, 0, 1, frontend_net_service_buttons,        0,          0, 640, 480, frontend_copy_mnu_background,0, NULL,    NULL,                    0, 0, 0,};
struct GuiMenu frontend_net_session_menu =
 { 21, 0, 1, frontend_net_session_buttons,        0,          0, 640, 480, frontend_copy_mnu_background,0, NULL,    NULL,                    0, 0, 0,};
struct GuiMenu frontend_net_start_menu =
 { 22, 0, 1, frontend_net_start_buttons,          0,          0, 640, 480, frontend_copy_mnu_background,0, NULL,    NULL,                    0, 0, 0,};
struct GuiMenu frontend_net_modem_menu =
 { 23, 0, 1, frontend_net_modem_buttons,          0,          0, 640, 480, frontend_copy_mnu_background,0, NULL,    NULL,                    0, 0, 0,};
struct GuiMenu frontend_net_serial_menu =
 { 24, 0, 1, frontend_net_serial_buttons,         0,          0, 640, 480, frontend_copy_mnu_background,0, NULL,    NULL,                    0, 0, 0,};
/******************************************************************************/
#ifdef __cplusplus
}
#endif
/******************************************************************************/
const char *get_net_speed_text(int id)
{
    static const char *net_speed[] = {
       "9600",
      "14400",
      "19200",
      "28800",
      "38400",
      "57600",
     "115200",
       "ISDN",
    };
    const int limit = sizeof(net_speed)/sizeof(*net_speed) - 1;
    if (id < 0)
      id = 0;
    if (id > limit)
      id = limit;
    return net_speed[id];
}

const char *get_net_comport_text(int id)
{
    static const char *net_comport[] = {
        "COM1",
        "COM2",
        "COM3",
        "COM4",
        "COM5",
        "COM6",
        "COM7",
        "COM8",
    };
    const int limit = sizeof(net_comport)/sizeof(*net_comport) - 1;
    if (id < 0)
      id = 0;
    if (id > limit)
      id = limit;
    return net_comport[id];
}

long frontnet_number_of_players_in_session(void)
{
    long i,nplyr;
    nplyr = 0;
    for (i=0; i < NET_PLAYERS_COUNT; i++)
    {
      if (network_player_active(i))
        nplyr++;
    }
    return nplyr;
}

void frontnet_session_up_maintain(struct GuiButton *gbtn)
{
    //_DK_frontnet_session_up_maintain(gbtn);
    gbtn->flags ^= (gbtn->flags ^ 8 * (net_session_scroll_offset != 0)) & 8;
}

void frontnet_session_down_maintain(struct GuiButton *gbtn)
{
    //_DK_frontnet_session_down_maintain(gbtn);
    gbtn->flags ^= (gbtn->flags ^ 8 * (net_number_of_sessions - 1 > net_session_scroll_offset)) & 8;
}

void frontnet_session_maintain(struct GuiButton *gbtn)
{
    //_DK_frontnet_session_maintain(gbtn);
    gbtn->flags ^= (gbtn->flags ^ 8 * (net_session_scroll_offset + (long)gbtn->content - 45 < net_number_of_sessions)) & 8;
}

void frontnet_players_up_maintain(struct GuiButton *gbtn)
{
    //_DK_frontnet_players_up_maintain(gbtn);
    gbtn->flags ^= (gbtn->flags ^ 8 * (net_player_scroll_offset != 0)) & 8;
}

void frontnet_players_down_maintain(struct GuiButton *gbtn)
{
    //_DK_frontnet_players_down_maintain(gbtn);
    gbtn->flags ^= (gbtn->flags ^ 8 * (net_number_of_enum_players - 1 > net_player_scroll_offset)) & 8;
}

void frontnet_join_game_maintain(struct GuiButton *gbtn)
{
    //_DK_frontnet_join_game_maintain(gbtn);
    if (net_service_index_selected == 1)
    {
      if ( net_session_index_active != -1 && net_config_info.str_join[0] )
        gbtn->flags |= 0x08;
      else
        gbtn->flags &= ~0x08;
    }
    else
    {
      gbtn->flags ^= (gbtn->flags ^ 8 * (net_session_index_active != -1)) & 8;
    }
}

void frontnet_maintain_alliance(struct GuiButton *gbtn)
{
    //_DK_frontnet_maintain_alliance(gbtn);
    long plyr_idx1, plyr_idx2;
    plyr_idx1 = gbtn->field_1B;
    plyr_idx2 = (long)gbtn->content - 74;
    if ( plyr_idx2 >= net_number_of_enum_players || net_number_of_enum_players <= plyr_idx1 || plyr_idx2 == plyr_idx1 )
      gbtn->flags &= ~0x08;
    else
      gbtn->flags |= 0x08;
}

void frontnet_messages_up_maintain(struct GuiButton *gbtn)
{
    //_DK_frontnet_messages_up_maintain(gbtn);
    gbtn->flags ^= (gbtn->flags ^ 8 * (net_message_scroll_offset != 0)) & 8;
}

void frontnet_messages_down_maintain(struct GuiButton *gbtn)
{
    //_DK_frontnet_messages_down_maintain(gbtn);
    gbtn->flags ^= (gbtn->flags ^ 8 * (net_number_of_messages - 1 > net_message_scroll_offset)) & 8;
}

void frontnet_start_game_maintain(struct GuiButton *gbtn)
{
    //_DK_frontnet_start_game_maintain(gbtn);
    gbtn->flags ^= (gbtn->flags ^ 8 * (net_number_of_enum_players > 1)) & 8;
}

void frontnet_comport_up_maintain(struct GuiButton *gbtn)
{
    //_DK_frontnet_comport_up_maintain(gbtn);
    gbtn->flags ^= (gbtn->flags ^ 8 * (net_comport_scroll_offset != 0)) & 8;
}

void frontnet_comport_down_maintain(struct GuiButton *gbtn)
{
    //_DK_frontnet_comport_down_maintain(gbtn);
    gbtn->flags ^= (gbtn->flags ^ 8 * (number_of_comports - 1 > net_comport_scroll_offset)) & 8;
}

void frontnet_comport_select_maintain(struct GuiButton *gbtn)
{
    //_DK_frontnet_comport_select_maintain(gbtn);
    gbtn->flags ^= (gbtn->flags ^ 8 * (net_comport_scroll_offset + (long)gbtn->content - 45 < number_of_comports)) & 8;
}

void frontnet_speed_up_maintain(struct GuiButton *gbtn)
{
    //_DK_frontnet_speed_up_maintain(gbtn);
    gbtn->flags ^= (gbtn->flags ^ 8 * (net_speed_scroll_offset != 0)) & 8;
}

void frontnet_speed_down_maintain(struct GuiButton *gbtn)
{
    //_DK_frontnet_speed_down_maintain(gbtn);
    gbtn->flags ^= (gbtn->flags ^ 8 * (number_of_speeds - 1 > net_speed_scroll_offset)) & 8;
}

void frontnet_speed_select_maintain(struct GuiButton *gbtn)
{
    //_DK_frontnet_speed_select_maintain(gbtn);
    gbtn->flags ^= (gbtn->flags ^ 8 * (net_speed_scroll_offset + (long)gbtn->content - 47 < number_of_speeds)) & 8;
}

void frontnet_net_modem_start_maintain(struct GuiButton *gbtn)
{
    //_DK_frontnet_net_modem_start_maintain(gbtn);
    if ((net_comport_index_active == -1) || (net_speed_index_active == -1))
      gbtn->flags &= ~0x08;
    else
      gbtn->flags |= 0x08;
}

void frontnet_net_serial_start_maintain(struct GuiButton *gbtn)
{
  if ((net_comport_index_active == -1) || (net_speed_index_active == -1))
    gbtn->flags &= ~0x08;
  else
    gbtn->flags |= 0x08;
}

void frontnet_serial_reset(void)
{
    //_DK_frontnet_serial_reset();
    net_write_config_file();
}

void frontnet_modem_reset(void)
{
    //_DK_frontnet_modem_reset();
    net_write_config_file();
}

void frontnet_start_input(void)
{
    //_DK_frontnet_start_input();
    if (lbInkey & 0x80)
    {
        lbInkey = 0;
        return;
    }
    if (lbInkey != 0)
    {
        unsigned short asckey;
        asckey = key_to_ascii(lbInkey, KMod_SHIFT);
        if ((lbInkey == 14) || (lbInkey == 28) || (frontend_font_char_width(1,asckey) > 0))
        {
            struct ScreenPacket *nspck;
            nspck = &net_screen_packet[my_player_number];
            if ((nspck->field_4 & 0xF8) == 0)
            {
              nspck->field_4 = (nspck->field_4 & 7) | 0x40;
              nspck->param1 = lbInkey;
              if ((lbKeyOn[42] == 0) && (lbKeyOn[54] == 0))
              {
                  nspck->param2 = 0;
                  lbInkey = 0;
                  return;
              }
              nspck->param2 = 1;
            }
        }
        lbInkey = 0;
    }
}

void frontnet_draw_services_scroll_tab(struct GuiButton *gbtn)
{
    frontend_draw_scroll_tab(gbtn, net_service_scroll_offset, 0, net_number_of_services);
}

void frontnet_session_set_player_name(struct GuiButton *gbtn)
{
    //_DK_frontnet_session_set_player_name(gbtn);
    strcpy(net_player_name, tmp_net_player_name);
    strcpy(net_config_info.str_u2, tmp_net_player_name);
    net_write_config_file();
}

void frontnet_draw_text_bar(struct GuiButton *gbtn)
{
    //_DK_frontnet_draw_text_bar(gbtn);
    struct TbSprite *spr;
    int i;
    long pos_x, pos_y;
    pos_x = gbtn->scr_pos_x;
    pos_y = gbtn->scr_pos_y;
    spr = &frontend_sprite[71];
    LbSpriteDraw(pos_x, pos_y, spr);
    pos_x += spr->SWidth;
    spr = &frontend_sprite[72];
    for (i=0; i < 4; i++)
    {
        LbSpriteDraw(pos_x, pos_y, spr);
        pos_x += spr->SWidth;
    }
    spr = &frontend_sprite[73];
    LbSpriteDraw(pos_x, pos_y, spr);
}

void frontnet_session_up(struct GuiButton *gbtn)
{
    //_DK_frontnet_session_up(gbtn);
    if (net_session_scroll_offset > 0)
      net_session_scroll_offset--;
}

void frontnet_session_down(struct GuiButton *gbtn)
{
    //_DK_frontnet_session_down(gbtn);
    if (net_session_scroll_offset < net_number_of_sessions - 1)
      net_session_scroll_offset++;
}

void frontnet_draw_sessions_scroll_tab(struct GuiButton *gbtn)
{
    //_DK_frontnet_draw_sessions_scroll_tab(gbtn);
    frontend_draw_scroll_tab(gbtn, net_session_scroll_offset, 0, net_number_of_sessions);
}

void frontnet_draw_session_selected(struct GuiButton *gbtn)
{
    //_DK_frontnet_draw_session_selected(gbtn);
    struct TbSprite *spr;
    long pos_x, pos_y;
    int i;
    pos_x = gbtn->scr_pos_x;
    pos_y = gbtn->scr_pos_y;
    if (net_session_index_active == -1)
    {
        spr = &frontend_sprite[55];
        for (i=0; i < 6; i++)
        {
            LbSpriteDraw(pos_x, pos_y, spr);
            pos_x += spr->SWidth;
            spr++;
        }
    }
    else
    {
        const char *text;
        spr = &frontend_sprite[55];
        for (i=0; i < 6; i++)
        {
            LbSpriteDraw(pos_x, pos_y, spr);
            pos_x += spr->SWidth;
            spr++;
        }
        text = net_session[net_session_index_active]->text;
        i = frontend_button_info[(long)gbtn->content].font_index;
        if (text != NULL)
        {
            lbDisplay.DrawFlags = 0;
            LbTextSetFont(frontend_font[i]);
            LbTextSetWindow(gbtn->scr_pos_x + 13, gbtn->scr_pos_y, gbtn->width - 26, LbTextHeight(text));
            LbTextDraw(0, 0, text);
        }
    }
}

void frontnet_session_select(struct GuiButton *gbtn)
{
    //_DK_frontnet_session_select(gbtn);
    long i;
    i = (long)gbtn->content + net_session_scroll_offset - 45;
    if (net_number_of_sessions > i)
    {
        net_session_index_active = i;
        net_session_index_active_id = net_session[i]->id;
    }
}

void frontnet_draw_session_button(struct GuiButton *gbtn)
{
  //_DK_frontnet_draw_session_button(gbtn);
  long sessionIndex;
  long font_idx;
  long btnIndex;
  long height;

  btnIndex = (long)gbtn->content;
  sessionIndex = net_session_scroll_offset + btnIndex - 45;
  if ((sessionIndex < 0) || (sessionIndex >= net_number_of_sessions))
      return;
  font_idx = frontend_button_info[btnIndex%FRONTEND_BUTTON_INFO_COUNT].font_index;
  if ((btnIndex > 0) && (frontend_mouse_over_button == btnIndex)) {
      font_idx = 2;
  }
  lbDisplay.DrawFlags = 0;
  LbTextSetFont(frontend_font[font_idx]);
  height = LbTextLineHeight();
  LbTextSetWindow(gbtn->scr_pos_x, gbtn->scr_pos_y, gbtn->width, height);
  LbTextDraw(0, 0, net_session[sessionIndex]->text);
}

void frontnet_players_up(struct GuiButton *gbtn)
{
    //_DK_frontnet_players_up(gbtn);
    if (net_player_scroll_offset > 0)
      net_player_scroll_offset--;
}

void frontnet_players_down(struct GuiButton *gbtn)
{
    //_DK_frontnet_players_down(gbtn);
    if (net_player_scroll_offset < net_number_of_enum_players - 1)
      net_player_scroll_offset++;
}

void frontnet_draw_players_scroll_tab(struct GuiButton *gbtn)
{
    //_DK_frontnet_draw_players_scroll_tab(gbtn);
    frontend_draw_scroll_tab(gbtn, net_player_scroll_offset, 0, net_number_of_enum_players);
}

void frontnet_draw_net_session_players(struct GuiButton *gbtn)
{
    //_DK_frontnet_draw_net_session_players(gbtn);
    int i;
    i = frontend_button_info[(long)gbtn->content].font_index;
    lbDisplay.DrawFlags = 0;
    LbTextSetFont(frontend_font[i]);
    int height;
    height = 0;
    long netplyr_idx;
    int shift_y;
    netplyr_idx = net_player_scroll_offset;
    for (shift_y=0; shift_y < gbtn->height; shift_y += height, netplyr_idx++)
    {
        const char *text;
        text = net_player[netplyr_idx].name;
        if (netplyr_idx >= net_number_of_enum_players)
            break;
        const struct TbSprite *spr;
        spr = &frontend_sprite[21+netplyr_idx];
        height = LbTextLineHeight();
        i = height - spr->SHeight;
        LbSpriteDraw(gbtn->scr_pos_x, gbtn->scr_pos_y + shift_y + abs(i)/2, spr);
        LbTextSetWindow(gbtn->scr_pos_x, shift_y + gbtn->scr_pos_y, gbtn->width - spr->SWidth, height);
        LbTextDraw(spr->SWidth, 0, text);
    }
}

void frontnet_session_add(struct GuiButton *gbtn)
{
    //TODO NET When clicked, it could either just display a modal text field (if that's possible), or a completely new screen which simply has a text field (for IP address) and OK/Cancel buttons.
}

void frontnet_session_join(struct GuiButton *gbtn)
{
    long plyr_num;
    plyr_num = network_session_join();
    if (plyr_num < 0)
        return;
    frontend_set_player_number(plyr_num);
    frontend_set_state(FeSt_NET_START);
}

void frontnet_session_create(struct GuiButton *gbtn)
{
  struct TbNetworkSessionNameEntry *nsname;
  unsigned long plyr_num;
  void *conn_options;
  char *text;
  char *txpos;
  long i,idx;
  idx = 0;
  for (i=0; i < net_number_of_sessions; i++)
  {
      nsname = net_session[i];
      if (nsname == NULL)
        continue;
      text = buf_sprintf("%s",nsname->text);
      txpos = strchr(text, '\'');
      if (txpos != NULL)
        *txpos = '\0';
      if (strcmp(text, net_player_name) != 0)
        idx++;
  }
  if (idx > 0)
    text = buf_sprintf("%s (%d)", net_player_name, idx+1);
  else
    text = buf_sprintf("%s", net_player_name);
  switch (net_service_index_selected)
  {
  case 1:
      modem_dev.field_0 = 0;
      modem_dev.field_4 = 0;
      strcpy(modem_dev.field_58, net_config_info.str_join);
      modem_dev.field_AC = modem_initialise_callback;
      modem_dev.field_B0 = modem_connect_callback;
      conn_options = &modem_dev;
      break;
  default:
      conn_options = NULL;
      break;
  }
  if (LbNetwork_Create(text, net_player_name, &plyr_num, conn_options))
  {
    if (net_service_index_selected == 1)
      process_network_error(modem_dev.field_A8);
    else
      process_network_error(-801);
    return;
  }
  frontend_set_player_number(plyr_num);
  fe_computer_players = 0;
  frontend_set_state(FeSt_NET_START);
}

void frontnet_return_to_main_menu(struct GuiButton *gbtn)
{
  if ( LbNetwork_Stop() )
  {
    ERRORLOG("LbNetwork_Stop() failed");
    return;
  }
  frontend_set_state(FeSt_MAIN_MENU);
}

void frontnet_draw_alliance_box_tab(struct GuiButton *gbtn)
{
    //_DK_frontnet_draw_alliance_box_tab(gbtn);
    const struct TbSprite *spr;
    int pos_x, pos_y;

    pos_x = gbtn->scr_pos_x;
    pos_y = gbtn->scr_pos_y;
    spr = &frontend_sprite[74];
    LbSpriteDraw(pos_x, pos_y, spr);
    pos_x += spr->SWidth;
    spr = &frontend_sprite[77];
    LbSpriteDraw(pos_x, pos_y, spr);
    pos_x += spr->SWidth;
    spr = &frontend_sprite[76];
    LbSpriteDraw(pos_x, pos_y, spr);

    pos_y += 5;
    pos_x = gbtn->scr_pos_x;
    spr = &frontend_sprite[74];
    pos_x += spr->SWidth - 1;
    if (net_number_of_enum_players > 0)
    {
        spr = &frontend_sprite[21];
        LbSpriteDraw(pos_x, pos_y, spr);
        pos_x += spr->SWidth;
    }
    if (net_number_of_enum_players > 1)
    {
        spr = &frontend_sprite[22];
        LbSpriteDraw(pos_x, pos_y, spr);
        pos_x += spr->SWidth;
    }
    if (net_number_of_enum_players > 2)
    {
        spr = &frontend_sprite[23];
        LbSpriteDraw(pos_x, pos_y, spr);
        pos_x += spr->SWidth;
    }
    if (net_number_of_enum_players > 3)
    {
        spr = &frontend_sprite[24];
        LbSpriteDraw(pos_x, pos_y, spr);
    }
}

void frontnet_draw_net_start_players(struct GuiButton *gbtn)
{
    //_DK_frontnet_draw_net_start_players(gbtn);
    int i;
    i = frontend_button_info[(long)gbtn->content].font_index;
    lbDisplay.DrawFlags = 0;
    LbTextSetFont(frontend_font[i]);
    int height;
    height = 0;
    long netplyr_idx;
    int shift_y;
    netplyr_idx = net_player_scroll_offset;
    for (shift_y=0; shift_y < gbtn->height; shift_y += height, netplyr_idx++)
    {
        const char *text;
        text = net_player[netplyr_idx].name;
        if (netplyr_idx >= net_number_of_enum_players)
            break;
        const struct TbSprite *spr;

        long subplyr_idx;
        for (subplyr_idx = 0; subplyr_idx < net_number_of_enum_players; subplyr_idx++)
        {
            if (subplyr_idx >= NET_PLAYERS_COUNT)
                break;
            if (net_player_info[subplyr_idx].active)
            {
                if (subplyr_idx == netplyr_idx)
                    break;
            }
        }
        spr = &frontend_sprite[21+netplyr_idx];
        height = LbTextLineHeight();
        i = height - spr->SHeight;
        LbSpriteDraw(gbtn->scr_pos_x, gbtn->scr_pos_y + shift_y + abs(i)/2, spr);
        LbTextSetWindow(gbtn->scr_pos_x, gbtn->scr_pos_y + shift_y, gbtn->width - spr->SWidth, height);
        LbTextDraw(spr->SWidth, 0, text);
    }
}

void frontnet_select_alliance(struct GuiButton *gbtn)
{
    //_DK_frontnet_select_alliance(gbtn);
    struct PlayerInfo *myplyr;
    myplyr = get_my_player();
    int plyr1_idx, plyr2_idx;
    plyr1_idx = (long)gbtn->content - 74;
    plyr2_idx = gbtn->field_1B;
    if ( plyr1_idx == myplyr->id_number || plyr2_idx == myplyr->id_number )
    {
        struct ScreenPacket *nspck;
        nspck = &net_screen_packet[my_player_number];
        if ((nspck->field_4 & 0xF8) == 0)
        {
            nspck->field_4 = (nspck->field_4 & 7) | 0x20;
            nspck->param1 = plyr1_idx;
            nspck->param2 = plyr2_idx;
        }
    }
}

void frontnet_draw_alliance_grid(struct GuiButton *gbtn)
{
    //_DK_frontnet_draw_alliance_grid(gbtn);
    int pos_x, pos_y;
    pos_y = gbtn->scr_pos_y;
    struct TbSprite *spr;
    int netplyr_idx;

    pos_x = gbtn->scr_pos_x;
    spr = &frontend_sprite[83];
    for (netplyr_idx=0; netplyr_idx < NET_PLAYERS_COUNT; netplyr_idx++)
    {
        LbSpriteDraw(pos_x / pixel_size, pos_y / pixel_size, spr);
        pos_x += spr->SWidth;
    }
    pos_y += spr->SHeight;

    pos_x = gbtn->scr_pos_x;
    spr = &frontend_sprite[84];
    for (netplyr_idx=0; netplyr_idx < NET_PLAYERS_COUNT; netplyr_idx++)
    {
        LbSpriteDraw(pos_x / pixel_size, pos_y / pixel_size, spr);
        pos_x += spr->SWidth;
    }
    pos_y += spr->SHeight;

    pos_x = gbtn->scr_pos_x;
    spr = &frontend_sprite[85];
    for (netplyr_idx=0; netplyr_idx < NET_PLAYERS_COUNT; netplyr_idx++)
    {
        LbSpriteDraw(pos_x / pixel_size, pos_y / pixel_size, spr);
        pos_x += spr->SWidth;
    }
    pos_y += spr->SHeight;
}

void frontnet_draw_alliance_button(struct GuiButton *gbtn)
{
    //_DK_frontnet_draw_alliance_button(gbtn);
    int plyr1_idx, plyr2_idx;
    struct TbSprite *spr;
    plyr2_idx = gbtn->field_1B;
    plyr1_idx = (long)gbtn->content - 74;
    if ((plyr1_idx == plyr2_idx) || (frontend_alliances & alliance_grid[plyr1_idx][plyr2_idx]))
      spr = &frontend_sprite[87];
    else
      spr = &frontend_sprite[84];
    LbSpriteDraw(gbtn->scr_pos_x, gbtn->scr_pos_y, spr);
}

void frontnet_messages_up(struct GuiButton *gbtn)
{
    //_DK_frontnet_messages_up(gbtn);
    if (net_message_scroll_offset > 0)
      net_message_scroll_offset--;
}

void frontnet_messages_down(struct GuiButton *gbtn)
{
    //_DK_frontnet_messages_down(gbtn);
    if (net_message_scroll_offset < net_number_of_messages - 1)
      net_message_scroll_offset++;
}

void frontnet_draw_bottom_scroll_box_tab(struct GuiButton *gbtn)
{
    //_DK_frontnet_draw_bottom_scroll_box_tab(gbtn);
    long pos_x, pos_y;
    struct TbSprite *spr;
    pos_x = gbtn->scr_pos_x;
    pos_y = gbtn->scr_pos_y;
    lbDisplay.DrawFlags = 0x02;
    spr = &frontend_sprite[74];
    LbSpriteDraw(pos_x, pos_y, spr);
    pos_x += spr->SWidth;
    spr = &frontend_sprite[75];
    LbSpriteDraw(pos_x, pos_y, spr);
    pos_x += spr->SWidth;
    LbSpriteDraw(pos_x, pos_y, spr);
    pos_x += spr->SWidth;
    spr = &frontend_sprite[76];
    LbSpriteDraw(pos_x, pos_y, spr);
    lbDisplay.DrawFlags = 0;
}

void frontnet_draw_messages_scroll_tab(struct GuiButton *gbtn)
{
    //_DK_frontnet_draw_messages_scroll_tab(gbtn);
    frontend_draw_scroll_tab(gbtn, net_message_scroll_offset, 0, net_number_of_messages);
}

void frontnet_draw_scroll_selection_box(struct GuiButton *gbtn, long font_idx, const char *text)
{
    struct TbSprite * sprite;
    int draw_x;
    int i;
    unsigned char height;
    sprite = &frontend_sprite[55];
    draw_x = gbtn->scr_pos_x;
    for (i = 6; i > 0; --i)
    {
      LbSpriteDraw(draw_x, gbtn->scr_pos_y, sprite);
      draw_x += sprite->SWidth;
      ++sprite;
    }

    if (text != NULL)
    {
      lbDisplay.DrawFlags = 0;
      LbTextSetFont(frontend_font[font_idx]);
      height = LbTextHeight(text);
      LbTextSetWindow(gbtn->scr_pos_x + 13, gbtn->scr_pos_y, gbtn->width - 26, height);
      LbTextDraw(0, 0, text);
    }
}

void frontnet_draw_current_message(struct GuiButton *gbtn)
{
    static TbClockMSec last_time = 0;
    static TbBool print_with_cursor = 1;

    struct PlayerInfo *player;
    int button_info_font_index;
    char text[2048];
    //_DK_frontnet_draw_current_message(gbtn);

    // Blink cursor - switch state every 100ms
    if (LbTimerClock() >= last_time + 100)
    {
        print_with_cursor = !print_with_cursor;
        last_time = LbTimerClock();
    }

    // Get player
    player = get_my_player();
    if (player_invalid(player)) {
        return;
    }

    // Prepare text buffer and font
    snprintf(text, sizeof(text), "%s%s", player->mp_message_text, print_with_cursor?"_":"");
    button_info_font_index = frontend_button_info[(unsigned) gbtn->content].font_index;
    // And draw the message
    frontnet_draw_scroll_selection_box(gbtn, button_info_font_index, text);
}

void frontnet_draw_messages(struct GuiButton *gbtn)
{
  //_DK_frontnet_draw_messages(gbtn);

  int y;
  int font_idx;
  struct NetMessage *message_ptr;
  int num_active;
  unsigned char font_height;
  struct TbSprite *player_sprite;
  long long height_diff;
  int scroll_offset;
  int i;

  y = 0;
  scroll_offset = net_message_scroll_offset;
  font_idx = frontend_button_info[(unsigned) gbtn->content].font_index;
  lbDisplay.DrawFlags = 0;
  LbTextSetFont(frontend_font[font_idx]);
  if ( gbtn->height )
  {
    message_ptr = &net_message[net_message_scroll_offset];
    do
    {
      if ( scroll_offset >= net_number_of_messages )
        break;
      num_active = 0;
      for (i = message_ptr->plyr_idx; i > 0; --i)
      {
        if ( net_player_info[i].active)
          ++num_active;
      }

      player_sprite = &frontend_sprite[num_active + 21];
      font_height = LbTextLineHeight();

      height_diff = font_height - player_sprite->SHeight;
      LbSpriteDraw(gbtn->scr_pos_x, y + gbtn->scr_pos_y + (((unsigned)height_diff - (unsigned) (height_diff >> 32)) >> 1), player_sprite);

      LbTextSetWindow(gbtn->scr_pos_x, y + gbtn->scr_pos_y, gbtn->width, font_height);
      LbTextDraw(player_sprite->SWidth, 0, message_ptr->text);

      ++message_ptr;
      y += font_height;
      ++scroll_offset;
    }
    while ( y < gbtn->height );
  }
}

void frontnet_return_to_session_menu(struct GuiButton *gbtn)
{
    if ( LbNetwork_Stop() )
    {
        ERRORLOG("LbNetwork_Stop() failed");
        return;
    }
    if ( setup_network_service(net_service_index_selected) )
        frontend_set_state(FeSt_NET_SESSION);
    else
        frontend_set_state(FeSt_MAIN_MENU);
}

void frontnet_draw_small_scroll_box_tab(struct GuiButton *gbtn)
{
    //_DK_frontnet_draw_small_scroll_box_tab(gbtn);
    long pos_x, pos_y;
    struct TbSprite *spr;
    pos_x = gbtn->scr_pos_x;
    pos_y = gbtn->scr_pos_y;
    spr = &frontend_sprite[74];
    LbSpriteDraw(pos_x, pos_y, spr);
    pos_x += spr->SWidth;
    spr = &frontend_sprite[75];
    LbSpriteDraw(pos_x, pos_y, spr);
    pos_x += spr->SWidth;
    spr = &frontend_sprite[77];
    LbSpriteDraw(pos_x, pos_y, spr);
    pos_x += spr->SWidth;
    spr = &frontend_sprite[76];
    LbSpriteDraw(pos_x, pos_y, spr);
}

void frontnet_draw_small_scroll_selection_box(struct GuiButton *gbtn, long font_idx, const char *text)
{
    struct TbSprite *spr;
    int pos_x, pos_y;
    pos_x = gbtn->scr_pos_x;
    pos_y = gbtn->scr_pos_y;
    spr = &frontend_sprite[55];
    LbSpriteDraw(pos_x, pos_y, spr);
    pos_x += spr->SWidth;
    spr = &frontend_sprite[56];
    LbSpriteDraw(pos_x, pos_y, spr);
    pos_x += spr->SWidth;
    LbSpriteDraw(pos_x, pos_y, spr);
    pos_x += spr->SWidth;
    spr = &frontend_sprite[60];
    LbSpriteDraw(pos_x, pos_y, spr);
    if (text != NULL)
    {
        lbDisplay.DrawFlags = 0;
        LbTextSetFont(frontend_font[font_idx]);
        int height;
        height = LbTextLineHeight();
        LbTextSetWindow(gbtn->scr_pos_x + 13, gbtn->scr_pos_y, gbtn->width - 26, height);
        LbTextDraw(0, 0, text);
    }
}

void frontnet_draw_small_scroll_box(struct GuiButton *gbtn)
{
  _DK_frontnet_draw_small_scroll_box(gbtn);
}

void frontnet_comport_up(struct GuiButton *gbtn)
{
    //_DK_frontnet_comport_up(gbtn);
    if (net_comport_scroll_offset > 0)
      net_comport_scroll_offset--;
}

void frontnet_comport_down(struct GuiButton *gbtn)
{
    //_DK_frontnet_comport_down(gbtn);
    if (net_comport_scroll_offset < number_of_comports - 1)
      net_comport_scroll_offset++;
}

void frontnet_draw_comport_scroll_tab(struct GuiButton *gbtn)
{
    //_DK_frontnet_draw_comport_scroll_tab(gbtn);
    frontend_draw_scroll_tab(gbtn, net_comport_scroll_offset, 0, number_of_comports);
}

void frontnet_draw_comport_selected(struct GuiButton *gbtn)
{
    //_DK_frontnet_draw_comport_selected(gbtn);
    if (net_comport_index_active == -1)
        frontnet_draw_small_scroll_selection_box(gbtn, frontend_button_info[(long)gbtn->content].font_index, 0);
    else
        frontnet_draw_small_scroll_selection_box(gbtn, frontend_button_info[(long)gbtn->content].font_index, get_net_comport_text(net_comport_index_active));
}

void frontnet_comport_select(struct GuiButton *gbtn)
{
    //_DK_frontnet_comport_select(gbtn);
    gbtn->flags ^= (gbtn->flags ^ 8 * (net_comport_scroll_offset + (long)gbtn->content - 45 < number_of_comports)) & 8;
}

void frontnet_draw_comport_button(struct GuiButton *gbtn)
{
    //_DK_frontnet_draw_comport_button(gbtn);
    int i;
    int febtn_idx;
    febtn_idx = (long)gbtn->content;
    i = net_comport_scroll_offset + febtn_idx - 45;
    if (i < number_of_comports)
    {
        int font_idx;
        font_idx = frontend_button_info[febtn_idx].font_index;
        if (febtn_idx > 0)
        {
          if (frontend_mouse_over_button == febtn_idx)
            font_idx = 2;
        }
        lbDisplay.DrawFlags = 0;
        LbTextSetFont(frontend_font[font_idx]);
        const char *text;
        text = get_net_comport_text(i);
        LbTextSetWindow(gbtn->scr_pos_x, gbtn->scr_pos_y, gbtn->width, LbTextHeight(text));
        LbTextDraw(0, 0, text);
    }
}

void frontnet_speed_up(struct GuiButton *gbtn)
{
    //_DK_frontnet_speed_up(gbtn);
    if (net_speed_scroll_offset > 0)
      net_speed_scroll_offset--;
}

void frontnet_speed_down(struct GuiButton *gbtn)
{
    //_DK_frontnet_speed_down(gbtn);
    if (net_speed_scroll_offset < number_of_speeds - 1)
      net_speed_scroll_offset++;
}

void frontnet_draw_speed_scroll_tab(struct GuiButton *gbtn)
{
    //_DK_frontnet_draw_speed_scroll_tab(gbtn);
    frontend_draw_scroll_tab(gbtn, net_speed_scroll_offset, 0, number_of_speeds);
}

void frontnet_draw_speed_selected(struct GuiButton *gbtn)
{
    //_DK_frontnet_draw_speed_selected(gbtn);
    if (net_speed_index_active == -1)
        frontnet_draw_small_scroll_selection_box(gbtn, frontend_button_info[(long)gbtn->content].font_index, 0);
    else
        frontnet_draw_small_scroll_selection_box(gbtn, frontend_button_info[(long)gbtn->content].font_index, get_net_speed_text(net_speed_index_active));
}

void frontnet_speed_select(struct GuiButton *gbtn)
{
    //_DK_frontnet_speed_select(gbtn);
    gbtn->flags ^= (gbtn->flags ^ 8 * (net_speed_scroll_offset + (long)gbtn->content - 47 < number_of_speeds)) & 8;
}

void frontnet_draw_speed_button(struct GuiButton *gbtn)
{
    //_DK_frontnet_draw_speed_button(gbtn);
    int i;
    int febtn_idx;
    febtn_idx = (long)gbtn->content;
    i = net_comport_scroll_offset + febtn_idx - 47;
    if (i < number_of_speeds)
    {
        int font_idx;
        font_idx = frontend_button_info[febtn_idx].font_index;
        if (febtn_idx > 0)
        {
          if (frontend_mouse_over_button == febtn_idx)
            font_idx = 2;
        }
        lbDisplay.DrawFlags = 0;
        LbTextSetFont(frontend_font[font_idx]);
        const char *text;
        text = get_net_speed_text(i);
        LbTextSetWindow(gbtn->scr_pos_x, gbtn->scr_pos_y, gbtn->width, LbTextHeight(text));
        LbTextDraw(0, 0, text);
    }
}

void frontnet_draw_text_cont_bar(struct GuiButton *gbtn)
{
    //_DK_frontnet_draw_text_cont_bar(gbtn);
    int pos_x, pos_y;
    pos_y = gbtn->scr_pos_y;
    struct TbSprite *spr;
    int netplyr_idx;
    pos_x = gbtn->scr_pos_x;

    spr = &frontend_sprite[80];
    LbSpriteDraw(pos_x, pos_y, spr);
    pos_x += spr->SWidth;

    spr = &frontend_sprite[81];
    for (netplyr_idx=0; netplyr_idx < NET_PLAYERS_COUNT; netplyr_idx++)
    {
        LbSpriteDraw(pos_x / pixel_size, pos_y / pixel_size, spr);
        pos_x += spr->SWidth;
    }

    spr = &frontend_sprite[82];
    LbSpriteDraw(pos_x, pos_y, spr);
}

void frontnet_net_set_modem_init(struct GuiButton *gbtn)
{
    //_DK_frontnet_net_set_modem_init(gbtn);
    strcpy(net_config_info.str_atz, tmp_net_modem_init);
}

void frontnet_net_set_modem_hangup(struct GuiButton *gbtn)
{
    //_DK_frontnet_net_set_modem_hangup(gbtn);
    strcpy(net_config_info.str_ath, tmp_net_modem_hangup);
}

void frontnet_net_set_modem_dial(struct GuiButton *gbtn)
{
    //_DK_frontnet_net_set_modem_dial(gbtn);
    strcpy(net_config_info.str_atdt, tmp_net_modem_dial);
}

void frontnet_net_set_phone_number(struct GuiButton *gbtn)
{
    //_DK_frontnet_net_set_phone_number(gbtn);
    strcpy(net_config_info.str_join, tmp_net_phone_number);
}

void frontnet_net_modem_start(struct GuiButton *gbtn)
{
    //_DK_frontnet_net_modem_start(gbtn);
    if ((net_comport_index_active == -1) || (net_speed_index_active == -1))
        gbtn->flags &= ~0x08;
    else
        gbtn->flags |= 0x08;
}

void frontnet_net_set_modem_answer(struct GuiButton *gbtn)
{
    //_DK_frontnet_net_set_modem_answer(gbtn);
    strcpy(net_config_info.str_ats, tmp_net_modem_answer);
}

void frontnet_net_serial_start(struct GuiButton *gbtn)
{
    const char *net_speed_text;
    net_serial_data.field_0 = net_config_info.numfield_0;
    net_speed_text = get_net_speed_text(net_config_info.numfield_9);
    if (strcmp(net_speed_text, "ISDN") != 0)
    {
        net_serial_data.numfield_4 = atoi(net_speed_text);
    } else
    {
        ERRORLOG("ISDN not supported by Serial");
    }
  net_serial_data.field_8 = net_config_info.numfield_1[(unsigned char)net_config_info.numfield_0];
  net_serial_data.str_dial = NULL;
  net_serial_data.str_phone = NULL;
  net_serial_data.str_hang = NULL;
  net_serial_data.str_answr = NULL;
  setup_network_service(0);
}

void frontnet_service_up_maintain(struct GuiButton *gbtn)
{
    set_flag_byte(&gbtn->flags, LbBtnF_Unknown08, (net_service_scroll_offset != 0));
}

void frontnet_service_down_maintain(struct GuiButton *gbtn)
{
    set_flag_byte(&gbtn->flags, LbBtnF_Unknown08, (net_number_of_services-1 > net_service_scroll_offset));
}

void frontnet_service_up(struct GuiButton *gbtn)
{
    if (net_service_scroll_offset > 0)
      net_service_scroll_offset--;
}

void frontnet_service_down(struct GuiButton *gbtn)
{
    if ( net_number_of_services-1 > net_service_scroll_offset )
      net_service_scroll_offset++;
}

void frontnet_service_maintain(struct GuiButton *gbtn)
{
    set_flag_byte(&gbtn->flags, LbBtnF_Unknown08, (net_service_scroll_offset+(long)gbtn->content-45 < net_number_of_services));
}

void frontnet_draw_service_button(struct GuiButton *gbtn)
{
  int srvidx;
  long fbinfo_idx;
  int font_idx;
  // Find and verify selected network service
  fbinfo_idx = (long)(gbtn->content);
  srvidx = fbinfo_idx + net_service_scroll_offset - 45;
  if (srvidx >= net_number_of_services)
    return;
  // Select font to draw
  font_idx = frontend_button_info[fbinfo_idx%FRONTEND_BUTTON_INFO_COUNT].font_index;
  if ((fbinfo_idx != 0) && (frontend_mouse_over_button == fbinfo_idx))
      font_idx = 2;
  LbTextSetFont(frontend_font[font_idx]);
  // Set drawing window
  int height;
  lbDisplay.DrawFlags = Lb_TEXT_HALIGN_LEFT;
  height = LbTextHeight(net_service[srvidx]);
  LbTextSetWindow(gbtn->scr_pos_x, gbtn->scr_pos_y, gbtn->width, height);
  //Draw the text
  LbTextDraw(0, 0, net_service[srvidx]);
}

void frontnet_service_select(struct GuiButton *gbtn)
{
  int srvidx;
  srvidx = (long)(gbtn->content) + net_service_scroll_offset - 45;
  if ( ((game.system_flags & GSF_AllowOnePlayer) != 0)
     && (srvidx+1 >= net_number_of_services) )
  {
      fe_network_active = 0;
      frontend_set_state(FeSt_NETLAND_VIEW);
  } else
  if (srvidx <= 0)
  {
      frontend_set_state(FeSt_NET_SERIAL);
  } else
  {
      setup_network_service(srvidx);
  }
}

/******************************************************************************/
