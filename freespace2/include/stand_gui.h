/*
 * Copyright (C) Volition, Inc. 1999.  All rights reserved.
 *
 * All source code herein is the property of Volition, Inc. You may not sell 
 * or otherwise commercially exploit the source or things you created based on
 * the source.
 */

/*
 * $Logfile: /Freespace2/code/Network/stand_gui.h $
 * $Revision: 307 $
 * $Date: 2010-02-08 10:09:13 +0200 (пн, 08 лют 2010) $
 * $Author: taylor $
 *
 * $Log$
 * Revision 1.2  2002/06/09 04:41:15  relnev
 * added copyright header
 *
 * Revision 1.1.1.1  2002/05/03 03:28:12  root
 * Initial import.
 *
 * 
 * 4     11/19/98 4:19p Dave
 * Put IPX sockets back in psnet. Consolidated all multiplayer config
 * files into one.
 * 
 * 3     11/05/98 5:55p Dave
 * Big pass at reducing #includes
 * 
 * 2     10/07/98 10:53a Dave
 * Initial checkin.
 * 
 * 1     10/07/98 10:50a Dave
 * 
 * 24    9/04/98 3:52p Dave
 * Put in validated mission updating and application during stats
 * updating.
 * 
 * 23    6/10/98 2:56p Dave
 * Substantial changes to reduce bandwidth and latency problems.
 * 
 * 22    5/24/98 3:45a Dave
 * Minor object update fixes. Justify channel information on PXO. Add a
 * bunch of configuration stuff for the standalone.
 * 
 * 21    5/22/98 9:35p Dave
 * Put in channel based support for PXO. Put in "shutdown" button for
 * standalone. UI tweaks for TvT
 * 
 * 20    5/18/98 9:15p Dave
 * Put in network config file support.
 * 
 * 19    5/15/98 5:16p Dave
 * Fix a standalone resetting bug.Tweaked PXO interface. Display captaincy
 * status for team vs. team. Put in asserts to check for invalid team vs.
 * team situations.
 * 
 * 18    5/09/98 7:16p Dave
 * Put in CD checking. Put in standalone host password. Made pilot into
 * popup scrollable.
 * 
 * 17    5/08/98 5:05p Dave
 * Go to the join game screen when quitting multiplayer. Fixed mission
 * text chat bugs. Put mission type symbols on the create game list.
 * Started updating standalone gui controls.
 * 
 * 16    3/24/98 5:00p Dave
 * Fixed several ui bugs. Put in pre and post voice stream playback sound
 * fx. Put in error specific popups for clients getting dropped from games
 * through actions other than their own.
 * 
 * 15    1/31/98 4:32p Dave
 * Put in new support for VMT player validation, game logging in, and game
 * logging out. Need to finish stats transfer.
 * 
 * 14    1/24/98 3:39p Dave
 * Fixed numerous multiplayer bugs (last frame quit problem, weapon bank
 * changing, deny packets). Add several controls to standalone server.
 * 
 * 13    1/17/98 5:51p Dave
 * Bug fixes for bugs generated by multiplayer testing.
 * 
 * 12    1/13/98 5:37p Dave
 * Reworked a lot of standalone interface code. Put in single and
 * multiplayer popups for death sequence. Solidified multiplayer kick
 * code.
 * 
 * 11    1/11/98 10:03p Allender
 * removed <winsock.h> from headers which included it.  Made psnet_socket
 * type which is defined just as SOCKET type is.
 * 
 * 10    12/10/97 4:46p Dave
 * Added in more detailed support for multiplayer packet lag/loss. Fixed
 * some multiplayer stuff. Added some controls to the standalone.
 * 
 * 9     12/03/97 11:59a Dave
 * Dependant merge checkin
 * 
 * 8     10/03/97 4:57p Dave
 * Added functions for new text controls. Added some more reset controls.
 * Put in checks for all-players-gone.
 * 
 * 7     9/24/97 5:04p Dave
 * Removed an unnecessary function prototype.
 * 
 * 6     8/29/97 5:03p Dave
 * Added a ton of new gui controls/features.
 * 
 * 5     8/26/97 5:03p Dave
 * Added bunch of informational controls. Standardized some functions for
 * external use. Put in godview mode (conditionaled out though).
 * 
 * 4     8/23/97 11:31a Dave
 * Put in new gui calls. Added a bunch of display controls.
 * 
 * 3     8/20/97 4:20p Dave
 * Added standalone state text box.
 * 
 * 2     8/11/97 4:52p Dave
 * Spliced out standalone GUI stuff from OsApi and WinMain.cpp to its own
 * module.
 * 
 * 1     8/11/97 4:21p Dave
 * 
 * $NoKeywords: $
 */

#ifndef _FREESPACE_STANDALONE_GUI_HEADER_FILE
#define _FREESPACE_STANDALONE_GUI_HEADER_FILE

// ----------------------------------------------------------------------------------------
// external variables
//

