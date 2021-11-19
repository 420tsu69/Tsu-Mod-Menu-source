
#pragma once
#include "stdafx.h"

// This Menu Base is made by maxiZzModz it would be cool if you use this base when you mark me in the Credits as the Base Dev 
// These Base also support the Numpad,Arrow Key and Controller Support Openkey  Numpad * (Controller : Both Shoulderbuttons


//Nano 42 Is am Extension of Virtual base that works for the update 1.42 - Doomsday. All Credits goes to Cretor of MaxxizzModz, and other developer involved in creation of Virtual Base.


bool TestBool = false;
bool featureVehStickyCar = false;
bool godmode = false;
bool neverwanted = false;
bool featurePlayerSuperJump = false;
bool TeleportToMarker = false;
bool invisibility = false;
bool FastSwim = false;
bool FastRun = false;
bool RepairCar = false;
bool featurePlayermoneyDrop = false;
bool moneyloop = false;
bool featureWeaponMoneyGun = false;
bool featureWeaponNoReload = false;
bool featureWeaponFireAmmo = false;
bool featureWeaponExplosiveAmmo = false;
bool featureWeaponExplosiveMelee = false;
bool featureWeaponVehRockets = false;
bool featureVehInvincible = false;
bool featureVehInvincibleUpdated = false;
bool featureWeaponVehGreen = false;
bool featureWeaponVehFlare = false;
bool featureVehRainbow = false;
bool featureWeaponVehRed = false;
bool featureWeaponVehSnow = false;
bool featureWeaponVehTank = false;
bool featureVehAllMod = false;
bool featureWeaponOneHit = false;
bool featureWeaponVehFire = false;
bool featureWeaponWhaleGun = false;
bool featureWeaponRainbowTint = false;
bool featureVehScrollingText = false;
bool featureVehSlide = false;
bool featureVehSuperRPM = false;
int selectedPlayer;


char* CharKeyboard(char* windowName = "", int maxInput = 21, char* defaultText = "") {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return "";
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}
int NumberKeyboard() {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(1, "", "", "", "", "", "", 10);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return 0;
	return atof(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
}
void notifyleft(char* msg)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(msg);
	UI::_DRAW_NOTIFICATION(2000, 1);
}

