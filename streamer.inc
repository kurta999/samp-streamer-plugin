/*
 * Copyright (C) 2017 Incognito
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#if defined _streamer_included
	#endinput
#endif
#define _streamer_included

#include <a_samp>

// Definitions

#define STREAMER_TYPE_OBJECT (0)
#define STREAMER_TYPE_PICKUP (1)
#define STREAMER_TYPE_CP (2)
#define STREAMER_TYPE_RACE_CP (3)
#define STREAMER_TYPE_MAP_ICON (4)
#define STREAMER_TYPE_3D_TEXT_LABEL (5)
#define STREAMER_TYPE_AREA (6)
#define STREAMER_TYPE_ACTOR (7)
#define STREAMER_TYPE_VEHICLE (8)

#define STREAMER_AREA_TYPE_CIRCLE (0)
#define STREAMER_AREA_TYPE_CYLINDER (1)
#define STREAMER_AREA_TYPE_SPHERE (2)
#define STREAMER_AREA_TYPE_RECTANGLE (3)
#define STREAMER_AREA_TYPE_CUBOID (4)
#define STREAMER_AREA_TYPE_POLYGON (5)

#define STREAMER_OBJECT_TYPE_GLOBAL (0)
#define STREAMER_OBJECT_TYPE_PLAYER (1)
#define STREAMER_OBJECT_TYPE_DYNAMIC (2)

#define STREAMER_VEHICLE_TYPE_STATIC (0)
#define STREAMER_VEHICLE_TYPE_DYNAMIC (1)

#define STREAMER_MAX_TYPES (8)
#define STREAMER_MAX_AREA_TYPES (5)
#define STREAMER_MAX_OBJECT_TYPES (3)

#define INVALID_STREAMER_ID (0)

#if !defined FLOAT_INFINITY
    #define FLOAT_INFINITY (Float:0x7F800000)
#endif

#if !defined STREAMER_ENABLE_TAGS
	#define STREAMER_TAG_OBJECT
	#define STREAMER_TAG_OBJECT_ALT
	#define STREAMER_TAG_PICKUP
	#define STREAMER_TAG_CP
	#define STREAMER_TAG_RACE_CP
	#define STREAMER_TAG_MAP_ICON
	#define STREAMER_TAG_AREA
	#define STREAMER_TAG_ACTOR
	#define STREAMER_TAG_VEHICLE

	#if !defined STREAMER_REMOVE_TEXT3D_TAG
		#if !defined STREAMER_USE_DYNAMIC_TEXT3D_TAG
			#define STREAMER_TAG_3D_TEXT_LABEL Text3D:
			#define STREAMER_ALL_TAGS {Text3D,_}:
		#else
			#define STREAMER_TAG_3D_TEXT_LABEL DynamicText3D:
			#define STREAMER_ALL_TAGS {DynamicText3D,_}:
		#endif
	#else
		#define STREAMER_TAG_3D_TEXT_LABEL
		#define STREAMER_ALL_TAGS
	#endif
#else
	#define STREAMER_TAG_OBJECT DynamicObject:
	#define STREAMER_TAG_OBJECT_ALT {DynamicObject,_}:
	#define STREAMER_TAG_PICKUP DynamicPickup:
	#define STREAMER_TAG_CP DynamicCP:
	#define STREAMER_TAG_RACE_CP DynamicRaceCP:
	#define STREAMER_TAG_MAP_ICON DynamicMapIcon:
	#define STREAMER_TAG_3D_TEXT_LABEL DynamicText3D:
	#define STREAMER_TAG_AREA DynamicArea:
	#define STREAMER_TAG_ACTOR DynamicActor:
	#define STREAMER_TAG_VEHICLE DynamicVehicle:

	#define STREAMER_ALL_TAGS {DynamicObject,DynamicPickup,DynamicCP,DynamicRaceCP,DynamicMapIcon,DynamicText3D,DynamicArea,DynamicActor,DynamicVehicle,_}:
#endif

#if !defined STREAMER_OBJECT_SD
	#define STREAMER_OBJECT_SD 300.0
#endif
#if !defined STREAMER_OBJECT_DD
	#define STREAMER_OBJECT_DD 0.0
#endif
#if !defined STREAMER_PICKUP_SD
	#define STREAMER_PICKUP_SD 200.0
#endif
#if !defined STREAMER_CP_SD
	#define STREAMER_CP_SD 200.0
#endif
#if !defined STREAMER_RACE_CP_SD
	#define STREAMER_RACE_CP_SD 200.0
#endif
#if !defined STREAMER_MAP_ICON_SD
	#define STREAMER_MAP_ICON_SD 200.0
#endif
#if !defined STREAMER_3D_TEXT_LABEL_SD
	#define STREAMER_3D_TEXT_LABEL_SD 200.0
#endif
#if !defined STREAMER_ACTOR_SD
	#define STREAMER_ACTOR_SD 200.0
#endif
#if !defined STREAMER_VEHICLE_SD
	#define STREAMER_VEHICLE_SD 250.0
#endif

// Include File Version

public Streamer_IncludeFileVersion = 0x291;

#pragma unused Streamer_IncludeFileVersion

// Enumerator

enum
{
	E_STREAMER_AREA_ID,
	E_STREAMER_ATTACHED_OBJECT,
	E_STREAMER_ATTACHED_PLAYER,
	E_STREAMER_ATTACHED_VEHICLE,
	E_STREAMER_ATTACH_OFFSET_X,
	E_STREAMER_ATTACH_OFFSET_Y,
	E_STREAMER_ATTACH_OFFSET_Z,
	E_STREAMER_ATTACH_R_X,
	E_STREAMER_ATTACH_R_Y,
	E_STREAMER_ATTACH_R_Z,
	E_STREAMER_ATTACH_X,
	E_STREAMER_ATTACH_Y,
	E_STREAMER_ATTACH_Z,
	E_STREAMER_COLOR_1,
	E_STREAMER_COLOR_2,
	E_STREAMER_DRAW_DISTANCE,
	E_STREAMER_EXTRA_ID,
	E_STREAMER_HEALTH,
	E_STREAMER_INTERIOR_ID,
	E_STREAMER_INVULNERABLE,
	E_STREAMER_MAX_X,
	E_STREAMER_MAX_Y,
	E_STREAMER_MAX_Z,
	E_STREAMER_MIN_X,
	E_STREAMER_MIN_Y,
	E_STREAMER_MIN_Z,
	E_STREAMER_MODEL_ID,
	E_STREAMER_MOVE_R_X,
	E_STREAMER_MOVE_R_Y,
	E_STREAMER_MOVE_R_Z,
	E_STREAMER_MOVE_SPEED,
	E_STREAMER_MOVE_X,
	E_STREAMER_MOVE_Y,
	E_STREAMER_MOVE_Z,
	E_STREAMER_NEXT_X,
	E_STREAMER_NEXT_Y,
	E_STREAMER_NEXT_Z,
	E_STREAMER_PAINTJOB,
	E_STREAMER_PLAYER_ID,
	E_STREAMER_PRIORITY,
	E_STREAMER_QUAT_W,
	E_STREAMER_QUAT_X,
	E_STREAMER_QUAT_Y,
	E_STREAMER_QUAT_Z,
	E_STREAMER_RESPAWN_TIME,
	E_STREAMER_ROTATION,
	E_STREAMER_R_X,
	E_STREAMER_R_Y,
	E_STREAMER_R_Z,
	E_STREAMER_SIZE,
	E_STREAMER_SPAWN_ANGLE,
	E_STREAMER_SPAWN_COLOR_1,
	E_STREAMER_SPAWN_COLOR_2,
	E_STREAMER_SPAWN_X,
	E_STREAMER_SPAWN_Y,
	E_STREAMER_SPAWN_Z,
	E_STREAMER_SIREN,
	E_STREAMER_STREAM_DISTANCE,
	E_STREAMER_STYLE,
	E_STREAMER_SYNC_ROTATION,
	E_STREAMER_TEST_LOS,
	E_STREAMER_TYPE,
	E_STREAMER_WORLD_ID,
	E_STREAMER_X,
	E_STREAMER_Y,
	E_STREAMER_Z
}

// For backward compatibility
#define E_STREAMER_COLOR E_STREAMER_COLOR_1

// Natives (Settings)

native Streamer_GetTickRate();
native Streamer_SetTickRate(rate);
native Streamer_GetPlayerTickRate(playerid);
native Streamer_SetPlayerTickRate(playerid, rate);
native Streamer_GetChunkTickRate(type, playerid = -1);
native Streamer_SetChunkTickRate(type, rate, playerid = -1);
native Streamer_GetChunkSize(type);
native Streamer_SetChunkSize(type, size);
native Streamer_GetMaxItems(type);
native Streamer_SetMaxItems(type, items);
native Streamer_GetVisibleItems(type, playerid = -1);
native Streamer_SetVisibleItems(type, items, playerid = -1);
native Streamer_GetRadiusMultiplier(type, &Float:multiplier, playerid = -1);
native Streamer_SetRadiusMultiplier(type, Float:multiplier, playerid = -1);
native Streamer_GetTypePriority(types[], maxtypes = sizeof types);
native Streamer_SetTypePriority(const types[], maxtypes = sizeof types);
native Streamer_GetCellDistance(&Float:distance);
native Streamer_SetCellDistance(Float:distance);
native Streamer_GetCellSize(&Float:size);
native Streamer_SetCellSize(Float:size);
native Streamer_ToggleItemStatic(type, STREAMER_ALL_TAGS id, toggle);
native Streamer_IsToggleItemStatic(type, STREAMER_ALL_TAGS id);
native Streamer_ToggleItemInvAreas(type, STREAMER_ALL_TAGS id, toggle);
native Streamer_IsToggleItemInvAreas(type, STREAMER_ALL_TAGS id);
native Streamer_ToggleItemCallbacks(type, STREAMER_ALL_TAGS id, toggle);
native Streamer_IsToggleItemCallbacks(type, STREAMER_ALL_TAGS id);
native Streamer_ToggleErrorCallback(toggle);
native Streamer_IsToggleErrorCallback();

// Natives (Updates)

native Streamer_ProcessActiveItems();
native Streamer_ToggleIdleUpdate(playerid, toggle);
native Streamer_IsToggleIdleUpdate(playerid);
native Streamer_ToggleCameraUpdate(playerid, toggle);
native Streamer_IsToggleCameraUpdate(playerid);
native Streamer_ToggleItemUpdate(playerid, type, toggle);
native Streamer_IsToggleItemUpdate(playerid, type);
native Streamer_GetLastUpdateTime(&Float:time);
native Streamer_Update(playerid, type = -1);
native Streamer_UpdateEx(playerid, Float:x, Float:y, Float:z, worldid = -1, interiorid = -1, type = -1, compensatedtime = -1, freezeplayer = 1);

// Natives (Data Manipulation)

native Streamer_GetFloatData(type, STREAMER_ALL_TAGS id, data, &Float:result);
native Streamer_SetFloatData(type, STREAMER_ALL_TAGS id, data, Float:value);
native Streamer_GetIntData(type, STREAMER_ALL_TAGS id, data);
native Streamer_SetIntData(type, STREAMER_ALL_TAGS id, data, value);
native Streamer_GetArrayData(type, STREAMER_ALL_TAGS id, data, dest[], maxdest = sizeof dest);
native Streamer_SetArrayData(type, STREAMER_ALL_TAGS id, data, const src[], maxsrc = sizeof src);
native Streamer_IsInArrayData(type, STREAMER_ALL_TAGS id, data, value);
native Streamer_AppendArrayData(type, STREAMER_ALL_TAGS id, data, value);
native Streamer_RemoveArrayData(type, STREAMER_ALL_TAGS id, data, value);
native Streamer_GetUpperBound(type);

// Natives (Miscellaneous)

native Streamer_GetDistanceToItem(Float:x, Float:y, Float:z, type, STREAMER_ALL_TAGS id, &Float:distance, dimensions = 3);
native Streamer_ToggleItem(playerid, type, STREAMER_ALL_TAGS id, toggle);
native Streamer_IsToggleItem(playerid, type, STREAMER_ALL_TAGS id);
native Streamer_ToggleAllItems(playerid, type, toggle, exceptions[] = { -1 }, maxexceptions = sizeof exceptions);
native Streamer_GetItemInternalID(playerid, type, STREAMER_ALL_TAGS streamerid);
native Streamer_GetItemStreamerID(playerid, type, internalid);
native Streamer_IsItemVisible(playerid, type, STREAMER_ALL_TAGS id);
native Streamer_DestroyAllVisibleItems(playerid, type, serverwide = 1);
native Streamer_CountVisibleItems(playerid, type, serverwide = 1);
native Streamer_DestroyAllItems(type, serverwide = 1);
native Streamer_CountItems(type, serverwide = 1);
native Streamer_GetNearbyItems(Float:x, Float:y, Float:z, type, STREAMER_ALL_TAGS items[], maxitems = sizeof items, Float:range = 300.0);
native Streamer_GetAllVisibleItems(playerid, type, STREAMER_ALL_TAGS items[], maxitems = sizeof items);
native Streamer_GetItemOffset(type, STREAMER_ALL_TAGS id, &Float:x, &Float:y, &Float:z);
native Streamer_SetItemOffset(type, STREAMER_ALL_TAGS id, Float:x, Float:y, Float:z);

// Natives (Objects)

native STREAMER_TAG_OBJECT CreateDynamicObject(modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_OBJECT_SD, Float:drawdistance = STREAMER_OBJECT_DD, STREAMER_TAG_AREA areaid = STREAMER_TAG_AREA -1, priority = 0);
native DestroyDynamicObject(STREAMER_TAG_OBJECT objectid);
native IsValidDynamicObject(STREAMER_TAG_OBJECT objectid);
native GetDynamicObjectPos(STREAMER_TAG_OBJECT objectid, &Float:x, &Float:y, &Float:z);
native SetDynamicObjectPos(STREAMER_TAG_OBJECT objectid, Float:x, Float:y, Float:z);
native GetDynamicObjectRot(STREAMER_TAG_OBJECT objectid, &Float:rx, &Float:ry, &Float:rz);
native SetDynamicObjectRot(STREAMER_TAG_OBJECT objectid, Float:rx, Float:ry, Float:rz);
native GetDynamicObjectNoCameraCol(STREAMER_TAG_OBJECT objectid);
native SetDynamicObjectNoCameraCol(STREAMER_TAG_OBJECT objectid);
native MoveDynamicObject(STREAMER_TAG_OBJECT objectid, Float:x, Float:y, Float:z, Float:speed, Float:rx = -1000.0, Float:ry = -1000.0, Float:rz = -1000.0);
native StopDynamicObject(STREAMER_TAG_OBJECT objectid);
native IsDynamicObjectMoving(STREAMER_TAG_OBJECT objectid);
native AttachCameraToDynamicObject(playerid, STREAMER_TAG_OBJECT objectid);
native AttachDynamicObjectToObject(STREAMER_TAG_OBJECT objectid, attachtoid, Float:offsetx, Float:offsety, Float:offsetz, Float:rx, Float:ry, Float:rz, syncrotation = 1);
native AttachDynamicObjectToPlayer(STREAMER_TAG_OBJECT objectid, playerid, Float:offsetx, Float:offsety, Float:offsetz, Float:rx, Float:ry, Float:rz);
native AttachDynamicObjectToVehicle(STREAMER_TAG_OBJECT objectid, vehicleid, Float:offsetx, Float:offsety, Float:offsetz, Float:rx, Float:ry, Float:rz, vehicletype = STREAMER_VEHICLE_TYPE_DYNAMIC);
native EditDynamicObject(playerid, STREAMER_TAG_OBJECT objectid);
native IsDynamicObjectMaterialUsed(STREAMER_TAG_OBJECT objectid, materialindex);
native GetDynamicObjectMaterial(STREAMER_TAG_OBJECT objectid, materialindex, &modelid, txdname[], texturename[], &materialcolor, maxtxdname = sizeof txdname, maxtexturename = sizeof texturename);
native SetDynamicObjectMaterial(STREAMER_TAG_OBJECT objectid, materialindex, modelid, const txdname[], const texturename[], materialcolor = 0);
native IsDynamicObjectMaterialTextUsed(STREAMER_TAG_OBJECT objectid, materialindex);
native GetDynamicObjectMaterialText(STREAMER_TAG_OBJECT objectid, materialindex, text[], &materialsize, fontface[], &fontsize, &bold, &fontcolor, &backcolor, &textalignment, maxtext = sizeof text, maxfontface = sizeof fontface);
native SetDynamicObjectMaterialText(STREAMER_TAG_OBJECT objectid, materialindex, const text[], materialsize = OBJECT_MATERIAL_SIZE_256x128, const fontface[] = "Arial", fontsize = 24, bold = 1, fontcolor = 0xFFFFFFFF, backcolor = 0, textalignment = 0);
native STREAMER_TAG_OBJECT GetPlayerCameraTargetDynObject(playerid);

// Natives (Pickups)

native STREAMER_TAG_PICKUP CreateDynamicPickup(modelid, type, Float:x, Float:y, Float:z, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_PICKUP_SD, STREAMER_TAG_AREA areaid = STREAMER_TAG_AREA -1, priority = 0);
native DestroyDynamicPickup(STREAMER_TAG_PICKUP pickupid);
native IsValidDynamicPickup(STREAMER_TAG_PICKUP pickupid);

// Natives (Checkpoints)

native STREAMER_TAG_CP CreateDynamicCP(Float:x, Float:y, Float:z, Float:size, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_CP_SD, STREAMER_TAG_AREA areaid = STREAMER_TAG_AREA -1, priority = 0);
native DestroyDynamicCP(STREAMER_TAG_CP checkpointid);
native IsValidDynamicCP(STREAMER_TAG_CP checkpointid);
native IsPlayerInDynamicCP(playerid, STREAMER_TAG_CP checkpointid);
native GetPlayerVisibleDynamicCP(playerid);

// Natives (Race Checkpoints)

native STREAMER_TAG_RACE_CP CreateDynamicRaceCP(type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_RACE_CP_SD, STREAMER_TAG_AREA areaid = STREAMER_TAG_AREA -1, priority = 0);
native DestroyDynamicRaceCP(STREAMER_TAG_RACE_CP checkpointid);
native IsValidDynamicRaceCP(STREAMER_TAG_RACE_CP checkpointid);
native IsPlayerInDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP checkpointid);
native GetPlayerVisibleDynamicRaceCP(playerid);

// Natives (Map Icons)

native STREAMER_TAG_MAP_ICON CreateDynamicMapIcon(Float:x, Float:y, Float:z, type, color, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_MAP_ICON_SD, style = MAPICON_LOCAL, STREAMER_TAG_AREA areaid = STREAMER_TAG_AREA -1, priority = 0);
native DestroyDynamicMapIcon(STREAMER_TAG_MAP_ICON iconid);
native IsValidDynamicMapIcon(STREAMER_TAG_MAP_ICON iconid);

// Natives (3D Text Labels)

native STREAMER_TAG_3D_TEXT_LABEL CreateDynamic3DTextLabel(const text[], color, Float:x, Float:y, Float:z, Float:drawdistance, attachedplayer = INVALID_PLAYER_ID, attachedvehicle = INVALID_VEHICLE_ID, vehicletype = STREAMER_VEHICLE_TYPE_DYNAMIC, testlos = 0, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_3D_TEXT_LABEL_SD, STREAMER_TAG_AREA areaid = STREAMER_TAG_AREA -1, priority = 0);
native DestroyDynamic3DTextLabel(STREAMER_TAG_3D_TEXT_LABEL id);
native IsValidDynamic3DTextLabel(STREAMER_TAG_3D_TEXT_LABEL id);
native GetDynamic3DTextLabelText(STREAMER_TAG_3D_TEXT_LABEL id, text[], maxtext = sizeof text);
native UpdateDynamic3DTextLabelText(STREAMER_TAG_3D_TEXT_LABEL id, color, const text[]);

// Natives (Areas)

native STREAMER_TAG_AREA CreateDynamicCircle(Float:x, Float:y, Float:size, worldid = -1, interiorid = -1, playerid = -1, priority = 0);
native STREAMER_TAG_AREA CreateDynamicCylinder(Float:x, Float:y, Float:minz, Float:maxz, Float:size, worldid = -1, interiorid = -1, playerid = -1, priority = 0);
native STREAMER_TAG_AREA CreateDynamicSphere(Float:x, Float:y, Float:z, Float:size, worldid = -1, interiorid = -1, playerid = -1, priority = 0);
native STREAMER_TAG_AREA CreateDynamicRectangle(Float:minx, Float:miny, Float:maxx, Float:maxy, worldid = -1, interiorid = -1, playerid = -1, priority = 0);
native STREAMER_TAG_AREA CreateDynamicCuboid(Float:minx, Float:miny, Float:minz, Float:maxx, Float:maxy, Float:maxz, worldid = -1, interiorid = -1, playerid = -1, priority = 0);
native STREAMER_TAG_AREA CreateDynamicCube(Float:minx, Float:miny, Float:minz, Float:maxx, Float:maxy, Float:maxz, worldid = -1, interiorid = -1, playerid = -1, priority = 0);
native STREAMER_TAG_AREA CreateDynamicPolygon(Float:points[], Float:minz = -FLOAT_INFINITY, Float:maxz = FLOAT_INFINITY, maxpoints = sizeof points, worldid = -1, interiorid = -1, playerid = -1, priority = 0);
native DestroyDynamicArea(STREAMER_TAG_AREA areaid);
native IsValidDynamicArea(STREAMER_TAG_AREA areaid);
native GetDynamicPolygonPoints(STREAMER_TAG_AREA areaid, Float:points[], maxpoints = sizeof points);
native GetDynamicPolygonNumberPoints(STREAMER_TAG_AREA areaid);
native IsPlayerInDynamicArea(playerid, STREAMER_TAG_AREA areaid, recheck = 0);
native IsPlayerInAnyDynamicArea(playerid, recheck = 0);
native IsAnyPlayerInDynamicArea(STREAMER_TAG_AREA areaid, recheck = 0);
native IsAnyPlayerInAnyDynamicArea(recheck = 0);
native GetPlayerDynamicAreas(playerid, STREAMER_TAG_AREA areas[], maxareas = sizeof areas);
native GetPlayerNumberDynamicAreas(playerid);
native IsPointInDynamicArea(STREAMER_TAG_AREA areaid, Float:x, Float:y, Float:z);
native IsPointInAnyDynamicArea(Float:x, Float:y, Float:z);
native IsLineInDynamicArea(STREAMER_TAG_AREA areaid, Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2);
native IsLineInAnyDynamicArea(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2);
native GetDynamicAreasForPoint(Float:x, Float:y, Float:z, STREAMER_TAG_AREA areas[], maxareas = sizeof areas);
native GetNumberDynamicAreasForPoint(Float:x, Float:y, Float:z);
native GetDynamicAreasForLine(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2, STREAMER_TAG_AREA areas[], maxareas = sizeof areas);
native GetNumberDynamicAreasForLine(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2);
native AttachDynamicAreaToObject(STREAMER_TAG_AREA areaid, STREAMER_TAG_OBJECT_ALT objectid, type = STREAMER_OBJECT_TYPE_DYNAMIC, playerid = INVALID_PLAYER_ID, Float:offsetx = 0.0, Float:offsety = 0.0, Float:offsetz = 0.0);
native AttachDynamicAreaToPlayer(STREAMER_TAG_AREA areaid, playerid, Float:offsetx = 0.0, Float:offsety = 0.0, Float:offsetz = 0.0);
native AttachDynamicAreaToVehicle(STREAMER_TAG_AREA areaid, vehicleid, vehicletype = STREAMER_VEHICLE_TYPE_DYNAMIC, Float:offsetx = 0.0, Float:offsety = 0.0, Float:offsetz = 0.0);
native ToggleDynAreaSpectateMode(STREAMER_TAG_AREA areaid, toggle);
native IsToggleDynAreaSpectateMode(STREAMER_TAG_AREA areaid);

// Natives (Actors)

native STREAMER_TAG_ACTOR CreateDynamicActor(modelid, Float:x, Float:y, Float:z, Float:r, invulnerable = 1, Float:health = 100.0, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_ACTOR_SD, STREAMER_TAG_AREA areaid = STREAMER_TAG_AREA -1, priority = 0);
native DestroyDynamicActor(STREAMER_TAG_ACTOR actorid);
native IsValidDynamicActor(STREAMER_TAG_ACTOR actorid);
native IsDynamicActorStreamedIn(STREAMER_TAG_ACTOR actorid, forplayerid);
native GetDynamicActorVirtualWorld(STREAMER_TAG_ACTOR actorid);
native SetDynamicActorVirtualWorld(STREAMER_TAG_ACTOR actorid, vworld);
native ApplyDynamicActorAnimation(STREAMER_TAG_ACTOR actorid, animlib[], animname[], Float:fdelta, loop, lockx, locky, freeze, time);
native ClearDynamicActorAnimations(STREAMER_TAG_ACTOR actorid);
native GetDynamicActorFacingAngle(STREAMER_TAG_ACTOR actorid, &Float:ang);
native SetDynamicActorFacingAngle(STREAMER_TAG_ACTOR actorid, Float:ang);
native GetDynamicActorPos(STREAMER_TAG_ACTOR actorid, &Float:x, &Float:y, &Float:z);
native SetDynamicActorPos(STREAMER_TAG_ACTOR actorid, Float:x, Float:y, Float:z);
native GetDynamicActorHealth(STREAMER_TAG_ACTOR actorid, &Float:health);
native SetDynamicActorHealth(STREAMER_TAG_ACTOR actorid, Float:health);
native SetDynamicActorInvulnerable(STREAMER_TAG_ACTOR actorid, invulnerable = 1);
native IsDynamicActorInvulnerable(STREAMER_TAG_ACTOR actorid);
native STREAMER_TAG_ACTOR GetPlayerTargetDynamicActor(playerid);
native STREAMER_TAG_ACTOR GetPlayerCameraTargetDynActor(playerid);

// Natives (Vehicles)

native STREAMER_TAG_VEHICLE CreateDynamicVehicle(modelid, Float:fX, Float:fY, Float:fZ, Float:fRot, color1, color2, respawndelay, addsiren = 0, worldid = -1, interiorid = 0, playerid = -1, 
	Float:streamdistance = STREAMER_VEHICLE_SD, STREAMER_TAG_AREA areaid = STREAMER_TAG_AREA -1, priority = 0);
		
	
native DestroyDynamicVehicle(STREAMER_TAG_VEHICLE vehicleid);
native IsValidDynamicVehicle(STREAMER_TAG_VEHICLE vehicleid);
native IsDynamicVehicleStreamedIn(STREAMER_TAG_VEHICLE vehicleid, forplayerid);
native GetDynamicVehicleSpawnInfo(STREAMER_TAG_VEHICLE vehicleid, &Float:fX, &Float:fY, &Float:fZ, &Float:fRot, &color1, &color2, &siren);
native GetDynamicVehiclePos(STREAMER_TAG_VEHICLE vehicleid, &Float:x, &Float:y, &Float:z);
native SetDynamicVehiclePos(STREAMER_TAG_VEHICLE vehicleid, Float:x, Float:y, Float:z);
native GetDynamicVehicleZAngle(STREAMER_TAG_VEHICLE vehicleid, &Float:z_angle);
native GetDynamicVehicleRotationQuat(STREAMER_TAG_VEHICLE vehicleid, &Float:w, &Float:x, &Float:y, &Float:z);
native SetDynamicVehicleZAngle(STREAMER_TAG_VEHICLE vehicleid, Float:z_angle);
native Float:GetDynamicVehDistanceFromPoint(STREAMER_TAG_VEHICLE vehicleid, Float:X, Float:Y, Float:Z);
native SetDynamicVehParamsForPlayer(STREAMER_TAG_VEHICLE vehicleid,playerid,objective,doorslocked);
native SetDynamicVehicleParamsEx(STREAMER_TAG_VEHICLE vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
native GetDynamicVehicleParamsEx(STREAMER_TAG_VEHICLE vehicleid, &engine, &lights, &alarm, &doors, &bonnet, &boot, &objective);
native GetDynamicVehParamsSirenState(STREAMER_TAG_VEHICLE vehicleid);
native SetDynamicVehParamsCarDoors(STREAMER_TAG_VEHICLE vehicleid, driver, passenger, backleft, backright);
native GetDynamicVehParamsCarDoors(STREAMER_TAG_VEHICLE vehicleid, &driver, &passenger, &backleft, &backright);
native SetDynamicVehParamsCarWindows(STREAMER_TAG_VEHICLE vehicleid, driver, passenger, backleft, backright);
native GetDynamicVehParamsCarWindows(STREAMER_TAG_VEHICLE vehicleid, &driver, &passenger, &backleft, &backright);
native SetDynamicVehicleToRespawn(STREAMER_TAG_VEHICLE vehicleid);
native LinkDynamicVehicleToInterior(STREAMER_TAG_VEHICLE vehicleid, interiorid);
native GetDynamicVehicleInterior(STREAMER_TAG_VEHICLE vehicleid);
native AddDynamicVehicleComponent(STREAMER_TAG_VEHICLE vehicleid, componentid);
native RemoveDynamicVehicleComponent(STREAMER_TAG_VEHICLE vehicleid, componentid);
native ChangeDynamicVehicleColor(STREAMER_TAG_VEHICLE vehicleid, color1, color2);
native GetDynamicVehicleColor(STREAMER_TAG_VEHICLE vehicleid, &color1, &color2);
native ChangeDynamicVehiclePaintjob(STREAMER_TAG_VEHICLE vehicleid, paintjobid);
native GetDynamicVehiclePaintjob(STREAMER_TAG_VEHICLE vehicleid);
native SetDynamicVehicleHealth(STREAMER_TAG_VEHICLE vehicleid, Float:health);
native GetDynamicVehicleHealth(STREAMER_TAG_VEHICLE vehicleid, &Float:health);
native AttachTrailerToDynamicVehicle(STREAMER_TAG_VEHICLE trailerid, STREAMER_TAG_VEHICLE vehicleid);
native DetachTrailerFromDynamicVeh(STREAMER_TAG_VEHICLE vehicleid);
native IsTrailerAttachedToDynamicVeh(STREAMER_TAG_VEHICLE vehicleid);
native GetDynamicVehicleTrailer(STREAMER_TAG_VEHICLE vehicleid);
native SetDynamicVehicleNumberPlate(STREAMER_TAG_VEHICLE vehicleid, plate[]);
native GetDynamicVehicleNumberPlate(STREAMER_TAG_VEHICLE vehicleid, plate[], size = sizeof(plate));
native GetDynamicVehicleModel(STREAMER_TAG_VEHICLE vehicleid);
native GetDynamicVehComponentInSlot(STREAMER_TAG_VEHICLE vehicleid, slot); // There is 1 slot for each CARMODTYPE_*
native RepairDynamicVehicle(STREAMER_TAG_VEHICLE vehicleid); // Repairs the damage model and resets the health
native GetDynamicVehicleVelocity(STREAMER_TAG_VEHICLE vehicleid, &Float:X, &Float:Y, &Float:Z);
native SetDynamicVehicleVelocity(STREAMER_TAG_VEHICLE vehicleid, Float:X, Float:Y, Float:Z);
native SetDynamicVehAngularVelocity(STREAMER_TAG_VEHICLE vehicleid, Float:X, Float:Y, Float:Z);
native GetDynamicVehicleDamageStatus(STREAMER_TAG_VEHICLE vehicleid, &panels, &doors, &lights, &tires);
native UpdateDynamicVehDamageStatus(STREAMER_TAG_VEHICLE vehicleid, panels, doors, lights, tires);
native SetDynamicVehicleVirtualWorld(STREAMER_TAG_VEHICLE vehicleid, worldid);
native GetDynamicVehicleVirtualWorld(STREAMER_TAG_VEHICLEvehicleid);
native GetPlayerSurfingDynamicVehID(playerid);
native PutPlayerInDynamicVehicle(playerid, STREAMER_TAG_VEHICLE vehicleid, seatid);
native GetPlayerDynamicVehicleID(playerid);
native IsPlayerInDynamicVehicle(playerid, STREAMER_TAG_VEHICLE vehicleid);
native IsPlayerInAnyDynamicVehicle(STREAMER_TAG_VEHICLE vehicleid);
native IsDynamicVehicleOccupied(STREAMER_TAG_VEHICLE vehicleid);
native PlayerSpectateDynamicVehicle(playerid, STREAMER_TAG_VEHICLE targetvehicleid, mode = 0);

// Natives (Extended)

native STREAMER_TAG_OBJECT CreateDynamicObjectEx(modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, Float:streamdistance = STREAMER_OBJECT_SD, Float:drawdistance = STREAMER_OBJECT_DD, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, STREAMER_TAG_AREA areas[] = { STREAMER_TAG_AREA -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players, maxareas = sizeof areas);
native STREAMER_TAG_PICKUP CreateDynamicPickupEx(modelid, type, Float:x, Float:y, Float:z, Float:streamdistance = STREAMER_PICKUP_SD, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, STREAMER_TAG_AREA areas[] = { STREAMER_TAG_AREA -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players, maxareas = sizeof areas);
native STREAMER_TAG_CP CreateDynamicCPEx(Float:x, Float:y, Float:z, Float:size, Float:streamdistance = STREAMER_CP_SD, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, STREAMER_TAG_AREA areas[] = { STREAMER_TAG_AREA -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players, maxareas = sizeof areas);
native STREAMER_TAG_RACE_CP CreateDynamicRaceCPEx(type, Float:x, Float:y, Float:z, Float:nextx, Float:nexty, Float:nextz, Float:size, Float:streamdistance = STREAMER_RACE_CP_SD, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, STREAMER_TAG_AREA areas[] = { STREAMER_TAG_AREA -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players, maxareas = sizeof areas);
native STREAMER_TAG_MAP_ICON CreateDynamicMapIconEx(Float:x, Float:y, Float:z, type, color, style = MAPICON_LOCAL, Float:streamdistance = STREAMER_MAP_ICON_SD, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, STREAMER_TAG_AREA areas[] = { STREAMER_TAG_AREA -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players, maxareas = sizeof areas);
native STREAMER_TAG_3D_TEXT_LABEL CreateDynamic3DTextLabelEx(const text[], color, Float:x, Float:y, Float:z, Float:drawdistance, attachedplayer = INVALID_PLAYER_ID, attachedvehicle = INVALID_VEHICLE_ID, testlos = 0, Float:streamdistance = STREAMER_3D_TEXT_LABEL_SD, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, STREAMER_TAG_AREA areas[] = { STREAMER_TAG_AREA -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players, maxareas = sizeof areas);
native STREAMER_TAG_AREA CreateDynamicCircleEx(Float:x, Float:y, Float:size, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native STREAMER_TAG_AREA CreateDynamicCylinderEx(Float:x, Float:y, Float:minz, Float:maxz, Float:size, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native STREAMER_TAG_AREA CreateDynamicSphereEx(Float:x, Float:y, Float:z, Float:size, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native STREAMER_TAG_AREA CreateDynamicRectangleEx(Float:minx, Float:miny, Float:maxx, Float:maxy, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native STREAMER_TAG_AREA CreateDynamicCuboidEx(Float:minx, Float:miny, Float:minz, Float:maxx, Float:maxy, Float:maxz, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native STREAMER_TAG_AREA CreateDynamicCubeEx(Float:minx, Float:miny, Float:minz, Float:maxx, Float:maxy, Float:maxz, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native STREAMER_TAG_AREA CreateDynamicPolygonEx(Float:points[], Float:minz = -FLOAT_INFINITY, Float:maxz = FLOAT_INFINITY, maxpoints = sizeof points, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players);
native STREAMER_TAG_ACTOR CreateDynamicActorEx(modelid, Float:x, Float:y, Float:z, Float:r, invulnerable = 1, Float:health = 100.0, Float:streamdistance = STREAMER_ACTOR_SD, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, STREAMER_TAG_AREA areas[] = { STREAMER_TAG_AREA -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players, maxareas = sizeof areas);
native STREAMER_TAG_VEHICLE CreateDynamicVehicleEx(modelid, Float:fX, Float:fY, Float:fZ, Float:fRot, color1, color2, respawndelay, addsiren = 0,
	paintjob = 3, Float:health = 1000.0, panels = 0, doors = 0, light = 0, tires = 0,
	param_engine = -1, param_lights = -1, param_alarm = -1, param_doors = -1, param_bonnet = -1, param_boot = -1, param_objective = -1,
	doors_driver = -1, doors_passenger = -1, doors_backleft = -1, doors_backright = -1,
	windows_driver = -1, windows_passenger = -1, windows_backleft = -1, windows_backright = -1, siren = -1,
	numberplate[] = "", carmods[] = { -1 }, Float:streamdistance = STREAMER_VEHICLE_SD, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 },
	STREAMER_TAG_AREA areas[] = { STREAMER_TAG_AREA - 1 }, priority = 0, maxcarmods = sizeof carmods, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players, maxareas = sizeof areas);
	
// Natives (Deprecated)

native Streamer_CallbackHook(callback, {Float,_}:...);

native Streamer_TickRate(rate);
native Streamer_MaxItems(type, items);
native Streamer_VisibleItems(type, items, playerid = -1);
native Streamer_CellDistance(Float:distance);
native Streamer_CellSize(Float:size);

native DestroyAllDynamicObjects();
native CountDynamicObjects();
native DestroyAllDynamicPickups();
native CountDynamicPickups();
native DestroyAllDynamicCPs();
native CountDynamicCPs();
native DestroyAllDynamicRaceCPs();
native CountDynamicRaceCPs();
native DestroyAllDynamicMapIcons();
native CountDynamicMapIcons();
native DestroyAllDynamic3DTextLabels();
native CountDynamic3DTextLabels();
native DestroyAllDynamicAreas();
native CountDynamicAreas();

native TogglePlayerDynamicCP(playerid, STREAMER_TAG_CP checkpointid, toggle);
native TogglePlayerAllDynamicCPs(playerid, toggle, exceptions[] = { -1 }, maxexceptions = sizeof exceptions);
native TogglePlayerDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP checkpointid, toggle);
native TogglePlayerAllDynamicRaceCPs(playerid, toggle, exceptions[] = { -1 }, maxexceptions = sizeof exceptions);
native TogglePlayerDynamicArea(playerid, STREAMER_TAG_AREA areaid, toggle);
native TogglePlayerAllDynamicAreas(playerid, toggle, exceptions[] = { -1 }, maxexceptions = sizeof exceptions);

// Callbacks

forward OnDynamicObjectMoved(STREAMER_TAG_OBJECT objectid);
forward OnPlayerEditDynamicObject(playerid, STREAMER_TAG_OBJECT objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz);
forward OnPlayerSelectDynamicObject(playerid, STREAMER_TAG_OBJECT objectid, modelid, Float:x, Float:y, Float:z);
forward OnPlayerShootDynamicObject(playerid, weaponid, STREAMER_TAG_OBJECT objectid, Float:x, Float:y, Float:z);
forward OnPlayerPickUpDynamicPickup(playerid, STREAMER_TAG_PICKUP pickupid);
forward OnPlayerEnterDynamicCP(playerid, STREAMER_TAG_CP checkpointid);
forward OnPlayerLeaveDynamicCP(playerid, STREAMER_TAG_CP checkpointid);
forward OnPlayerEnterDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP checkpointid);
forward OnPlayerLeaveDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP checkpointid);
forward OnPlayerEnterDynamicArea(playerid, STREAMER_TAG_AREA areaid);
forward OnPlayerLeaveDynamicArea(playerid, STREAMER_TAG_AREA areaid);
forward OnPlayerGiveDamageDynamicActor(playerid, STREAMER_TAG_ACTOR actorid, Float:amount, weaponid, bodypart);
forward OnDynamicActorStreamIn(STREAMER_TAG_ACTOR actorid, forplayerid);
forward OnDynamicActorStreamOut(STREAMER_TAG_ACTOR actorid, forplayerid);
forward Streamer_OnItemStreamIn(type, STREAMER_ALL_TAGS id);
forward Streamer_OnItemStreamOut(type, STREAMER_ALL_TAGS id);
forward OnDynamicVehicleSpawn(STREAMER_TAG_VEHICLE vehicleid);
forward OnDynamicVehicleDeath(STREAMER_TAG_VEHICLE vehicleid, killerid);
forward OnPlayerEnterDynamicVehicle(playerid, STREAMER_TAG_VEHICLE vehicleid, ispassenger);
forward OnPlayerExitDynamicVehicle(playerid, STREAMER_TAG_VEHICLE vehicleid);
forward OnDynamicVehicleMod(playerid, STREAMER_TAG_VEHICLE vehicleid, componentid);
forward OnDynamicVehiclePaintjob(playerid, STREAMER_TAG_VEHICLE vehicleid, paintjobid);
forward OnDynamicVehicleRespray(playerid, STREAMER_TAG_VEHICLE vehicleid, color1, color2);
forward OnDynamicVehDamageStatusUpdate(STREAMER_TAG_VEHICLE vehicleid, playerid);
forward OnUnoccupiedDynamicVehUpdate(STREAMER_TAG_VEHICLE vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z);
forward OnDynamicVehicleStreamIn(STREAMER_TAG_VEHICLE vehicleid, forplayerid);
forward OnDynamicVehicleStreamOut(STREAMER_TAG_VEHICLE vehicleid, forplayerid);
forward OnDynamicTrailerUpdate(playerid, STREAMER_TAG_VEHICLE vehicleid);
forward OnDynamicVehSirenStateChange(playerid, STREAMER_TAG_VEHICLE vehicleid, newstate);
forward Streamer_OnPluginError(error[]);