struct net_player;

// ----------------------------------------------------------------------------------------
// generic dialog functions
//

// create the validate dialog 
void std_create_gen_dialog(const char *title);

// kill the validate dialog();
void std_destroy_gen_dialog();

// set the text in the filename of the validate dialog
// valid values for field_num == 0 .. 2
void std_gen_set_text(const char *str, int field_num);

// is the validate dialog active
int std_gen_is_active();


// ----------------------------------------------------------------------------------------
// connection page/tab functions
//

// set the text box indicating how many players are connected, returning the determined count
int std_connect_set_connect_count();

// set the connect status (connected or not) of the game host
void std_connect_set_host_connect_status();

// add an ip string to the connect page listbox
void std_connect_add_ip_string(const char *string);

// remove an ip string from the connect page listbox
void std_connect_remove_ip_string(const char *string);

// set an ip string on the connect page listbox
void std_connect_set_ip_string(const char *lookup, const char *string);

// kick a player (the one currently selected in the listbox)
void std_connect_kick_player();

// update the ping for this particular player
void std_connect_update_ping(net_player *p);

// clear all the controls for this page
void std_connect_clear_controls();

// set the game name for the standalone. passing NULL uses the default
void std_connect_set_gamename(const char *name);

// the user has changed the text in the server name text box. handle this
void std_connect_handle_name_change();

// the user has changed the text in the host password text box
void std_connect_handle_passwd_change();


// ----------------------------------------------------------------------------------------
// multiplayer page/tab functions
//

// set the mission time in seconds
void std_multi_set_standalone_missiontime(float mission_time);

// set the mission name
void std_multi_set_standalone_mission_name(const char *mission_name);

// initialize the goal tree for this mission 
void std_multi_setup_goal_tree();

// add all the goals from the current mission to the tree control
void std_multi_add_goals();

// update all the goals in the goal tree based upon the mission status
void std_multi_update_goals();

// set the framerate text box for this tab
void std_multi_set_framerate(float f);

// clear all the controls for this page
void std_multi_clear_controls();

// update the netgame information area controls with the current Netgame settings
void std_multi_update_netgame_info_controls();


// ---------------------------------------------------------------------------------------
// player info page/tab functions
//

// start displaying info for the passed player on this page
void std_pinfo_display_player_info(net_player *p);

// check to see if this player is the one being displayed, and if so, then update the display info
// return 1 if the player was updated
int std_pinfo_maybe_update_player_info(net_player *p);

// add a player to the list on the player info page
void std_pinfo_add_player_list_item(net_player *p);

// remove a player from the list on the player info page
void std_pinfo_remove_player_list_item(net_player *p);

// update the ping display for this player
void std_pinfo_update_ping(net_player *p);

// clear all the controls for this page
void std_pinfo_clear_controls();


// ---------------------------------------------------------------------------------------
// player god stuff page/tab functions
//

// add a player to the listbox on the godstuff page
void std_gs_add_player(net_player *p);

// remove a player from the listbox on the godstuff page
void std_gs_remove_player(net_player *p);

// send a message as if the standalone were a player
void std_gs_send_godstuff_message();

// set the framerate text box for this page
void std_gs_set_framerate(float f);

// clear all the controls for this page
void std_gs_clear_controls();


// ---------------------------------------------------------------------------------------
// debug page/tab functions
//

// set the text on the standalones state indicator box
void std_debug_set_standalone_state_string(const char *str);

// clear all the controls for this page
void std_debug_clear_controls();


// ---------------------------------------------------------------------------------------
// general functions
// 

// add a player and take care of updating all gui/data details
void std_add_player(net_player *p);

// remove a player and take care of updateing all gui/data details
int std_remove_player(net_player *p);

// set any relevant controls which display the framerate of the standalone
void std_set_standalone_fps(float fps);

// update any relveant controls which display the ping for the given player
void std_update_player_ping(net_player *p);

// reset all gui stuff for the standalone
void std_reset_standalone_gui();

// reset all networking/gui stuff (calls reset_standalone_gui) for the standalone
void std_multi_standalone_reset_all();

// close down the standalone
void std_deinit_standalone();

// initialize the standalone
void std_init_standalone();

// do any gui related issues on the standalone (like periodically updating player stats, etc...)
void std_do_gui_frame();

// notify the user that the standalone has failed to login to the tracker on startup
void std_tracker_notify_login_fail();

// attempt to log the standalone into the tracker
void std_tracker_login();

// reset all stand gui timestamps
void std_reset_timestamps();

// add a line of text chat to the standalone
void std_add_chat_text(const char *text, int player_index, int add_id);

// if the standalone is host password protected
int std_is_host_passwd();

// change the default property sheet interface into something more useful
void std_mutate_sheet();

// if the given callsign is banned from the server
int std_player_is_banned(const char *name);

// add a callsign to the ban list
void std_add_ban(const char *name);

#endif