Vector3 TPCoords;
void TPto(Vector3 Coords)
{
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
	{
		ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(Handle, false), Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
	}
	else
		ENTITY::SET_ENTITY_COORDS(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
}
void Features()
{
#define PROP_MONEY_BAG_01 0x113FD533
#define PICKUP_MONEY_CASE 0x711D02A4
#define PROP_POLY_BAG_01 0x9CA6F755
		Vector3 ONLINE_PLAYER_COORDS = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1);

	Entity player = PLAYER::PLAYER_ID();
	Entity playerPed = PLAYER::PLAYER_PED_ID();
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(playerPed);
	
	if (FastSwim)
	{
		PLAYER::SET_SWIM_MULTIPLIER_FOR_PLAYER(player, 2);
	}
	else {
		PLAYER::SET_SWIM_MULTIPLIER_FOR_PLAYER(player, 1);
	}
	if (FastRun) {
		PLAYER::SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(player, 2);
	}
	else {
		PLAYER::SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(player, 1);
	}
	if (godmode)
	{
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), true);
	}
	else { ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), false); }

	if (neverwanted)
	{
		PLAYER::CLEAR_PLAYER_WANTED_LEVEL(playerPed);
		PLAYER::SET_MAX_WANTED_LEVEL(0);
		PLAYER::SET_POLICE_IGNORE_PLAYER(playerPed, true);
		PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(playerPed, false);
		PLAYER::SET_EVERYONE_IGNORE_PLAYER(playerPed, true);
		PLAYER::SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS(playerPed, true);
	}
	else {
		PLAYER::SET_MAX_WANTED_LEVEL(5);
		PLAYER::SET_POLICE_IGNORE_PLAYER(playerPed, false);
		PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(playerPed, true);
		PLAYER::SET_EVERYONE_IGNORE_PLAYER(playerPed, false);
		PLAYER::SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS(playerPed, false);
	}


	if (featurePlayermoneyDrop)
	{
		STREAMING::REQUEST_MODEL(PROP_MONEY_BAG_01);
		while (!STREAMING::HAS_MODEL_LOADED(PROP_MONEY_BAG_01))
			WAIT(0);
		if (STREAMING::HAS_MODEL_LOADED(PROP_MONEY_BAG_01))
		{
			int NUMBER_OF_BAGS = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(6, 12);
			int MONEY = (GAMEPLAY::GET_RANDOM_INT_IN_RANGE(40000, 120001) / NUMBER_OF_BAGS);
			MONEY = (int)round(MONEY);
			for (int i = 0; i < NUMBER_OF_BAGS; i++)
			{
				OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, ONLINE_PLAYER_COORDS.x, ONLINE_PLAYER_COORDS.y, ONLINE_PLAYER_COORDS.z + 0.15f, 0, MONEY, PROP_MONEY_BAG_01, false, true);
			}
		}
	}
	if (featurePlayerSuperJump)
	{
		if (bPlayerExists)
			GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(player);
	}
	if (featureWeaponFireAmmo)
	{
		if (bPlayerExists)
			GAMEPLAY::SET_FIRE_AMMO_THIS_FRAME(player);
	}
	if (featureWeaponExplosiveAmmo)
	{
		if (bPlayerExists)
			GAMEPLAY::SET_EXPLOSIVE_AMMO_THIS_FRAME(player);
	}
	if (featureWeaponMoneyGun && bPlayerExists)
	{
		if (ENTITY::DOES_ENTITY_EXIST(playerPed) && PED::IS_PED_SHOOTING(playerPed))
		{
			float xD[6];
			WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, (Vector3*)xD);
			if (xD[0] != 0 || xD[2] != 0 || xD[4] != 0)
			{
				STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("prop_money_bag_01"));
				while (!STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("prop_money_bag_01"))) WAIT(0);
				{
					OBJECT::CREATE_AMBIENT_PICKUP(GAMEPLAY::GET_HASH_KEY("pickup_money_case"), xD[0], xD[2], xD[4], 30000.0, 40000.0, GAMEPLAY::GET_HASH_KEY("prop_money_bag_01"), false, true);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("prop_money_bag_01"));
				}
			}
		}
	}

	if (featureWeaponOneHit)
	{
		if (bPlayerExists)
		{
			PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(player, 999999);
		}
	}
	if (bPlayerExists && featureWeaponNoReload)
	{
		Hash cur;
		if (WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &cur, 1))
		{
			if (WEAPON::IS_WEAPON_VALID(cur))
			{
				int maxAmmo;
				if (WEAPON::GET_MAX_AMMO(playerPed, cur, &maxAmmo))
				{
					WEAPON::SET_PED_AMMO(playerPed, cur, maxAmmo);

					maxAmmo = WEAPON::GET_MAX_AMMO_IN_CLIP(playerPed, cur, 1);
					if (maxAmmo > 0)
						WEAPON::SET_AMMO_IN_CLIP(playerPed, cur, maxAmmo);
				}
			}
		}
	}
	if (RepairCar) {
		VEHICLE::SET_VEHICLE_FIXED(vehicle);
		VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
		VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.0f);
		VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.0f);
		VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.0f);
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle, 0.0f);
	}
	if (featureVehAllMod)
	{

		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 1);
		VEHICLE::SET_VEHICLE_COLOURS(veh, 120, 120);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, "Tsu");
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, 1);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 18, 1);
		VEHICLE::TOGGLE_VEHICLE_MOD(veh, 22, 1);
		VEHICLE::SET_VEHICLE_MOD(veh, 16, 5, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 12, 2, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 11, 3, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 14, 14, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 15, 3, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 13, 2, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 6);
		VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, 5);
		VEHICLE::SET_VEHICLE_MOD(veh, 23, 19, 1);
		VEHICLE::SET_VEHICLE_MOD(veh, 0, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 1, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 2, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 3, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 4, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 5, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 6, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 7, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 8, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 9, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(veh, 10, 1, 0);
	}
	if (featureVehInvincible)
	{
		if (bPlayerExists && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
			ENTITY::SET_ENTITY_INVINCIBLE(veh, true);
			ENTITY::SET_ENTITY_PROOFS(veh, 1, 1, 1, 1, 1, 1, 1, 1);
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
			VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(veh, 0);
			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(veh, 0);
		}
	}

	if (featureVehInvincibleUpdated)
	{
		if (bPlayerExists && !featureVehInvincible && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
		{
			Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
			ENTITY::SET_ENTITY_INVINCIBLE(veh, false);
			ENTITY::SET_ENTITY_PROOFS(veh, 0, 0, 0, 0, 0, 0, 0, 0);
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 1);
			VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(veh, 1);
			VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(veh, 1);
		}
		featureVehInvincibleUpdated = false;
	}
	if (featureVehRainbow)
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		DWORD model = ENTITY::GET_ENTITY_MODEL(veh);

		if (PED::IS_PED_IN_ANY_VEHICLE)
		{
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, rand() % 255, rand() % 255, rand() % 255);
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, rand() % 255, rand() % 255, rand() % 255);
		}
	}
	if (featureVehStickyCar)
	{
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
		{
			int myVehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(myVehicle);
		}
	}
	if (invisibility)
	{
		ENTITY::SET_ENTITY_VISIBLE(playerPed, false, 0);
	}
	else { ENTITY::SET_ENTITY_VISIBLE(playerPed, true, 0); }
#define PICKUP_MONEY_PAPER_BAG 1897726628
	if (moneyloop)
	{
		STREAMING::REQUEST_MODEL(1897726628);
		Vector3 player = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
		if (STREAMING::HAS_MODEL_LOADED(1897726628));
		{
			OBJECT::CREATE_AMBIENT_PICKUP(PICKUP_MONEY_PAPER_BAG, player.x, player.y, player.z, 0, 2500, 1897726628, true, false);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(1897726628);
		}
	}
}


void main() {

	while (true) {
		Menu::Checks::Controlls();
		Features();
		notifyMap("Welcome to Tsu's Mod Menu!");
		switch (Menu::Settings::currentMenu) {

		case mainmenu:
		{
			Menu::Title("Tsu's Mod Menu");
			Menu::MenuOption("Health ~b~>", health);
			Menu::MenuOption("Money ~b~>", money);
			Menu::MenuOption("Police ~b~>", police);
			Menu::MenuOption("Vehicle ~b~>", vehicle);
			Menu::MenuOption("Weapons ~b~>", weaponsmenu);
			Menu::MenuOption("Player List ~b~>", plist);
			Menu::MenuOption("Miscellaneous ~b~>", miscellaneous);
			Menu::MenuOption("Settings ~b~>", settings);
			Menu::MenuOption("Credits ~b~>", Credits);
		}
		break;
#pragma region Self Menu
		case plist:
		{
			Menu::Title("Player List");
			for (int i{}; i < 32; i++) {
				if (NETWORK::NETWORK_IS_PLAYER_CONNECTED(i)) {
					Menu::PlayerOption(i);
				}
			}
		}
			break;
		case pmenu:
		{
			Menu::Title(PLAYER::GET_PLAYER_NAME(selectedPlayer));
			Menu::Break("It Works!");
		}
			break;
		case sub :
		{
			Menu::Title("Sub Menu");
			Menu::Toggle("Test Bool", TestBool);
			//To use functions do _>
			if (Menu::Option("Toggle Function"))
			{
				//Code to execute
			}
			//SubMenu
		}
		break;
#pragma endregion
#pragma region Settings Menu
		case settings:
		{
			Menu::Title("Settings");
			Menu::MenuOption("Colors ~b~>", settingstheme);
			if (Menu::Int("Scroll Delay", Menu::Settings::keyPressDelay2, 1, 200))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::keyPressDelay2 = NumberKeyboard();
				}
			}
			if (Menu::Int("Int Delay", Menu::Settings::keyPressDelay3, 1, 200))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::keyPressDelay3 = NumberKeyboard();
				}
			}
			Menu::Option("~HUD_COLOUR_GOLD~Social Club Account:");
			Menu::Option(PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID()));
			Menu::MenuOption("~r~KILL GAME", exitgta);
		}
		break;
		case Credits:
		{
			Menu::Title("Credits");
			Menu::Option("Modified By : ~f~Tsu");
			Menu::Option("Updated By : ~HUD_COLOUR_GOLD~Tsu");
			Menu::Option("Base : ~r~Nano");
			Menu::Option("~r~Tsu's Mod Menu");
			Menu::Option("V. 1.0");
		}
		break;
		case exitgta:
		{
			Menu::Title("Exit GTA V");
			if (Menu::Option("Yes")) exit(0);
		}
		break;
		case settingstheme:
		{
			Menu::Title("Colors");
			Menu::MenuOption("Theme Loader ~b~>", themeloader);
			Menu::MenuOption("Title Background ~b~>", settingstitlerect);
			Menu::MenuOption("Selection Box ~b~>", settingsscroller);
			Menu::MenuOption("Option Text ~b~>", settingsoptiontext);
			if (Menu::Option("MenuX plus")) {
				if (Menu::Settings::menuX < 0.81f) Menu::Settings::menuX += 0.01f;
			}
			if (Menu::Option("MenuX minus")) {
				if (Menu::Settings::menuX > 0.17f) Menu::Settings::menuX -= 0.01f;
			}
		}
		break;
		case themeloader:
		{
			Menu::Title("Theme Colors");
			if (Menu::Option("Red Theme")) {
				Menu::Settings::titleRect = { 100, 0, 0, 255 };
				Menu::Settings::scroller = { 100, 0, 0, 255 };
			}
			if (Menu::Option("Blue Theme")) {
				Menu::Settings::titleRect = { 0, 0, 200, 255 };
				Menu::Settings::scroller = { 0, 0, 200, 255 };
			}
			if (Menu::Option("Green Theme")) {
				Menu::Settings::titleRect = { 0, 180, 0, 255 };
				Menu::Settings::scroller = { 0, 0, 180, 255 };
			}
			if (Menu::Option("Load Default Theme")) {
				Menu::Settings::titleText = { 255, 255, 255, 255, 7 };
				Menu::Settings::titleRect = { 100, 0, 0, 255 };
				Menu::Settings::scroller = { 100, 0, 0, 255 };
				Menu::Settings::optionText = { 255, 255, 255, 255, 0 };
				Menu::Settings::optionRect = { 0, 0, 0, 110 };
			}
		}
		break;
		case settingstitlerect:
		{
			Menu::Title("Title Rect");
			if (Menu::Int("Red", Menu::Settings::titleRect.r, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::titleRect.r = NumberKeyboard();
				}
			}
			if (Menu::Int("Green", Menu::Settings::titleRect.g, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::titleRect.g = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue", Menu::Settings::titleRect.b, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::titleRect.b = NumberKeyboard();
				}
			}
			if (Menu::Int("Opacity", Menu::Settings::titleRect.a, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::titleRect.a = NumberKeyboard();
				}
			}
		}
		break;
		case settingsoptiontext:
		{
			Menu::Title("Option Text");
			if (Menu::Int("Red", Menu::Settings::optionText.r, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.r = NumberKeyboard();
				}
			}
			if (Menu::Int("Green", Menu::Settings::optionText.g, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.g = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue", Menu::Settings::optionText.b, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.b = NumberKeyboard();
				}
			}
			if (Menu::Int("Opacity", Menu::Settings::optionText.a, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::optionText.a = NumberKeyboard();
				}
			}
			Menu::MenuOption("Font ~b~>", font);
		}
		break;
		case font:
		{
			Menu::Title("Font");
			if (Menu::Option("Chalet London")) { Menu::Settings::optionText.f = 0; }
			if (Menu::Option("House Script")) { Menu::Settings::optionText.f = 1; }
			if (Menu::Option("Monospace")) { Menu::Settings::optionText.f = 2; }
			if (Menu::Option("Wing Dings")) { Menu::Settings::optionText.f = 3; }
			if (Menu::Option("Chalet Comprime Cologne")) { Menu::Settings::optionText.f = 4; }
			if (Menu::Option("Pricedown")) { Menu::Settings::optionText.f = 7; }
		}
		break;
		case settingsscroller:
		{
			Menu::Title("Scroller");
			if (Menu::Int("Red", Menu::Settings::scroller.r, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::scroller.r = NumberKeyboard();
				}
			}
			if (Menu::Int("Green", Menu::Settings::scroller.g, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::scroller.g = NumberKeyboard();
				}
			}
			if (Menu::Int("Blue", Menu::Settings::scroller.b, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::scroller.b = NumberKeyboard();
				}
			}
			if (Menu::Int("Opacity", Menu::Settings::scroller.a, 0, 255))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::scroller.a = NumberKeyboard();
				}
			}
		}
		break;
#pragma endregion
#pragma region health
		case health: {
			Menu::Title("Health");
			Menu::Toggle("God Mode", godmode);
			if (Menu::Option("Heal"))
			{
				ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 400);
			}
			if (Menu::Option("Max Armour"))
			{
				PED::ADD_ARMOUR_TO_PED(PLAYER::PLAYER_PED_ID(), 200);
			}
			if (Menu::Option("Suicide"))
			{
				ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 0);
			}
		}
				   break;
#pragma endregion
#pragma region Police
		case police:
		{
			Menu::Title("Police");
			Menu::Toggle("Never Wanted", neverwanted);
			if (Menu::Option("Clear Wanted Level"))
			{
				PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_PED_ID());
			}
		}
		break;
#pragma endregion

#pragma region Money
		case money:
		{
			Menu::Title("Money");
			Menu::Toggle("Moneyloop", featurePlayermoneyDrop);
		}
		break;
#pragma endregion
#pragma region Miscellaneous
		case miscellaneous:
		{
			Menu::Title("Miscellaneous");
			Menu::Toggle("Invisibility", invisibility);
			Menu::Toggle("Super Jump", featurePlayerSuperJump);
			Menu::Toggle("Teleport To Marker", TeleportToMarker);
			Menu::Toggle("Swim Fast", FastSwim);
			Menu::Toggle("Run Fast", FastRun);
		}
		break;
#pragma endregion
#pragma region Weapons
		case weaponsmenu:
		{
			Menu::Title("Weapons");
			Menu::Toggle("No Reload", featureWeaponNoReload);
			Menu::Toggle("Money Gun", featureWeaponMoneyGun);
			Menu::Toggle("Fire Ammo", featureWeaponFireAmmo);
			Menu::Toggle("Explosive Ammo", featureWeaponExplosiveAmmo);
			Menu::Toggle("One hit", featureWeaponOneHit);
		}
		break;
#pragma endregion

#pragma region Vehicles
		case vehicle:
		{
			Menu::Title("Vehicle");
			Menu::Toggle("Invincible", featureVehInvincible);
			Menu::Toggle("Rainbow", featureVehRainbow);
			Menu::Toggle("Full Upgrade", featureVehAllMod);
			Menu::Toggle("Sticky", featureVehStickyCar);
			Menu::Toggle("Repair Car", RepairCar);
		}
			break;
#pragma endregion
		}
		Menu::End();
		WAIT(0);
	}
}

void ScriptMain() {
	srand(GetTickCount());

	main();
}